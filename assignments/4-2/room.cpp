/*******************************************************************
file: room.cpp
description: implementation for room class
*******************************************************************/
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
Function: room
Description: default constructor for room type
********************************************************************/
room::room(){
  arrows = 0;
  reveal = false;
  e = nullptr;
}
/*******************************************************************
Function: ev_encounter
Description: returns the room's event's encounter
********************************************************************/
int room::ev_encounter(){
  return e->encounter();
}
/*******************************************************************
Function: get_arrows()
Description: accessor for arrows
********************************************************************/
int room::get_arrows(){
  return arrows;
}
/*******************************************************************
Function: set_arrows
Description: mutator for arrows
********************************************************************/
void room::set_arrows(int a){
  arrows = a;
}
/*******************************************************************
Function: get_reveal
Description: accessor for reveal
********************************************************************/
bool room::get_reveal(){
  return reveal;
}
/*******************************************************************
Function: set_reveal
Parameter: bool
Description: mutator for reveal
********************************************************************/
void room::set_reveal(bool r){
  reveal = r;
}
/*******************************************************************
Function: get_event
Description: accessor for event
********************************************************************/
event* room::get_event(){
  return e;
}
/*******************************************************************
Function: set_event
parameter: event &
Description: mutator for event type
********************************************************************/
void room::set_event(event &ne){
  e = &ne;
}
/*******************************************************************
Function: get_e_symbol
Description: accessor for room's event's symbol
********************************************************************/
char room::get_e_symbol(){
  return e->get_symbol();
}
/*******************************************************************
Function: get_e_percept
Description: accessor for room's event's percept
********************************************************************/
string room::get_e_percept(){
  return e->get_percept();
}
/*******************************************************************
Function: get_e_encounter
Description: accessor for room's event's encounter
********************************************************************/
int room::get_e_encounter(){
  return e->encounter();
}
