
#include "managers/resources-manager.h"


bool ResourcesManager::Load() {
  if (!map_.loadFromFile("assets/atlases/map.png")) {
    return false;
  }
  if (!tower_.loadFromFile("assets/textures/tower.png")) {
    return false;
  }

  return true;
}
