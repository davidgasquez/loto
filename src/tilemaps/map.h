
#ifndef TILEMAPS_MAP_H_
#define TILEMAPS_MAP_H_

#include <SFML/Graphics.hpp>

#include <string>

class Map {
 public:
  bool Load(std::string tilemapPath);
};

#endif  // TILEMAPS_MAP_H_
