
#include "tilemaps/map.h"

#include <fstream>

#include "base/debug.h"


Map::Map(const std::string & tilesetPath, const std::string& tilemapPath,
         sf::Vector2u tileSize)
: tilesetPath_(tilesetPath), tilemapPath_(tilemapPath), tileSize_(tileSize) {
  // empty
}

bool Map::Load() {
  std::ifstream f(tilemapPath_.c_str());
  if (!f) {
    return false;
  }

  unsigned width, height;
  f >> width >> height;
  sf::Vector2u size(width, height);

  unsigned* groundTiles = new unsigned[width * height];
  for (unsigned j = 0; j < height; ++j) {
    for (unsigned i = 0; i < width; ++i) {
      unsigned tile;
      f >> tile;
      groundTiles[j * width + i] = (tile == 0) ? 19 : tile - 1;
    }
  }
  ground_ = new TileMap(tilesetPath_, tileSize_, groundTiles, size);

  if (!ground_->Load()) {
    return false;
  }

  unsigned* midTiles = new unsigned[width * height];
  for (unsigned j = 0; j < height; ++j) {
    for (unsigned i = 0; i < width; ++i) {
      unsigned tile;
      f >> tile;
      midTiles[j * width + i] = (tile == 0) ? 19 : tile - 1;
    }
  }
  mid_ = new TileMap(tilesetPath_, tileSize_, midTiles, size);

  if (!mid_->Load()) {
    return false;
  }

  unsigned* ceilTiles = new unsigned[width * height];
  for (unsigned j = 0; j < height; ++j) {
    for (unsigned i = 0; i < width; ++i) {
      unsigned tile;
      f >> tile;
      ceilTiles[j * width + i] = (tile == 0) ? 19 : tile - 1;
    }
  }
  ceil_ = new TileMap(tilesetPath_, tileSize_, ceilTiles, size);

  if (!ceil_->Load()) {
    return false;
  }

  return true;
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(*ground_);
  target.draw(*mid_);
  target.draw(*ceil_);
}
