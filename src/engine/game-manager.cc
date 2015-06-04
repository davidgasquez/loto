
#include "engine/game-manager.h"


ResourcesManager *gResources = nullptr;
InstancesManager *gInstances = nullptr;
EventsManager *gEvents = nullptr;
MapController *gMap = nullptr;
PlayerController *gPlayer = nullptr;

sf::RenderWindow* gWindow = nullptr;


ResourcesManager *GameManager::GetResourcesManager() {
  if (gResources == NULL) {
    gResources = new ResourcesManager();
  }

  return gResources;
}


InstancesManager *GameManager::GetInstancesManager() {
  if (gInstances == NULL) {
    gInstances = new InstancesManager();
  }

  return gInstances;
}


EventsManager *GameManager::GetEventsManager() {
  if (gEvents == NULL) {
    gEvents = new EventsManager();
  }

  return gEvents;
}


MapController *GameManager::GetMapController() {
  if (gMap == NULL) {
    gMap = new MapController();
  }

  return gMap;
}


PlayerController *GameManager::GetPlayerController() {
  if (gPlayer == NULL) {
    gPlayer = new PlayerController();
  }

  return gPlayer;
}


sf::RenderWindow* GameManager::GetWindow() {
  return gWindow;
}


void GameManager::SetWindow(sf::RenderWindow* window) {
  gWindow = window;
}
