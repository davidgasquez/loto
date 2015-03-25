
#ifndef TILE_MAP_H_
#define TILE_MAP_H_

#include <string>

#include <SFML/Graphics.hpp>


class TileMap : public sf::Drawable, public sf::Transformable {
public:
  TileMap(const std::string& tilesetPath, sf::Vector2u tileSize,
          const int* tiles, sf::Vector2u size);

  bool Load();

private:
  std::string tilesetPath_;
  sf::Vector2u tileSize_;
  const int* tiles_;
  sf::Vector2u size_;

  sf::VertexArray vertices_;
  sf::Texture tileset_;

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
