#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "deck.h"
#include "player.h"

using namespace std;

class game {
  private:
    deck cards;
    deck pile;
    player players[2];
  public:
    // must have constructors, destructor, accessor methods, and mutator methods
    game();
    ~game();
    const deck get_cards();
    player get_players(int);
    deck set_cards();
    player set_players();
    bool check_win();
    void play_game();
};

string get_string();

#endif
