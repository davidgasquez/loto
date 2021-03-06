// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#include "tilemaps/map.h"

#include <fstream>
#include <string>

#include "engine/game.h"
#include "tilemaps/tile-map.h"


bool Map::Load(std::string tilemapPath) {
  std::ifstream f(tilemapPath.c_str());

  if (!f) {
    return false;
  }

  unsigned width, height;
  f >> width >> height;
  Vec2u size(width, height);

  auto instances = Game::GetInstancesManager();

  auto map = new TileMap();
  map->Load(&f, size);
  instances->AddInstance(map, kLayerBot);

  map = new TileMap();
  map->Load(&f, size);
  instances->AddInstance(map, kLayerMid);

  map = new TileMap();
  map->Load(&f, size);
  instances->AddInstance(map, kLayerTop);

  Game::GetMapController()->Load(width, height);

  return true;
}
