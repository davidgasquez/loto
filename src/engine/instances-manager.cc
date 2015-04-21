
#include "engine/instances-manager.h"


void InstancesManager::AddInstance(Instance *instance) {
  instances_.push_back(instance);
}

void InstancesManager::RemoveInstance(Instance *instance) {
  std::remove(instances_.begin(), instances_.end(), instance);
}

void InstancesManager::Draw(sf::RenderTarget *target) {
  for (Instance *instance : instances_) {
    target->draw(*instance);
  }
}

void InstancesManager::Step(sf::Time elapsed) {
  for (Instance *instance : instances_) {
    instance->Step(elapsed);
  }
}

void InstancesManager::KeyPressed(sf::Event::KeyEvent event) {
  for (Instance *instance : instances_) {
    instance->KeyPressed(event);
  }
}

void InstancesManager::KeyReleased(sf::Event::KeyEvent event) {
  for (Instance *instance : instances_) {
    instance->KeyReleased(event);
  }
}
