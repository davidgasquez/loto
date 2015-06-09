// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#ifndef UNITS_ENEMY_H_
#define UNITS_ENEMY_H_

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include <string>
#include <vector>

#include "units/unit.h"


class EnemyUnit : public Unit {
 public:
  explicit EnemyUnit(std::string name)
    : name_(name) { }

  void Load();

  void Attack();

  void Step(sf::Time elapsed);
  void EventTriggered(GameEvent event);

 private:
  std::string name_;
  sf::Clock clock_;
  std::vector<Vec2u> path_;

  void Remove_();
};

#endif  // UNITS_ENEMY_H_
