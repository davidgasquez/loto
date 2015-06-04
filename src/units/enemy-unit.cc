
#include "units/enemy-unit.h"

#include "engine/game-manager.h"


void EnemyUnit::Load() {
  sprite_.set_texture(GameManager::GetResourcesManager()->Enemy());
  set_movement_speed(sf::Vector2f(-50.f, 0.f));
}

void EnemyUnit::Step(sf::Time elapsed) {
  Unit::Step(elapsed);

  auto map_controller = GameManager::GetMapController();
  Vec2u tile(map_controller->CalcRowCol(position()));
  map_controller->PlaceEnemy(tile, this);
}
