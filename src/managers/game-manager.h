
#ifndef BASE_GAME_MANAGER_H_
#define BASE_GAME_MANAGER_H_

#include "managers/resources-manager.h"


class GameManager {
public:
  static ResourcesManager* GetResourcesManager();
};

#endif  // BASE_GAME_MANAGER_H_
