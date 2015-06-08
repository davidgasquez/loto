
#include "ui/ingame.h"

#include <sstream>

#include "engine/game.h"
#include "base/debug.h"


void InGame::Load() {
  tower_button_.setTexture(*Game::GetResourcesManager()->UITowerButton());
  tower_selection_.setTexture(*Game::GetResourcesManager()->TowerSelected());
  tower_selection_bad_.setTexture(*Game::GetResourcesManager()->TowerBad());

  heart_.setTexture(*Game::GetResourcesManager()->Heart());
  heart_.setPosition(Vec2f(5.f, 10.f));

  coin_.setTexture(*Game::GetResourcesManager()->Coin());
  coin_.setPosition(Vec2f(6.f, 65.f));

  Vec2f pos(Game::GetWindowSize());
  pos.x = 10;
  pos.y = (pos.y / 2) - 80;
  tower_button_.setPosition(pos);
}


void InGame::draw(sf::RenderTarget& target, sf::RenderStates  states) const {
  target.draw(tower_button_);
  target.draw(heart_);
  target.draw(coin_);

  if (active_) {
    if (bad_selection_) {
      target.draw(tower_selection_bad_);
    } else {
      target.draw(tower_selection_);
    }
  }

  auto font = *Game::GetResourcesManager()->Font();

  std::stringstream player_life;
  auto player_controller = Game::GetPlayerController();
  player_life << player_controller->life();
  sf::Text life(player_life.str(), font, 32);
  life.setPosition(65.f, 10.f);
  target.draw(life);

  std::stringstream player_gold;
  player_gold << player_controller->gold();
  sf::Text gold(player_gold.str(), font, 32);
  gold.setPosition(65.f, 67.f);
  target.draw(gold);

  if (player_controller->life() <=0 || player_controller->life() > 100) {
    std::stringstream lose;
    lose << "Game Over";
    sf::Text game_over(lose.str(), font, 200);
    game_over.setColor(sf::Color::Black);
    game_over.setStyle(sf::Text::Bold);
    game_over.setPosition(270, 100);
    target.draw(game_over);

    sf::Text sad_face(":(", font, 200);
    sad_face.setColor(sf::Color::Black);
    sad_face.setStyle(sf::Text::Bold);
    sad_face.setPosition(800, 400);
    sad_face.setRotation(90);
    target.draw(sad_face);
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
    auto map_controller = Game::GetMapController();
    auto tower = new Tower();
    tower->Load();
    tower->set_position(last_tower_position_);

    Game::GetEventsManager()->Trigger(GameEvent(TOWER_PLACED));
    Game::GetInstancesManager()->AddInstance(tower, kLayerMid);

    map_controller->PlaceTower(last_tower_position_, tower);
    active_ = false;
  }

  if (active_) {
    Game::GetCursorManager()->Hide();
  } else {
    Game::GetCursorManager()->Show();
  }
}


void InGame::MouseMoved(sf::Event::MouseMoveEvent event) {
  if (!active_) {
    return;
  }

  calcTowerPlace_(Vec2f(event.x, event.y));
}


void InGame::calcTowerPlace_(Vec2f mouse_pos) {
  auto map_controller = Game::GetMapController();

  last_tower_position_ = map_controller->CalcRowCol(mouse_pos);

  bad_selection_ = !map_controller->CanPlaceTower(last_tower_position_);
  Vec2u a(last_tower_position_);
  Vec2u b(Game::GetTileSize());
  Vec2f pos(a.x * b.x, a.y * b.y);
  tower_selection_.setPosition(pos);
  tower_selection_bad_.setPosition(pos);
}
