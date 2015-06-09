
#include "projectiles/tower-arrow.h"

#include "engine/game.h"


// Lower than the re-hit interval of the tower
const float kMaxTimeAlive = 700.f;


float Lerp(float v0, float v1, float t) {
  return v0 + t * (v1 - v0);
}


void TowerArrow::Load(Vec2f initial_position) {
  initial_position_ = initial_position;
  sprite_.set_texture(Game::GetResourcesManager()->Arrow());
  sprite_.set_position(initial_position);
  clock_.restart();
}


void TowerArrow::Step(sf::Time elapsed) {
  auto alive = clock_.getElapsedTime().asMilliseconds();
  if (alive >= kMaxTimeAlive) {
    Game::GetInstancesManager()->MarkToRemoveAndDelete(this);
    enemy_->Attack();
    return;
  }

  auto epos = enemy_->position();
  Vec2f pos(initial_position_);

  auto rad = atan2(epos.y - pos.y, epos.x - pos.x);
  sprite_.set_rotation(rad * (180 / M_PI));

  auto remaining = (kMaxTimeAlive - alive) / kMaxTimeAlive;
  pos.x = Lerp(epos.x, pos.x, remaining);
  pos.y = Lerp(epos.y, pos.y, remaining);
  sprite_.set_position(pos);
}
