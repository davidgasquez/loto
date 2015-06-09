// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#include "engine/animated-sprite.h"


void AnimatedSprite::set_texture(sf::Texture* texture) {
  texture_ = texture;

  sprite_.setTexture(*texture, true);

  Vec2u size(texture->getSize());
  sprite_.setOrigin(Vec2f(size.x / 2.f, size.y / 2.f));
}


void AnimatedSprite::Step(sf::Time elapsed) {
}


void AnimatedSprite::draw(sf::RenderTarget& target,
                          sf::RenderStates  states) const {
  target.draw(sprite_);
}


void AnimatedSprite::set_animation(Animation* animation) {
  animation_ = animation;
  animation_->Restart();
}
