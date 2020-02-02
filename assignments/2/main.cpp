#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"

using namespace std;

int main() {
  player a;
  deck b;

  a.set_name(get_string());
  cout << a.get_name() << endl;

  b.create_deck(52);
  b.shuffle_deck();
  a.set_hand(b);

  hand h = a.get_hand();
  h.print_hand();

  //b.print_deck(52);

  return 0;
}
