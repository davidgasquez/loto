
#include "ai/graph.h"

#include "base/debug.h"
#include "engine/game.h"


const float kDefaultWeight = 1.f;


void Graph::Load() {
  for (unsigned row = 0; row < rows_; ++row) {
    for (unsigned col = 0; col < cols_; ++col) {
      unsigned vertex = VertexIndex_(Vec2u(col, row));

      if (col > 0) {
        unsigned other = VertexIndex_(Vec2u(col - 1, row));
        AddEdge_(vertex, Neighbour(other, kDefaultWeight));
        AddEdge_(other, Neighbour(vertex, kDefaultWeight));
      }
      if (row  > 0) {
        unsigned other = VertexIndex_(Vec2u(col, row - 1));
        AddEdge_(vertex, Neighbour(other, kDefaultWeight));
        AddEdge_(other, Neighbour(vertex, kDefaultWeight));
      }
      if (row > 0 && col > 0) {
        unsigned other = VertexIndex_(Vec2u(col - 1, row - 1));
        AddEdge_(vertex, Neighbour(other, kDefaultWeight));
        AddEdge_(other, Neighbour(vertex, kDefaultWeight));
      }
    }
  }
  
  for (unsigned row = 1; row < rows_; ++row) {
    for (unsigned col = 0; col < cols_ - 1; ++col) {
      unsigned vertex = VertexIndex_(Vec2u(col, row));
      unsigned other = VertexIndex_(Vec2u(col + 1, row - 1));
      AddEdge_(vertex, Neighbour(other, kDefaultWeight));
      AddEdge_(other, Neighbour(vertex, kDefaultWeight));
    }
  }
}


void Graph::AddEdge_(unsigned from, Neighbour neighbour) {
  neighbours_[from].push_back(neighbour);
}


unsigned Graph::VertexIndex_(Vec2u node) {
  return node.x + node.y * rows_;
}
  

Vec2f Graph::CalcPos(Vec2u node) {
  Vec2f tile(Game::GetTileSize());
  Vec2f half_tile(tile / 2.f);
  return Vec2f(half_tile.x / 2.f + half_tile.x * node.x, half_tile.y / 2.f + half_tile.y * node.y);
}


Vec2u Graph::CalcNode(Vec2f pos) {
  Vec2u node;
  node.x = 1;
  node.y = 1;

  return node;
}
