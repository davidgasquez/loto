
#ifndef CONTROLLERS_MAP_CONTROLLER_H_
#define CONTROLLERS_MAP_CONTROLLER_H_

#include <SFML/System.hpp>

class MapController {
 public:
  MapController(){}

  void Load();

  void Step(sf::Time elapsed);

 private:
};

#endif  // CONTROLLERS_MAP_CONTROLLER_H_