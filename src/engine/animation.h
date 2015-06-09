// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#ifndef ENGINE_ANIMATION_H_
#define ENGINE_ANIMATION_H_

#include <SFML/Graphics.hpp>

#include <vector>


class Animation {
 public:
  void AddFrame(sf::IntRect bounds);

  void Restart();

 private:
  std::vector<sf::IntRect> frames_;
  unsigned current_frame_;
};

#endif  // ENGINE_ANIMATION_H_
