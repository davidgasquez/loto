
#include "tilemaps/map.h"

#include <fstream>

#include "base/debug.h"


bool Map::Load(std::string tilemapPath) {
  std::ifstream f(tilemapPath.c_str());
  if (!f) {
    return false;
  }

  unsigned width, height;
  f >> width >> height;
  sf::Vector2u size(width, height);

  ground_.Load(&f, size);
  mid_.Load(&f, size);
  ceil_.Load(&f, size);

  return true;
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(ground_);
  target.draw(mid_);
  target.draw(ceil_);
}
