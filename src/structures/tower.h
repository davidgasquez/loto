
#ifndef STRUCTURES_TOWER_H_
#define STRUCTURES_TOWER_H_

#include <SFML/Graphics.hpp>


class Tower : public sf::Drawable {
public:
  void Load();

  void SetTilePosition(sf::Vector2u pos);

private:
  sf::Sprite sprite_;

  virtual void draw(sf::RenderTarget& target, sf::RenderStates  states) const;
};

#endif  // STRUCTURES_TOWER_H_
