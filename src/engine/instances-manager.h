
#ifndef BASE_INSTANCES_MANAGER_H_
#define BASE_INSTANCES_MANAGER_H_

#include <SFML/Graphics.hpp>

#include <vector>

#include "engine/instance.h"

enum Layer {
  kLayerHidden,
  kLayerBot,
  kLayerMid,
  kLayerTop,
  kLayerUI,
  kLayerCursor,
  kLayers
};

class InstancesManager {
 public:
  InstancesManager();

  void AddInstance(Instance *instance, Layer layer);
  void RemoveInstance(Instance *instance);

  void Draw(sf::RenderTarget *target);
  void Step(sf::Time elapsed);

  void KeyPressed(sf::Event::KeyEvent event);
  void KeyReleased(sf::Event::KeyEvent event);

  void MousePressed(sf::Event::MouseButtonEvent event);
  void MouseReleased(sf::Event::MouseButtonEvent event);
  void MouseMoved(sf::Event::MouseMoveEvent event);

  void EventTriggered(GameEvent event);

 private:
  std::vector <std::vector<Instance* > > layers_;
};

#endif  // BASE_INSTANCES_MANAGER_H_
