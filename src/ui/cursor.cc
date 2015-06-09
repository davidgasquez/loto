// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#include "ui/cursor.h"

#include "engine/game.h"


Cursor::Cursor() {
  SetDefault();
}


void Cursor::Load() {
  sprite_.set_texture(Game::GetResourcesManager()->UICursor());

  Vec2f pos(Game::GetWindowSize());
  sprite_.set_position(pos / 2.f);
}


void Cursor::MouseMoved(sf::Event::MouseMoveEvent event) {
  sprite_.set_position(Vec2f(event.x, event.y));
}


void Cursor::SetDefault() {
}
