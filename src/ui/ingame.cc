// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#include "ui/ingame.h"

#include <sstream>

#include "engine/game.h"


void InGame::Load() {
  auto resources = Game::GetResourcesManager();

  tower_button_.setTexture(*resources->UITowerButton());
  tower_selection_.setTexture(*resources->TowerSelected());
  tower_selection_bad_.setTexture(*resources->TowerBad());

  heart_.setTexture(*resources->Heart());
  heart_.setPosition(Vec2f(5.f, 10.f));

  coin_.setTexture(*resources->Coin());
  coin_.setPosition(Vec2f(6.f, 65.f));

  Vec2f pos(Game::GetWindowSize());
  pos.x = 10;
  pos.y = (pos.y / 2) - 80;
  tower_button_.setPosition(pos);

  place_tower_.setBuffer(*resources->PlaceTower());
  place_tower_.setVolume(30);
}


void InGame::draw(sf::RenderTarget& target, sf::RenderStates states) const {
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
}


void InGame::MouseReleased(sf::Event::MouseButtonEvent event) {
  if (!event.button == sf::Mouse::Button::Left) {
    return;
  }

  mouse_pos_ = Vec2f(event.x, event.y);
  if (tower_button_.getGlobalBounds().contains(mouse_pos_)) {
    active_ = !active_;
    if (active_) {
      Game::GetCursorManager()->Hide();
      calcTowerPlace_();
      return;
    } else {
      Game::GetCursorManager()->Show();
    }
  }

  if (active_) {
    calcTowerPlace_();
    if (!bad_selection_) {
      auto map_controller = Game::GetMapController();
      auto tower = new Tower();
      tower->Load();
      tower->set_position(last_tower_position_);

      Game::GetEventsManager()->Trigger(GameEvent(TOWER_PLACED));
      Game::GetInstancesManager()->AddInstance(tower, kLayerMidElevated);

      place_tower_.play();

      map_controller->PlaceTower(last_tower_position_, tower);
      active_ = false;
      Game::GetCursorManager()->Show();
    }
  }
}


void InGame::MouseMoved(sf::Event::MouseMoveEvent event) {
  if (!active_) {
    return;
  }

  mouse_pos_ = Vec2f(event.x, event.y);
  calcTowerPlace_();
}


void InGame::EventTriggered(GameEvent event) {
  switch (event.type()) {
  case GAME_OVER:
  case VICTORY: {
    auto instances = Game::GetInstancesManager();
    instances->MarkToRemoveAndDelete(this);
    break;
  }

  default:
    {}
  }
}


void InGame::Step(sf::Time elapsed) {
  calcTowerPlace_();
}


void InGame::calcTowerPlace_() {
  auto map_controller = Game::GetMapController();

  last_tower_position_ = map_controller->CalcRowCol(mouse_pos_);

  bad_selection_ = !map_controller->CanPlaceTower(last_tower_position_);
  Vec2u a(last_tower_position_);
  Vec2u b(Game::GetTileSize());
  Vec2f pos(a.x * b.x, a.y * b.y);
  tower_selection_.setPosition(pos);
  tower_selection_bad_.setPosition(pos);
}
