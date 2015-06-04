
#include "units/enemy-unit.h"

#include "engine/game-manager.h"


void EnemyUnit::Load() {
  sprite_.set_texture(GameManager::GetResourcesManager()->Enemy());
  set_movement_speed(50.f);
  set_rotation(180);
}

void EnemyUnit::Step(sf::Time elapsed) {
  Unit::Step(elapsed);

  auto map_controller = GameManager::GetMapController();
  Vec2u tile(map_controller->CalcRowCol(position()));
  map_controller->PlaceEnemy(tile, this);

  if (map_controller->ReachedCastle(tile)) {
    auto events = GameManager::GetEventsManager();
    auto instances = GameManager::GetInstancesManager();

    events->Trigger(GameEvent(ENEMY_REACHED_CASTLE));

    instances->RemoveInstance(this);
    delete this;
    return;
  }
}
