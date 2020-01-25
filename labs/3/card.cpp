#include <string>
#include "card.h"
using namespace std;

card::card() {

}

int card::get_rank() const{
  return rank;
}

string card::get_suit() const{
  return suit;
}

void card::set_rank(int num){
  rank = num;
}

void card::set_suit(int num){
  if (num==1){
    suit = "Diamonds";
  } else if (num==2) {
    suit = "Hearts";
  } else if (num==3) {
    suit = "Spades";
  } else if (num==4){
    suit = "Clubs";
  } else {
    suit = "Uninitialized";
  }
}
