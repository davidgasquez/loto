
#include "units/unit.h"


Unit::Unit()
: life_(0), damage_(0), moveSpeed_(0.f) {
  // empty
}

Unit::~Unit() {
  // empty
}

void Unit::draw(sf::RenderTarget& target, sf::RenderStates  states) const {
  target.draw(sprite_);
}
