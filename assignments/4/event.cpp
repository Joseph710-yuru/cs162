/*******************************************************************
file: event.cpp
description: implementation for event type
*******************************************************************/
#include "event.h"

#include <string>
#include <iostream>

using namespace std;

/*******************************************************************
Function: event::wake_up()
Description: defaults to false for all events unless otherwise defined
********************************************************************/
bool event::wake_up(){
  return false;
}
/*******************************************************************
Function: contain
Description: Returns the type of event
*******************************************************************/
string event::contain(){
  return "empty";
}
