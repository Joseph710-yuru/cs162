#ifndef DECK_H
#define DECK_H

#include <iostream>
#include "card.h"

using namespace std;

class deck {
  private:
    card cards[52];
    int n_cards;  // Number of cards remaining in the deck.
  public:
    deck();
    ~deck();
    card get_cards(int);
    void set_cards(int, int, int);
    int get_n_cards();
    void set_n_cards(int);
    void create_deck(int);
    void shuffle_deck();
    void print_deck(int);
    void clean();
};

void swap_cards(card &, card &);
#endif
