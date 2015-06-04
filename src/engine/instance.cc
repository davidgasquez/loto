
#include "engine/instance.h"


void Instance::draw(sf::RenderTarget& target, sf::RenderStates  states) const {
  if (visible_) {
    target.draw(sprite_);
  }
}
