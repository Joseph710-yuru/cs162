/******************************************************
** Program: wumpus.cpp
** Author: Garrett
** Date: 02/28/2020
** Description: A game of hunt the wumpus
** Input:
** Output:
******************************************************/

//#include "room.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  srand(time(0));
  
  vector<vector<int> > vect{  {1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9} };
/*
  for (int i = 0; i < vect.size(); i++) {
    for (int j = 0; j < vect[i].size(); j++){
      cout << "| " << vect[i][j] << " ";
    }
    cout << "|" <<endl;
  }
*/


  return 0;
}

/*

+---+---+---+---+
|   |   |   |   |
|   |   |   |   |
|   |   |   |   |
+---+---+---+---+
|   |   |   |   |
|   |   |   |   |
|   |   |   |   |
+---+---+---+---+
|   |   |   |   |
|   |   | * |   |
|   |   |   |   |
+---+---+---+---+
|   |   |   |   |
|   |   |   |   |
|   |   |   |   |
+---+---+---+---+

*/
