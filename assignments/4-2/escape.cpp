/*******************************************************************
file: escape.cpp
description: implementation for escape class
*******************************************************************/
#include "escape.h"

#include <iostream>

using namespace std;
/*******************************************************************
Function: escape
Description: default constructor for escape type
********************************************************************/
escape::escape(){
  set_symbol('e');
}
/*******************************************************************
Function: encounter
Description: returns the encounter for the escape type
             int is for use in game class
********************************************************************/
int escape::encounter(){
  cout << "You climb the escape rope.\n";
  return 5;
}
