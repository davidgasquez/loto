
#ifndef BASE_GAME_MANAGER_H_
#define BASE_GAME_MANAGER_H_

#include "engine/resources-manager.h"
#include "engine/instances-manager.h"
#include "engine/events-manager.h"


class GameManager {
 public:
  static ResourcesManager* GetResourcesManager();
  static InstancesManager* GetInstancesManager();
  static EventsManager* GetEventsManager();

  static sf::Vector2u GetTileSize() {
    return sf::Vector2u(64, 64);
  }

  static sf::Vector2u GetWindowSize() {
    return sf::Vector2u(1280, 704);
  }
};

#endif  // BASE_GAME_MANAGER_H_
