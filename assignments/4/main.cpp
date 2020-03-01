/******************************************************
** Program: wumpus.cpp
** Author: Garrett
** Date: 02/28/2020
** Description: A game of hunt the wumpus
******************************************************/

#include "game.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  srand(time(0));
  game a;
  a.print_map();
  
  return 0;
}

/*

+---+---+---+---+
|   |   |   |   |
|   |   |   |   |
|   |   |   |   |
+---+---+---+---+
|   |   |   |   |
|   |   |   |   |
|   |   |   |   |
+---+---+---+---+
|   |   |   |   |
|   |   | * |   |
|   |   |   |   |
+---+---+---+---+
|   |   |   |   |
|   |   |   |   |
|   |   |   |   |
+---+---+---+---+

*/
