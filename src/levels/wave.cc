// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#include "levels/wave.h"

#include <fstream>
#include <sstream>
#include <string>

#include "engine/game.h"
#include "base/debug.h"


void Wave::Load() {
  // Create filename
  std::stringstream filename;
  filename << "assets/waves/level_" << level_ << ".wave";

  // Open file
  std::ifstream wave_info(filename.str().c_str());

  unsigned accum = 0;

  while (wave_info) {
    Enemy new_enemy;

    // Get spawn time
    unsigned seconds;
    wave_info >> seconds;
    accum = seconds + accum;
    new_enemy.spawn_time = sf::milliseconds(accum * 1000 + rand() % 2000);

    // Get enemy name
    std::string name;
    wave_info >> name;
    new_enemy.enemy = new EnemyUnit(name);
    new_enemy.enemy->Load();

    // Get start graph node
    unsigned row = 0;
    wave_info >> row;

    unsigned max_cols = Game::GetMapSize().x * 2 - 1;
    Vec2f pos(Game::GetMapController()->graph()->CalcPos(Vec2u(max_cols, row)));
    new_enemy.enemy->set_position(pos);

    // Add enemy to wave
    wave_.push_back(new_enemy);
  }

  // The last one was a blank line
  wave_.pop_back();
}


void Wave::Start() {
  clock_.restart();
}


void Wave::Step(sf::Time elapsed) {
  auto elapsed_time = clock_.getElapsedTime();

  auto instances = Game::GetInstancesManager();
  while (wave_[current_enemy_].spawn_time < elapsed_time) {
    instances->AddInstance(wave_[current_enemy_].enemy, kLayerMid);
    current_enemy_++;

    if (current_enemy_ >= wave_.size()) {
      instances->MarkToRemoveAndDelete(this);
      Game::GetMapController()->set_all_enemies(true);
      return;
    }
  }
}
