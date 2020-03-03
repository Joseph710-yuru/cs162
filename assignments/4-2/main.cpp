/*******************************************************************
Author: Garrett Martin
Date: 3/1/2020
file: main.cpp
description: driver for hunt the wumpus game
*******************************************************************/
#include "game.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv){
  int square, debug, repeat=1, same=0, ts, td;
  srand(time(0));
  check_args(square, debug, argc, argv);
  game a(square, debug);
  a.game_loop();

  return 0;
}
