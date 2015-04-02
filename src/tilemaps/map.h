
#ifndef TILEMAPS_MAP_H_
#define TILEMAPS_MAP_H_

#include <string>

#include <SFML/Graphics.hpp>

#include "tilemaps/tile-map.h"


class Map : public sf::Drawable {
public:
  Map(const std::string & tilesetPath, const std::string& tilemapPath,
      sf::Vector2u tileSize);

  bool Load();

private:
  std::string tilesetPath_;
  std::string tilemapPath_;
  sf::Vector2u tileSize_;

  TileMap* ground_;
  TileMap* mid_;
  TileMap* ceil_;

  virtual void draw(sf::RenderTarget& target, sf::RenderStates  states) const;
};

#endif  // TILEMAPS_MAP_H_
