
#include "ui/ingame.h"

#include "engine/game-manager.h"
#include "base/debug.h"


void InGame::Load() {
  tower_button_.setTexture(*GameManager::GetResourcesManager()->UITowerButton());
  tower_selection_.setTexture(*GameManager::GetResourcesManager()->TowerSelected());
  tower_selection_bad_.setTexture(*GameManager::GetResourcesManager()->TowerBad());

  Vec2f pos(GameManager::GetWindowSize());
  pos.x = 10;
  pos.y = (pos.y / 2) - 80;
  tower_button_.setPosition(pos);
}


void InGame::draw(sf::RenderTarget& target, sf::RenderStates  states) const {
  target.draw(tower_button_);

  if (active_) {
    if (bad_selection_) {
      target.draw(tower_selection_bad_);
    } else {
      target.draw(tower_selection_);
    }
  }
}


void InGame::MouseReleased(sf::Event::MouseButtonEvent event) {
  if (!event.button == sf::Mouse::Button::Left) {
    return;
  }

  Vec2f mouse_pos(event.x, event.y);
  if (tower_button_.getGlobalBounds().contains(mouse_pos)) {
    active_ = !active_;
    calcTowerPlace_(mouse_pos);
  } else if (active_ && !bad_selection_) {
    auto map_controller = GameManager::GetMapController();
    auto tower = new Tower();
    tower->Load();
    tower->set_position(last_tower_position_);

    GameManager::GetInstancesManager()->AddInstance(tower);

    map_controller->PlaceTower(last_tower_position_, tower);
    active_ = false;
  }

  GameManager::GetWindow()->setMouseCursorVisible(!active_);
}


void InGame::MouseMoved(sf::Event::MouseMoveEvent event) {
  if (!active_) {
    return;
  }

  calcTowerPlace_(Vec2f(event.x, event.y));
}


void InGame::calcTowerPlace_(Vec2f mouse_pos) {
  auto map_controller = GameManager::GetMapController();

  last_tower_position_ = map_controller->CalcRowCol(mouse_pos);

  bad_selection_ = !map_controller->CanPlaceTower(last_tower_position_);
  Vec2u a(last_tower_position_);
  Vec2u b(GameManager::GetTileSize());
  Vec2f pos(a.x * b.x, a.y * b.y);
  tower_selection_.setPosition(pos);
  tower_selection_bad_.setPosition(pos);
}