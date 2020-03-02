/********************************************************************
file: room.cpp
description: implementation for room class
********************************************************************/
#include "room.h"
#include "event.h"
#include "wumpus.h"
#include "escape.h"
#include "pit.h"
#include "bats.h"
#include "gold.h"


#include <iostream>

using namespace std;

/*******************************************************************
Function: default constructor for event type
Description: sets event to null
********************************************************************/
room::room(){
  arrow = false;
  show = false;
  e = new event;
  cout << e->get_name();
}
/*******************************************************************
Function: ~room
Description: default destructor for room, deletes event pointer
********************************************************************/
room::~room(){
  delete e;
  e = NULL;
}
/*******************************************************************
Function:
Description:
********************************************************************/
char room::get_symbol(){
  return e->get_symbol();
}
/*******************************************************************
Function: accessor for private member e
Description: returns the event e
********************************************************************/
event room::get_event(){
  return *e;
}
/*******************************************************************
Function: set_event
Description: mutator for private member e
********************************************************************/
void room::set_event(event *ve){
  e = ve;
}
/*******************************************************************
Function: contains
Description: Returns the type of event
*******************************************************************/
string room::get_name(){
  return e->get_name();
}
/*******************************************************************
Function:
Description:
********************************************************************/
void room::get_percept(){
  if (e->get_percept() != "undefined") cout << e->get_percept() << endl;
}
/*******************************************************************
Function:
Description:
********************************************************************/
bool room::get_arrow(){
  return arrow;
}
/*******************************************************************
Function:
Description:
********************************************************************/
void room::set_arrow(bool a){
  arrow = a;
}
/*******************************************************************
Function:
Description:
********************************************************************/
bool room::get_show(){
  return show;
}
/*******************************************************************
Function:
Description:
********************************************************************/
void room::set_show(bool s){
  show = s;
}
/*******************************************************************
Function:
Description:
********************************************************************/
bool room::kill(){
  if (e->get_name() == "wumpus") {
    event *ev = new event;
    set_event(ev);
    return true;
  } else return false;
}

int room::get_ent(){
  return e->get_ent();
}
/*******************************************************************
Function:
Description:
********************************************************************/
void room::assign_escape(){
  delete e;
  e = new escape;
}
/*******************************************************************
Function:
Description:
********************************************************************/
void room::assign_empty(){
  delete e;
  e = new event();
}
/*******************************************************************
Function:
Description:
********************************************************************/
void room::assign_wumpus(){
  delete e;
  e = new wumpus;
}
/*******************************************************************
Function:
Description:
********************************************************************/
void room::assign_pit(){
  delete e;
  e = new pit;
}
/*******************************************************************
Function:
Description:
********************************************************************/
void room::assign_bats(){
  delete e;
  e = new bats;
}
/*******************************************************************
Function:
Description:
********************************************************************/
void room::assign_gold(){
  delete e;
  e = new gold;
}
