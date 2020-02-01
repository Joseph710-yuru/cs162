#include <iostream>
#include "card.h"

using namespace std;
/*******************************************************************
Function: card()
Description: constructor for card class
Parameters: none
Pre-Conditions:
Post-Conditions: sets initial values of rank and suit to -1
********************************************************************/
card::card(){
  rank = -1;
  suit = -1;
}
/*******************************************************************
Function: ~card()
Description: destructor for card class
Parameters: none
Pre-Conditions:
Post-Conditions:
********************************************************************/
card::~card(){

}
/*******************************************************************
Function: get_rank()
Description: accessor for card member rank
Parameters: none
Pre-Conditions:
Post-Conditions: return rank value
********************************************************************/
int card::get_rank(){
  return rank;
}
/*******************************************************************
Function: get_suit()
Description: accessor for card member suit
Parameters: none
Pre-Conditions:
Post-Conditions: return suit value
********************************************************************/
int card::get_suit(){
  return suit;
}
/*******************************************************************
Function: set_rank()
Description: mutator for card member rank
Parameters: int
Pre-Conditions: called with int as parameter
Post-Conditions: assigns member variable rank to value of int parameter
                 within a specified range.
********************************************************************/
void card::set_rank(int num){
  if (num >= 0 && num < 12){
    rank = num;
  }
}
/*******************************************************************
Function: set_suit()
Description: mutator for card member variable suit
Parameters: int
Pre-Conditions: called with int as parameter
Post-Conditions: assigns member variable suit to value of int parameter
                 within a specified range.
********************************************************************/
void card::set_suit(int num){
  if (num>=0 && num <4){
    suit = num;
  }
}
/*******************************************************************
Function: name_suit()
Description: Gives a string equivalent to the int value of suit. Used for
             readability.
Parameters: none
Pre-Conditions:
Post-Conditions: returns one of four names for their respective suit value
********************************************************************/
string card::name_suit(){
  if (suit==0){
    return "Clubs";
  } else if (suit == 1) {
    return "Spades";
  } else if (suit == 2) {
    return "Hearts";
  } else if (suit == 3) {
    return "Diamonds";
  }
}
/*******************************************************************
Function: name_rank()
Description: Gives a named equivalent to the int value of rank. Used for
             readability.
Parameters: none
Pre-Conditions:
Post-Conditions: returns the name respective to rank value.
********************************************************************/
string card::name_rank(){
  if (rank > 0 && rank < 10){
    return to_string(rank);
  } else if (rank == 0){
    return "Ace";
  }else if (rank == 10){
    return "Jack";
  } else if (rank == 11){
    return "Queen";
  } else if (rank == 12){
    return "King";
  } else if (rank < 10 && rank > 0) {
    return to_string(rank + 1);
  }
}
