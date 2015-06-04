
#include <SFML/Graphics.hpp>

#include <iostream>

#include "engine/game.h"
#include "levels/level.h"
#include "tilemaps/map.h"
#include "ui/cursor.h"
#include "ui/ingame.h"
#include "units/enemy-unit.h"


int main(int argc, char const *argv[]) {
  Vec2u window_size(Game::GetWindowSize());
  sf::RenderWindow window(sf::VideoMode(window_size.x, window_size.y),
                          "Lord of the Orb",
                          sf::Style::None);
  Game::SetWindow(&window);

  auto instances = Game::GetInstancesManager();

  auto resources = Game::GetResourcesManager();
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

  Game::GetCursorManager()->Load();

  auto map_controller = Game::GetMapController();
  auto player_controller = Game::GetPlayerController();
  player_controller->Load();

  sf::Clock clock;

  while (window.isOpen()) {
    Game::GetEventsManager()->EventsLoop(&window);

    sf::Time elapsed = clock.restart();

    map_controller->Step(elapsed);
    player_controller->Step(elapsed);
    instances->Step(elapsed);

    window.clear(sf::Color::Black);

    instances->Draw(&window);

    window.display();

    instances->RemovePass();
  }

  return 0;
}
