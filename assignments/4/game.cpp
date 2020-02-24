/*******************************************************************
file: game.cpp
description: implementation for game class
*******************************************************************/
#include "game.h"

#include <iostream>

using namespace std;
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
game::game(){
 rooms = 4;
 arrows = 3;
 player_x = 0;
 player_y = 0;
 debug = 0;

}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
game::game(int a, int b=0){
  rooms = a;
  arrows = 3;
  player_x = 0;
  player_y = 0;
  debug = b;

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
int game::get_player_x(){
  return player_x;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
int game::get_player_y(){
  return player_y;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
int game::get_arrows(){
  return arrows;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void game::set_player_x(int a){
 player_x = a;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void game::set_player_y(int a){
  player_y = a;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void game::set_arrows(int a){
  arrows = a;
}
/*******************************************************************
Function: move_north()
Description:
********************************************************************/
void game::move_north(){
  if (player_y < n_rooms) player_y += 1;
  else cout << "You cannot move further north.\n";
}
/*******************************************************************
Function: move_south()
Description: move player one room south
********************************************************************/
void game::move_south(){
  if (player_y > 0) player_y -= 1;
  else cout << "You cannot move further south.\n";
}
/*******************************************************************
Function: move_east()
Description: moves the player one room east
********************************************************************/
void game::move_east(){
  if (player_y < n_rooms) player_y += 1;
  else cout << "You cannot move further east.\n";
}
/*******************************************************************
Function: move_west()
Description: moves player one room west
********************************************************************/
void game::move_west(){
  if (player_y > 0) player_y -= 1;
  else cout << "You cannot move further west.\n";
}
/*******************************************************************
Function: print_map()
Description: prints the game map out
********************************************************************/
void game::print_map(){
  for (int i = 0; i < 4; ++i){
    for (int j = 0; j < 4; ++j) cout << "+---";
    cout << "+" << endl;
    for (int x=0; x < 3; ++x){
      for (int j=0;j<4;++j) cout << "|   ";
      cout << "|" << endl;
    }
  }
  for (int j = 0; j < 4; ++j) cout << "+---";
  cout << "+" << endl;
}
