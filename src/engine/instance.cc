
#include "engine/instance.h"


Instance::Instance() {
  // empty
}

Instance::~Instance() {
  // empty
}

void Instance::draw(sf::RenderTarget& target, sf::RenderStates  states) const {
  target.draw(sprite_);
}
