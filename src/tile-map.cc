
#include "tile-map.h"


TileMap::TileMap(const std::string& tilesetPath, sf::Vector2u tileSize,
                 const int* tiles, sf::Vector2u size)
: tilesetPath_(tilesetPath), tileSize_(tileSize), tiles_(tiles), size_(size)
{
  // empty
}


bool TileMap::Load() {
  if (!tileset_.loadFromFile(tilesetPath_)) {
    return false;
  }

  unsigned int width = size_.x;
  unsigned int height = size_.y;
  unsigned int wTile = tileSize_.x;
  unsigned int hTile = tileSize_.y;

  vertices_.setPrimitiveType(sf::Quads);
  vertices_.resize(width * height * 4);

  for (unsigned int i = 0; i < width; ++i) {
    for (unsigned int j = 0; j < height; ++j) {
      int tile = tiles_[i + j * width];

      sf::Vertex* quad = &vertices_[(i + j * width) * 4];

      quad[0].position = sf::Vector2f(i * wTile, j * hTile);
      quad[1].position = sf::Vector2f((i + 1) * wTile, j * hTile);
      quad[2].position = sf::Vector2f((i + 1) * wTile, (j + 1) * hTile);
      quad[3].position = sf::Vector2f(i * wTile, (j + 1) * hTile);

      int tu = tile % (tileset_.getSize().x / wTile);
      int tv = tile / (tileset_.getSize().x / wTile);

      quad[0].texCoords = sf::Vector2f(tu * wTile, tv * hTile);
      quad[1].texCoords = sf::Vector2f((tu + 1) * wTile, tv * hTile);
      quad[2].texCoords = sf::Vector2f((tu + 1) * wTile, (tv + 1) * hTile);
      quad[3].texCoords = sf::Vector2f(tu * wTile, (tv + 1) * hTile);
    }
  }

  return true;
}


void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();
  states.texture = &tileset_;
  target.draw(vertices_, states);
}
