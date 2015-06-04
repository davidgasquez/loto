
#include "engine/instances-manager.h"

#include <vector>

#include "base/debug.h"


InstancesManager::InstancesManager() {
  layers_.resize(kLayers);
}


void InstancesManager::AddInstance(Instance *instance, Layer layer) {
  layers_[layer].push_back(instance);
}


void InstancesManager::RemoveInstance(Instance *instance) {
  for (std::vector<Instance*>& layer : layers_) {
    layer.erase(std::remove(layer.begin(), layer.end(), instance),
                layer.end());
  }
}


void InstancesManager::Draw(sf::RenderTarget *target) {
  for (auto layer : layers_) {
    for (auto instance : layer) {
      target->draw(*instance);
    }
  }
}


void InstancesManager::Step(sf::Time elapsed) {
  for (auto layer : layers_) {
    for (auto instance : layer) {
      instance->Step(elapsed);
    }
  }
}


void InstancesManager::KeyPressed(sf::Event::KeyEvent event) {
  for (auto layer : layers_) {
    for (auto instance : layer) {
      instance->KeyPressed(event);
    }
  }
}


void InstancesManager::KeyReleased(sf::Event::KeyEvent event) {
  for (auto layer : layers_) {
    for (auto instance : layer) {
      instance->KeyReleased(event);
    }
  }
}


void InstancesManager::MousePressed(sf::Event::MouseButtonEvent event) {
  for (auto layer : layers_) {
    for (auto instance : layer) {
      instance->MousePressed(event);
    }
  }
}


void InstancesManager::MouseReleased(sf::Event::MouseButtonEvent event) {
  for (auto layer : layers_) {
    for (auto instance : layer) {
      instance->MouseReleased(event);
    }
  }
}


void InstancesManager::MouseMoved(sf::Event::MouseMoveEvent event) {
  for (auto layer : layers_) {
    for (auto instance : layer) {
      instance->MouseMoved(event);
    }
  }
}


void InstancesManager::EventTriggered(GameEvent event) {
  for (auto layer : layers_) {
    for (auto instance : layer) {
      instance->EventTriggered(event);
    }
  }
}
