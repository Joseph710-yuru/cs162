#ifndef DECK_H
#define DECK_H

#include "card.h"

class deck {
  private:
    card deckofcards [52];

  public:
    deck(int);
    void create_deck(int);
    void shuffle_deck(int);
    void print_deck(int);
};

#endif
