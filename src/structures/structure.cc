
#include "structures/structure.h"

#include "base/debug.h"


Structure::Structure()
  : life_(0), damage_(0), attack_speed_(0) {
  // empty
}

Structure::~Structure() {
  // empty
}

void Structure::Step(sf::Time elapsed) {
  // empty
}
