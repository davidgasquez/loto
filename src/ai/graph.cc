
#include "ai/graph.h"

#include "base/debug.h"
#include "engine/game.h"


const float kSquareMoveWeight = 1.f;
const float kDiagonalMoveWeight = 1.41f;


void Graph::Load() {
  for (unsigned row = 0; row < rows_; ++row) {
    for (unsigned col = 0; col < cols_; ++col) {
      unsigned vertex = VertexIndex(Vec2u(col, row));

      if (col > 0) {
        unsigned other = VertexIndex(Vec2u(col - 1, row));
        AddEdge_(vertex, Neighbour(other, kSquareMoveWeight));
        AddEdge_(other, Neighbour(vertex, kSquareMoveWeight));
      }
      if (row  > 0) {
        unsigned other = VertexIndex(Vec2u(col, row - 1));
        AddEdge_(vertex, Neighbour(other, kSquareMoveWeight));
        AddEdge_(other, Neighbour(vertex, kSquareMoveWeight));
      }
      if (row > 0 && col > 0) {
        unsigned other = VertexIndex(Vec2u(col - 1, row - 1));
        AddEdge_(vertex, Neighbour(other, kDiagonalMoveWeight));
        AddEdge_(other, Neighbour(vertex, kDiagonalMoveWeight));
      }
    }
  }
  
  for (unsigned row = 1; row < rows_; ++row) {
    for (unsigned col = 0; col < cols_ - 1; ++col) {
      unsigned vertex = VertexIndex(Vec2u(col, row));
      unsigned other = VertexIndex(Vec2u(col + 1, row - 1));
      AddEdge_(vertex, Neighbour(other, kDiagonalMoveWeight));
      AddEdge_(other, Neighbour(vertex, kDiagonalMoveWeight));
    }
  }
}


void Graph::AddEdge_(unsigned from, Neighbour neighbour) {
  neighbours_[from].push_back(neighbour);
}


unsigned Graph::VertexIndex(Vec2u node) {
  return node.x + node.y * cols_;
}


Vec2u Graph::IndexToVertex(unsigned index) {
  Vec2u pos;
  pos.x = static_cast<unsigned>(index % cols_);
  pos.y = static_cast<unsigned>(index / cols_);

  return pos;
}
  

Vec2f Graph::CalcPos(Vec2u node) {
  Vec2f tile(Game::GetTileSize());
  Vec2f half_tile(tile / 2.f);
  return Vec2f(half_tile.x / 2.f + half_tile.x * node.x, half_tile.y / 2.f + half_tile.y * node.y);
}


Vec2u Graph::CalcNode(Vec2f pos) {
  Vec2f half_tile(Game::GetTileSize());
  half_tile /= 2.f;

  Vec2u node;
  node.x = static_cast<unsigned>(pos.x / half_tile.x);
  node.y = static_cast<unsigned>(pos.y / half_tile.y);

  return node;
}


void Graph::RemoveEdges(Vec2u node) {
  auto index = VertexIndex(node);
  
  for (Neighbour neighbour : neighbours_[index]) {
    auto& nconns = neighbours_[neighbour.vertex()];
    for (unsigned i = 0; i < nconns.size(); ++i) {
      if (nconns[i].vertex() == index) {
        nconns.erase(nconns.begin() + i);
        break;
      }
    }
  }

  neighbours_[index].clear();
}
