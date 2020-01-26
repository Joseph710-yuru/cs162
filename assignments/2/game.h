#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "deck.h"
#include "player.h"

using namespace std;

class Game {
  private:
    Deck cards;
    Player players[2];
  public:
  // must have constructors, destructor, accessor methods, and mutator methods
};
#endif
