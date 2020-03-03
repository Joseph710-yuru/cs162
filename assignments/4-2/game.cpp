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
#include "empty.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*******************************************************************
Function: game
Description: default constructor for game class
********************************************************************/
game::game(){
  p_y=0;
  p_arrows=3;
  n_rooms=8;

  debug = true;
  alive = true;
  has_gold = false;
  can_flee = false;
  w_alive = true;

  r.resize(n_rooms, vector<room>(n_rooms));
   vector<vector<room>>::iterator row;
   vector<room>::iterator col;
    for (row=r.begin(); row != r.end();++row){
      for (col=row->begin(); col != row->end(); ++col){
        col->set_event(empt);
      }
    }

  assign_events();
  set_starting_location();

  if (debug==true) {
    for (row=r.begin(); row != r.end();++row){
      for (col=row->begin(); col != row->end(); ++col){
        col->set_reveal(true);
      }
    }
  }
}
/**************************************************************
Function:
Description:
***************************************************************/
game::game(int ro, bool de=false){
  p_y=0;
  p_arrows=3;
  n_rooms=ro;

  debug = de;
  alive = true;
  has_gold = true;
  can_flee = false;
  w_alive = true;
  debug = true;
}

/**************************************************************************
                        accessors and mutators
**************************************************************************/
//accessors
/**************************************************************
Function:
Description:
***************************************************************/
int game::get_p_x(){
  return p_x;
}
/**************************************************************
Function:
Description:
***************************************************************/
int game::get_p_y(){
  return p_y;
}
/**************************************************************
Function:
Description:
***************************************************************/
int game::get_n_rooms(){
  return n_rooms;
}
/**************************************************************
Function:
Description:
***************************************************************/
int game::get_p_arrows(){
  return p_arrows;
}
/**************************************************************
Function:
Description:
***************************************************************/
bool game::get_alive(){
  return alive;
}
/**************************************************************
Function:
Description:
***************************************************************/
bool game::get_has_gold(){
  return has_gold;
}
/**************************************************************
Function:
Description:
***************************************************************/
bool game::get_can_flee(){
  return can_flee;
}
/**************************************************************
Function:
Description:
***************************************************************/
bool game::get_w_alive(){
  return w_alive;
}
/**************************************************************
Function:
Description:
***************************************************************/
bool game::get_debug(){
  return debug;
}
//mutators
/**************************************************************
Function:
Description:
***************************************************************/
void game::set_p_x(int x){
  p_x = x;
}
/**************************************************************
Function:
Description:
***************************************************************/
void game::set_p_y(int y){
  p_y = y;
}
/**************************************************************
Function:
Description:
***************************************************************/
void game::set_n_rooms(int n){
  n_rooms = n;
}
/**************************************************************
Function:
Description:
***************************************************************/
void game::set_p_arrows(int a){
  p_arrows = a;
}
/**************************************************************
Function:
Description:
***************************************************************/
void game::set_alive(bool a){
  alive = a;
}
/**************************************************************
Function:
Description:
***************************************************************/
void game::set_has_gold(bool g){
  has_gold = g;
}
/**************************************************************
Function:
Description:
***************************************************************/
void game::set_can_flee(bool f){
  can_flee = f;
}
/**************************************************************
Function:
Description:
***************************************************************/
void game::set_w_alive(bool w){
  w_alive = w;
}
/**************************************************************
Function:
Description:
***************************************************************/
void game::set_debug(bool d){
  debug = d;
}
/**************************************************************************
                              player movement
**************************************************************************/
/**************************************************************
Function:
Description:
***************************************************************/
void game::player_move(){
  int repeat=1;
  char a;
  cout << "Your move: ";
  get_char(a);
  while (repeat==1){
    if (a=='w'||a=='a'||a=='s'||a=='d'||a==' '||a==32){
      if (a =='w') move_north();
      if (a =='a') move_west();
      if (a =='s') move_south();
      if (a =='d') move_east();
      if (a == 32) arrow_direction();
      repeat = 0;
    } else {
      cout << "Your move: ";
      get_char(a);
    }
  }
}
/**************************************************************
Function: move_north()
Description: move player one room north.
***************************************************************/
void game::move_north(){
  if (p_x > 0) p_x -= 1;
  else {
    cout << "You cannot move farther north.\n";
  }
}
/**************************************************************
Function: move_south()
Description: move player one room south
***************************************************************/
void game::move_south(){
  if (p_x < n_rooms-1) p_x += 1;
  else {
    cout << "You cannot move farther south.\n";
  }
}
/**************************************************************
Function: move_east()
Description: moves the player one room east
***************************************************************/
void game::move_east(){
  if (p_y < n_rooms-1) p_y += 1;
  else {
    cout << "You cannot move farther east.\n";
  }
}
/**************************************************************
Function: move_west()
Description: moves the player one room west
***************************************************************/
void game::move_west(){
  if (p_y > 0) p_y -= 1;
  else {
    cout << "You cannot move farther west.\n";
  }
}
/**************************************************************************
                                arrow things
**************************************************************************/
/**************************************************************
Function: arrow_direction
Description: handles which direction you want to fire the arrow
***************************************************************/
void game::arrow_direction(){
  int repeat = 1;
  char d;

  while (repeat==1){
    cout << "direction to fire: ";
    get_char(d);
    if (d=='s') {
      arrow_north();
      repeat = 0;
    } else if (d=='a') {
      arrow_west();
      repeat = 0;
    } else if (d=='w') {
      arrow_south();
      repeat = 0;
    } else if (d=='d') {
      arrow_east();
      repeat = 0;
    } else cout << "Bad direction, try again\n";
  }
}
/**************************************************************
Function: arrow_north
Description: shoots an arrow north
***************************************************************/
void game::arrow_north(){
  void wumpwake();
  for (int i=0; i < n_rooms; ++i){
    if (p_x+i < n_rooms-1){
      r[p_y][p_x+i].set_reveal(true);
      if (killwump(p_y, p_x+i) == true) {
        break;
      }
    } else {
      r[p_y][p_x+i-1].set_arrows(r[p_y][p_x+i-1].get_arrows() + 1);
      break;
    }
  }
}
/**************************************************************
Function: arrow_south
Description: shoots an arrow south
***************************************************************/
void game::arrow_south(){
  void wumpwake();
  for (int i=0; i < n_rooms; ++i){
    if (p_x-i >= 0){
      r[p_y][p_x-i].set_reveal(true);
      if (killwump(p_y, p_x-i) == true) {
        break;
      }
    } else {
      r[p_y][p_x-i+1].set_arrows(r[p_y][p_x-i+1].get_arrows() + 1);
      break;
    }
  }
}
/**************************************************************
Function: arrow_east
Description: shoots an arrow east
***************************************************************/
void game::arrow_east(){
  void wumpwake();
  for (int i=0; i < n_rooms; ++i){
    if (p_y+i < n_rooms){
      r[p_y+i][p_x].set_reveal(true);
      if (killwump(p_y+i, p_x) == true) {
        break;
      }
    } else {
      r[p_y+i-1][p_x].set_arrows(r[p_y+i-1][p_x].get_arrows() + 1);
      break;
    }
  }
}
/**************************************************************
Function: arrow_west
Description: shoots an arrow west
***************************************************************/
void game::arrow_west(){
  void wumpwake();
  for (int i=0; i < n_rooms; ++i){
    if (p_y-i >= 0){
      r[p_y-i][p_x].set_reveal(true);
      if (killwump(p_y-i, p_x) == true) {
        break;
      }
    } else {
      r[p_y-i+1][p_x].set_arrows(r[p_y-i+1][p_x].get_arrows() + 1);
      break;
    }
  }
}
/**************************************************************************
                          event related functions
**************************************************************************/
/**************************************************************
Function:
Description:
***************************************************************/
void game::assign_events(){
  assign_wumpus();
  assign_pit();
  assign_bats();
  assign_gold();
}
/**************************************************************
Function: assign_wumpus
Description: puts the wumpus in a room
***************************************************************/
void game::assign_wumpus(){
  int x=rand() % (n_rooms-1), y=rand() % (n_rooms-1), num=0;
  while (num < 1){
    if (r[y][x].get_e_symbol() == ' ') {
      r[y][x].set_event(w);
      w_x = y;
      w_y = x;
      num++;
    } else {
      x = rand() % (n_rooms-1);
      y = rand() % (n_rooms-1);
    }
  }
}
/**************************************************************
Function: assign_pit
Description: puts the pit in a room
***************************************************************/
void game::assign_pit(){
  int x=rand() % (n_rooms-1), y=rand() % (n_rooms-1), num=0;
  while (num < 1){
    if (r[y][x].get_e_symbol() == ' ') {
      r[y][x].set_event(p);
      num++;
    } else {
      x = rand() % (n_rooms-1);
      y = rand() % (n_rooms-1);
    }
  }
}
/**************************************************************
Function: assign_bats
Description: puts bats in rooms
***************************************************************/
void game::assign_bats(){
  int x=rand() % (n_rooms-1), y=rand() % (n_rooms-1), num=0;
  while (num < 1){
    if (r[y][x].get_e_symbol() == ' ') {
      r[y][x].set_event(b1);
      num++;
    } else {
      x = rand() % (n_rooms-1);
      y = rand() % (n_rooms-1);
    }
  }
  num=0;
  while (num < 1){
    if (r[y][x].get_e_symbol() == ' ') {
      r[y][x].set_event(b2);
      num++;
    } else {
      x = rand() % (n_rooms-1);
      y = rand() % (n_rooms-1);
    }
  }
}
/**************************************************************
Function: assign_gold
Description: puts gold in a room
***************************************************************/
void game::assign_gold(){
  int x=rand() % (n_rooms-1), y=rand() % (n_rooms-1), num=0;
  while (num < 1){
    if (r[y][x].get_e_symbol() == ' ') {
      r[y][x].set_event(g);
      num++;
    } else {
      x = rand() % (n_rooms-1);
      y = rand() % (n_rooms-1);
    }
  }
}
/**************************************************************
Function: post_event
Description: Handles which event effect occurs
***************************************************************/
void game::post_event(int event){
  switch(event) {
    default: break;
    case 0: break;
    case 1: post_bats();
            break;
    case 2: post_gold();
            break;
    case 3: post_wumpit();
            break;
    case 5: post_escape();
            break;
  }
}
/**************************************************************
Function: post_bats
Description: a bunch of bats mess with your player location
***************************************************************/
void game::post_bats(){
  p_x = rand() % (n_rooms-1);
  p_y = rand() % (n_rooms-1);
  if (r[p_y][p_x].get_e_symbol() == 'w')
    post_event(r[p_y][p_x].get_e_encounter());
  if (r[p_y][p_x].get_e_symbol() == 'p')
    post_event(r[p_y][p_x].get_e_encounter());
  if (r[p_y][p_x].get_e_symbol() == 'b')
    post_event(r[p_y][p_x].get_e_encounter());
}
/**************************************************************
Function: post_gold
Description: updates gold private member to reflect the player
             possessing the gold horde.
***************************************************************/
void game::post_gold(){
  has_gold = true;
  r[p_y][p_x].set_event(empt);
}
/**************************************************************
Function: post_wumpus
Description: player walked into a bad room and died
***************************************************************/
void game::post_wumpit(){
  alive = false;
}
/**************************************************************
Function: post_escape
Description: Maybe the player escapes, maybe they dont
***************************************************************/
void game::post_escape(){
  if (alive==true && has_gold == true && w_alive==false){
    can_flee=true;
  }
}
/**************************************************************************
                          Other functions
**************************************************************************/
/**************************************************************
Function: print_map
Description: it prints the map
***************************************************************/
void game::print_map(){
  for (int i=0; i < n_rooms; ++i){
    for (int j=0; j < n_rooms; ++j) cout << "*---";
    cout << "*\n";
    for (int j=0; j < n_rooms; ++j) {
      cout << "| ";
      if (r[j][i].get_arrows() != 0) cout << '^';
      else cout << " ";
      cout << " ";
    }
    cout << "|\n";
    for (int j=0; j < n_rooms; ++j) {
      cout << "| ";
      if (r[j][i].get_reveal()==true) cout << r[j][i].get_e_symbol();
      else cout << " ";
      cout << " ";
    }
    cout << "|\n";
    for (int j=0; j < n_rooms; ++j){
      cout << "| ";
      if (j == p_y && i == p_x) cout << "*";
      else cout << " ";
      cout << " ";
    }
    cout << "|\n";
  }
  for (int j=0; j < n_rooms; ++j) cout << "*---";
  cout << "*\n";
}
/**************************************************************
Function: wumpwake
Description: handles if the wumpus wakes up and moving it
***************************************************************/
void game::wumpwake(){
  int num = rand() % 5;
  int new_x = rand() % (n_rooms - 1), new_y = rand() % (n_rooms - 1);

  if (num < 4){
    cout << "The Wumpus wakes up and walks to another room.\n";
    cout << "The Wumpus falls asleep again.\n";
    if (new_x != p_x && new_y != p_y ){
      if (new_x != w_x || new_y != w_y){
        r[new_x][new_y].set_event(w);
        r[w_x][w_y].set_event(empt);
        w_x = new_x;
        w_y = new_y;
      }
    }
  }
}
/**************************************************************
Function: killwump
Description: checks if your arrow goes through the wumpus room.
             if it does the wumpus dies and the function returns
             true.
***************************************************************/
bool game::killwump(int x, int y){
  if (r[x][y].get_e_symbol() == 'w'){
    r[x][y].set_event(empt);
    cout << "Your arrow pierces the heart of the Wumpus, striking it dead.\n";
    w_alive = false;
    return true;
  } else return false;
}
/**************************************************************
Function: set_starting_location
Description: sets the player starting location
***************************************************************/
void game::set_starting_location(){
  int x=rand() % (n_rooms-1), repeat=0;
  while (repeat==0){
    if (r[p_y][x].get_e_symbol() == ' ') {
      p_x = x;
      repeat = 1;
      r[p_y][p_x].set_event(e);
    } else {
      x=rand() % n_rooms;
    }
  }
}
/**************************************************************
Function:
Description:
***************************************************************/
void game::print_percepts(){
  if (p_y < n_rooms-1 && r[p_y+1][p_x].get_e_symbol() != ' ')
    cout << r[p_y+1][p_x].get_e_percept() << endl;
  if (p_y > 0 && r[p_y-1][p_x].get_e_symbol() != ' ')
    cout << r[p_y-1][p_x].get_e_percept() << endl;
  if (p_x < n_rooms-1 && r[p_y][p_x+1].get_e_symbol() != ' ')
    cout << r[p_y][p_x+1].get_e_percept() << endl;
  if (p_x > 0 && r[p_y][p_x-1].get_e_symbol() != ' ')
    cout << r[p_y][p_x-1].get_e_percept() << endl;
}
/**************************************************************
Function: game_loop
Description: function that loops through user turns, and checks
             for win/loss and calls end_game if either occurs.
***************************************************************/
void game::game_loop(){
  while(can_flee==false && alive==true){
    if (can_flee==false && alive==true){
      turn();
    }
  }
  print_map();
  if (can_flee==true && alive==true) cout << "You've won!\n";
}
/**************************************************************
Function: turn
Description: one turn of the game
***************************************************************/
void game::turn(){
  clear_terminal();
  print_map();
  print_percepts();
  player_move();
  post_event(r[p_y][p_x].get_e_encounter());
}
/**************************************************************
Function: clear_terminal
Description: clears the terminal
***************************************************************/
void game::clear_terminal(){
  cout << "\033[2J";
}
/**************************************************************
Function: get_char
Description: gets a char from the user, checks if it's a char, loops
             until it finally gets the char it so desires
***************************************************************/

void game::get_char(char &a){
  int repeat = 1;
  string temp;
  getline(cin, temp);
  while (repeat == 1) {
    if (cin.fail() == true) {
      cin.clear();
      cin.ignore(1000000000,'\n');
      cout << "\terror: Non-character input\n\tInput an character: ";
      getline(cin, temp);
    } else if (temp[0]>=32 && temp[0] <= 126){
        a = temp[0];
        repeat = 0;
    }
  }
}
