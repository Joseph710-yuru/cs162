#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"

using namespace std;

int main() {
  //game a;
  //a.play_game();
  player p, comp;
  deck stock, pile;

  p.set_name("Garrett");
  stock.create_deck(52);
  stock.shuffle_deck();
  p.set_hand(stock);
  comp.set_hand(stock);
  p.take_turn(pile, stock);
  cout << "top of pile: ";
  pile.print_top();
  comp.auto_turn(pile, stock);
  cout << "top of pile: ";
  pile.print_top();

  //b.print_deck(52);

  return 0;
}

/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void play_card(card c, deck &pile){
  pile.set_cards(pile.get_n_cards()+1, c.get_rank(), c.get_suit());
  pile.set_n_cards(pile.get_n_cards() + 1);
}
