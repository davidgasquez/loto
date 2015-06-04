
#include "engine/cursor-manager.h"

#include "engine/instances-manager.h"
#include "engine/game.h"


void CursorManager::Load() {
  Game::GetWindow()->setMouseCursorVisible(false);

  cursor_ = new Cursor();
  cursor_->Load();
  Game::GetInstancesManager()->AddInstance(cursor_, kLayerCursor);
}


void CursorManager::Show() {
  cursor_->set_visible(true);
}


void CursorManager::Hide() {
  cursor_->set_visible(false);
}
