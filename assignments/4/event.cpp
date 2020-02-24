/*******************************************************************
file: event.cpp
description: implementation for event class
*******************************************************************/
#include "event.h"

#include <iostream>

using namespace std;

/*******************************************************************
Function: event::wake_up()
Description: defaults to false for all events unless otherwise defined
Parameters: n/a
Pre-Conditions:
Post-Conditions: returns false
********************************************************************/
bool event::wake_up(){
  return false;
}
