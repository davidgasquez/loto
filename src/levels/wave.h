
#ifndef LEVELS_WAVE_H_
#define LEVELS_WAVE_H_

#include <vector>

#include <SFML/Graphics.hpp>

class Enemy
{
public:
  EnemyUnit enemy;
  sf::time spawn_time;
};

class Wave {
public:
  Wave(unsigned level)
    : level_(level) { }

  void Load();

private:

  std::vector <Enemy *> wave_;
  unsigned level_;
};

#endif // LEVELS_WAVE_H_
