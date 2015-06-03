
#ifndef CONTROLLERS_PLAYER_CONTROLLER_H_
#define CONTROLLERS_PLAYER_CONTROLLER_H_

#include <SFML/System.hpp>

class PlayerController {
 public:
  PlayerController(){}

  void Load();

  void Step(sf::Time elapsed);

 private:
    int life_;
    int gold_;
};

#endif  // CONTROLLERS_PLAYER_CONTROLLER_H_
