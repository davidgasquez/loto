
#ifndef AI_GRAPH_H_
#define AI_GRAPH_H_

#include <vector>

#include "base/aliases.h"


class Neighbour {
public:
  Neighbour(unsigned vertex, float weight)
  : vertex_(vertex), weight_(weight) { }

  unsigned vertex() {
    return vertex_;
  }

  float weight() {
    return weight_;
  }

private:
  unsigned vertex_;
  float weight_;
};


class Graph {
public:
  Graph(unsigned width, unsigned height)
  : rows_(height * 2), cols_(width * 2), neighbours_(rows_ * cols_) { }

  void Load();

  Vec2f CalcPos(Vec2u node);
  Vec2u CalcNode(Vec2f pos);

private:
  unsigned rows_, cols_;
  std::vector<std::vector<Neighbour> > neighbours_;

  void AddEdge_(unsigned from, Neighbour neighbour);
  unsigned VertexIndex_(Vec2u node);
};


#endif // AI_GRAPH_H_
