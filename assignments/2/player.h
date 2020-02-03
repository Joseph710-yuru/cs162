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
    void set_hand(deck &);
    void set_name(string);
    void play_game();
    void take_turn(deck &, deck &);
    bool can_play(deck);
    int hand_count();
    void auto_turn(deck &, deck &);
    bool empty_hand();
    void play_card(card, deck &, int);
    void increase_hand();
};
void gimmean_int(int &);
#endif
