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
    cards[j].set_rank(-1);
    cards[j].set_suit(-1);
  }
  n_cards = 52;
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
  int index=0;
  for (int i=0; i < 4; i++){
    for (int j=0; j<13; j++){
      cards[index].set_suit(i); //1-4
      cards[index].set_rank(j); // 1-13
      index++;
    }
  }
}
/*******************************************************************
Function: deck::shuffle_deck()
Description: shuffles the deck
Parameters: n/a
Pre-Conditions: gets called
Post-Conditions: cards array is put into a random order
********************************************************************/
void deck::shuffle_deck(){
  srand(time(0));
  int r;
  for (int i=0; i < 52; i++){
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
    if (cards[i].get_rank() < 0 || cards[i].get_rank() > 13){
      i++;
    } else {
      cout << cards[i].name_rank() << " of ";
      cout << cards[i].name_suit() << endl;
    }
  }
}
/*******************************************************************
Function: deck::get_cards()
Description: returns specifc card
Parameters: int
Pre-Conditions: called with valid int
Post-Conditions: returns a single card from a card array.
********************************************************************/
card deck::get_cards(int i) {
  return cards[i];
}
/*******************************************************************
Function: deck::set_cards()
Description: sets a specific card's rank and suit
Parameters: int, int, int
Pre-Conditions: gets called with 3 valid ints
Post-Conditions: card rank and suit is changed
********************************************************************/
void deck::set_cards(int index, int rank, int suit){
  cards[index].set_rank(rank);
  cards[index].set_suit(suit);
}
/*******************************************************************
Function: deck::get_n_cards()
Description: accessor for n_cards member variable
Parameters: none
Pre-Conditions:
Post-Conditions: returns value of n_cards
********************************************************************/
int deck::get_n_cards(){
 return n_cards;
}
/*******************************************************************
Function: deck::set_n_cards()
Description: mutator for member variable n_cards
Parameters: int
Pre-Conditions: called with int as parameter
Post-Conditions: assigns n_cards to the value of the int parameter
********************************************************************/
void deck::set_n_cards(int num){
  n_cards = num;
}
/*******************************************************************
Function: deck::swap_cards()
Description: Swaps the location of a card in an array with another
Parameters: card &, card &
Pre-Conditions:
Post-Conditions: card a has the inital value of b and vice versa
********************************************************************/
void swap_cards(card &a, card &b){
  card temp_card;
  temp_card = a;
  //if (temp_card.get_rank() != NULL){
    a = b;
    b = temp_card;
//  }
}
/*******************************************************************
Function: deck::clean()
Description: moves cards without rank to end of array and decrements n_cards
Parameters: n/a
Pre-Conditions: yous call it
Post-Conditions: all cards with rank moved to end of cards array and get_n_cards
                 decremented to reflect number of valid cards left in deck.
********************************************************************/
void deck::clean(){
  for (int i=0; i < n_cards; i++){
    if (cards[i].get_rank() == -1){
      swap_cards(cards[i], cards[n_cards - 1]);
      set_n_cards(get_n_cards() - 1);
    }
  }
}
/*******************************************************************
Function: can_draw()
Description: returns true or false if there are valid cards left to draw
Parameters: n/a
Pre-Conditions: ya call the dang ol' thing
Post-Conditions: true if there is a card left to draw, otherwise false
********************************************************************/
bool deck::can_draw() {
  if (cards[0].get_rank() == -1) {
    return false;
  } else {
    return true;
  }
}
/*******************************************************************
Function: print_top()
Description: print "top" card
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void deck::print_top(){
  if (cards[n_cards-1].get_rank() == -1){
    cout << "uninitialized\n";
  } else {
    cout << cards[n_cards-1].name_rank() << " of ";
    cout << cards[n_cards-1].name_suit() << endl;
  }
}
