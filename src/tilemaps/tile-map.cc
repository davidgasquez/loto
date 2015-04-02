
#include "tilemaps/tile-map.h"

#include "engine/game-manager.h"


void TileMap::Load(std::ifstream *f, sf::Vector2u size) {
  unsigned int width  = size.x;
  unsigned int height = size.y;
  unsigned int wTile  = GameManager::GetTileSize().x;
  unsigned int hTile  = GameManager::GetTileSize().y;

  tiles_ = new unsigned[width * height];

  for (unsigned j = 0; j < height; ++j) {
    for (unsigned i = 0; i < width; ++i) {
      unsigned tile;
      *f >> tile;
      tiles_[j * width + i] = (tile == 0) ? 19 : tile - 1;
    }
  }

  vertices_.setPrimitiveType(sf::Quads);
  vertices_.resize(width * height * 4);

  for (unsigned int i = 0; i < width; ++i) {
    for (unsigned int j = 0; j < height; ++j) {
      int tile = tiles_[j * width + i];

      sf::Vertex *quad = &vertices_[(i + j * width) * 4];

      quad[0].position = sf::Vector2f(i * wTile, j * hTile);
      quad[1].position = sf::Vector2f((i + 1) * wTile, j * hTile);
      quad[2].position = sf::Vector2f((i + 1) * wTile, (j + 1) * hTile);
      quad[3].position = sf::Vector2f(i * wTile, (j + 1) * hTile);

      sf::Texture *tileset = GameManager::GetResourcesManager()->Map();
      int tu               = tile % (tileset->getSize().x / wTile);
      int tv               = tile / (tileset->getSize().x / wTile);

      quad[0].texCoords = sf::Vector2f(tu * wTile, tv * hTile);
      quad[1].texCoords = sf::Vector2f((tu + 1) * wTile, tv * hTile);
      quad[2].texCoords = sf::Vector2f((tu + 1) * wTile, (tv + 1) * hTile);
      quad[3].texCoords = sf::Vector2f(tu * wTile, (tv + 1) * hTile);
    }
  }
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();
  states.texture    = GameManager::GetResourcesManager()->Map();
  target.draw(vertices_, states);
}
