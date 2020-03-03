#include <iostream>
#include <string>

using namespace std;

class ass {
  private:
    string name;
    int age;
  public:
    ass();
    ass(string, int);
    void set_name(string);
    void set_age(int);
    int get_age();
    string get_name();
};

int main(){
  int a;
  cout << "a: ";
  cin >> a;
  string b;
  cout << "b: ";
  getline(cin, b);

  ass z(b, a);
  cout << z.get_name() << endl;
  cout << z.get_age() << endl;
}

ass::ass(){
  name = "default";
  age = -1;
}

ass::ass(string n, int a){
  name = n;
  age = a;
}

void ass::set_name(string a){
  name = a;
}

void ass::set_age(int a){
  age = a;
}

string ass::get_name(){
  return name;
}

int ass::get_age(){
  return age;
}
