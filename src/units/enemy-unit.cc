
#include "units/enemy-unit.h"

#include "engine/game.h"


void EnemyUnit::Load() {
  sprite_.set_texture(Game::GetResourcesManager()->Enemy());
  set_movement_speed(50.f);
  set_rotation(180);
}

void EnemyUnit::Attack() {
  life_--;
  if (life_ == 0) {
    Remove_(ENEMY_DIED);
    return;
  }
}

void EnemyUnit::Remove_(GameEventType type) {
  auto events = Game::GetEventsManager();
  events->Trigger(GameEvent(type));
  auto instances = Game::GetInstancesManager();
  instances->MarkToRemoveAndDelete(this);
  auto map_controller = Game::GetMapController();
  map_controller->RemoveEnemy(this);
}


void EnemyUnit::Step(sf::Time elapsed) {
  Unit::Step(elapsed);

  auto map_controller = Game::GetMapController();
  Vec2u tile(map_controller->CalcRowCol(position()));
  map_controller->PlaceEnemy(tile, this);

  if (map_controller->ReachedCastle(tile)) {
    Remove_(ENEMY_REACHED_CASTLE);
    return;
  }
}
