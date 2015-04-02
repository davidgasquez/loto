
#include "engine/game-manager.h"


ResourcesManager *resources_ = NULL;
InstancesManager *instances_ = NULL;


ResourcesManager * GameManager::GetResourcesManager() {
  if (resources_ == NULL) {
    resources_ = new ResourcesManager();
  }

  return resources_;
}

InstancesManager * GameManager::GetInstancesManager() {
  if (instances_ == NULL) {
    instances_ = new InstancesManager();
  }

  return instances_;
}
