
#include "units/unit.h"

#include <cmath>

#include "base/debug.h"


Unit::Unit()
  : life_(1), damage_(0), attack_speed_(0),
    movement_speed_(0) {
  // empty
}


Unit::~Unit() {
  // empty
}


void Unit::Step(sf::Time elapsed) {
  float angle = rotation();
  Vec2f v(cos(angle * (M_PI / 180)), sin(angle * (M_PI / 180)));
  sprite_.move(v * movement_speed_ * elapsed.asSeconds());
}
