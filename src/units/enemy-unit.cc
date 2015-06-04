
#include "units/enemy-unit.h"

#include "engine/game-manager.h"


void EnemyUnit::Load() {
  sprite_.setTexture(*GameManager::GetResourcesManager()->Enemy());
  set_movement_speed(sf::Vector2f(-50.f, 0.f));
}

void EnemyUnit::Step(sf::Time elapsed) {
  Unit::Step(elapsed);
  // Vec2u tile(GameManager::GetMapController()->CalcRowCol(position()));
}
