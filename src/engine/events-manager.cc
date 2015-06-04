
#include "engine/events-manager.h"

#include "engine/game.h"
#include "controllers/map-controller.h"
#include "controllers/player-controller.h"

void EventsManager::EventsLoop(sf::RenderWindow* window) {
  sf::Event event;

  auto instances = Game::GetInstancesManager();
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

      case sf::Event::MouseButtonPressed:
        instances->MousePressed(event.mouseButton);
        break;

      case sf::Event::MouseButtonReleased:
        instances->MouseReleased(event.mouseButton);
        break;

      case sf::Event::MouseMoved:
        instances->MouseMoved(event.mouseMove);
        break;

      default:
        break;
    }
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
    window->close();
  }
}


void EventsManager::Trigger(GameEvent event) {
  auto map_controller = Game::GetMapController();
  map_controller->EventTriggered(event);

  auto player_controller = Game::GetPlayerController();
  player_controller->EventTriggered(event);

  auto instances = Game::GetInstancesManager();
  instances->EventTriggered(event);
}
