
#ifndef BASE_INSTANCES_MANAGER_H_
#define BASE_INSTANCES_MANAGER_H_

#include <vector>

#include <SFML/Graphics.hpp>


class InstancesManager {
public:
  void AddInstance(sf::Drawable* instance);
  void RemoveInstance(sf::Drawable* instance);

  void Draw(sf::RenderTarget* target);

private:
  std::vector<sf::Drawable*> instances_;
};

#endif  // BASE_INSTANCES_MANAGER_H_
