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
  h.set_cards(d);

  return 0;
}
