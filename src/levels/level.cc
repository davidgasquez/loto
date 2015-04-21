
#include "levels/level.h"

void Level::Load() {
  wave_ = new Wave(level_);
  wave_->Load();
}
