
#include "engine/game-manager.h"


ResourcesManager *gResources = nullptr;
InstancesManager *gInstances = nullptr;
EventsManager *gEvents = nullptr;
CursorManager *gCursor = nullptr;

MapController *gMapController = nullptr;
PlayerController *gPlayerController = nullptr;

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


CursorManager *GameManager::GetCursorManager() {
  if (gCursor == NULL) {
    gCursor = new CursorManager();
  }

  return gCursor;
}


MapController *GameManager::GetMapController() {
  if (gMapController == NULL) {
    gMapController = new MapController();
  }

  return gMapController;
}


PlayerController *GameManager::GetPlayerController() {
  if (gPlayerController == NULL) {
    gPlayerController = new PlayerController();
  }

  return gPlayerController;
}


sf::RenderWindow* GameManager::GetWindow() {
  return gWindow;
}


void GameManager::SetWindow(sf::RenderWindow* window) {
  gWindow = window;
}
