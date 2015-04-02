
#include "structures/tower.h"

#include "managers/game-manager.h"


void Tower::Load() {
  sprite_.setTexture(*GameManager::GetResourcesManager()->Tower());
}

void Tower::draw(sf::RenderTarget& target, sf::RenderStates  states) const {
  states.transform *= getTransform();
  target.draw(sprite_);
}
