// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#include "engine/game.h"


ResourcesManager *gResources = nullptr;
InstancesManager *gInstances = nullptr;
EventsManager *gEvents = nullptr;
CursorManager *gCursor = nullptr;

MapController *gMapController = nullptr;
PlayerController *gPlayerController = nullptr;

sf::RenderWindow* gWindow = nullptr;

bool gHardcore = false;


ResourcesManager *Game::GetResourcesManager() {
  if (gResources == NULL) {
    gResources = new ResourcesManager();
  }

  return gResources;
}


InstancesManager *Game::GetInstancesManager() {
  if (gInstances == NULL) {
    gInstances = new InstancesManager();
  }

  return gInstances;
}


EventsManager *Game::GetEventsManager() {
  if (gEvents == NULL) {
    gEvents = new EventsManager();
  }

  return gEvents;
}


CursorManager *Game::GetCursorManager() {
  if (gCursor == NULL) {
    gCursor = new CursorManager();
  }

  return gCursor;
}


MapController *Game::GetMapController() {
  if (gMapController == NULL) {
    gMapController = new MapController();
  }

  return gMapController;
}


PlayerController *Game::GetPlayerController() {
  if (gPlayerController == NULL) {
    gPlayerController = new PlayerController();
  }

  return gPlayerController;
}


sf::RenderWindow* Game::GetWindow() {
  return gWindow;
}


void Game::SetWindow(sf::RenderWindow* window) {
  gWindow = window;
}


void Game::set_hardcore(bool hardcore) {
  gHardcore = hardcore;
}


bool Game::hardcore() {
  return gHardcore;
}
