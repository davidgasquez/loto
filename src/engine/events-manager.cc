
#include "engine/events-manager.h"

#include "engine/game-manager.h"


void EventsManager::EventsLoop(sf::RenderWindow* window) {
  sf::Event event;

  auto instances = GameManager::GetInstancesManager();
  while (window->pollEvent(event)) {
    switch (event.type) {
      case sf::Event::Closed:
        window->close();
        break;

      case sf::Event::KeyPressed:
        instances->KeyPressed(event.key);
        break;

      case sf::Event::KeyReleased:
        instances->KeyReleased(event.key);
        break;

      default:
        break;
    }
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
    window->close();
  }
}
