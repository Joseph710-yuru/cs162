#include <iostream>
#include "hand.h"

using namespace std;
/*******************************************************************
Function: hand()
Description: default constructor for class hand
Parameters: n/a
Pre-Conditions:
Post-Conditions: object of type hand is constructed
********************************************************************/
hand::hand(){
 n_cards = 7;
 cards = new card[26];
}
/*******************************************************************
Function: hand()
Description: constructor for hand with a parameter of int, incrase you want to
Parameters: int
Pre-Conditions:
Post-Conditions: hand with n_cards and array size of whatever you want
********************************************************************/
hand::hand(int n){
 n_cards = n;
 cards = new card[n_cards];
}
/*******************************************************************
Function: hand::hand()
Description: copy constructor
Parameters: const hand &hand1
Pre-Conditions: you're tryin to copy a hand to another hand
Post-Conditions: non-shallow copy of hand created
********************************************************************/
hand::hand(const hand &hand1){
  this->n_cards = hand1.n_cards;
  this->cards = new card[this->n_cards];
  for (int i=0;i < this->n_cards;i++){
    this->cards[i] = hand1.cards[i];
  }
}
/*******************************************************************
Function: hand::operator=()
Description: assignment operator overload for objects of type hand
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
const hand& hand::operator=(const hand& hand1){
  delete [] this->cards;
  this->n_cards = hand1.n_cards;
  this->cards = new card[this->n_cards];
  for (int i=0;i < this->n_cards;i++){
    this->cards[i] = hand1.cards[i];
  }
  return *this;
}
/*******************************************************************
Function: hand::~hand()
Description: default destructor for hand
Parameters:
Pre-Conditions:
Post-Conditions: deletes the dynamically allocated array within a hand
                 so we dont get a memory leak
********************************************************************/
hand::~hand(){
  delete [] cards;
}
/*******************************************************************
Function: hand::get_cards()
Description: accessor for cards
Parameters: int i, dont remember why i did that but it's there
Pre-Conditions:
Post-Conditions: you've got access, like, total access. Dont call this
********************************************************************/
card* hand::get_cards(int i){
 return cards;
}
/*******************************************************************
Function: hand::get_card()
Description: returns a specific card from your hand, way more useful. maybe.
Parameters: int i
Pre-Conditions: accepts an int as a parameter
Post-Conditions: returns specific card from a hand
********************************************************************/
card hand::get_card(int i){
  return cards[i];
}
/*******************************************************************
Function: hand::set_cards()
Description:: basically an initial draw from deck function
Parameters: deck &a
Pre-Conditions:
Post-Conditions: "all" your cards have real values now
********************************************************************/
card* hand::set_cards(deck &a){
  for (int i=0; i < n_cards; i++){
    card temp_card = a.get_cards(i);
    this->cards[i].set_rank(temp_card.get_rank());
    this->cards[i].set_suit(temp_card.get_suit());
    a.set_cards(i, -1, -1);
    a.clean();
  }
}
/*******************************************************************
Function: get_n_cards()
Description: accessor for n_cards
Parameters: n/a
Pre-Conditions: gets called
Post-Conditions: returns value of n_cards()
********************************************************************/
int hand::get_n_cards(){
  return n_cards;
}
/*******************************************************************
Function: set_n_cards()
Description: changes the value of n_cards
Parameters: int n
Pre-Conditions: accepts int as parameter
Post-Conditions: n_cards changes to the value of n
********************************************************************/
void hand::set_n_cards(int n){
  n_cards = n;
}
/*******************************************************************
Function: print_hand()
Description: prints out the rank and suit of each card in a player's hand
Parameters: n/a
Pre-Conditions:
Post-Conditions: each card in the player's hand is printed to terminal
********************************************************************/
void hand::print_hand(){
  for (int i=0; i < n_cards; i++){
    if (cards[i].get_rank() != -1){
      cout << i+1 << ". " << cards[i].name_rank() << " of ";
      cout << cards[i].name_suit() << endl;
    }
  }
}
/*******************************************************************
Function: clean()  h.set_n_cards(7);
Description: removes "empty" cards from hand
Parameters: n/a
Pre-Conditions:
Post-Conditions: any card with -1 value is removed from hand
                 hand is sorted and n_cards is adjusted
********************************************************************/
void hand::clean(){
  for (int i=0; i < 26; i++){
    if (cards[i].get_rank() == -1 && cards[25].get_rank() != -1){
      if (cards[i].get_rank() == -1) {
        swap_cards(cards[i], cards[25]);
      }
    }
  }
}
/*******************************************************************
Function:draw_cards()
Description: draws cards from deck and puts them into the hand
Parameters: deck &
Pre-Conditions: accepts a deck as a parameter
Post-Conditions:
********************************************************************/
void hand::draw_card(deck &deck){
    set_n_cards(get_n_cards() + 1);
    cards[n_cards] = deck.get_cards(0);
    deck.set_cards(0, -1, -1);
    deck.clean();
    clean();
}
/*******************************************************************
Function: remove_card()
Description: "removes" a card from the hand
Parameters: int i
Pre-Conditions: accepts integer i as parameter
Post-Conditions: sets cards[i] rank & suit to -1
********************************************************************/
void hand::remove_card(int i){
  set_n_cards(get_n_cards() - 1);
  cards[i].set_suit(-1);
  cards[i].set_rank(-1);
  clean();
}
