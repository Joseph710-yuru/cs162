#include "card.h"
#include "deck.h"
#include <iostream>

using namespace std;

int main(){
  deck newd(52);
  //newd.create_deck(52);
  //newd.print_deck(52);
  cout << "creating deck... \n";
  newd.create_deck(52);
  cout << "shuffling deck... \n";
  newd.shuffle_deck(52);
  newd.print_deck(52);
  return 0;
}
