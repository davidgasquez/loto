
#include "levels/wave.h"

#include <fstream>
#include <sstream>


void Wave::Load() {
  // Create filename
  std::stringstream filename;
  filename << "assets/waves/level_" << level_ << ".wave";

  // Open file
  std::ifstream wave_info(filename.str().c_str());

  // Read filenamee
  while (!wave_info) {
    Enemy new_enemy;

    // Get spawn time
    unsigned seconds;
    wave_info >> seconds;
    sf::Time spawn_time = sf::seconds(seconds);

    // Get enemy name
    std::string name;
    wave_info >> name;
    new_enemy.enemy = new EnemyUnit(name);

    // Get position
    sf::Vector2f pos(GameManager::GetWindowSize());
    wave_info >> pos.y;
    new_enemy.enemy->set_position(pos);

    // Add enemy to wave
    wave_.push_back(enemy);
  }
}

void Wave::Step(sf::Time elapsed){
  
}
