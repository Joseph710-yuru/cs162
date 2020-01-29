#include <iostream>
#include "deck.h"
#include <ctime>
#include <cstdlib>


using namespace std;

deck::deck(int num){
  for (int i=1; i < num; i++){
    for (int j=1; j < 5;j++){
      deckofcards[i].set_rank(0);
      deckofcards[i].set_suit(0);
    }
  }
}

void deck::create_deck(int num) {
  int index=0;
  for (int i=0; i < 4; i++){
    for (int j=0; j<13; j++){
      deckofcards[index].set_suit(i+1); //1-4
      deckofcards[index].set_rank(j+1); // 1-13
      index++;
    }
  }
}

void deck::shuffle_deck(int num){
  srand(time(0));
  int r;
  for (int i=0; i < num; i++){
    r = i + (rand() % (52-i));
    swap_cards(deckofcards[i], deckofcards[r]);
  }
}

void deck::print_deck(int num){
  for (int i=0;i<num;i++) {
    cout << deckofcards[i].get_rank() << "\tof\t";
    cout << deckofcards[i].get_suit() << endl;
  }
}

void swap_cards(card &a, card &b){
  card temp_card;
  temp_card = a;
  a = b;
  b = temp_card;
}
