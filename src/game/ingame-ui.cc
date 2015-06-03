
#include "game/ingame-ui.h"

#include "engine/game-manager.h"
#include "base/aliases.h"
#include "base/debug.h"


void InGameUI::Load() {
  tower_button_.setTexture(*GameManager::GetResourcesManager()->UITowerButton());
  tower_selection_.setTexture(*GameManager::GetResourcesManager()->Tower());

  Vec2f pos(GameManager::GetWindowSize());
  pos.x = 10;
  pos.y = (pos.y / 2) - 80;
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

  Vec2f mouse_pos(event.x, event.y);
  if (tower_button_.getGlobalBounds().contains(mouse_pos)) {
    active_ = !active_;
  }
}


void InGameUI::MouseMoved(sf::Event::MouseMoveEvent event) {
  auto mapController = GameManager::GetMapController();

  Vec2f mouse_pos(event.x, event.y);

  Vec2f tile_size(GameManager::GetTileSize());
  unsigned row = static_cast<unsigned>(mouse_pos.y / tile_size.y);
  unsigned col = static_cast<unsigned>(mouse_pos.x / tile_size.x);

  if (col < 2) {
    col = 2;
  }
  if (col > mapController->width() - 3) {
    col = mapController->width() - 3;
  }

  if (mapController->CanPlaceTower(row, col)) {
    mouse_pos.x = col * tile_size.x;
    mouse_pos.y = row * tile_size.y;

    tower_selection_.setPosition(mouse_pos);
  }
}
