
#ifndef BASE_GAME_MANAGER_H_
#define BASE_GAME_MANAGER_H_

#include "engine/resources-manager.h"
#include "engine/instances-manager.h"
#include "engine/events-manager.h"
#include "controllers/map-controller.h"
#include "controllers/player-controller.h"


class GameManager {
 public:
  static ResourcesManager* GetResourcesManager();
  static InstancesManager* GetInstancesManager();
  static EventsManager* GetEventsManager();
  static MapController* GetMapController();
  static PlayerController* GetPlayerController();

  static Vec2u GetTileSize() {
    return Vec2u(64, 64);
  }

  static Vec2u GetWindowSize() {
    return Vec2u(1280, 704);
  }
};

#endif  // BASE_GAME_MANAGER_H_
