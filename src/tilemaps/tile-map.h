
#ifndef TILES_TILE_MAP_H_
#define TILES_TILE_MAP_H_

#include <SFML/Graphics.hpp>

#include <fstream>


class TileMap : public sf::Drawable, public sf::Transformable {
 public:
  void Load(std::ifstream *f,
            sf::Vec2u   size);

 private:
  unsigned *tiles_;
  sf::VertexArray vertices_;

  virtual void draw(sf::RenderTarget& target,
                    sf::RenderStates  states) const;
};

#endif  // TILES_TILE_MAP_H_
