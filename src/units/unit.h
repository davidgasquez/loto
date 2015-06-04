
#ifndef UNITS_UNIT_H_
#define UNITS_UNIT_H_

#include <SFML/Graphics.hpp>

#include "engine/instance.h"
#include "base/aliases.h"


class Unit : public Instance {
 public:
  Unit();
  virtual ~Unit();

  virtual void Step(sf::Time elapsed);

  void set_life(unsigned life) {
    life_ = life;
  }

  unsigned life() {
    return life_;
  }

  void set_position(Vec2f pos) {
    sprite_.setPosition(pos);
  }

  Vec2f position() {
    return sprite_.getPosition();
  }

  void set_movement_speed(Vec2f movement_speed) {
    movement_speed_ = movement_speed;
  }

  void set_attack_speed(unsigned attack_speed) {
    attack_speed_ = attack_speed;
  }

 protected:
  unsigned life_;
  unsigned damage_;
  unsigned attack_speed_;
  Vec2f movement_speed_;
};

#endif  // UNITS_UNIT_H_
