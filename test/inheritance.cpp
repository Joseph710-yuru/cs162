#include <iostream>
#include <string>
#include <vector>

using namespace std;

class base {
  private:
    string name;
  public:
    base();
    void set_name(string);
    string get_name();
    virtual void print_name();
};

class derived : public base {
  public:
    void print_name();
};

int main(){
  vector<vector<base*>> array;
  array.resize(2, vector<base*>(2));

  base one;
  derived two;

  array[0][0] = &one;
  array[1][0] = &two;

  array[0][0]->print_name();
  array[1][0]->print_name();
  cout << endl;

  return 0;
}

base::base() {
  name = "no name";
}

string base::get_name(){
  return name;
}

void base::set_name(string a){
  name = a;
}

void base::print_name(){
  cout << name << endl;
}

void derived::print_name(){
  cout << "the right honorable " + get_name();
}
