#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "hand.h"

using namespace std;

class player {
  private:
    hand h;
    string name;
  public:
    // must have constructors, destructor, accessor methods, and mutator methods
    player();
    ~player();
    const hand get_hand();
    const string get_name();
    void set_hand();
    void set_name(string);
    void play_game();
};

#endif
