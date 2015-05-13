
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

  unsigned accum = 0;

  // Read filename
  while (wave_info) {
    Enemy new_enemy;

    // Get spawn time
    unsigned seconds;
    wave_info >> seconds;
    accum = seconds + accum;
    new_enemy.spawn_time = sf::seconds(accum);

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
  auto instances = GameManager::GetInstancesManager();

  auto elapsed_time = clock_.getElapsedTime();

  while (true) {
    if (elapsed_time < wave_[current_enemy_].spawn_time) {
      break;
    }

    instances->AddInstance(wave_[current_enemy_].enemy);
    current_enemy_++;

    if (current_enemy_ >= wave_.size()) {
      instances->RemoveInstance(this);
      delete this;
      return;
    }
  }

}
