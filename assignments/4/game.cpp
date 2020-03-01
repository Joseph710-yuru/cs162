/*******************************************************************
file: game.cpp
description: implementation for game class
*******************************************************************/
#include "game.h"
#include "room.h"
#include "event.h"
#include "wumpus.h"
#include "bats.h"
#include "pit.h"
#include "gold.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*******************************************************************
Function: game
Description: default constructor for game class
********************************************************************/
game::game(){
  player_x = 0;
  player_y = 0;
  alive = 1;
  rooms = 4;
  debug = false;
  arrows = 3;

  r.resize(rooms, vector<room>(rooms));
  assign_events();
}
/*******************************************************************
Function: game
Parameters: int ro, int de
Description: builds a game with a custom size and/or allows the
             use of debug mode
********************************************************************/
game::game(int ro=4, bool de=false){
  player_x = 0;
  player_y = 0;
  alive = 1;
  rooms = ro;
  debug = de;
  arrows = 3;

  r.resize(rooms, vector<room>(rooms));
  assign_events();
}
/*******************************************************************
Function:
Description:
********************************************************************/
game::~game(){

}
/*******************************************************************
Function:
Description:
********************************************************************/
int game::get_player_x(){
  return player_x;
}
/*******************************************************************
Function:
Description:
********************************************************************/
int game::get_player_y(){
  return player_y;
}
/*******************************************************************
Function:
Description:
********************************************************************/
int game::get_arrows(){
  return arrows;
}
/*******************************************************************
Function:
Description:
********************************************************************/
int game::get_rooms(){
  return rooms;
}
/*******************************************************************
Function:
Description:
********************************************************************/
bool game::get_debug(){
  return debug;
}
/*******************************************************************
Function:
Description:
********************************************************************/
void game::set_player_x(int a){
 player_x = a;
}
/*******************************************************************
Function:
Description:
********************************************************************/
void game::set_player_y(int a){
  player_y = a;
}
/*******************************************************************
Function:
Description:
********************************************************************/
void game::set_arrows(int a){
  arrows = a;
}
/*******************************************************************
Function:
Description:
********************************************************************/
void game::set_rooms(int r){
  rooms = r;
}
/*******************************************************************
Function:
Description:
********************************************************************/
void game::set_debug(bool d){
  debug = d;
}
/*******************************************************************
Function: move_north()
Description:
********************************************************************/
void game::move_north(){
  if (player_y < rooms) player_y += 1;
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
  if (player_y < rooms) player_y += 1;
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
Function: assign_events
Description: Places all required events onto the game map
********************************************************************/
void game::assign_events(){
  assign_wumpus();
  assign_bats();
  assign_pit();
  assign_gold();
}
/*******************************************************************
Function: assign_wumpus
Description: places a wumpus in specified room
********************************************************************/
void game::assign_wumpus(){
  int x, y, num=0;
  wumpus w;
  while (num < 1){
    if (r[x][y].contain() != "empty") {
      r[x][y].set_event(w);
      num = 1;
    } else {
      x = rand() % rooms;
      y = rand() % rooms;
    }
  }
}
/*******************************************************************
Function: assign_pit
Description: places a pit in the specified room
********************************************************************/
void game::assign_pit(){
  int x, y, num=0;
  pit p;
  while (num < 1){
    if (r[x][y].contain() != "empty") {
      r[x][y].set_event(p);
      num = 1;
    } else {
      x = rand() % rooms;
      y = rand() % rooms;
    }
  }
}
/*******************************************************************
Function: assign_bats
Description: places bats in the specified room
********************************************************************/
void game::assign_bats(){
  int x, y, num=0;
  bats b;

  while (num < 2){
    if (r[x][y].contain() != "empty") {
      r[x][y].set_event(b);
      num++;
    } else {
      x = rand() % rooms;
      y = rand() % rooms;
    }
  }
}
/*******************************************************************
Function: assign_gold
Description: places gold in the assigned room
********************************************************************/
void game::assign_gold(){
  int x, y, num=0;
  gold g;
  while (num < 1){
    if (r[x][y].contain() != "empty") {
      r[x][y].set_event(g);
      num = 1;
    } else {
      x = rand() % rooms;
      y = rand() % rooms;
    }
  }
}
/*******************************************************************
Function: print_map()
Description: prints the game map out
********************************************************************/
void game::print_map(){
  for (int i = 0; i < rooms; ++i){
    for (int j = 0; j < rooms; ++j) cout << "+---";
    cout << "+" << endl;
    for (int x=0; x < rooms-1; ++x){
      for (int j=0;j<rooms;++j) cout << "|   ";
      cout << "|" << endl;
    }
  }
  for (int j = 0; j < rooms; ++j) cout << "+---";
  cout << "+" << endl;
}
