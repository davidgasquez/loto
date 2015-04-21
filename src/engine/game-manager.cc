
#include "engine/game-manager.h"


ResourcesManager *resources_ = NULL;
InstancesManager *instances_ = NULL;
EventsManager *events_ = NULL;


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

EventsManager * GameManager::GetEventsManager() {
  if (events_ == NULL) {
    events_ = new EventsManager();
  }

  return events_;
}
