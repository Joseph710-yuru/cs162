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
#include "escape.h"

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
  rooms = 4;
  arrows = 3;

  debug = true;
  alive = true;
  horde = false;
  flee = false;
  walive = true;

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
Function: game
Parameters: int ro, int de
Description: builds a game with a custom size and allows the
             use of debug mode
********************************************************************/
game::game(int ro, bool de=false){
  player_y = 0;
  rooms = ro;
  arrows = 3;

  debug = de;
  alive = true;
  horde = false;
  flee = false;
  walive = true;

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
  int repeat=1;
  char a;
  cout << "Your move: ";
  get_char(a);
  while (repeat==1){
    if (a=='w'||a=='a'||a=='s'||a=='d'||a==' '){
      if (a =='w') move_north();
      if (a =='a') move_west();
      if (a =='s') move_south();
      if (a =='d') move_east();
      if (a == ' ') arrow_direction();
      repeat = 0;
    } else {
      cout << "Your move: ";
      get_char(a);
    }
  }
}
/*******************************************************************
Function: move_north()
Description: move player one room north.
********************************************************************/
void game::move_north(){
  if (player_x > 0) player_x -= 1;
  else {
    cout << "You cannot move farther north.\n";
  }
}
/*******************************************************************
Function: move_south()
Description: move player one room south
********************************************************************/
void game::move_south(){
  if (player_x < rooms-1) player_x += 1;
  else {
    cout << "You cannot move farther south.\n";
  }
}
/*******************************************************************
Function: move_east()
Description: moves the player one room east
********************************************************************/
void game::move_east(){
  if (player_y < rooms-1) player_y += 1;
  else {
    cout << "You cannot move farther east.\n";
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
  int x=rand() % (rooms-1), y=rand() % (rooms-1), num=0;
  while (num < 1){
    if (r[y][x].get_symbol() == ' ') {
      r[y][x].assign_wumpus();
      num = 10;
    } else {
      x = rand() % (rooms-1);
      y = rand() % (rooms-1);
    }
  }
}
/*******************************************************************
Function: assign_pit
Description: places a pit in the specified room
********************************************************************/
void game::assign_pit(){
  int x=rand() % (rooms-1), y=rand() % (rooms-1), num=0;
  while (num < 1){
    if (r[y][x].get_symbol() == ' ') {
      r[y][x].assign_pit();
      num = 1;
    } else {
      x = rand() % (rooms-1);
      y = rand() % (rooms-1);
    }
  }
}
/*******************************************************************
Function: assign_gold
Description: places gold in the assigned room
********************************************************************/
void game::assign_gold(){
  int x=rand() % (rooms-1), y=rand() % (rooms-1), num=0;
  while (num < 1){
    if (r[y][x].get_name() == "undefined") {
      r[y][x].assign_gold();
      num = 1;
    } else {
      x = rand() % (rooms-1);
      y = rand() % (rooms-1);
    }
  }
}
/*******************************************************************
Function: assign_bats
Description: places bats in the specified room
********************************************************************/
void game::assign_bats(){
  int x=rand() % (rooms-1), y=rand() % (rooms-1), num=0;
  while (num < 2){
    if (r[y][x].get_name() == "undefined") {
      r[y][x].assign_bats();
      num++;
    } else {
      x = rand() % (rooms-1);
      y = rand() % (rooms-1);
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
    case 4: post_escape();
            break;
  }
}
/*******************************************************************
Function: post_event
Description: Handles which event effect occurs
********************************************************************/
void game::post_escape(){
  if (alive==true && horde == true && walive==false){
    flee=true;
  }
}
/*******************************************************************
Function: post_bats
Description: moves player to random room, runs room event and prints percepts
********************************************************************/
void game::post_bats(){
  event temp = r[player_y][player_x].get_event();
  temp.encounter();
  player_x = rand() % (rooms-1);
  player_y = rand() % (rooms-1);
  clear_terminal();
  print_map();
  post_event(r[player_y][player_x].get_ent());
}
/*******************************************************************
Function: post_gold
Description: updates gold private member to reflect the player
             possessing the gold horde.
********************************************************************/
void game::post_gold(){
  horde = true;
  r[player_y][player_x].assign_empty();
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
void game::arrow_direction(){
  int repeat = 1;
  char d;
  while (repeat==1){
    cout << "direction to fire: ";
    get_char(d);

    if (d=='w') {
      arrow_north();
      repeat = 0;
    } else if (d=='a') {
      arrow_west();
      repeat = 0;
    } else if (d=='s') {
      arrow_south();
      repeat = 0;
    } else if (d=='d') {
      arrow_east();
      repeat = 0;
    }  else cout << "Bad direction, try again\n";
  }
}
/*******************************************************************
Function:
Description:
********************************************************************/
void game::arrow_north(){
  for (int i=0; i < rooms; ++i){
    if (player_y-i >= 0){
      r[player_y-i][player_x].set_show(true);
      if (r[player_y-i][player_x].kill() == true) {
        break;
      }
    } else {
      r[player_y-i+1][player_x].set_arrow(true);
      arrow_noise(player_x-i+1,player_y);
      break;
    }
  }
}
/*******************************************************************
Function:
Description:
********************************************************************/
void game::arrow_south(){
  for (int i=0; i < rooms; ++i){
    if (player_y+i >= 0){
      r[player_y+i][player_x].set_show(true);
      if (r[player_y+i][player_x].kill() == true) {
        break;
      }
    } else {
      r[player_y-i-1][player_x].set_arrow(true);
      arrow_noise(player_y-i+1,player_x);
      break;
    }
  }
}
/*******************************************************************
Function:
Description:
********************************************************************/
void game::arrow_east(){
  for (int i=0; i < rooms; ++i){
    if (player_x+i >= 0){
      r[player_y][player_x+i].set_show(true);
      if (r[player_y][player_x+i].kill() == true) {
        break;
      }
    } else {
      r[player_y][player_x+i-1].set_arrow(true);
      arrow_noise(player_y,player_x+i-1);
      break;
    }
  }
}
/*******************************************************************
Function:
Description:
********************************************************************/
void game::arrow_west(){
  for (int i=0; i < rooms; ++i){
    if (player_x-i >= 0){
      r[player_y][player_x-i].set_show(true);
      if (r[player_x-i][player_y].kill() == true) {
        break;
      }
    } else {
      r[player_y][player_x-i+1].set_arrow(true);
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
  if (x+1<rooms) if (r[x+1][y].get_name()=="wumpus") wumpywakey(x+1, y);
  if (x-1>=0) if (r[x-1][y].get_name()=="wumpus") wumpywakey(x-1, y);
  if (y+1<rooms) if (r[x+1][y].get_name()=="wumpus") wumpywakey(x, y+1);
  if (y-1>=0) if (r[x+1][y].get_name()=="wumpus") wumpywakey(x, y-1);
}
/*******************************************************************
Function: print_map()
Description: prints the game map out
********************************************************************/
void game::print_map(){
  for (int i=0; i < rooms; ++i){
    for (int j=0; j < rooms; ++j) cout << "*---";
    cout << "*\n";
    for (int j=0; j < rooms; ++j) {
      cout << "| ";
      if (r[j][i].get_arrow()==true) cout << '^';
      else cout << " ";
      cout << " ";
    }
    cout << "|\n";
    for (int j=0; j < rooms; ++j) {
      cout << "| ";
      if (r[j][i].get_show()==true) cout << r[j][i].get_symbol();
      else cout << " ";
      cout << " ";
    }
    cout << "|\n";
    for (int j=0; j < rooms; ++j){
      cout << "| ";
      if (j == player_y && i == player_x) cout << "*";
      else cout << " ";
      cout << " ";
    }
    cout << "|\n";
  }
  for (int j=0; j < rooms; ++j) cout << "*---";
  cout << "*\n";
}
/*******************************************************************
Function:
Description:
********************************************************************/
void game::set_starting_location(){
  int x=rand() % (rooms-1), repeat=0;
  while (repeat==0){
    if (r[player_y][x].get_name() == "undefined") {
      player_x = x;
      repeat = 1;
      r[player_y][player_x].assign_escape();
    } else {
      x=rand() % rooms;
    }
  }
}
/*******************************************************************
Function:
Description:
********************************************************************/
void game::print_percepts(){
  if (player_y < rooms-1) r[player_y+1][player_x].get_percept();
  if (player_y > 0) r[player_y-1][player_x].get_percept();
  if (player_x < rooms-1) r[player_y][player_x+1].get_percept();
  if (player_x > 0) r[player_y][player_x-1].get_percept();
}
/*******************************************************************
Function: game_loop
Description: function that loops through user turns, and checks
             for win/loss and calls end_game if either occurs.
********************************************************************/
void game::game_loop(){
  event temp;
  while(flee==false && alive==true){
    clear_terminal();
    print_map();
    post_event(r[player_y][player_x].get_ent());
    if (flee==false && alive==true){
      print_percepts();
      player_move();
    }
  }
}
/*******************************************************************
Function: clear_terminal
Description: clears the terminal
********************************************************************/
void game::clear_terminal(){
  cout << "\033[2J";
}
/*******************************************************************
Function: wumpywakey
Description: wumpus wakes up and moves rooms
********************************************************************/
void game::wumpywakey(int x, int y){
  int new_x = rand() % (rooms-1), new_y = rand() % (rooms-1);

  r[x][y].assign_empty();
  if (new_x != player_x && new_y != player_y)
    if (new_x != x && new_y != y)
      r[x][y].assign_wumpus();
}
/*******************************************************************
Function: get_char
Description: gets a char from the user, checks if it's a char, loops
             until it finally gets the char it so desires
********************************************************************/
void game::get_char(char &a){
  int repeat = 1;

  cin >> a;

  while (repeat == 1) {
    if (cin.fail() == true) {
      cin.clear();
      cin.ignore(1000000000,'\n');
      cout << "\terror: Non-character input\n\tInput an character: ";
      cin >> a;
    } else {
      repeat = 0;
    }
  }
}
