
#include "levels/level.h"

#include <sstream>

Level::Level(const int level)
  : level_(level) // initialize wave_
{

  // Create filename
  std::stringstream filename;
  filename << "data/levels/" << level_ << ".lvl";

  // Open file
  ifstream wave_info(filename.str().c_str());

  // Read file
  while (!wave_info) {

    // Get enemy info
    Enemy enemy;
    wave_info >> enemy.spawn_time;
    wave_info >> enemy.start_position;
    wave_info >> enemy.name;

    // Add enemy to wave
    wave_.push_back(enemy);
  }
}
