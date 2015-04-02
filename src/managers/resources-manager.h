
#ifndef BASE_RESOURCES_MANAGER_H_
#define BASE_RESOURCES_MANAGER_H_

#include <SFML/Graphics.hpp>


class ResourcesManager {
public:
  bool Load();

  sf::Texture* Map() {
    return &map_;
  }

  sf::Texture* Tower() {
    return &tower_;
  }

private:
  sf::Texture map_;
  sf::Texture tower_;
};

#endif  // BASE_RESOURCES_MANAGER_H_
