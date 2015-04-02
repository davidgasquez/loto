
#ifndef STRUCTURES_TOWER_H_
#define STRUCTURES_TOWER_H_

#include <SFML/Graphics.hpp>

#include "engine/instance.h"


class Tower : public Instance {
public:

  Tower();
  virtual ~Tower();

  virtual void Step(sf::Time elapsed);

  void         set_life(unsigned life) {
    life_ = life;
  }

  unsigned life() {
    return life_;
  }

  void set_position(sf::Vector2f pos) {
    sprite_.setPosition(pos);
  }

  void set_attack_speed(unsigned attack_speed) {
    attack_speed_ = attack_speed;
  }

protected:

  unsigned life_;
  unsigned damage_;
  unsigned attack_speed_;
};

#endif // STRUCTURES_TOWER_H_
