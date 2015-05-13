
#include "engine/instances-manager.h"

#include "base/debug.h"


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


void InstancesManager::MousePressed(sf::Event::MouseButtonEvent event) {
  for (Instance *instance : instances_) {
    instance->MousePressed(event);
  }
}


void InstancesManager::MouseReleased(sf::Event::MouseButtonEvent event) {
  for (Instance *instance : instances_) {
    instance->MouseReleased(event);
  }
}


void InstancesManager::MouseMoved(sf::Event::MouseMoveEvent event) {
  for (Instance *instance : instances_) {
    instance->MouseMoved(event);
  }
}
