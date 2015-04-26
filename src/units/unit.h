
#ifndef UNITS_UNIT_H_
#define UNITS_UNIT_H_

#include <SFML/Graphics.hpp>

#include "engine/instance.h"


class Unit : public Instance {
 public:
  Unit();
  virtual ~Unit();

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

  void set_movement_speed(sf::Vector2f movement_speed) {
    movement_speed_ = movement_speed;
  }

  void set_attack_speed(unsigned attack_speed) {
    attack_speed_ = attack_speed;
  }

 protected:
  unsigned life_;
  unsigned damage_;
  unsigned attack_speed_;
  sf::Vector2f movement_speed_;
};

#endif  // UNITS_UNIT_H_
