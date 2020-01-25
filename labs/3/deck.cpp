#include <iostream>
#include "deck.h"

using namespace std;

deck::deck(int num){
 for (int i=1; i < num; i++){
  for (int j=1; j < 5)
    deckofcards[i].set_rank(0);
    deckofcards[i].set_suit(0);
  }
}

void deck::create_deck(int num) {
  for (int i=0; i < num; i++){
    deckofcards[i].set_rank(); // 1-13
    deckofcards[i].set_suit(); // 1-4
  }
}

void deck::shuffle_deck(int num){

}

void deck::print_deck(int num){
  for (int i=0;i<num;i++){
    cout << deckofcards[i].get_rank() << " of ";
    cout << deckofcards[i].get_suit() << endl;
  }
}
