
#include <SFML/Graphics.hpp>

#include <iostream>

#include "engine/game-manager.h"
#include "levels/level.h"
#include "tilemaps/map.h"
#include "ui/cursor.h"
#include "ui/ingame.h"
#include "units/enemy-unit.h"


int main(int argc, char const *argv[]) {
  Vec2u window_size(GameManager::GetWindowSize());
  sf::RenderWindow window(sf::VideoMode(window_size.x, window_size.y),
                          "Lord of the Orb",
                          sf::Style::None);
  GameManager::SetWindow(&window);

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

  auto level = new Level(1);
  level->Load();

  auto inGame = new InGame();
  inGame->Load();
  instances->AddInstance(inGame, kLayerUI);

  GameManager::GetCursorManager()->Load();

  auto map_controller = GameManager::GetMapController();
  auto player_controller = GameManager::GetPlayerController();
  player_controller->Load();

  sf::Clock clock;

  while (window.isOpen()) {
    GameManager::GetEventsManager()->EventsLoop(&window);

    sf::Time elapsed = clock.restart();

    map_controller->Step(elapsed);
    player_controller->Step(elapsed);
    instances->Step(elapsed);

    window.clear(sf::Color::Black);

    instances->Draw(&window);

    window.display();
  }

  return 0;
}
