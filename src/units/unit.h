
#ifndef UNITS_UNIT_H_
#define UNITS_UNIT_H_

#include <SFML/Graphics.hpp>

#include "engine/instance.h"


class Unit : public Instance {
public:
  Unit();
  virtual ~Unit();

  void set_life(unsigned life) {
    life_ = life;
  }

  unsigned life() {
    return life_;
  }

protected:
  unsigned life_;
  unsigned damage_;
  float moveSpeed_;
};

#endif  // UNITS_UNIT_H_
