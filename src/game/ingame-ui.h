
#ifndef GAME_INGAME_UI_H_
#define GAME_INGAME_UI_H_

#include "engine/instance.h"

class InGameUI : public Instance {
 public:
  InGameUI()
  : active_(false), bad_selection_(false) { }

  void Load();

  void MouseReleased(sf::Event::MouseButtonEvent event);
  void MouseMoved(sf::Event::MouseMoveEvent event);

 private:
  sf::Sprite tower_button_;
  sf::Sprite tower_selection_;
  sf::Sprite tower_selection_bad_;
  bool active_;

  bool bad_selection_;
  sf::Vector2u last_tower_position_;

  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif  // GAME_INGAME_UI_H_
