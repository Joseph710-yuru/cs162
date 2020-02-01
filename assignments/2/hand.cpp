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
card* hand::get_cards(){

}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
card* hand::set_cards(int){

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
