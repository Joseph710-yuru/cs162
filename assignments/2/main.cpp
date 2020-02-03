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
  game a;
  a.play_game();
/*
  deck stock, pile;
  hand a, b;
  stock.create_deck(52);
  stock.shuffle_deck();
  a.set_cards(stock);
  card l = a.get_card(0);
  cout << l.name_rank() << " " << l.name_suit() << endl;
  a.remove_card(0);

  //b.print_deck(52);
*/
  return 0;
}

/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
