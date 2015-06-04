
#include "structures/tower.h"

#include "engine/game-manager.h"


void Tower::Load() {
  sprite_.setTexture(*GameManager::GetResourcesManager()->Tower());
}

void Tower::set_position(sf::Vec2u pos) {
  sf::Vec2u tile_size = GameManager::GetTileSize();

  sprite_.setPosition(tile_size.x * pos.x, tile_size.y * pos.y);
}

void Tower::draw(sf::RenderTarget& target,
                 sf::RenderStates  states) const {
  target.draw(sprite_);
}
