#include <iostream>
#include <ctime>
#include <cstdlib>
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
 cout << "deck destructor called\n";
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
  int index=0;
  for (int i=0; i < 4; i++){
    for (int j=0; j<13; j++){
      cards[index].set_suit(i+1); //1-4
      cards[index].set_rank(j+1); // 1-13
      index++;
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
  srand(time(0));
  int r;
  for (int i=0; i < num; i++){
    r = i + (rand() % (52-i));
    swap_cards(cards[i], cards[r]);
  }
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
    cout << "rank: " << cards[i].name_rank() << " suit: ";
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
/*******************************************************************
Function: swap_cards()
Description: Swaps the location of a card in an array with another
Parameters: card &, card &
Pre-Conditions:
Post-Conditions: car a has the inital value of b and vice versa
********************************************************************/
void swap_cards(card &a, card &b){
  card temp_card;
  temp_card = a;
  a = b;
  b = temp_card;
}
