#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv){
  int square;
  if (argc != 2) return 0;
  square = stoi(argv[1]);

  cout << square << endl;

  return 0;
}
