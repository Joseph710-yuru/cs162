#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"

using namespace std;

int main() {
  deck d;
  d.create_deck(52);
  d.shuffle_deck();
  hand h;
  cout << "h created\n";
  h.set_cards(d);
  cout << "h cards set\n";
  h.print_hand();
  cout << "deck check\n";
  d.print_deck(52);

  return 0;
}
