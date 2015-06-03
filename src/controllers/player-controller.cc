
#include "controllers/player-controller.h"


void PlayerController::Load() {
  // Set initial life
  life_ = 100;

  // Set starting gold
  gold_ = 100;

  // Start timer
  clock_.restart();
}


void PlayerController::Step(sf::Time elapsed) {
}
