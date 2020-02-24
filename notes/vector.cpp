#include <vector>
#include <iostream>

using namespace std;

int main() {
  vector<float> num;
  num.reserve(100);

  cout << num.size() << endl;
  
  return 0;
}
