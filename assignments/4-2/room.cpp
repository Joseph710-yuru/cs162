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
  e = nullptr;
}
/*******************************************************************
Function:
Description:
********************************************************************/
int room::ev_encounter(){
  return e->encounter();
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
  return e;
}
void room::set_event(event &ne){
  e = &ne;
}
char room::get_e_symbol(){
  return e->get_symbol();
}
string room::get_e_percept(){
  return e->get_percept();
}
int room::get_e_encounter(){
  return e->encounter();
}
