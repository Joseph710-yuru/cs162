/******************************************************
** Program: main.cpp
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
  game a, temp;
//  while (repeat==1){
    a.game_loop();
//    cout << "Do you want to play again? (0-no, 1-yes) ";
    //get int for repeat
//    if (repeat==1) "do you want to play the same map and settings? (0-no, 1-yes) ";
    //get int for duplicate
      //if yes duplicate temp to a
      //if no prompt for rooms/debug mode and create new game and copy to a
//  }
  return 0;
}
