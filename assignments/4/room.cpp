/********************************************************************
file: room.cpp
description: implementation for room class
********************************************************************/
#include "room.h"
#include "event.h"

#include <iostream>

using namespace std;

/*******************************************************************
Function: default constructor for event type
Description: sets event to null
********************************************************************/
room::room(){
  arrow = false;
  show = false;
}
/*******************************************************************
Function: accessor for private member e
Description: returns the event e
********************************************************************/
event room::get_event(){
  return e;
}
/*******************************************************************
Function: set_event
Description: mutator for private member e
********************************************************************/
void room::set_event(event &ve){
  e = ve;
}
/*******************************************************************
Function: contains
Description: Returns the type of event
*******************************************************************/
string room::get_name(){
  return e.get_name();
}
/*******************************************************************
Function:
Description:
********************************************************************/
void room::get_percept(){
  cout << e.get_percept() << endl;
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
  if (e.get_name() == "wumpus") {
    set_show(false);
    return true;
  } else return false;
}
