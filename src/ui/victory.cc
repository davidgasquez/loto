// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#include "ui/victory.h"

#include "engine/game.h"


void Victory::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  Game::GetCursorManager()->Show();

  auto font = *Game::GetResourcesManager()->Font();

  sf::Color color(33, 150, 143);

  sf::Text victory("Victory", font, 200);
  victory.setColor(color);
  victory.setStyle(sf::Text::Bold);
  victory.setPosition(315, 100);
  target.draw(victory);

  sf::Text smile(":)", font, 200);
  smile.setColor(color);
  smile.setStyle(sf::Text::Bold);
  smile.setPosition(800, 400);
  smile.setRotation(90);
  target.draw(smile);
}
