// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#include "controllers/player-controller.h"

#include "engine/game.h"
#include "ui/game-over.h"


void PlayerController::Load() {
  // Set initial life
  life_ = 100;

  // Set starting gold
  gold_ = 100;

  // Start timer
  clock_.restart();
}


void PlayerController::EventTriggered(GameEvent event) {
  switch (event.type()) {
  // Increase gold when killing an enemy
  case ENEMY_DIED:
    gold_ += 10;
    break;

  // Decrease gold when buying structures and units
  case TOWER_PLACED:
    gold_ -= kTowerCost;
    break;

  // Decrease life each time monster reach castle
  case ENEMY_REACHED_CASTLE:
    if (life_ == 0) {
      auto events = Game::GetEventsManager();
      events->Trigger(GameEvent(GAME_OVER));

      auto instances = Game::GetInstancesManager();
      instances->AddInstance(new GameOver(), kLayerUI);
    } else {
      life_ -= 5;
    }
    break;

  default:
    ;
  }
}


void PlayerController::Step(sf::Time elapsed) {
  auto elapsed_time = clock_.getElapsedTime();

  // Passively increase gold
  if (elapsed_time > sf::seconds(2)) {
    gold_++;
    clock_.restart();
  }
}
