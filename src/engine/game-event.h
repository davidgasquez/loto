// Copyright (c) 2015 Ernesto Alejo and David Gasquez.
// Distributed under the MIT software license, see LICENSE

#ifndef ENGINE_GAME_EVENT_H_
#define ENGINE_GAME_EVENT_H_

enum GameEventType {
  ENEMY_DIED,
  TOWER_PLACED,
  ENEMY_REACHED_CASTLE,
  GAME_OVER,
  VICTORY
};


class GameEvent {
 public:
  explicit GameEvent(GameEventType type)
  : type_(type) { }

  GameEventType type() {
    return type_;
  }

 private:
  GameEventType type_;
};

#endif  // ENGINE_GAME_EVENT_H_
