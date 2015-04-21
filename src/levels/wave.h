
#ifndef LEVELS_WAVE_H_
#define LEVELS_WAVE_H_

#include <vector>

#include <SFML/Graphics.hpp>

#include "engine/instance.h"

class Enemy {
public:
  EnemyUnit *enemy;
  sf::Time spawn_time;
};

class Wave : public Instance {
public:
  Wave(unsigned level)
    : level_(level) { }

  void Load();

  void Step(sf::Time elapsed);
  void Start();

private:
  std::vector <Enemy> wave_;
  unsigned level_;
  sf::Clock clock_;
};

#endif // LEVELS_WAVE_H_