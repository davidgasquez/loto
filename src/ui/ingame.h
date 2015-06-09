// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#ifndef UI_INGAME_H_
#define UI_INGAME_H_

#include <SFML/Audio.hpp>

#include "base/aliases.h"
#include "engine/instance.h"


class InGame : public Instance {
 public:
  InGame()
  : active_(false), bad_selection_(false) { }

  void Load();

  void MouseReleased(sf::Event::MouseButtonEvent event);
  void MouseMoved(sf::Event::MouseMoveEvent event);
  
  void EventTriggered(GameEvent event);
  
  void Step(sf::Time elapsed);

 private:
  sf::Sprite tower_button_;
  sf::Sprite tower_selection_;
  sf::Sprite tower_selection_bad_;
  sf::Sprite heart_;
  sf::Sprite coin_;
  bool active_;

  bool bad_selection_;
  Vec2u last_tower_position_;

  Vec2f mouse_pos_;
  
  sf::Sound place_tower_;

  void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  void calcTowerPlace_();
};

#endif  // UI_INGAME_H_
