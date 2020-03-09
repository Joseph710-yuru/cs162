#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> a;
  a.reserve(100);
  cout << a.size() << endl;

  return 0;

}
