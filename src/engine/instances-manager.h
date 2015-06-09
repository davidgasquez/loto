// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#ifndef BASE_INSTANCES_MANAGER_H_
#define BASE_INSTANCES_MANAGER_H_

#include <SFML/Graphics.hpp>

#include <vector>

#include "engine/instance.h"

enum Layer {
  kLayerHidden,
  kLayerBot,
  kLayerMid,
  kLayerMidElevated,
  kLayerTop,
  kLayerUI,
  kLayerCursor,
  kLayers
};

class InstancesManager {
 public:
  InstancesManager();

  void AddInstance(Instance *instance, Layer layer);
  void MarkToRemoveAndDelete(Instance *instance);

  void Draw(sf::RenderTarget *target);
  void Step(sf::Time elapsed);

  void KeyPressed(sf::Event::KeyEvent event);
  void KeyReleased(sf::Event::KeyEvent event);

  void MousePressed(sf::Event::MouseButtonEvent event);
  void MouseReleased(sf::Event::MouseButtonEvent event);
  void MouseMoved(sf::Event::MouseMoveEvent event);

  void EventTriggered(GameEvent event);

  void RemovePass();

 private:
  std::vector<std::vector<Instance*> > layers_;
  std::vector<Instance*> markedDelete_;
};

#endif  // BASE_INSTANCES_MANAGER_H_
