
#ifndef LEVELS_LEVEL_H_
#define LEVELS_LEVEL_H_

#include <SFML/Graphics.hpp>


struct Enemy
{
  float spawn_time; // sf::time??
  float start_position;
  std::string name;
};

class Level {
public:
  Level(int level);
  virtual ~Level();

private:
  std::vector<Enemy> wave_;
  int level_;
};

#endif // LEVELS_LEVEL_H_
