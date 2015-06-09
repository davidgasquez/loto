// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#ifndef STRUCTURES_TOWER_H_
#define STRUCTURES_TOWER_H_

#include "base/aliases.h"
#include "structures/structure.h"


class Tower : public Structure {
 public:
  void Load();

  void set_position(Vec2u pos);

  void draw(sf::RenderTarget& target,
            sf::RenderStates states) const;

  void Step(sf::Time elapsed);

 private:
  sf::Clock attack_clock_;
};

#endif  // STRUCTURES_TOWER_H_
