/*******************************************************************
file: gold.cpp
description: implementation for gold class
*******************************************************************/
#include "gold.h"

#include <iostream>

using namespace std;

gold::gold(){
  set_percept("You see a glimmer nearby.");
  set_symbol('g');
}

int gold::encounter(){
  cout << "You have found a room filled with gold!\n";
  cout << "You load up your pockets with as much as you can carry.\n";
  return 2;
}
