#include <iostream>
#include "deck.h"
#include "card.h"

using namespace std;
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
deck::deck(int num){
 for (int i=1; i < num; i++){
  for (int j=1; j < 5)
    cards[i].set_rank(0);
    cards[i].set_suit(0);
  }
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
deck::~deck(){

}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void deck::create_deck(int num) {
  for (int i=0; i < num; i++){
    cards[i].set_rank(); // 1-13
    cards[i].set_suit(); // 1-4
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
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void deck::print_deck(int num){
  for (int i=0;i<num;i++){
    cout << cards[i].get_rank() << " of ";
    cout << cards[i].get_suit() << endl;
  }
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
card deck::get_cards(){

}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void deck::set_cards(){

}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
int deck::get_n_cards(){

}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void deck::set_n_cards(int){

}
