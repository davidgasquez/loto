// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#ifndef ENGINE_CURSOR_MANAGER_H_
#define ENGINE_CURSOR_MANAGER_H_

#include "ui/cursor.h"


class CursorManager {
 public:
  void Load();

  void Show();
  void Hide();

 private:
  Cursor* cursor_;
};

#endif  // ENGINE_CURSOR_MANAGER_H_
