
#ifndef CONTROLLERS_MAP_CONTROLLER_H_
#define CONTROLLERS_MAP_CONTROLLER_H_

#include <SFML/System.hpp>
#include <vector>
#include <map>

#include "engine/game-event.h"
#include "structures/tower.h"
#include "units/enemy-unit.h"

class MapController {
 public:
  MapController() { }

  void Load(unsigned width, unsigned height);

  void Step(sf::Time elapsed);

  void EventTriggered(GameEvent event);

  std::vector<EnemyUnit *> GetNearEnemies(Vec2u tile);

  bool CanPlaceTower(Vec2u tile);
  void PlaceTower(Vec2u tile, Tower *tower);

  void PlaceEnemy(Vec2u tile, EnemyUnit* enemy);
  void RemoveEnemy(EnemyUnit* enemy);
  bool ReachedCastle(Vec2u tile);

  Vec2u CalcRowCol(Vec2f position);

 private:
  unsigned width_, height_;

  std::vector<Tower *> towers_;
  std::vector<std::vector<EnemyUnit *> > enemies_;

  std::map<EnemyUnit*, unsigned> enemy_position_;

  unsigned Index_(Vec2u tile);
};

#endif  // CONTROLLERS_MAP_CONTROLLER_H_
