#include <iostream>
#include "game.h"
#include "card.h"

using namespace std;
/*******************************************************************
Function: game()
Description: default constructor, assigns user player name and auto assigns
             computer player name
Parameters: n/a
Pre-Conditions:
Post-Conditions: Player sets their own name, computer name auto set.
********************************************************************/
game::game(){
  pile.set_n_cards(0);
  players[0].set_name(get_string());
  players[1].set_name("Computer");
  cards.create_deck(52);
  cards.shuffle_deck();
  players[0].set_hand(cards);
  players[1].set_hand(cards);
  card temp = cards.get_cards(0);
  pile.set_cards(0, temp.get_rank(), temp.get_suit());
  pile.set_n_cards(pile.get_n_cards() + 1);
  cards.set_cards(0, -1, -1);
  cards.clean();
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
game::~game(){
 cout << "Destructor called\n";
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void game::play_game(){
  cout << players[0].get_name() << " goes first.\n";
  cout << "Top of pile: ";
  pile.print_top();
  while (check_win()==false){
    players[0].take_turn(pile, cards);
    cout << "Top of the pile is: ";
    pile.print_top();
    players[1].auto_turn(pile, cards);
    cout << "Top of the pile is: ";
    pile.print_top();
  }
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
const deck game::get_cards(){
  return cards;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
player game::get_players(int i){
  if (i>=0 && i < 2){
    return players[i];
  }
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
deck game::set_cards(){

}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
player game::set_players(){

}

/*******************************************************************
Function: get_string()
Description: prompts user for a user name, accepts a string input
Parameters: n/a
Pre-Conditions:
Post-Conditions: returns a string defined by the user
********************************************************************/
string get_string(){
  string temp;
  cout << "Set player Name: ";
  cin >> temp;
  return temp;
}
/*******************************************************************
Function: check_win()
Description: checks if any win condition is met and returns true if it is
Parameters: n/a
Pre-Conditions:
Post-Conditions: returns true if win condition met, false otherwise.
********************************************************************/
bool game::check_win(){
  if (cards.can_draw() == false) {
    if (players[0].can_play(pile) || players[1].can_play(pile) == true){
      return false;
    } else {
      if (players[0].hand_count() > players[1].hand_count()) cout << "Player wins!\n";
      else cout << "The computer has fewer cards and wins!\n";
      return true;
    }
  } else if (players[0].empty_hand()==true) {
    cout << players[0].get_name() << "'s hand is empty and wins!\n";
    return true;
  } else if (players[1].empty_hand()==true) {
    cout << "Computer's hand is empty and wins!\n";
    return true;
  }
  return false;
}
