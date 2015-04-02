
#ifndef BASE_INSTANCES_H_
#define BASE_INSTANCES_H_

#include <SFML/Graphics.hpp>


class Instance : public sf::Drawable {
public:

  Instance();
  virtual ~Instance();

  virtual void Step(sf::Time elapsed) {}

protected:

  sf::Sprite sprite_;

  virtual void draw(sf::RenderTarget& target,
                    sf::RenderStates  states) const;
};

#endif // BASE_INSTANCES_H_
