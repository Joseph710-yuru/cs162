#include <iostream>
#include "game.h"

using namespace std;
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
game::game(){
  players[0].set_name(get_string());
  players[1].set_name("Computer");
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
game::~game(){

}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
const deck game::get_cards(){
  return cards;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
player game::get_players(int i){
  if (i>=0 && i < 2){
    return players[i];
  }
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
deck game::set_cards(){

}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
player game::set_players(){

}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void game::play_game(){
  cout << players[0].get_name() << " goes first.\n";
  while (check_win()!=true){
    players[0].take_turn(pile, cards);
    pile.print_top();
    players[1].auto_turn(pile, cards);
    pile.print_top();
  }
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
string get_string(){
  string temp;
  cout << "Set player Name: ";
  cin >> temp;
  return temp;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
bool game::check_win(){
  if (cards.can_draw() == false) {
    if (players[0].can_play(pile) || players[1].can_play(pile) == true){
      return false;
    } else {
      if (players[0].hand_count() > players[1].hand_count()) cout << "Player wins!\n";
      else cout << "Computer wins!\n";
      return true;
    }
  } else if (players[0].empty_hand()==true) {
    cout << players[0].get_name() << " wins!\n";
  } else if (players[1].empty_hand()==true) {
    cout << "Computer wins!\n";
    return true;
  }
}
