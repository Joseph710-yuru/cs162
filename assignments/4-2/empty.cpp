/*******************************************************************
file: empty.cpp
description: implementation for empty class
*******************************************************************/
#include "empty.h"

#include <iostream>

using namespace std;
/*******************************************************************
Function: encounter
Description: default constructor for an empty event
********************************************************************/
empty::empty(){
  set_symbol(' ');
}
/*******************************************************************
Function: encounter
Description: returns the encounter for the empty type
             int is for use in game class
********************************************************************/
int empty::encounter(){
  return -1;
}
