/*******************************************************************
file: event.cpp
description: implementation for event type
*******************************************************************/
#include "event.h"

#include <string>
#include <iostream>

using namespace std;

/*******************************************************************
Function: event
Description: Default constructor for event type
*******************************************************************/
event::event(){
  name = "Undefined Event";
  percept = "No Percept";
}
/*******************************************************************
Function: event::wake_up()
Description: defaults to false for all events unless otherwise defined
********************************************************************/
bool event::wake_up(){
  return false;
}
