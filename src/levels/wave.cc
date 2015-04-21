
#include "levels/wave.h"

#include <sstream>


Wave::Load() {
  // Create filename
  std::stringstream filename;

  filename << "assets/waves/level_" << level_ << ".wave";

  // Open file
  std::ifstream wave_info(filename.str().c_str());

  // Read filenamee
  while (!wave_info) {
    Enemy new_enemy;

    // Get spawn time
    wave_info >> new_enemy.spawn_time;

    // Get enemy name
    std::string name;
    wave_info >> name;
    new_enemy.enemy = new Enemy(name);

    // Get position
    int position;
    wave_info >> position;
    // TODO: Remove magic number
    new_enemy.enemy.set_position(sf::Vector2f(1280.f, position));

    // Add enemy to wave
    wave_.push_back(enemy);
  }
}
