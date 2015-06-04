
#ifndef BASE_INSTANCES_H_
#define BASE_INSTANCES_H_

#include <SFML/Graphics.hpp>

#include "engine/game-event.h"
#include "engine/animated-sprite.h"


class Instance : public sf::Drawable {
 public:
  Instance()
  : visible_(true) { }
  virtual ~Instance() { }

  virtual void Step(sf::Time elapsed) { }

  virtual void KeyPressed(sf::Event::KeyEvent event) { }
  virtual void KeyReleased(sf::Event::KeyEvent event) { }

  virtual void MousePressed(sf::Event::MouseButtonEvent event) { }
  virtual void MouseReleased(sf::Event::MouseButtonEvent event) { }
  virtual void MouseMoved(sf::Event::MouseMoveEvent event) { }

  virtual void EventTriggered(GameEvent event) { }

  void set_visible(bool visible) {
    visible_ = visible;
  }

  bool visible() {
    return visible_;
  }

 protected:
  AnimatedSprite sprite_;
  bool visible_;

  virtual void draw(sf::RenderTarget& target,
                    sf::RenderStates  states) const;
};

#endif  // BASE_INSTANCES_H_
