
#include "levels/wave.h"

#include <fstream>
#include <sstream>
#include <string>

#include "engine/game-manager.h"


void Wave::Load() {
  // Create filename
  std::stringstream filename;
  filename << "assets/waves/level_" << level_ << ".wave";

  // Open file
  std::ifstream wave_info(filename.str().c_str());

  // Read filenamee
  while (wave_info) {
    Enemy new_enemy;

    // Get spawn time
    unsigned seconds;
    wave_info >> seconds;
    new_enemy.spawn_time = sf::seconds(seconds);

    // Get enemy name
    std::string name;
    wave_info >> name;
    new_enemy.enemy = new EnemyUnit(name);

    // Get position
    sf::Vector2f pos(GameManager::GetWindowSize());
    wave_info >> pos.y;
    new_enemy.enemy->set_position(pos);

    // Add enemy to wave
    wave_.push_back(new_enemy);
  }
}

void Wave::Start() {
  clock_.restart();
}

void Wave::Step(sf::Time elapsed) {
  // Handle wave
}
