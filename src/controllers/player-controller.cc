
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
  auto elapsed_time = clock_.getElapsedTime();

  while (true) {
    if (elapsed_time > sf::seconds(1)){
      gold_++;
      clock_.restart();
    }
  cout << "Gold:" << gold_ << endl;
  }
}
