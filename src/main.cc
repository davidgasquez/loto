
#include <iostream>

#include <SFML/Graphics.hpp>

#include "managers/game-manager.h"
#include "structures/tower.h"
#include "tilemaps/map.h"
#include "units/enemy-unit.h"


int main(int argc, char const *argv[]) {
  sf::RenderWindow window(sf::VideoMode(1280, 704),
                          "Lord of the Orb",
                          sf::Style::None);

  InstancesManager* instances = GameManager::GetInstancesManager();
  ResourcesManager* resources = GameManager::GetResourcesManager();

  if (!resources->Load()) {
    std::cerr << "Cannot load game resources!" << std::endl;
    return 1;
  }

  auto map = new Map();
  if (!map->Load("assets/tilemaps/map.txt")) {
    std::cerr << "Cannot load tilemap" << std::endl;
    return 1;
  }
  instances->AddInstance(map);

  auto tower = new Tower();
  tower->Load();
  tower->SetTilePosition(sf::Vector2u(7, 5));
  instances->AddInstance(tower);

  auto enemy = new EnemyUnit();
  enemy->Load();
  instances->AddInstance(enemy);

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
        break;
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
      window.close();
      break;
    }

    window.clear(sf::Color::Black);

    instances->Draw(&window);

    window.display();
  }

  return 0;
}
