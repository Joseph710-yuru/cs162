#include "card.h"
#include "deck.h"

using namespace std;

int main(){
  deck newd(52);
  //newd.create_deck(52);
  newd.print_deck(52);
  return 0;
}
