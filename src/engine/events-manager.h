// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

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
