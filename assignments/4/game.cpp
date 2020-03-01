/*******************************************************************
file: game.cpp
description: implementation for game class
*******************************************************************/
#include "game.h"
#include "room.h"
#include "event.h"
#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*******************************************************************
Function: game
Description: default constructor for game class
********************************************************************/
game::game(){
  player_y=0;
  player_x=0;
  rooms = 4;
  arrows = 3;

  debug = false;
  alive = true;
  horde = false;
  escape = false;

  r.resize(rooms, vector<room>(rooms));
  assign_events();
  //set_starting_location();
}
/*******************************************************************
Function: game
Parameters: int ro, int de
Description: builds a game with a custom size and/or allows the
             use of debug mode
********************************************************************/
game::game(int ro=4, bool de=false){
  player_y = 0;
  rooms = ro;
  arrows = 3;

  debug = de;
  alive = true;
  horde = false;
  escape = false;

  r.resize(rooms, vector<room>(rooms));
  assign_events();
  set_starting_location();
  if (debug==true) {
    for (int i=0; i < rooms-1;++i)
      for (int j=0; j < rooms-1;++j)
        r[i][j].set_show(true);
  }
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
Function:
Description:
********************************************************************/
void game::player_move(){

}
/*******************************************************************
Function: move_north()
Description: move player one room north.
********************************************************************/
void game::move_north(){
  if (player_y < rooms) player_y += 1;
  else {
    cout << "You cannot move farther north.\n";
    player_move();
  }
}
/*******************************************************************
Function: move_south()
Description: move player one room south
********************************************************************/
void game::move_south(){
  if (player_y > 0) player_y -= 1;
  else {
    cout << "You cannot move farther south.\n";
    player_move();
  }
}
/*******************************************************************
Function: move_east()
Description: moves the player one room east
********************************************************************/
void game::move_east(){
  if (player_y < rooms) player_y += 1;
  else {
    cout << "You cannot move farther east.\n";
    player_move();
  }
}
/*******************************************************************
Function: move_west()
Description: moves player one room west
********************************************************************/
void game::move_west(){
  if (player_y > 0) player_y -= 1;
  else {
    cout << "You cannot move farther west.\n";
    player_move();
  }
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
  int x=rand() % rooms-1, y=rand() % rooms-1, num=0;
  wumpus w;
  while (num < 1){
    if (r[x][y].get_name() == "undefined") {
      r[x][y].set_event(w);
      num = 1;
    } else {
      x = rand() % rooms-1;
      y = rand() % rooms-1;
    }
  }
}
/*******************************************************************
Function: assign_pit
Description: places a pit in the specified room
********************************************************************/
void game::assign_pit(){
  int x=rand() % rooms-1, y=rand() % rooms-1, num=0;
  pit p;
  while (num < 1){
    if (r[x][y].get_name() == "undefined") {
      r[x][y].set_event(p);
      num = 1;
    } else {
      x = rand() % rooms-1;
      y = rand() % rooms-1;
    }
  }
}
/*******************************************************************
Function: assign_gold
Description: places gold in the assigned room
********************************************************************/
void game::assign_gold(){
  gold g;
  int x=rand() % rooms-1, y=rand() % rooms-1, num=0;

  while (num < 1){
    if (r[x][y].get_name() == "undefined") {
      r[x][y].set_event(g);
      num = 1;
    } else {
      x = rand() % rooms-1;
      y = rand() % rooms-1;
    }
  }
}
/*******************************************************************
Function: assign_bats
Description: places bats in the specified room
********************************************************************/
void game::assign_bats(){
  int x=rand() % rooms-1, y=rand() % rooms-1, num=0;
  bats b;

  while (num < 2){
    if (r[x][y].get_name() == "undefined") {
      r[x][y].set_event(b);
      num++;
    } else {
      x = rand() % rooms-1;
      y = rand() % rooms-1;
    }
  }
}
/*******************************************************************
Function: post_event
Description: Handles which event effect occurs
********************************************************************/
void game::post_event(int event){
  switch(event) {
    case 0: break;
    case 1: post_bats();
            break;
    case 2: post_gold();
            break;
    case 3: post_wumpit();
            break;
  }
}
/*******************************************************************
Function: post_bats
Description: moves player to random room, runs room event and prints percepts
********************************************************************/
void game::post_bats(){
  player_x = rand() % rooms-1;
  player_y = rand() % rooms-1;
  print_map();
  r[player_x][player_y].get_event();
}
/*******************************************************************
Function: post_gold
Description: updates gold private member to reflect the player
             possessing the gold horde.
********************************************************************/
void game::post_gold(){
  horde = true;
}
/*******************************************************************
Function: post_wumpus
Description: player walked into a bad room and died
********************************************************************/
void game::post_wumpit(){
  alive = false;
}
/*******************************************************************
Function:
Description:
********************************************************************/
void game::arrow_direction(char d){
  if (d=='w') arrow_north();
  if (d=='a') arrow_west();
  if (d=='s') arrow_south();
  if (d=='d') arrow_east();
}
/*******************************************************************
Function:
Description:
********************************************************************/
void game::arrow_north(){

}
/*******************************************************************
Function:
Description:
********************************************************************/
void game::arrow_south(){

}
/*******************************************************************
Function:
Description:
********************************************************************/
void game::arrow_east(){

}
/*******************************************************************
Function:
Description:
********************************************************************/
void game::arrow_west(){
  for (int i=0; i < rooms; ++i){
    if (player_x-i >= 0){
      r[player_x-i][player_y].set_show(true);
      if (r[player_x-i][player_y].kill() == true) {
        escape = true;
        break;
      }
    } else {
      r[player_x-i+1][player_y].set_arrow(true);
      arrow_noise(player_x-i+1,player_y);
      break;
    }
  }
}
/*******************************************************************
Function:
Description:
********************************************************************/
void game::arrow_noise(int x, int y){

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
      for (int j=0;j<rooms;++j) {
        cout << "|  ";
        if (player_x==i && player_y == j) cout << "*";
        else cout << " ";
      }
      cout << "|" << endl;
    }
  }
  for (int j = 0; j < rooms; ++j) cout << "+---";
  cout << "+" << endl;
}
/*******************************************************************
Function:
Description:
********************************************************************/
void game::set_starting_location(){
  int x=rand() % rooms-1, repeat=0;
  while (repeat==0){
    if (r[x][player_y].get_name() == "undefined") {
      player_x = x;
      repeat = 1;
    } else {
      x=rand() % rooms-1;
    }
  }

}
/*******************************************************************
Function:
Description:
********************************************************************/
void game::print_percepts(){
  if (player_x < rooms) r[player_x+1][player_y].get_percept();
  if (player_x > 0) r[player_x-1][player_y].get_percept();
  if (player_y < rooms) r[player_x][player_y+1].get_percept();
  if (player_y > 0) r[player_x][player_y-1].get_percept();
}
/*******************************************************************
Function:
Description:
********************************************************************/
bool game::check_win(){
  if (alive==true, horde==true, escape==true) return true;
  else return false;
}
