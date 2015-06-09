
#include "ui/game-over.h"

#include "engine/game.h"


void GameOver::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  Game::GetCursorManager()->Show();
  
  auto font = *Game::GetResourcesManager()->Font();

  sf::Text game_over("Game Over", font, 200);
  game_over.setColor(sf::Color::Black);
  game_over.setStyle(sf::Text::Bold);
  game_over.setPosition(270, 100);
  target.draw(game_over);

  sf::Text sad_face(":(", font, 200);
  sad_face.setColor(sf::Color::Black);
  sad_face.setStyle(sf::Text::Bold);
  sad_face.setPosition(800, 400);
  sad_face.setRotation(90);
  target.draw(sad_face);
}
