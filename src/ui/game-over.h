// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#ifndef UI_GAME_OVER_H_
#define UI_GAME_OVER_H_

#include "base/aliases.h"
#include "engine/instance.h"


class GameOver : public Instance {
 private:
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif  // UI_GAME_OVER_H_
