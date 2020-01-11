#include <iostream>
#include "mult_div.h"
using namespace std;

bool is_valid_dimensions(char *rows, char *cols){
  if (*rows == 0 | *rows > 5){
    cout << "Invalid row value provded.\n";
    cout << "Please provide an integer value between 1-5.\n";
    cout << "Rows: ";
    cin >> rows;
    return false;
  }
  if (*cols == 0 | *cols > 5){
    cout << "Invalid column value provded.\n";
    cout << "Please provide an integer value between 1-5.\n";
    cout << "Columns: ";
    cin >> cols;
    return false;
  }
  return true;
}

void print_table(mult_div_values **table, int m, int n){
  cout << "Multiplication Table\n";
  for (int i=0; i < m; i++){
    for (int j=0; j<n; j++){
      cout << " " << table[i][j].mult << " ";
    }
    cout << endl;
  }

  cout << "\nDivision Table\n";
  for (int i=0; i < m; i++){
    for (int j=0; j<n; j++){
      cout << " " << table[i][j].div << " ";
    }
    cout << endl;
  }
}
void set_mult_values(mult_div_values **table, int m, int n){
  for (int i=0; i < m; i++){
    for (int j=0; j < n; j++){
      table[i][j].mult = (i+1)*(j+1);
    }
  }
}

void set_div_values(mult_div_values **table, int m, int n){
  for (int i=0; i < m; i++){
    for (int j=0; j < n; j++){
      table[i][j].div = (i+1.0)/(j+1.0);
    }
  }
}

void delete_table(mult_div_values **table, int m){
 for (int i=0; i < m; i++){
    delete [] table[i];
  }
  delete [] table;
}
