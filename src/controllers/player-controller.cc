
#include "controllers/player-controller.h"


void PlayerController::Load() {
  // Set initial life
  life_ = 100;

  // Set starting gold
  gold_ = 100;

  // Start timer
  clock_.restart();
}

void EventTriggered(GameEvent event) {
}


void PlayerController::Step(sf::Time elapsed) {
  auto elapsed_time = clock_.getElapsedTime();

  // Passively increase gold
  if (elapsed_time > sf::seconds(2)) {
    gold_++;
    clock_.restart();
  }

  // Increase gold when killing an enemy

  // Decrease gold when buying structures and units

  // Decrease life each attack received
}
