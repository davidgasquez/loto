
#include "game/ingame-ui.h"

#include "engine/game-manager.h"


void InGameUI::Load() {
  tower_button_.setTexture(*GameManager::GetResourcesManager()->UITowerButton());

  sf::Vector2f pos(GameManager::GetWindowSize());
  pos.x = (pos.x / 2) - 30;
  pos.y = pos.y - 80;
  tower_button_.setPosition(pos);
}

void InGameUI::draw(sf::RenderTarget& target, sf::RenderStates  states) const {
  target.draw(tower_button_);
}
