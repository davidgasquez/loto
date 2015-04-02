
#ifndef UNITS_UNIT_H_
#define UNITS_UNIT_H_

#include <SFML/Graphics.hpp>


class Unit : public sf::Drawable {
public:
  Unit();
  virtual ~Unit();

  void set_life(unsigned life) {
    life_ = life;
  }

  unsigned life() {
    return life_;
  }

protected:
  sf::Sprite sprite_;

  unsigned life_;
  unsigned damage_;
  float moveSpeed_;

  virtual void draw(sf::RenderTarget& target, sf::RenderStates  states) const;
};

#endif  // UNITS_UNIT_H_
