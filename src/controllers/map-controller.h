
#ifndef CONTROLLERS_MAP_CONTROLLER_H_
#define CONTROLLERS_MAP_CONTROLLER_H_

#include <SFML/System.hpp>

class MapController {
 public:
  MapController() { }

  void Load(unsigned width, unsigned height);

  void Step(sf::Time elapsed);

 private:
  unsigned width_, height_;
};

#endif  // CONTROLLERS_MAP_CONTROLLER_H_
