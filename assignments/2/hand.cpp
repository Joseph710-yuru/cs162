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
card* hand::get_cards(int){
 return cards;
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
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
int hand::get_n_cards(){

}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
int hand::set_n_cards(){

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
      cout << i+1 << ". " << cards[i].get_rank() << " of ";
      cout << cards[i].get_suit() << endl;
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
      n_cards--;
    }
  }
}
/*******************************************************************
Function: num_draw()
Description: get the number of cards to draw to fill hand
Parameters: n/a
Pre-Conditions:
Post-Conditions: returns int number that corresponds to amount of cards with
                 rank of -1 in hand.
********************************************************************/
int hand::num_draw(){
  int num=0;
  for (int i=0; i < 7; i++){
    if (cards[i].get_rank() == -1){
      num++;
    }
  }
  return num;
}
/*******************************************************************
Function:draw_cards()
Description: draws cards from deck and puts them into the hand
Parameters: deck &
Pre-Conditions: accepts a deck as a parameter
Post-Conditions:
********************************************************************/
void draw_cards(int num, deck &deck){
  for (int i=0; i < num; i++){
    cards[n_cards+i] = deck.get_cards(i);
    deck.set_cards(i, -1, -1);
    deck.clean();
  }
}
