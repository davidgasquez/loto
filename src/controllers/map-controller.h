// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#ifndef CONTROLLERS_MAP_CONTROLLER_H_
#define CONTROLLERS_MAP_CONTROLLER_H_

#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <map>

#include "engine/game-event.h"
#include "structures/tower.h"
#include "units/enemy-unit.h"
#include "ai/graph.h"


class MapController {
 public:
  MapController()
  : all_enemies_(false) { }

  void Load(unsigned width, unsigned height);

  void Step(sf::Time elapsed);

  void EventTriggered(GameEvent event);

  EnemyUnit* GetNearEnemy(Vec2u tile);

  bool CanPlaceTower(Vec2u tile);
  void PlaceTower(Vec2u tile, Tower *tower);

  void PlaceEnemy(Vec2u tile, EnemyUnit* enemy);
  void RemoveEnemy(EnemyUnit* enemy);
  bool ReachedCastle(Vec2u tile);

  Vec2u CalcRowCol(Vec2f position);

  Graph* graph() {
    return graph_;
  }

  // TODO(ernesto): Remove this
  void set_graph(Graph* graph) {
    graph_ = graph;
  }

  void set_all_enemies(bool all_enemies) {
    all_enemies_ = all_enemies;
  }

 private:
  unsigned width_, height_;
  sf::Sound loop_, game_over_, victory_;

  std::vector<Tower *> towers_;
  std::vector<std::vector<EnemyUnit *> > enemies_;
  Graph* graph_;

  std::map<EnemyUnit*, unsigned> enemy_position_;
  bool all_enemies_;

  unsigned Index_(Vec2u tile);
};

#endif  // CONTROLLERS_MAP_CONTROLLER_H_
