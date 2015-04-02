
#include "managers/game-manager.h"


ResourcesManager* resources_ = NULL;


ResourcesManager* GameManager::GetResourcesManager() {
  if (resources_ == NULL) {
    resources_ = new ResourcesManager();
  }

  return resources_;
}
