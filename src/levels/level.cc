
#include "levels/level.h"

#include "engine/game-manager.h"

void Level::Load() {
  wave_ = new Wave(level_);
  wave_->Load();

  auto instances = GameManager::GetInstancesManager();
  instances->AddInstance(wave_, kLayerHidden);
}
