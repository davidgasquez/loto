
#include "structures/sample-tower.h"

#include "engine/game-manager.h"


void SampleTower::Load() {
  sprite_.setTexture(*GameManager::GetResourcesManager()->Tower());
}

void SampleTower::set_tile_position(sf::Vector2u pos) {
  sf::Vector2u tile_size = GameManager::GetTileSize();

  sprite_.setPosition(tile_size.x * pos.x, tile_size.y * pos.y);
}

void SampleTower::draw(sf::RenderTarget& target,
                       sf::RenderStates  states) const {
  target.draw(sprite_);
}
