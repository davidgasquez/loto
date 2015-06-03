
#ifndef BASE_EVENTS_MANAGER_H_
#define BASE_EVENTS_MANAGER_H_

#include <SFML/Graphics.hpp>

#include "engine/game-manager.h"
#include "engine/game-event.h"


class EventsManager {
 public:
  void EventsLoop(sf::RenderWindow* window);
  void Trigger(GameEvent event);

 private:
};

#endif  // BASE_EVENTS_MANAGER_H_
