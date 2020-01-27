#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "hand.h"
#include <string>

using namespace std;

class player {
  private:
    hand h;
    string name;
  public:
    // must have constructors, destructor, accessor methods, and mutator methods
    player();
    ~player();
    hand get_hand();
    string get_name();
    void set_hand();
    void set_name();
};

#endif
