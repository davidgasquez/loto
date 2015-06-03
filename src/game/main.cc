
#include <SFML/Graphics.hpp>

#include <iostream>

#include "engine/game-manager.h"
#include "structures/tower.h"
#include "tilemaps/map.h"
#include "units/enemy-unit.h"
#include "game/ingame-ui.h"
#include "levels/level.h"


int main(int argc, char const *argv[]) {
  sf::Vector2u window_size(GameManager::GetWindowSize());
  sf::RenderWindow window(sf::VideoMode(window_size.x, window_size.y),
                          "Lord of the Orb",
                          sf::Style::None);

  auto instances = GameManager::GetInstancesManager();

  auto resources = GameManager::GetResourcesManager();
  if (!resources->Load()) {
    std::cerr << "Cannot load game resources!" << std::endl;
    return 1;
  }

  auto map = new Map();

  if (!map->Load("assets/tilemaps/level_1.map")) {
    std::cerr << "Cannot load tilemap" << std::endl;
    return 1;
  }
  instances->AddInstance(map);

  auto tower = new Tower();
  tower->Load();
  tower->set_position(sf::Vector2u(7, 5));
  instances->AddInstance(tower);

  auto level = new Level(1);
  level->Load();

  auto ui = new InGameUI();
  ui->Load();
  instances->AddInstance(ui);

  GameManager::GetMapController()->Load();
  GameManager::GetPlayerController()->Load();

  sf::Clock clock;

  while (window.isOpen()) {
    GameManager::GetEventsManager()->EventsLoop(&window);

    sf::Time elapsed = clock.restart();
    instances->Step(elapsed);

    window.clear(sf::Color::Black);

    instances->Draw(&window);

    window.display();
  }

  return 0;
}
