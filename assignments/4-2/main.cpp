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
  int square, debug, repeat=1, same=0,ts, td;
  game temp;
  srand(time(0));
  check_args(square, debug, argc, argv);

  while (repeat==1){
    if (same==0) {
      game a(5, 2);
      temp = a;
    } else if (same==1) {
      game c;
      c = temp;
    }

    a.game_loop();
    cout << "Would you like to play again? (0-no, 1-yes) ";
    cin >> repeat;
    cout << "Would you like to play the same map and settings? (0-no, 1-yes) ";
    cin >> same;
    if (repeat==1) {
      a.~game();
      if (same==1) a = copy;
      else if(same==0) {
        save_lines(square, debug);
      }
    }
  }
  return 0;
}
