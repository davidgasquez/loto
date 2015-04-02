
#include "structures/tower.h"

#include "engine/game-manager.h"
#include "base/debug.h"


void Tower::Load() {
  sprite_.setTexture(*GameManager::GetResourcesManager()->Tower());
}

void Tower::SetTilePosition(sf::Vector2u pos) {
  sf::Vector2u tileSize = GameManager::GetTileSize();
  sprite_.setPosition(tileSize.x * pos.x, tileSize.y * pos.y);
}

void Tower::draw(sf::RenderTarget& target, sf::RenderStates  states) const {
  target.draw(sprite_);
}
