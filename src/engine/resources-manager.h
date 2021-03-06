// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#ifndef BASE_RESOURCES_MANAGER_H_
#define BASE_RESOURCES_MANAGER_H_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


class ResourcesManager {
 public:
  bool Load();

  sf::Texture* Map() {
    return &map_;
  }

  sf::Texture* Tower() {
    return &tower_;
  }

  sf::Texture* TowerBad() {
    return &tower_bad_;
  }

  sf::Texture* TowerSelected() {
    return &tower_selected_;
  }

  sf::Texture* Enemy() {
    return &enemy_;
  }

  sf::Texture* UITowerButton() {
    return &ui_tower_button_;
  }

  sf::Texture* UICursor() {
    return &ui_cursor_;
  }

  sf::Texture* Coin() {
    return &coin_;
  }

  sf::Texture* Heart() {
    return &heart_;
  }

  sf::Font* Font() {
    return &font_;
  }

  sf::SoundBuffer* Loop() {
    return &loop_;
  }

  sf::Texture* Arrow() {
    return &arrow_;
  }

  sf::SoundBuffer* GameOver() {
    return &game_over_;
  }

  sf::SoundBuffer* Victory() {
    return &victory_;
  }

  sf::SoundBuffer* EnemyDead() {
    return &enemy_dead_;
  }

  sf::SoundBuffer* EnemyReachedCastle() {
    return &enemy_reached_castle_;
  }

  sf::SoundBuffer* PlaceTower() {
    return &place_tower_;
  }

  sf::SoundBuffer* ArrowSound() {
    return &arrow_sound_;
  }

 private:
  sf::Texture map_;
  sf::Texture tower_;
  sf::Texture tower_bad_;
  sf::Texture tower_selected_;
  sf::Texture enemy_;
  sf::Texture ui_tower_button_;
  sf::Texture ui_cursor_;
  sf::Texture heart_;
  sf::Texture coin_;
  sf::SoundBuffer loop_;
  sf::Texture arrow_;
  sf::SoundBuffer game_over_;
  sf::SoundBuffer victory_;
  sf::SoundBuffer enemy_dead_;
  sf::SoundBuffer enemy_reached_castle_;
  sf::SoundBuffer place_tower_;
  sf::SoundBuffer arrow_sound_;

  sf::Font font_;
};

#endif  // BASE_RESOURCES_MANAGER_H_
