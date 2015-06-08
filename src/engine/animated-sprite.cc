
#include "engine/animated-sprite.h"


void AnimatedSprite::Load(sf::Texture* texture) {
  sprite_.setTexture(*texture);
}


void AnimatedSprite::Step(sf::Time elapsed) {
}


void AnimatedSprite::draw(sf::RenderTarget& target, sf::RenderStates  states) const {
  target.draw(sprite_);
}


void AnimatedSprite::set_animation(Animation* animation) {
  animation_ = animation;
  animation_->Restart();
}
