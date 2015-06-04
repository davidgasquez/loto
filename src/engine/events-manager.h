
#ifndef ENGINE_EVENTS_MANAGER_H_
#define ENGINE_EVENTS_MANAGER_H_

#include <SFML/Graphics.hpp>

#include "engine/game-event.h"


class EventsManager {
 public:
  void EventsLoop(sf::RenderWindow* window);
  void Trigger(GameEvent event);

 private:
};

#endif  // ENGINE_EVENTS_MANAGER_H_
