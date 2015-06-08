
#ifndef BASE_GAME_MANAGER_H_
#define BASE_GAME_MANAGER_H_

#include "engine/resources-manager.h"
#include "engine/instances-manager.h"
#include "engine/events-manager.h"
#include "engine/cursor-manager.h"
#include "controllers/map-controller.h"
#include "controllers/player-controller.h"
#include "base/aliases.h"


class Game {
 public:
  static ResourcesManager* GetResourcesManager();
  static InstancesManager* GetInstancesManager();
  static EventsManager* GetEventsManager();
  static CursorManager* GetCursorManager();

  static MapController* GetMapController();
  static PlayerController* GetPlayerController();

  static Vec2u GetTileSize() {
    return Vec2u(64, 64);
  }

  static Vec2u GetWindowSize() {
    return Vec2u(1280, 704);
  }

  static Vec2u GetMapSize() {
    Vec2u window(GetWindowSize());
    Vec2u tile(GetTileSize());
    return Vec2u(window.x / tile.x, window.y / tile.y);
  }

  static sf::RenderWindow* GetWindow();
  static void SetWindow(sf::RenderWindow* window);
};

#endif  // BASE_GAME_MANAGER_H_
