
#ifndef ENGINE_CURSOR_MANAGER_H_
#define ENGINE_CURSOR_MANAGER_H_

#include "ui/cursor.h"


class CursorManager {
 public:
  void Load();

 private:
  Cursor* cursor_;
};

#endif  // ENGINE_CURSOR_MANAGER_H_
