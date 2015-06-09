// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#include "engine/instance.h"


void Instance::draw(sf::RenderTarget& target, sf::RenderStates  states) const {
  if (visible_) {
    target.draw(sprite_);
  }
}
