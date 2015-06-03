
#ifndef ENGINE_GAME_EVENT_H_
#define ENGINE_GAME_EVENT_H_

enum GameEventType {
  ENEMY_DIED,
  TOWER_PLACED,
  ENEMY_REACHED_CASTLE
};


class GameEvent {
 public:
  GameEvent(GameEventType type)
  : type_(type) { }

  GameEventType type() {
    return type_;
  }

 private:
  GameEventType type_;
};

#endif  // ENGINE_GAME_EVENT_H_
