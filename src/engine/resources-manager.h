
#ifndef BASE_RESOURCES_MANAGER_H_
#define BASE_RESOURCES_MANAGER_H_

#include <SFML/Graphics.hpp>


class ResourcesManager {
public:

  bool         Load();

  sf::Texture* Map() {
    return &map_;
  }

  sf::Texture* Tower() {
    return &tower_;
  }

  sf::Texture* Enemy() {
    return &enemy_;
  }

  sf::Texture* UITowerButton() {
    return &ui_tower_button_;
  }

private:

  sf::Texture map_;
  sf::Texture tower_;
  sf::Texture enemy_;
  sf::Texture ui_tower_button_;
};

#endif // BASE_RESOURCES_MANAGER_H_
