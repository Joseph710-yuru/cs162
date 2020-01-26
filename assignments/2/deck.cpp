#include <iostream>
#include "deck.h"

using namespace std;

deck::deck(int num){
 for (int i=1; i < num; i++){
  for (int j=1; j < 5)
    cards[i].set_rank(0);
    cards[i].set_suit(0);
  }
}

void deck::create_deck(int num) {
  for (int i=0; i < num; i++){
    cards[i].set_rank(); // 1-13
    cards[i].set_suit(); // 1-4
  }
}

void deck::shuffle_deck(int num){

}

void deck::print_deck(int num){
  for (int i=0;i<num;i++){
    cout << cards[i].get_rank() << " of ";
    cout << cards[i].get_suit() << endl;
  }
}
