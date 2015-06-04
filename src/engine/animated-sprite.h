
#ifndef ENGINE_ANIMATED_SPRITE_H_
#define ENGINE_ANIMATED_SPRITE_H_

#include <SFML/Graphics.hpp>

#include <vector>

#include "base/aliases.h"
#include "engine/animation.h"


class AnimatedSprite : public sf::Drawable {
 public:
  AnimatedSprite()
  : animation_(nullptr) { }

  void Load(sf::Texture* texture);

  void Step(sf::Time elapsed);

  void set_animation(Animation* animation);
  
  void set_texture(sf::Texture* texture) {
    sprite_.setTexture(*texture);
  }

  Vec2f position() {
    return sprite_.getPosition();
  }

  void set_position(Vec2f position) {
    sprite_.setPosition(position);
  }

 private:
  sf::Sprite sprite_;
  std::vector<sf::IntRect> frames_;
  Animation* animation_;

  virtual void draw(sf::RenderTarget& target,
                    sf::RenderStates  states) const;
};

#endif  // ENGINE_ANIMATED_SPRITE_H_
