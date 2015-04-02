
#include "units/enemy-unit.h"

#include "engine/game-manager.h"


void EnemyUnit::Load() {
  sprite_.setTexture(*GameManager::GetResourcesManager()->Enemy());
}
