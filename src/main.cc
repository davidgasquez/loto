
#include <iostream>

#include <SFML/Graphics.hpp>

#include "tilemaps/map.h"


int main(int argc, char const *argv[]) {
  sf::RenderWindow window(sf::VideoMode(1280, 720),
                          "Lord of the Orb",
                          sf::Style::None);

  Map map("assets/atlases/map.png", "assets/tilemaps/map.txt", sf::Vector2u(64, 64));
  if (!map.Load()) {
    std::cerr << "Cannot load tilemap" << std::endl;
    return 1;
  }

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

    window.display();
  }

  return 0;
}
