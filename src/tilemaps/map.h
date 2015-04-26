
#ifndef TILEMAPS_MAP_H_
#define TILEMAPS_MAP_H_

#include <SFML/Graphics.hpp>

#include <string>

#include "engine/instance.h"
#include "tilemaps/tile-map.h"


class Map : public Instance {
 public:
  bool Load(std::string tilemapPath);

 private:
  TileMap ground_, mid_, ceil_;

  virtual void draw(sf::RenderTarget& target,
                    sf::RenderStates  states) const;
};

#endif  // TILEMAPS_MAP_H_
