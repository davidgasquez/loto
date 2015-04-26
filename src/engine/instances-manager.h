
#ifndef BASE_INSTANCES_MANAGER_H_
#define BASE_INSTANCES_MANAGER_H_

#include <SFML/Graphics.hpp>

#include <vector>

#include "engine/instance.h"


class InstancesManager {
 public:
  void AddInstance(Instance *instance);
  void RemoveInstance(Instance *instance);

  void Draw(sf::RenderTarget *target);
  void Step(sf::Time elapsed);
  void KeyPressed(sf::Event::KeyEvent event);
  void KeyReleased(sf::Event::KeyEvent event);

 private:
  std::vector < Instance * > instances_;
};

#endif  // BASE_INSTANCES_MANAGER_H_
