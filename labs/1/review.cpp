#include <iostream>

int main(int argc, char* argv[]) {
  struct mult_div_values {
     int mult;
     float div;
  };

  int rows = atoi(argv[1]);
  int cols = atoi(argv[2]);

  mult_div_values** a = new mult_div_values*[rows];

  for (int i=0; i < rows;i++){
      a[i] = new mult_div_values[cols];
  }

  return 0;
}
