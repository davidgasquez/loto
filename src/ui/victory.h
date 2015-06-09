
#ifndef UI_VICTORY_H_
#define UI_VICTORY_H_

#include "base/aliases.h"
#include "engine/instance.h"


class Victory : public Instance {
 private:
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif  // UI_VICTORY_H_
