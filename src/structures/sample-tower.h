
#ifndef STRUCTURES_SAMPLE_TOWER_H_
#define STRUCTURES_SAMPLE_TOWER_H_

#include "structures/tower.h"


class SampleTower : public Tower {
public:

  void Load();

  void set_tile_position(sf::Vector2u pos);

  void draw(sf::RenderTarget& target, sf::RenderStates  states);
};

#endif // STRUCTURES_SAMPLE_TOWER_H_
