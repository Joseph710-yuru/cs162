#include <iostream>
#include "deck.h"
#include "card.h"

using namespace std;
/*******************************************************************
Function: deck()
Description: constructor for deck class
Parameters: none
Pre-Conditions: class called
Post-Conditions: initializes a new deck with default member values of 0
********************************************************************/
deck::deck() {
  for (int j=0; j < 52; j++){
    cards[j].set_rank(0);
    cards[j].set_suit(0);
  }
}
/*******************************************************************
Function: ~deck()
Description: destructor for deck class
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
deck::~deck(){

}
/*******************************************************************
Function: create_deck()
Description: Assigns default rank and suit values to each card in the deck
             up to the specified number
Parameters: int num
Pre-Conditions:
Post-Conditions: Each card in the deck has a rank and suit not -1
********************************************************************/
void deck::create_deck(int num) {
  int i = 0, j = 0;
  while (i+j <= num){
    for (i=0; j < 4; j++){
      for (j; j < 13; j++){
        cards[i+j].set_rank(j);
      }
      cards[i+j].set_suit(i);
    }
  }
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void deck::shuffle_deck(int num){

}
/*******************************************************************
Function: print_deck()
Description: print function for the deck of cards
Parameters: none
Pre-Conditions:
Post-Conditions: prints every card in the deck's rank and suit to terminal
********************************************************************/
void deck::print_deck(int num){
  for (int i=0;i<num;i++){
    cout << "rank " << cards[i].name_rank() << " suit: ";
    cout << cards[i].name_suit() << endl;
  }
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
card deck::get_cards() {

}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void deck::set_cards(int index, int rank, int suit){
  cards[index].set_rank(rank);
  cards[index].set_suit(suit);
}
/*******************************************************************
Function: get_n_cards()
Description: accessor for n_cards member variable
Parameters: none
Pre-Conditions:
Post-Conditions: returns value of n_cards
********************************************************************/
int deck::get_n_cards(){
 return n_cards;
}
/*******************************************************************
Function: set_n_cards()
Description: mutator for member variable n_cards
Parameters: int
Pre-Conditions: called with int as parameter
Post-Conditions: assigns n_cards to the value of the int parameter
********************************************************************/
void deck::set_n_cards(int num){
  n_cards = num;
}
