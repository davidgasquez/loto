// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#ifndef LEVELS_LEVEL_H_
#define LEVELS_LEVEL_H_

#include <SFML/Graphics.hpp>

#include "levels/wave.h"


class Level {
 public:
  explicit Level(unsigned level)
    : level_(level) { }

  void Load();

 private:
  unsigned level_;
  Wave *wave_;
};

#endif  // LEVELS_LEVEL_H_
