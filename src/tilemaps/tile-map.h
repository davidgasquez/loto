
#ifndef TILES_TILE_MAP_H_
#define TILES_TILE_MAP_H_

#include <fstream>

#include <SFML/Graphics.hpp>


class TileMap : public sf::Drawable, public sf::Transformable {
public:
  void Load(std::ifstream* f, sf::Vector2u size, sf::Vector2u tileSize);

private:
  unsigned   *tiles_;
  sf::VertexArray vertices_;

  virtual void draw(sf::RenderTarget& target, sf::RenderStates  states) const;
};

#endif  // TILES_TILE_MAP_H_
