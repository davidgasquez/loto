// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#include "controllers/map-controller.h"

#include <utility>
#include <vector>

#include "engine/game.h"
#include "ui/victory.h"


const float kTowerGraphWeight = 50.f;


void MapController::Load(unsigned width, unsigned height) {
  width_ = width;
  height_ = height;
  towers_.resize(width * height, nullptr);
  enemies_.resize(width * height);

  graph_ = new Graph(width, height);
  graph_->Load();

  auto resources = Game::GetResourcesManager();

  game_over_.setBuffer(*resources->GameOver());
  game_over_.setVolume(50);

  victory_.setBuffer(*resources->Victory());
  victory_.setVolume(50);

  loop_.setBuffer(*resources->Loop());
  loop_.play();
  loop_.setVolume(50);
  loop_.setLoop(true);

  enemy_dead_.setBuffer(*resources->EnemyDead());
  enemy_reached_castle_.setBuffer(*resources->EnemyReachedCastle());
}


void MapController::Step(sf::Time elapsed) {
}


bool MapController::ReachedCastle(Vec2u tile) {
  return (tile.x < 2);
}


void MapController::EventTriggered(GameEvent event) {
  switch (event.type()) {
  case GAME_OVER:
    loop_.stop();
    game_over_.play();
    break;

  case VICTORY: {
    loop_.stop();
    victory_.play();

    auto instances = Game::GetInstancesManager();
    instances->AddInstance(new Victory(), kLayerUI);
    break;
  }

  case ENEMY_DIED:
    enemy_dead_.play();
    enemy_dead_.setVolume(50);
    break;

  case ENEMY_REACHED_CASTLE:
    enemy_reached_castle_.play();
    break;

  default:
    break;
  }
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

  if (all_enemies_ && !game_over_flag_ && enemy_position_.size() == 0) {
    Game::GetEventsManager()->Trigger(GameEvent(VICTORY));
  }
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

  if (Game::hardcore()) {
    float min_row = gpos.y;
    if (min_row > 2) {
      min_row -= 4;
    } else if (min_row > 0) {
      min_row -= 2;
    }
    float max_row = gpos.y + 1;
    if (max_row < Game::GetMapSize().y * 2 - 2) {
      max_row += 4;
    } else if (max_row < Game::GetMapSize().y * 2 - 1) {
      max_row += 2;
    }
    for (unsigned i = gpos.x - 4; i < gpos.x + 4; ++i) {
      for (unsigned j = min_row; j < max_row; ++j) {
        graph_->AddWeight(Vec2u(i, j), kTowerGraphWeight);
      }
    }
  }
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

