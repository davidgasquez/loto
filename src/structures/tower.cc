
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
  Vec2u row_col = map_controller->CalcRowCol(sprite_.position());
  auto near_enemies = map_controller->GetNearEnemies(row_col);

  if (near_enemies.size() == 0) {
    return;
  }

  EnemyUnit* nearest_enemy;
  float min_distance = 9999999;
  for (EnemyUnit* enemy : near_enemies) {
    float dx = enemy->position().x - sprite_.position().x;
    float dy = enemy->position().y - sprite_.position().y;
    float distance = dx * dx + dy * dy;

    if (distance < min_distance) {
      nearest_enemy = enemy;
      min_distance = distance;
    }
  }

  nearest_enemy->Attack();
}
