
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
  sprite_.move(movement_speed_ * elapsed.asSeconds());
}
