// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#include "structures/tower.h"

#include "engine/game.h"
#include "projectiles/tower-arrow.h"


void Tower::Load() {
  auto resources = Game::GetResourcesManager();
  sprite_.set_texture(resources->Tower());
  arrow_.setBuffer(*resources->ArrowSound());
  arrow_.setVolume(50);
}


void Tower::set_position(Vec2u pos) {
  Vec2u tile_size = Game::GetTileSize();
  Vec2u size(sprite_.size());
  sprite_.set_position(Vec2f(tile_size.x * pos.x + size.x / 2,
                             tile_size.y * pos.y + size.y / 2));
}


void Tower::draw(sf::RenderTarget& target,
                 sf::RenderStates  states) const {
  target.draw(sprite_);
}


void Tower::Step(sf::Time elapsed) {
  if (attack_clock_.getElapsedTime().asMilliseconds() < 800) {
    return;
  }
  attack_clock_.restart();

  auto map_controller = Game::GetMapController();
  Vec2u tile = map_controller->CalcRowCol(sprite_.position());

  auto near_enemy = map_controller->GetNearEnemy(tile);
  if (near_enemy == nullptr) {
    return;
  }

  arrow_.play();
  auto arrow = new TowerArrow();
  arrow->Load(sprite_.position());
  arrow->set_enemy(near_enemy);
  Game::GetInstancesManager()->AddInstance(arrow, kLayerProjectiles);
}
