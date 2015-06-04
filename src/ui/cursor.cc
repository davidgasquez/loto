
#include "ui/cursor.h"

#include "engine/game-manager.h"


Cursor::Cursor() {
  SetDefault();
}


void Cursor::Load() {
  sprite_.set_texture(GameManager::GetResourcesManager()->UICursor());

  Vec2f pos(GameManager::GetWindowSize());
  sprite_.set_position(pos / 2.f);
}


void Cursor::MouseMoved(sf::Event::MouseMoveEvent event) {
  sprite_.set_position(Vec2f(event.x, event.y));
}


void Cursor::SetDefault() {

}
