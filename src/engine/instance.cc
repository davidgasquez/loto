
#include "engine/instance.h"


void Instance::draw(sf::RenderTarget& target, sf::RenderStates  states) const {
  target.draw(sprite_);
}
