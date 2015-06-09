// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#ifndef TILES_TILE_MAP_H_
#define TILES_TILE_MAP_H_

#include <SFML/Graphics.hpp>

#include <fstream>

#include "engine/instance.h"
#include "base/aliases.h"

class TileMap : public Instance {
 public:
  void Load(std::ifstream *f,
            Vec2u   size);

 private:
  unsigned *tiles_;
  sf::VertexArray vertices_;

  virtual void draw(sf::RenderTarget& target,
                    sf::RenderStates  states) const;
};

#endif  // TILES_TILE_MAP_H_
