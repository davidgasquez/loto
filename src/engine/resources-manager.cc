// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#include "engine/resources-manager.h"


bool ResourcesManager::Load() {
  if (!map_.loadFromFile("assets/atlases/map.png")) {
    return false;
  }

  if (!tower_.loadFromFile("assets/textures/tower.png")) {
    return false;
  }

  if (!tower_bad_.loadFromFile("assets/textures/ui/tower-bad.png")) {
    return false;
  }

  if (!tower_selected_.loadFromFile("assets/textures/ui/tower-selected.png")) {
    return false;
  }

  if (!enemy_.loadFromFile("assets/textures/enemy.png")) {
    return false;
  }

  if (!ui_tower_button_.loadFromFile("assets/textures/ui/tower-button.png")) {
    return false;
  }

  if (!ui_cursor_.loadFromFile("assets/textures/ui/cursor.png")) {
    return false;
  }

  if (!font_.loadFromFile("assets/textures/ui/font.ttf")) {
    return false;
  }

  if (!heart_.loadFromFile("assets/textures/ui/heart.png")) {
    return false;
  }

  if (!coin_.loadFromFile("assets/textures/ui/coin.png")) {
    return false;
  }

  if (!loop_.loadFromFile("assets/sounds/loop.wav")) {
    return false;
  }

  if (!arrow_.loadFromFile("assets/textures/arrow.png")) {
    return false;
  }

  if (!game_over_.loadFromFile("assets/sounds/game-over.ogg")) {
    return false;
  }

  return true;
}
