#include <vector>
#include <iostream>

using namespace std;

int main(){
  vector<vector<int>> v;

  vector<vector<int>>::iterator row;
  vector<int>::iterator col;

  v.resize(4, vector<int>(4));

  for (row = v.begin(); row < v.end(); ++row){
    for (col = row->begin(); col < row->end(); ++col){
      *col = 1;
    }
  }
  for (row = v.begin(); row < v.end(); ++row){
    for (col = row->begin(); col < row->end(); ++col){
      cout << *col;
    }
    cout << endl;
  }

  return 0;
}
