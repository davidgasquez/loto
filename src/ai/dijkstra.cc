
#include "ai/dijkstra.h"

#include <set>
#include <limits>
#include <vector>


#include "engine/game.h"


class GraphNode {
 public:
  GraphNode(unsigned vertex, unsigned distance)
    : vertex_(vertex), distance_(distance) { }

  GraphNode(const GraphNode& other)
    : vertex_(other.vertex_), distance_(other.distance_) { }

  unsigned vertex() const {
    return vertex_;
  }

  unsigned distance() const {
    return distance_;
  }

 private:
  unsigned vertex_;
  float distance_;
};


bool operator<(const GraphNode& a, const GraphNode& b) {
  if (a.distance() - b.distance() < .001f) {
    return a.vertex() < b.vertex();
  }

  return a.distance() < b.distance();
}


std::vector<Vec2u> DijkstraPathFinding(Vec2u from) {
  auto graph = Game::GetMapController()->graph();
  auto from_vertex = graph->VertexIndex(from);

  std::vector<std::vector<Neighbour> > neighbours(graph->neighbours());

  std::set<GraphNode> queue;
  queue.insert(GraphNode(from_vertex, 0));

  std::vector<float> min_distance(neighbours.size(),
                                  std::numeric_limits<float>::max());
  min_distance[from_vertex] = 0.f;

  std::vector<unsigned> previous(neighbours.size(), 0);

  while (!queue.empty()) {
    GraphNode node(*queue.begin());
    queue.erase(queue.begin());

    if (min_distance[node.vertex()] < node.distance()) {
      continue;
    }

    Vec2u vertex(graph->IndexToVertex(node.vertex()));
    if (vertex.x < 2) {
      break;
    }

    for (auto& neighbour : neighbours[node.vertex()]) {
      auto distance = node.distance() + 1.f * neighbour.weight();
      if (distance < min_distance[neighbour.vertex()]) {
        min_distance[neighbour.vertex()] = distance;
        previous[neighbour.vertex()] = node.vertex();

        queue.insert(GraphNode(neighbour.vertex(), distance));
      }
    }
  }

  unsigned dest;
  for (unsigned row = 0; row < graph->rows(); ++row) {
    unsigned v = graph->VertexIndex(Vec2u(1, row));
    if (min_distance[v] < std::numeric_limits<float>::max()) {
      dest = v;
      break;
    }
  }

  std::vector<Vec2u> path;
  for (unsigned vertex = dest; min_distance[vertex] != 0; vertex = previous[vertex]) {
    path.push_back(Vec2u(graph->IndexToVertex(vertex)));
  }
  std::reverse(path.begin(), path.end());

  // static unsigned j = 0;
  // j++;
  // if (j == 10) {
  //   for (unsigned i = 0; i < path.size(); ++i) {
  //     cout << "path[" << i << "] = " << path[i].x << " " << path[i].y << endl;
  //   }
  //   exit(0);
  // }

  path.push_back(Vec2u(8, 11));
  return path;
}
