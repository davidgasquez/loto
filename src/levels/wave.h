// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#ifndef LEVELS_WAVE_H_
#define LEVELS_WAVE_H_

#include <SFML/Graphics.hpp>

#include <vector>

#include "engine/instance.h"
#include "units/enemy-unit.h"


class Enemy {
 public:
  EnemyUnit *enemy;
  sf::Time spawn_time;
};


class Wave : public Instance {
 public:
  explicit Wave(unsigned level)
    : level_(level), current_enemy_(0) { }

  void Load();

  void Step(sf::Time elapsed);
  void Start();

 private:
  std::vector <Enemy> wave_;
  unsigned level_;
  sf::Clock clock_;

  unsigned current_enemy_;
};

#endif  // LEVELS_WAVE_H_
