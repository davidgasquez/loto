// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

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

  void MouseMoved(sf::Event::MouseMoveEvent event);

  void SetDefault();

 protected:
};

#endif  // UI_CURSOR_H_
