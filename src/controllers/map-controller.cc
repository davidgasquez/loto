
#include "controllers/map-controller.h"


void MapController::Load(unsigned width, unsigned height) {
  width_ = width;
  height_ = height;
}


void MapController::Step(sf::Time elapsed) {

}


bool MapController::CanPlaceTower(unsigned row, unsigned col) {
  return true;
}
