// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#include "units/enemy-unit.h"

#include <cmath>

#include "engine/game.h"
#include "ai/dijkstra.h"


void EnemyUnit::Load() {
  sprite_.set_texture(Game::GetResourcesManager()->Enemy());
  set_movement_speed(50.f);
  set_rotation(180);
  life_ = 3;
  clock_.restart();
}


void EnemyUnit::Attack() {
  life_--;
  if (life_ == 0) {
    auto events = Game::GetEventsManager();
    events->Trigger(GameEvent(ENEMY_DIED));
    Remove_();
    return;
  }
}


void EnemyUnit::Remove_() {
  auto instances = Game::GetInstancesManager();
  instances->MarkToRemoveAndDelete(this);
  auto map_controller = Game::GetMapController();
  map_controller->RemoveEnemy(this);
}


void EnemyUnit::Step(sf::Time elapsed) {
  if (life_ == 0) {
    return;
  }

  auto map_controller = Game::GetMapController();
  auto graph = map_controller->graph();
  if (path_.size() == 0 || clock_.getElapsedTime().asMilliseconds() > 500) {
    clock_.restart();
    path_ = DijkstraPathFinding(graph->CalcNode(position()));

    Vec2f dest(graph->CalcPos(path_[0]));
    auto rad = atan2(dest.y - position().y, dest.x - position().x);
    set_rotation(rad * (180 / M_PI));
  }

  Unit::Step(elapsed);

  Vec2u tile(map_controller->CalcRowCol(position()));
  map_controller->PlaceEnemy(tile, this);

  if (map_controller->ReachedCastle(tile)) {
    auto events = Game::GetEventsManager();
    events->Trigger(GameEvent(ENEMY_REACHED_CASTLE));
    Remove_();
    return;
  }
}


void EnemyUnit::EventTriggered(GameEvent event) {
  if (event.type() == GAME_OVER) {
    Remove_();
  }
}
