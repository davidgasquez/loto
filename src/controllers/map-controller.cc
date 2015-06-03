
#include "controllers/map-controller.h"


void MapController::Load(unsigned width, unsigned height) {
  width_ = width;
  height_ = height;
}


void MapController::Step(sf::Time elapsed) {
}


void MapController::EventTriggered(GameEvent event) {
  switch (event.type()) {
    case ENEMY_DIED:
      break;
    case TOWER_PLACED:
      break;
    case ENEMY_REACHED_CASTLE:
      break;
  }
}


bool MapController::CanPlaceTower(unsigned row, unsigned col) {
  return true;
}
