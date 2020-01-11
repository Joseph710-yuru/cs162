#include <iostream>
#include <cstring>
#include "mult_div.h"

using namespace std;


int main(int argc, char* argv[]) {
  int m=0, n=0, dim=0, repeat=0;
  char tempm=atoi(argv[1]), tempn=atoi(argv[2]);

  while (dim==0){
    if (is_valid_dimensions(&tempm, &tempn)==true){
      dim = 1;
    }
  }

  m = tempm;
  n = tempn;

  mult_div_values** table = new mult_div_values*[m];
  for (int i=0; i < m;i++){
      table[i] = new mult_div_values[n];
  }

  set_mult_values(table, m, n);
  set_div_values(table, m, n);
  print_table(table, m, n);

  delete_table(table, m);

  return 0;
}
