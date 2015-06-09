// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#ifndef UI_TOWER_ARROW_H_
#define UI_TOWER_ARROW_H_

#include <SFML/Graphics.hpp>

#include "engine/instance.h"
#include "base/aliases.h"
#include "units/enemy-unit.h"


class TowerArrow : public Instance {
 public:
  virtual ~TowerArrow() { }

  void Load(Vec2f initial_position);

  void Step(sf::Time elapsed);

  void set_enemy(EnemyUnit* enemy) {
    enemy_ = enemy;
  }

 protected:
  EnemyUnit* enemy_;
  sf::Clock clock_;
  Vec2f initial_position_;
};

#endif  // UI_TOWER_ARROW_H_
