
#include "engine/cursor-manager.h"

#include "engine/instances-manager.h"
#include "engine/game-manager.h"


void CursorManager::Load() {
  // GameManager::GetWindow()->setMouseCursorVisible(false);

  cursor_ = new Cursor();
  cursor_->Load();
  GameManager::GetInstancesManager()->AddInstance(cursor_);
}
