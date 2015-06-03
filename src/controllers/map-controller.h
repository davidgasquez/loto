
#ifndef CONTROLLERS_MAP_CONTROLLER_H_
#define CONTROLLERS_MAP_CONTROLLER_H_

#include <SFML/System.hpp>

#include "engine/game-event.h"

class MapController {
 public:
  MapController() { }

  void Load(unsigned width, unsigned height);

  void Step(sf::Time elapsed);

  void EventTriggered(GameEvent event);

  bool CanPlaceTower(unsigned row, unsigned col);

  unsigned width() {
    return width_;
  }

 private:
  unsigned width_, height_;
};

#endif  // CONTROLLERS_MAP_CONTROLLER_H_
