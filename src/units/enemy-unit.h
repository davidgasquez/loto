
#ifndef UNITS_ENEMY_H_
#define UNITS_ENEMY_H_

#include "units/unit.h"


class EnemyUnit : public Unit {
public:
  EnemyUnit(std::string name)
    : name_(name) { }

  void Load();

private:
  std::string name_;
};

#endif // UNITS_ENEMY_H_
