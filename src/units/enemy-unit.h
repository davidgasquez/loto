
#ifndef UNITS_ENEMY_H_
#define UNITS_ENEMY_H_

#include <SFML/System.hpp>

#include <string>

#include "units/unit.h"


class EnemyUnit : public Unit {
 public:
  explicit EnemyUnit(std::string name)
    : name_(name) { }

  void Load();

  void Step(sf::Time elapsed);

 private:
  std::string name_;
};

#endif  // UNITS_ENEMY_H_
