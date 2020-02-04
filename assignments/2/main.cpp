/******************************************************
** Program: crazyeights.cpp
** Author: Garrett Martin
** Date: 02/01/2020
** Description:  a game of crazy eights
** Input:
** Output:
******************************************************/
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"

using namespace std;

int main() {
  int repeat=1;
  while (repeat==1){
    game a;
    a.play_game();
    cout << "Would you like to play again? (0-no, 1-yes): ";
    gimmean_int(repeat);
    a.~game();
  }
  return 0;
}

/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
