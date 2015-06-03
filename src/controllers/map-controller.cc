
#include "controllers/map-controller.h"

#include "base/debug.h"


void MapController::Load(unsigned width, unsigned height) {
  width_ = width;
  height_ = height;
  towers_.resize(width * height, nullptr);
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
  if (col < 2 || col > width_ - 3) {
    return false;
  }

  unsigned min_row = row;
  if (min_row > 0) {
    min_row--;
  }
  unsigned max_row = row;
  if (row < height_ - 1) {
    max_row++;
  }
  unsigned min_col = col - 1;
  unsigned max_col = col + 1;

  for (unsigned i = min_row; i <= max_row; ++i) {
    for (unsigned j = min_col; j <= max_col; ++j) {
      if (towers_[index_(i, j)] != nullptr) {
        return false;
      }
    }
  }

  return true;
}


void MapController::PlaceTower(unsigned row, unsigned col, Tower* tower) {
  towers_[index_(row, col)] = tower;
}


unsigned MapController::index_(unsigned row, unsigned col) {
  return row * width_ + col;
}
