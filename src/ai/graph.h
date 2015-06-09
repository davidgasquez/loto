// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

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

  void add_weight(float weight) {
    weight_ += weight;
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

  std::vector<std::vector<Neighbour> > neighbours() {
    return neighbours_;
  }

  unsigned rows() {
    return rows_;
  }

  unsigned cols() {
    return cols_;
  }

  unsigned VertexIndex(Vec2u node);
  Vec2u IndexToVertex(unsigned index);

  void RemoveEdges(Vec2u node);
  void AddWeight(Vec2u node, float weight);

 private:
  unsigned rows_, cols_;
  std::vector<std::vector<Neighbour> > neighbours_;

  void AddEdge_(unsigned from, Neighbour neighbour);
};

#endif  // AI_GRAPH_H_
