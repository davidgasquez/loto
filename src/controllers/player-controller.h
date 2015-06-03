
#ifndef CONTROLLERS_PLAYER_CONTROLLER_H_
#define CONTROLLERS_PLAYER_CONTROLLER_H_

#include <SFML/System.hpp>
#include "base/debug.h"

class PlayerController {
 public:
  PlayerController(){}

  void Load();

  void Step(sf::Time elapsed);

 private:
    unsigned life_;
    unsigned gold_;
    sf::Clock clock_;
};

#endif  // CONTROLLERS_PLAYER_CONTROLLER_H_
