
#ifndef BASE_INSTANCES_H_
#define BASE_INSTANCES_H_

#include <SFML/Graphics.hpp>

#include "engine/game-event.h"


class Instance : public sf::Drawable {
 public:
  Instance() { }
  virtual ~Instance() { }

  virtual void Step(sf::Time elapsed) { }

  virtual void KeyPressed(sf::Event::KeyEvent event) { }
  virtual void KeyReleased(sf::Event::KeyEvent event) { }

  virtual void MousePressed(sf::Event::MouseButtonEvent event) { }
  virtual void MouseReleased(sf::Event::MouseButtonEvent event) { }
  virtual void MouseMoved(sf::Event::MouseMoveEvent event) { }

  virtual void EventTriggered(GameEvent event) { }

 protected:
  sf::Sprite sprite_;

  virtual void draw(sf::RenderTarget& target,
                    sf::RenderStates  states) const;
};

#endif  // BASE_INSTANCES_H_
