
class Base{
  public:
    int pub;
  private:
    int pri;
  protected:
    int pro;
};

class Derived : public Base{ // use this one for assignment 3. use 99% of the time
  public:
    Derived(){
      pub = 1; // allowed
      pri = 2; // not allowed
      pro = 3; // allowed
    }
};

class Ass : protected Base {

};

class Mast : private: Base {
  c.pub = 6; // allowed
  c.pri = 9; // not allowed
  c.pro = 10; // allowed
};

int main(){
  Base b;
  b.pub = 1; // gucci
  b.pri = 2; // not allowed
  b.pro = 3; // not allowed
  Derived a;
  a.pub = 1;
  a.pri = 5; // not allowed
  a.pro = 6; // not allowed
  Mast c;
  c.pub = 6; // allowed
  c.pri = 9 // not allowed
  c.pro = 10 // not allowed;
  Ass d;
  d.pub = 0; // not allowed
  d.pri = 22; // not allowed
  d.pro = 2020 // not allowed
}

Derived::Derived(){
  // base constructor called, then derived constructor
}
