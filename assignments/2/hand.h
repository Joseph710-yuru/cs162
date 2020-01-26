#ifndef HAND_H
#define HAND_H

#include <iostream>
#include "card.h"

class hand {
  private:
    card* cards;
    int n_cards;  // Number of cards in the hand.
  public:
    // must have constructors, destructor, accessor methods, and mutator methods
    hand();
    ~hand();
    card* get_cards();
    card* set_cards(int);
    int get_n_cards();
    int set_n_cards();
};

#endif
