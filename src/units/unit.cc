
#include "units/unit.h"

#include "base/debug.h"


Unit::Unit()
  : life_(0), damage_(0), attack_speed_(0),
  movement_speed_(sf::Vector2f(0.f, 0.f)) {
  // empty
}

Unit::~Unit() {
  // empty
}

void Unit::Step(sf::Time elapsed) {
  sf::Vector2f pos(sprite_.getPosition());

  pos += movement_speed_ * elapsed.asSeconds();
  sprite_.setPosition(pos);
}
