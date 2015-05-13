
#include "game/ingame-ui.h"

#include "engine/game-manager.h"
#include "base/debug.h"


void InGameUI::Load() {
  tower_button_.setTexture(*GameManager::GetResourcesManager()->UITowerButton());
  tower_selection_.setTexture(*GameManager::GetResourcesManager()->Tower());

  sf::Vector2f pos(GameManager::GetWindowSize());
  pos.x = (pos.x / 2) - 30;
  pos.y = pos.y - 80;
  tower_button_.setPosition(pos);
}


void InGameUI::draw(sf::RenderTarget& target, sf::RenderStates  states) const {
  target.draw(tower_button_);

  if (active_) {
    target.draw(tower_selection_);
  }
}


void InGameUI::MouseReleased(sf::Event::MouseButtonEvent event) {
  if (!event.button == sf::Mouse::Button::Left) {
    return;
  }

  sf::Vector2f mouse_pos(event.x, event.y);
  if (tower_button_.getGlobalBounds().contains(mouse_pos)) {
    active_ = !active_;
  }
}


void InGameUI::MouseMoved(sf::Event::MouseMoveEvent event) {
  sf::Vector2f mouse_pos(event.x, event.y);
  tower_selection_.setPosition(mouse_pos);
}
