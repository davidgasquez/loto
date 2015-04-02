
#ifndef BASE_INSTANCES_MANAGER_H_
#define BASE_INSTANCES_MANAGER_H_

#include <vector>

#include <SFML/Graphics.hpp>

#include "engine/instance.h"


class InstancesManager {
public:

  void AddInstance(Instance *instance);
  void RemoveInstance(Instance *instance);

  void Draw(sf::RenderTarget *target);
  void Step(sf::Time elapsed);

private:

  std::vector < Instance * > instances_;
};

#endif // BASE_INSTANCES_MANAGER_H_
