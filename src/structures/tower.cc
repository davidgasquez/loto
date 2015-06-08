
#include "structures/tower.h"

#include "engine/game.h"


void Tower::Load() {
  sprite_.set_texture(Game::GetResourcesManager()->Tower());
}


void Tower::set_position(Vec2u pos) {
  Vec2u tile_size = Game::GetTileSize();

  sprite_.set_position(Vec2f(tile_size.x * pos.x, tile_size.y * pos.y));
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

  near_enemy->Attack();
}
