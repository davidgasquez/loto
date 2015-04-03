
#ifndef STRUCTURES_TOWER_H_
#define STRUCTURES_TOWER_H_

#include "structures/structure.h"


class Tower : public Structure {
public:

  void Load();

  void set_tile_position(sf::Vector2u pos);

  void draw(sf::RenderTarget& target,
            sf::RenderStates  states);
};

#endif // STRUCTURES_TOWER_H_
