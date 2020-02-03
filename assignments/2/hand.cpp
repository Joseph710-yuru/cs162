#include <iostream>
#include "hand.h"

using namespace std;
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
hand::hand(){
 n_cards = 7;
 cards = new card[n_cards];
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
hand::hand(const hand &hand1){
  this->n_cards = hand1.n_cards;
  this->cards = new card[this->n_cards];
  for (int i=0;i < this->n_cards;i++){
    this->cards[i] = hand1.cards[i];
  }
}
/*******************************************************************
Function:
Description:
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
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
hand::~hand(){
  delete [] cards;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
card* hand::get_cards(int i){
 return cards;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
card hand::get_card(int i){
  return cards[i];
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
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
Function: clean()
Description: removes "empty" cards from hand
Parameters: n/a
Pre-Conditions:
Post-Conditions: any card with -1 value is removed from hand
                 hand is sorted and n_cards is adjusted
********************************************************************/
void hand::clean(){
  for (int i=0; i < n_cards; i++){
    if (cards[i].get_rank() == -1) {
      swap_cards(cards[i], cards[n_cards]);
      set_n_cards(get_n_cards() - 1);
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
void hand::draw_cards(int num, deck &deck){
  for (int i=0; i < num; i++){
    cards[n_cards + i] = deck.get_cards(i);
    deck.set_cards(i, -1, -1);
    deck.clean();
    if (n_cards + i > n_cards){
      n_cards = n_cards + i;
    }
  }
}
/*******************************************************************
Function: remove_card()
Description: "removes" a card from the hand
Parameters: int i
Pre-Conditions: accepts integer i as parameter
Post-Conditions: sets card[i] rank & suit to -1
********************************************************************/
void hand::remove_card(int i){
  cards[i].set_suit(-1);
  cards[i].set_rank(-1);
  n_cards--;
}
