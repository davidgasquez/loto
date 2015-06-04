
#ifndef UI_CURSOR_H_
#define UI_CURSOR_H_

#include <SFML/Graphics.hpp>

#include "engine/instance.h"
#include "base/aliases.h"


class Cursor : public Instance {
 public:
  Cursor();
  virtual ~Cursor() { }

  void Load();

  void SetDefault();

  void set_visible(bool visible);

 protected:
  bool visible_;
};

#endif  // UI_CURSOR_H_
