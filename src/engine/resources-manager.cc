
#include "engine/resources-manager.h"


bool ResourcesManager::Load() {
  if (!map_.loadFromFile("assets/atlases/map.png")) {
    return false;
  }

  if (!tower_.loadFromFile("assets/textures/tower.png")) {
    return false;
  }

  if (!enemy_.loadFromFile("assets/textures/enemy.png")) {
    return false;
  }

  if (!ui_tower_button_.loadFromFile("assets/textures/ui/tower-button.png")) {
    return false;
  }

  return true;
}
