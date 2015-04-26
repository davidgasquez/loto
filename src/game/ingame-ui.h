
#ifndef GAME_INGAME_UI_H_
#define GAME_INGAME_UI_H_

#include "engine/instance.h"

class InGameUI : public Instance {
 public:
  void Load();

 private:
  sf::Sprite tower_button_;

  virtual void draw(sf::RenderTarget& target,
                    sf::RenderStates  states) const;
};

#endif  // GAME_INGAME_UI_H_
