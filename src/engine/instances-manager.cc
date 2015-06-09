// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#include "engine/instances-manager.h"

#include <vector>

#include "base/debug.h"


InstancesManager::InstancesManager() {
  layers_.resize(kLayers);
}


void InstancesManager::AddInstance(Instance *instance, Layer layer) {
  layers_[layer].push_back(instance);
}


void InstancesManager::MarkToRemoveAndDelete(Instance* instance) {
  if (std::find(markedDelete_.begin(), markedDelete_.end(), instance) == markedDelete_.end()) {
    markedDelete_.push_back(instance);
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


void InstancesManager::RemovePass() {
  for (Instance* instance : markedDelete_) {
    for (std::vector<Instance*>& layer : layers_) {
      layer.erase(std::remove(layer.begin(), layer.end(), instance),
                  layer.end());
    }

    delete instance;
  }

  markedDelete_.clear();
}
