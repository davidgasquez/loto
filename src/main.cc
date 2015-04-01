
#include <SFML/Graphics.hpp>


int main(int argc, char const *argv[]) {
  sf::RenderWindow window(sf::VideoMode(1280, 720),
                          "Lord of the Orb",
                          sf::Style::None);

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

    window.display();
  }

  return 0;
}
