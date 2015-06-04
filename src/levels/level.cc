
#include "levels/level.h"

#include "engine/game.h"

void Level::Load() {
  wave_ = new Wave(level_);
  wave_->Load();

  auto instances = Game::GetInstancesManager();
  instances->AddInstance(wave_, kLayerHidden);
}
