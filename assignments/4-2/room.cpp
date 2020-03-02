#include "room.h"
#include "event.h"
#include "wumpus.h"
#include "gold.h"
#include "escape.h"
#include "pit.h"
#include "bats.h"

#include <iostream>
#include <string>

using namespace std;
/*******************************************************************
Function:
Description:
********************************************************************/
room::room(){
  arrows = 0;
  reveal = false;
  e.resize(1);
  event empty;
  e[0] = &empty;
}
/*******************************************************************
Function:
Description:
********************************************************************/
int room::ev_encounter(){
  return e[0]->encounter();
}
int room::get_arrows(){
  return arrows;
}
void room::set_arrows(int a){
  arrows = a;
}
bool room::get_reveal(){
  return reveal;
}
void room::set_reveal(bool r){
  reveal = r;
}
event* room::get_event(){
  return e[0];
}
void room::set_event(event &ne){
  e[0] = &ne;
}
char room::get_e_symbol(){
  return e[0]->get_symbol();
}
string room::get_e_percept(){
  return e[0]->get_percept();
}
int room::get_e_encounter(){
  return e[0]->encounter();
}
void room::assign_e_wumpus(){
  wumpus a, &w = a;
  set_event(w);
}
void room::assign_e_escape(){
  escape a, &e = a;
  set_event(e);
}
void room::assign_e_pit(){
  pit a, &p = a;
  set_event(p);
}
void room::assign_e_bats(){
  bats a, &b = a;
  set_event(b);
}
void room::assign_e_gold(){
  gold a, &g = a;
  set_event(g);
}
