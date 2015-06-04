
#include "structures/tower.h"

#include "engine/game-manager.h"


void Tower::Load() {
  sprite_.set_texture(GameManager::GetResourcesManager()->Tower());
}

void Tower::set_position(Vec2u pos) {
  Vec2u tile_size = GameManager::GetTileSize();

  sprite_.set_position(Vec2f(tile_size.x * pos.x, tile_size.y * pos.y));
}

void Tower::draw(sf::RenderTarget& target,
                 sf::RenderStates  states) const {
  target.draw(sprite_);
}
