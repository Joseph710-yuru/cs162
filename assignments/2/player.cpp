#include <iostream>
#include <string>
#include "player.h"
#include "game.h"

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
void player::take_turn(deck &pile, deck &stock){
  int c,repeat=0;
  card temp;
  while (repeat==0){
    h.print_hand();
    cout << "Play card: ";
    gimmean_int(c);
    temp = h.get_card(c-1);
    if (game::check_rules(temp, ) == true){
      pile.set_cards(pile.get_n_cards()+1, temp.get_rank(), temp.get_suit());
      pile.set_n_cards(pile.get_n_cards() + 1);
      repeat=1;
    } else {
      cout << "Invalid move, try again.\n";
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
/****************************************************************************
Function: gimmean_int()
Description: Takes a ref int as a parameter, has user assign it and checks if that
             bad boi is a real int or not then assigns that value to the ref.
Parameters: int &num
Pre-Conditions: takes integer variable as parameter
Post-Conditions: returns provided integer
***************************************************************************/
void gimmean_int(int &num) {
  int repeat = 1;

  cin >> num;

  while (repeat == 1) {
    if (cin.fail() == true) {
      cin.clear();
      cin.ignore(1000000000,'\n');
      cout << "\tERROR: Non-Integer Input\n\tInput an integer: ";
      cin >> num;
    } else {
      repeat = 0;
    }
  }
}
