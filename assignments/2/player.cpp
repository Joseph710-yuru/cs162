#include <iostream>
#include <string>
#include "player.h"

using namespace std;
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
player::player(){

}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
player::~player(){

}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
const hand player::get_hand(){
  return h;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
const string player::get_name(){
  return name;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void player::set_hand(deck &a){
  h.set_cards(a);
}
/*******************************************************************
Function: set_name()
Description: mutator for name member variable
Parameters: string n
Pre-Conditions: accepts string as parameter
Post-Conditions: value of name is changed to the value of n
********************************************************************/
void player::set_name(string n){
  name = n;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void player::take_turn(){
  h.print_hand();
  cout << "Play card: ";


}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
bool player::can_play(deck a){
  card temp1, temp2;
  temp2 = a.get_cards(0);
  for (int i=0; i < h.get_n_cards(); i++){
    temp1 = h.get_card(0);
    if (temp1.get_rank() == 7) return true;
    if (temp1.get_rank() == temp2.get_rank() || temp1.get_suit() == temp2.get_suit()){
      return true;
    }
  }
  return false;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
int player::hand_count(){
  int i = h.get_n_cards();
  return i;
}
