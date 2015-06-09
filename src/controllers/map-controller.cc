// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#include "controllers/map-controller.h"

#include <utility>
#include <vector>
#include "base/debug.h"
#include "engine/game.h"


void MapController::Load(unsigned width, unsigned height) {
  width_ = width;
  height_ = height;
  towers_.resize(width * height, nullptr);
  enemies_.resize(width * height);

  graph_ = new Graph(width, height);
  graph_->Load();
}


void MapController::Step(sf::Time elapsed) {
}


bool MapController::ReachedCastle(Vec2u tile) {
  return (tile.x < 2);
}


void MapController::EventTriggered(GameEvent event) {
}


void MapController::PlaceEnemy(Vec2u tile, EnemyUnit* enemy) {
  unsigned n = Index_(tile);

  auto pos = enemy_position_.find(enemy);
  if (pos != enemy_position_.end()) {
    if (pos->second == n) {
      return;
    }

    auto removed = std::remove(enemies_[pos->second].begin(),
                               enemies_[pos->second].end(), enemy);
    enemies_[pos->second].erase(removed, enemies_[pos->second].end());
  }

  enemies_[n].push_back(enemy);
  enemy_position_[enemy] = Index_(tile);
}


void MapController::RemoveEnemy(EnemyUnit* enemy) {
  auto pos = enemy_position_.find(enemy);
  if (pos == enemy_position_.end()) {
    return;
  }

  auto removed = std::remove(enemies_[pos->second].begin(),
                             enemies_[pos->second].end(), enemy);
  enemies_[pos->second].erase(removed, enemies_[pos->second].end());

  enemy_position_.erase(pos);
}


bool MapController::CanPlaceTower(Vec2u tile) {
  if (tile.x < 2 || tile.x > width_ - 3) {
    return false;
  }

  if (enemies_[Index_(tile)].size() > 0) {
    return false;
  }

  auto player_controller = Game::GetPlayerController();
  if (player_controller->gold() < kTowerCost) {
    return false;
  }

  unsigned min_row = tile.y;
  if (min_row > 0) {
    min_row--;
  }
  unsigned max_row = tile.y;
  if (tile.y < height_ - 1) {
    max_row++;
  }
  unsigned min_col = tile.x - 1;
  unsigned max_col = tile.x + 1;

  for (unsigned i = min_row; i <= max_row; ++i) {
    for (unsigned j = min_col; j <= max_col; ++j) {
      if (towers_[Index_(Vec2u(j, i))] != nullptr) {
        return false;
      }
    }
  }

  return true;
}



EnemyUnit* MapController::GetNearEnemy(Vec2u tile) {
  unsigned min_row = tile.y;
  if (min_row > 0) {
    min_row--;
  }
  unsigned max_row = tile.y;
  if (tile.y < height_ - 1) {
    max_row++;
  }
  unsigned min_col = tile.x - 1;
  unsigned max_col = tile.x + 1;

  for (unsigned i = min_row; i <= max_row; ++i) {
    for (unsigned j = min_col; j <= max_col; ++j) {
      unsigned pos = Index_(Vec2u(j, i));
      for (EnemyUnit * enemy : enemies_[pos]) {
        return enemy;
      }
    }
  }

  return nullptr;
}


void MapController::PlaceTower(Vec2u tile, Tower* tower) {
  towers_[Index_(tile)] = tower;

  Vec2u gpos(tile.x * 2, tile.y * 2);
  graph_->RemoveEdges(gpos);
  graph_->RemoveEdges(Vec2u(gpos.x + 1, gpos.y));
  graph_->RemoveEdges(Vec2u(gpos.x, gpos.y + 1));
  graph_->RemoveEdges(Vec2u(gpos.x + 1, gpos.y + 1));
}


unsigned MapController::Index_(Vec2u tile) {
  return tile.y * width_ + tile.x;
}


Vec2u MapController::CalcRowCol(Vec2f position) {
  sf::Vector2f tile_size(Game::GetTileSize());

  unsigned row = static_cast<unsigned>(position.y / tile_size.y);
  unsigned col = static_cast<unsigned>(position.x / tile_size.x);

  return Vec2u(col, row);
}

