
#ifndef STRUCTURES_TOWER_H_
#define STRUCTURES_TOWER_H_

#include "structures/structure.h"


class Tower : public Structure {
 public:
  void Load();

  void set_position(sf::Vec2u pos);

  void draw(sf::RenderTarget& target,
            sf::RenderStates  states) const;
};

#endif  // STRUCTURES_TOWER_H_
