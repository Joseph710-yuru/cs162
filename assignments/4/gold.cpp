/*******************************************************************
file: gold.cpp
description: implementation for gold class
*******************************************************************/
#include "gold.h"

#include <iostream>
#include <string>

using namespace std;
/*******************************************************************
Function:
Description:
*******************************************************************/
gold::gold(){
  set_name("gold");
  set_percept("You see a glimmer nearby.");
}
/*******************************************************************
Function:
Description:
********************************************************************/
int gold::encounter(){
  cout << "You have found the horde of gold!\n";
  cout << "You have added the horde of gold to your inventory.\n";
  return 2;
}


/*******************************************************************

gold::gold(){
  set_name("Gold");
  set_percept("You see a glimmer nearby.");
}
/*******************************************************************
Function: gold::encounter()
Description:

int gold::encounter(){
  cout << "You have found the horde of gold!\n";
  cout << "You have added the horde of gold to your inventory.\n";
  return 2;
}
********************************************************************/
