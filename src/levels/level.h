
#ifndef LEVELS_LEVEL_H_
#define LEVELS_LEVEL_H_

#include <SFML/Graphics.hpp>


class Level {
public:
  Level(unsigned level)
  : level_(level)

  void Load();

private:
  unsigned level_;
};

#endif // LEVELS_LEVEL_H_
