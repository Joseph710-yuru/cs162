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
  p_y=0;
  p_arrows=3;
  n_rooms=4;

  debug = true;
  alive = true;
  has_gold = true;
  can_flee = false;
  w_alive = true;
  debug = true;

  r.resize(n_rooms, vector<room>(n_rooms));
  assign_events();
  set_starting_location();
  if (debug==true) {
    for (int i=0; i < n_rooms-1;++i)
      for (int j=0; j < n_rooms-1;++j)
        r[i][j].set_reveal(true);
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

  r.resize(n_rooms, vector<room>(n_rooms));
  assign_events();
  set_starting_location();
  if (debug==true) {
    for (int i=0; i < n_rooms-1;++i)
      for (int j=0; j < n_rooms-1;++j)
        r[i][j].set_reveal(true);
  }
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
Function:
Description:
***************************************************************/
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
    } else cout << "Bad direction, try again\n";
  }
}

void game::arrow_north(){

}
/**************************************************************
Function:
Description:
***************************************************************/
void game::arrow_south(){}

void game::arrow_east(){}
/**************************************************************
Function:
Description:
***************************************************************/
void game::arrow_west(){
  for (int i=0; i < n_rooms; ++i){
    if (p_x-i >= 0){
      r[p_y][p_x-i].set_reveal(true);
      if (killwump(p_y, p_x-i) == true) {
        break;
      }
    } else {
      r[p_y][p_x-i+1].set_arrows(r[p_y][p_x-i+1].get_arrows() + 1);
      arrow_noise(p_x-i+1,p_y);
      break;
    }
  }
}
/**************************************************************
Function: arrow_noise
Description: if the arrow hits the wall, does it make a noise
***************************************************************/
void game::arrow_noise(int x, int y){
  if (x+1<n_rooms) if (r[x+1][y].get_e_symbol()=='w') wumpwake(x+1, y);
  if (x-1>=0) if (r[x-1][y].get_e_symbol()=='w') wumpwake(x-1, y);
  if (y+1<n_rooms) if (r[x+1][y].get_e_symbol()=='w') wumpwake(x, y+1);
  if (y-1>=0) if (r[x+1][y].get_e_symbol()=='w') wumpwake(x, y-1);
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
Function:
Description:
***************************************************************/
void game::assign_wumpus(){
  int x=rand() % (n_rooms-1), y=rand() % (n_rooms-1), num=0;
  while (num < 1){
    if (r[y][x].get_e_symbol() == ' ') {
      r[y][x].assign_e_wumpus();
      num++;
    } else {
      x = rand() % (n_rooms-1);
      y = rand() % (n_rooms-1);
    }
  }
}
/**************************************************************
Function:
Description:
***************************************************************/
void game::assign_pit(){
  int x=rand() % (n_rooms-1), y=rand() % (n_rooms-1), num=0;
  while (num < 1){
    if (r[y][x].get_e_symbol() == ' ') {
      r[y][x].assign_e_pit();
      num++;
    } else {
      x = rand() % (n_rooms-1);
      y = rand() % (n_rooms-1);
    }
  }
}
/**************************************************************
Function:
Description:
***************************************************************/
void game::assign_bats(){
  int x=rand() % (n_rooms-1), y=rand() % (n_rooms-1), num=0;
  while (num < 2){
    if (r[y][x].get_e_symbol() == ' ') {
      r[y][x].assign_e_bats();
      num++;
    } else {
      x = rand() % (n_rooms-1);
      y = rand() % (n_rooms-1);
    }
  }
}
/**************************************************************
Function:
Description:
***************************************************************/
void game::assign_gold(){
  int x=rand() % (n_rooms-1), y=rand() % (n_rooms-1), num=0;
  while (num < 1){
    if (r[y][x].get_e_symbol() == ' ') {
      r[y][x].assign_e_gold();
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
  clear_terminal();
  print_map();
  post_event(r[p_y][p_x].get_e_encounter());
}
/**************************************************************
Function: post_gold
Description: updates gold private member to reflect the player
             possessing the gold horde.
***************************************************************/
void game::post_gold(){
  has_gold = true;
  event e;
  r[p_y][p_x].set_event(e);
}
/**************************************************************
Function: post_wumpus
Description: player walked into a bad room and died
***************************************************************/
void game::post_wumpit(){
  r[p_y][p_x].get_e_encounter();
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
Function:
Description:
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
Function: print_map
Description: it prints the map
***************************************************************/
void game::wumpwake(int x,int y){
  int num = rand() % 4;
  event e;
  int new_x = rand() % (n_rooms - 1), new_y = rand() % (n_rooms - 1);

  if (num < 4){
    if (new_x != p_x && new_y != p_y ){
      if (new_x != x || new_y != y){
        r[new_x][new_y].assign_e_wumpus();
        r[x][y].set_event(e);
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
      r[p_y][p_x].assign_e_escape();
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
  cout << "in percepts - " << "y: " << p_y << " x: " << p_x << endl;
  if (p_y < n_rooms-1) r[p_y+1][p_x].get_e_percept();
  if (p_y > 0) r[p_y-1][p_x].get_e_percept();
  if (p_x < n_rooms-1) r[p_y][p_x+1].get_e_percept();
  if (p_x > 0) r[p_y][p_x-1].get_e_percept();
}
/**************************************************************
Function: game_loop
Description: function that loops through user turns, and checks
             for win/loss and calls end_game if either occurs.
***************************************************************/
void game::game_loop(){
  while(can_flee==false && alive==true){
    clear_terminal();
    cout << r[p_y][p_x].get_e_encounter() << endl;
    post_event(r[p_y][p_x].get_e_encounter());
    print_map();
    cout << "y: "<< p_y << " x: " << p_x << endl;
    if (can_flee==false && alive==true){
      print_percepts();
      player_move();
    }
  }
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
