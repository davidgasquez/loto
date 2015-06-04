
#ifndef CONTROLLERS_PLAYER_CONTROLLER_H_
#define CONTROLLERS_PLAYER_CONTROLLER_H_

#include <SFML/System.hpp>

#include "base/debug.h"

#include "engine/game-event.h"

const unsigned kTowerCost = 30;

class PlayerController {
 public:
  PlayerController() {}

  void Load();

  void EventTriggered(GameEvent event);

  unsigned life() {
    return life_;
  }

  unsigned gold() {
    return gold_;
  }

  void Step(sf::Time elapsed);

 private:
  unsigned life_;
  unsigned gold_;
  sf::Clock clock_;
};

#endif  // CONTROLLERS_PLAYER_CONTROLLER_H_
