/********************************************************************
file: room.cpp
description: implementation for room class
********************************************************************/
#include "room.h"
#include "event.h"

/*******************************************************************
Function: default constructor for event type
Description: sets event to null
********************************************************************/
room::room(){

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
string room::contain(){
  return e.contain() ;
}
