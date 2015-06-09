// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#ifndef TILEMAPS_MAP_H_
#define TILEMAPS_MAP_H_

#include <SFML/Graphics.hpp>

#include <string>

class Map {
 public:
  bool Load(std::string tilemapPath);
};

#endif  // TILEMAPS_MAP_H_
