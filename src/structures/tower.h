
#ifndef STRUCTURES_TOWER_H_
#define STRUCTURES_TOWER_H_

#include <SFML/Graphics.hpp>

#include "engine/instance.h"


class Tower : public Instance {
public:
  void Load();

  void SetTilePosition(sf::Vector2u pos);

private:
  sf::Sprite sprite_;

  virtual void draw(sf::RenderTarget& target, sf::RenderStates  states) const;
};

#endif  // STRUCTURES_TOWER_H_
