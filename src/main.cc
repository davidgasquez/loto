
#include <iostream>

#include <SFML/Graphics.hpp>

#include "managers/game-manager.h"
#include "structures/tower.h"
#include "tilemaps/map.h"


int main(int argc, char const *argv[]) {
  sf::RenderWindow window(sf::VideoMode(1280, 704),
                          "Lord of the Orb",
                          sf::Style::None);

  ResourcesManager* resources = GameManager::GetResourcesManager();
  if (!resources->Load()) {
    std::cerr << "Cannot load game resources!" << std::endl;
    return 1;
  }

  Map map;
  if (!map.Load("assets/tilemaps/map.txt", sf::Vector2u(64, 64))) {
    std::cerr << "Cannot load tilemap" << std::endl;
    return 1;
  }

  Tower tower;
  tower.Load();

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

    window.draw(map);
    window.draw(tower);

    window.display();
  }

  return 0;
}
