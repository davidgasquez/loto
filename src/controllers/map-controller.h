
#ifndef CONTROLLERS_MAP_CONTROLLER_H_
#define CONTROLLERS_MAP_CONTROLLER_H_

#include <SFML/System.hpp>
#include <vector>

#include "engine/game-event.h"
#include "structures/tower.h"

class MapController {
 public:
  MapController() { }

  void Load(unsigned width, unsigned height);

  void Step(sf::Time elapsed);

  void EventTriggered(GameEvent event);

  bool CanPlaceTower(unsigned row, unsigned col);
  void PlaceTower(unsigned row, unsigned col, Tower *tower);

 private:
  unsigned width_, height_;

  std::vector<Tower *> towers_;
  std::vector<std::vector<EnemyUnit *> > enemies_;

  unsigned index_(unsigned row, unsigned col);
};

#endif  // CONTROLLERS_MAP_CONTROLLER_H_
