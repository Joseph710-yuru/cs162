/*******************************************************************
file: bats.cpp
description: implementation for bats class
*******************************************************************/
#include "bats.h"

#include <iostream>
#include <string>

using namespace std;
/*******************************************************************
Function:
Description:
*******************************************************************/
bats::bats(){
  set_name("bats");
  set_percept("You hear wings flapping.");
  set_ent(1);
}
/*******************************************************************
Function:
Description:
********************************************************************/
void bats::encounter(){
  cout << "You enter a room filled with spooky scary bats.\n";
  cout << "The bats carry you away.\n";
}
