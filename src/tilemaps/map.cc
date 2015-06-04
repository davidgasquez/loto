
#include "tilemaps/map.h"

#include <fstream>

#include "engine/game-manager.h"


bool Map::Load(std::string tilemapPath) {
  std::ifstream f(tilemapPath.c_str());

  if (!f) {
    return false;
  }

  unsigned width, height;
  f >> width >> height;
  Vec2u size(width, height);

  ground_.Load(&f, size);
  mid_.Load(&f, size);
  ceil_.Load(&f, size);

  GameManager::GetMapController()->Load(width, height);

  return true;
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(ground_);
  target.draw(mid_);
  target.draw(ceil_);
}
