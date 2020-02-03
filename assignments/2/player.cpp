#include <iostream>
#include <string>
#include "player.h"
#include "game.h"
#include "card.h"

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
  card temp_card;
  while (repeat==0){
    cout << get_name() << "'s turn\nYour hand:\n";
    h.print_hand();
    cout << "Play card (1 - " << h.get_n_cards() << "): ";
    gimmean_int(c);
    temp_card = h.get_card(c-1);
    if (check_rules(temp_card, pile) == true){
      pile.set_cards(pile.get_n_cards()+1, temp_card.get_rank(), temp_card.get_suit());
      pile.set_n_cards(pile.get_n_cards() + 1);
      h.remove_card(c-1);
      h.clean();
      repeat=1;
    } else {
      cout << "Error: Invalid move, try again.\n";
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
void player::auto_turn(deck &pile, deck &stock){
  card temp_card = pile.get_card(0);
  for (int i=0; i < h.get_n_cards(); i++){
    if (h[i].get_suit() == temp_card.get_suit()){
      play_card(h[i], pile);
      h.remove_card(i);
      h.clean();
      draw_card(h, stock);
    } else if (h[i].get_rank() == temp_card.get_rank()){
      play_card(h[i], pile);
      h.remove_card(i);
      h.clean();
      draw_card(h, stock);
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
void player::play_card(card c, deck &pile){

}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void player::draw_card(hand &h, deck &stock){
  h.draw_cards(1, stock);
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
    temp1 = h.get_card(i);
    if (temp1.get_rank() == 7) return true;
    if (temp1.get_rank() == temp2.get_rank() || temp1.get_suit() == temp2.get_suit()){
      return true;
    }
  }
  return false;
}
/*******************************************************************
Function: hand_count()
Description: just get_n_cards, but up another level
Parameters: n/a
Pre-Conditions:
Post-Conditions: return number of cards in player's hand
********************************************************************/
int player::hand_count(){
  int i = h.get_n_cards();
  return i;
}
/*******************************************************************
Function: empty_hand()
Description: returns true/false if player hand is empty or not.
Parameters:
Pre-Conditions:
Post-Conditions: returns true if player hand is empty, false otherwise.
********************************************************************/
bool player::empty_hand(){
  if (h.get_n_cards() == 0) return true;
  else return false;
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
/*******************************************************************
Function: check_rules()
Description: checks if a play is valid
Parameters: card play, deck pile
Pre-Conditions: called with two cards as parameters
Post-Conditions: returns true if play is valid, false otherwise
********************************************************************/
bool check_rules(card play, deck &pile){
  card top_pile = pile.get_cards(0);
  if (play.get_rank() == top_pile.get_rank()) return true;
  else if (play.get_suit() == top_pile.get_suit()) return true;
  else if (play.get_rank() == 8) return true;
  else if (top_pile.get_rank() == -1) return true; // should just be the instance of an empty pile
  else return false;
}
