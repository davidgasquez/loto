
#include "managers/instances-manager.h"


void InstancesManager::AddInstance(sf::Drawable* instance) {
  instances_.push_back(instance);
}

void InstancesManager::RemoveInstance(sf::Drawable* instance) {
  std::remove(instances_.begin(), instances_.end(), instance);
}

void InstancesManager::Draw(sf::RenderTarget* target) {
  for (sf::Drawable* instance : instances_) {
    target->draw(*instance);
  }
}
