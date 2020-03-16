#include "other_funkz.h"

#include <iostream>

using namespace std;

void options(char &val, char one, char two){
  string temp;
  int repeat=1;
  cin.ignore(1000, '\n');

  getline(cin, temp);

  while (repeat == 1){
    if (temp[0]==one||temp[0]==two) repeat = 0;
    else {
      cin.clear();
      cin.ignore(10000000000, '\n');
      cout << "Error: Bad input\n";
      cout << "Please enter " << one << " or " << two << ": ";
      getline(cin, temp);
    }
  }
  val = temp[0];
}

void gimmean_int(int &num){
  int repeat = 1;

  cin >> num;

  while (repeat == 1) {
    if (cin.fail() == true) {
      cin.clear();
      cin.ignore(1000000000,'\n');
      cout << "\tError: Non-Integer Input\n\tInput an integer: ";
      cin >> num;
    } else {
      repeat = 0;
    }
  }
}
