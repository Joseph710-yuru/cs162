/*******************************************************************
file: escape.cpp
description: implementation for escape class
*******************************************************************/
#include "escape.h"

#include <iostream>
#include <string>

using namespace std;
/*******************************************************************
Function:
Description:
*******************************************************************/
escape::escape(){
  set_name("escape");
  set_ent(4);
}
/*******************************************************************
Function:
Description:
********************************************************************/
void escape::encounter(){
  cout << "You killed the Wumpus and escaped with the horde of gold!\n";
}
