
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
