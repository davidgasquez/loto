
#include "tilemaps/map.h"

#include <fstream>
#include <string>

#include "engine/game-manager.h"
#include "tilemaps/tile-map.h"


bool Map::Load(std::string tilemapPath) {
  std::ifstream f(tilemapPath.c_str());

  if (!f) {
    return false;
  }

  unsigned width, height;
  f >> width >> height;
  Vec2u size(width, height);

  auto instances = GameManager::GetInstancesManager();

  auto map = new TileMap();
  map->Load(&f, size);
  instances->AddInstance(map, kLayerBot);

  map = new TileMap();
  map->Load(&f, size);
  instances->AddInstance(map, kLayerMid);

  map = new TileMap();
  map->Load(&f, size);
  instances->AddInstance(map, kLayerTop);

  GameManager::GetMapController()->Load(width, height);

  return true;
}
