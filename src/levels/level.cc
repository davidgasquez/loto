// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#include "levels/level.h"

#include "engine/game.h"

void Level::Load() {
  wave_ = new Wave(level_);
  wave_->Load();

  auto instances = Game::GetInstancesManager();
  instances->AddInstance(wave_, kLayerHidden);
}
