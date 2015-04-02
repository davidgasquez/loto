
#ifndef UNITS_UNIT_H_
#define UNITS_UNIT_H_

#include <SFML/Graphics.hpp>

#include "engine/instance.h"


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

  void set_position(sf::Vector2f pos) {
    sprite_.setPosition(pos);
  }

  void set_moveSpeed(sf::Vector2f moveSpeed) {
    moveSpeed_ = moveSpeed;
  }

protected:
  unsigned life_;
  unsigned damage_;
  sf::Vector2f moveSpeed_;
};

#endif  // UNITS_UNIT_H_
