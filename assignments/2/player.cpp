#include <iostream>
#include <string>
#include "player.h"
#include "game.h"
#include "card.h"

using namespace std;
/*******************************************************************
Function: player()
Description: default constructor for player class
Parameters: n/a
Pre-Conditions:
Post-Conditions: object of type player is created
********************************************************************/
player::player(){

}
/*******************************************************************
Function: ~player()
Description: default destructor for player class
Parameters:
Pre-Conditions:
Post-Conditions: object of type player is destructed
********************************************************************/
player::~player(){

}
/*******************************************************************
Function: player::get_hand()
Description: accessor for hand private member variable
Parameters:
Pre-Conditions:
Post-Conditions: returns const hand
********************************************************************/
const hand player::get_hand(){
  return h;
}
/*******************************************************************
Function: player::get_name()
Description: accessor for name private member variable
Parameters:
Pre-Conditions:
Post-Conditions: returns the value of name
********************************************************************/
const string player::get_name(){
  return name;
}
/*******************************************************************
Function: set_hand()
Description: sets all the cards in a hand to value of cards in a deck
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void player::set_hand(deck &a){
  h.set_cards(a);
}
/*******************************************************************
Function: set_name()
Description: mutator for name member variable
Parameters: string n
Pre-Conditions: accepts string as parameter
Post-Conditions: value of name is changed to the value of n
********************************************************************/
void player::set_name(string n){
  name = n;
}
/*******************************************************************
Function: player::take_turn()
Description: runs through an entire turn for the given player
Parameters:  deck &pile, deck &stock
Pre-Conditions: accepts two decks as parameters
Post-Conditions: you do a turn
********************************************************************/
void player::take_turn(deck &pile, deck &stock){
  int c,repeat=0;
  card a;
  cout << get_name() << "'s turn\nYour hand:\n";
  while (repeat==0){
    h.print_hand();
    if (can_play(pile)==true){
      cout << "Play card (1 - " << h.get_n_cards() << "): ";
      gimmean_int(c);
      a = h.get_card(c-1);
      if (check_rules(a, pile) == true){
        play_card(h.get_card(c-1), pile, c-1);
        h.draw_card(stock);
        repeat=1;
      } else {
        cout << "Error: Invalid move, try again.\n";
      }
    } else if (can_play(pile)==false && stock.get_n_cards() > 0){
      cout << "No move available, drawing card...\nYour Hand:\n";
      h.draw_card(stock);
    } else if (can_play(pile)==false) {
      cout << "No move available and no cards to draw. Skipping turn.\n";
      repeat=1;
    }
  }
}
/*******************************************************************
Function: auto_turn()
Description: handles the computer's turns
Parameters: deck &, deck &
Pre-Conditions: accepts two decks as parameters
Post-Conditions: computer's turn complete
********************************************************************/
void player::auto_turn(deck &pile, deck &stock){
  int repeat = 1;
  card top_card = pile.get_cards(pile.get_n_cards() - 1), temp2;
  cout << "Computer's turn\n";
  while (repeat==1){
    if (can_play(pile)==true){
      repeat = 0;
      for (int i=0; i < h.get_n_cards(); i++){
        temp2 = h.get_card(i);
        if (temp2.get_suit() == top_card.get_suit()){
          play_card(h.get_card(i), pile, i);
          if (stock.get_n_cards() > 0) h.draw_card(stock);
          break;
        } else if (temp2.get_rank() == top_card.get_rank()){
          play_card(h.get_card(i), pile, i);
          if (stock.get_n_cards() > 0) h.draw_card(stock);
          break;
        } else if (temp2.get_rank() == 7) {
          play_wild_card(h.get_card(i), pile, i);
          if (stock.get_n_cards() > 0) h.draw_card(stock);
          break;
        }
      }
    } else if (stock.get_n_cards() > 0){
      cout << "No move available, drawing card.\n";
      h.draw_card(stock);
    } else if (can_play(pile)==false && stock.get_n_cards() == 0){
      cout << "No move available and no card to draw, skipping turn.\n";
      repeat = 0;
    }
  }
}
/*******************************************************************
Function: player::play_card()
Description: handles playing a card from hand to pile
Parameters: card c, deck &pile, int n
Pre-Conditions: accepts card, deck ref and int as parameters
Post-Conditions: card gets played, everyone's happy
********************************************************************/
void player::play_card(card c, deck &pile, int n){
  int r,s,repeat=1;
  card temp = pile.get_cards(pile.get_n_cards()-1);

  if (c.get_rank()==7){
    while (repeat==1){
      cout << "\t8s are wild!\n\tChoose a suit (0-Clubs, 1-Spades, 2-Hearts, 3-Diamonds): ";
      gimmean_int(r);
      c.set_suit(r);
      cout << "\tChoose a rank (1-Ace, 2-10, 11-Jack, 12-Queen, 13-King): ";
      gimmean_int(s);
      c.set_rank(s-1);
      if (c.get_rank() == temp.get_rank() || c.get_suit() == temp.get_suit()) repeat=0;
      else cout << "\tError: either rank or suit must match top of pile, try again.\n";
    }
  }

  pile.set_cards(pile.get_n_cards(), c.get_rank(), c.get_suit());
  pile.set_n_cards(pile.get_n_cards() + 1);
  temp = pile.get_cards(pile.get_n_cards() - 1);
  h.remove_card(n);
}
/*******************************************************************
Function: player::play_wild_card()
Description: handles playing a card from hand to pile
Parameters: card c, deck &pile, int n
Pre-Conditions: accepts card, deck ref and int as parameters
Post-Conditions: card gets played, everyone's happy
********************************************************************/
void player::play_wild_card(card c, deck &pile, int n){
  card temp = pile.get_cards(pile.get_n_cards()-1);
  cout << "Computer played a wild card.\n";
  if (c.get_rank()==7){
      c.set_suit(temp.get_suit());
      c.set_rank(rand() % 13);
    }

  pile.set_cards(pile.get_n_cards(), c.get_rank(), c.get_suit());
  pile.set_n_cards(pile.get_n_cards() + 1);
  temp = pile.get_cards(pile.get_n_cards() - 1);
  h.remove_card(n);
}
/*******************************************************************
Function: can_play()
Description: checks if a user has a valid move this turn
Parameters: deck a
Pre-Conditions: accepts a deck as a parameter
Post-Conditions: returns true if there's a valid move, false otherwise
********************************************************************/
bool player::can_play(deck a){
  card temp1, temp2;
  temp2 = a.get_cards(a.get_n_cards()-1);
  for (int i=0; i < h.get_n_cards(); i++){
    temp1 = h.get_card(i);
    if (temp1.get_rank() == 7) return true;
    if (temp1.get_rank() == temp2.get_rank() || temp1.get_suit() == temp2.get_suit()){
      return true;
    }
  }
  return false;
}
/*******************************************************************
Function: hand_count()
Description: just get_n_cards, but up another level
Parameters: n/a
Pre-Conditions:
Post-Conditions: return number of cards in player's hand
********************************************************************/
int player::hand_count(){
  int i = h.get_n_cards();
  return i;
}
/*******************************************************************
Function: empty_hand()
Description: returns true/false if player hand is empty or not.
Parameters:
Pre-Conditions:
Post-Conditions: returns true if player hand is empty, false otherwise.
********************************************************************/
bool player::empty_hand(){
  if (h.get_n_cards() == 0) return true;
  else return false;
}
/****************************************************************************
Function: gimmean_int()
Description: Takes a ref int as a parameter, has user assign it and checks if that
             bad boi is a real int or not then assigns that value to the ref.
Parameters: int &num
Pre-Conditions: takes integer variable as parameter
Post-Conditions: returns provided integer
***************************************************************************/
void gimmean_int(int &num) {
  int repeat = 1;

  cin >> num;

  while (repeat == 1) {
    if (cin.fail() == true) {
      cin.clear();
      cin.ignore(1000000000,'\n');
      cout << "\tERROR: Non-Integer Input\n\tInput an integer: ";
      cin >> num;
    } else {
      repeat = 0;
    }
  }
}
/*******************************************************************
Function: check_rules()
Description: checks if a play is valid
Parameters: card play, deck pile
Pre-Conditions: called with two cards as parameters
Post-Conditions: returns true if play is valid, false otherwise
********************************************************************/
bool check_rules(card play, deck &pile){
  card top_pile = pile.get_cards(pile.get_n_cards() - 1);
  if (play.get_rank() == top_pile.get_rank()) return true;
  else if (play.get_suit() == top_pile.get_suit()) return true;
  else if (play.get_rank() == 7) return true;
  else return false;
}
