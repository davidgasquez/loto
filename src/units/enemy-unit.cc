
#include "units/enemy-unit.h"

#include "engine/game-manager.h"


void EnemyUnit::Load() {
  sprite_.set_texture(GameManager::GetResourcesManager()->Enemy());
  set_movement_speed(50.f);
  set_rotation(180);
}

void EnemyUnit::Attack() {
  life_--;
  cout << "life_" << life_ << endl;
  if (life_ == 0) {
    cout << "Atacando" << endl;
    Remove_(ENEMY_DIED);
    return;
  }
}

void EnemyUnit::Remove_(GameEventType type) {
  auto events = GameManager::GetEventsManager();
  events->Trigger(GameEvent(type));
  auto instances = GameManager::GetInstancesManager();
  instances->RemoveInstance(this);
  auto map_controller = GameManager::GetMapController();
  map_controller->RemoveEnemy(this);
  delete this;
}

void EnemyUnit::Step(sf::Time elapsed) {
  Unit::Step(elapsed);

  auto map_controller = GameManager::GetMapController();
  Vec2u tile(map_controller->CalcRowCol(position()));
  map_controller->PlaceEnemy(tile, this);

  if (map_controller->ReachedCastle(tile)) {
    Remove_(ENEMY_REACHED_CASTLE);
    return;
  }
}
