/*******************************************************************
Author: Garrett Martin
assignment: 5 - linked lists and sorts
date: 3/11/2020
file: main.cpp
*******************************************************************/

#include "node.h"
#include "linked_list.h"

using namespace std;

int main(){
  linked_list l;
  char c = 'y', s, repeat= 'y';
  int v;


  while (repeat == 'y'){
    cout << "Please enter a number: "; // get initial value for list
    cin >> v;
    l.push_back(v);

    while (c == 'y'){ // why not get some more values for the list
      cout << "Add another number to you list (y/n): ";
      cin >> c;
      if (c == 'y') {
        cout << "Enter a number: ";
        cin >> v;
        l.push_back(v);
      }
    }
    l.print();

    cout << "Sort list in ascending or descending order (a/d): ";
    cin >> s;
    if (s == 'a') {
      cout << "Sort ascending...\n";
      l.sort_ascending();
    } else if (s == 'd') {
      cout << "Sort descending...\n";
      l.sort_descending();
    }

    cout << "Your linked list is: ";
    l.print();
    cout << "You have " << l.prime_amount() << " prime(s) in your list.\nThey are: ";
    l.print_prime();

    cout << "Do you want to do this again (y/n): ";
    cin >> repeat;
    if (repeat == 'y') {
      c = 'y';
      l.clear();
    }
  }

  return 0;
}
