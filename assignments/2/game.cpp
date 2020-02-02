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
  while (check_win()!=true){
    take_turn(players[0]);
    take_turn(players[1]);
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
