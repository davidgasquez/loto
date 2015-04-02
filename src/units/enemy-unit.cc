
#include "units/enemy-unit.h"

#include "managers/game-manager.h"


void EnemyUnit::Load() {
  sprite_.setTexture(*GameManager::GetResourcesManager()->Enemy());
}
