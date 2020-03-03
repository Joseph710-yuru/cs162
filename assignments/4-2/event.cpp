/*******************************************************************
file: event.cpp
description: implementation for event class
*******************************************************************/
#include "event.h"

#include <iostream>

using namespace std;
/*******************************************************************
Function: event
Description: default constructor for room type
********************************************************************/
event::event(){
  symbol = ' ';
}
/*******************************************************************
Function: encounter
Description: default encounter return
********************************************************************/
int event::encounter(){
  return 0;
}
/*******************************************************************
Function: set_percept
Description: mutator for percept
********************************************************************/
void event::set_percept(string p){
  percept = p;
}
/*******************************************************************
Function: set_symbol
Description: mutator for symbol
********************************************************************/
void event::set_symbol(char s){
  symbol = s;
}
/*******************************************************************
Function: get_percept
Description: accessor for percept
********************************************************************/
string event::get_percept(){
  return percept;
}
/*******************************************************************
Function: get_symbol
Description: accessor for symbol
********************************************************************/
char event::get_symbol(){
  return symbol;
}
