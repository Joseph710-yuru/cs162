#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using namespace std;

class animal {
  private:
    string name;
    int age; // months
  public:
    animal();
    //~animal();
    void set_name(string);
    void set_age(int);
    string get_name();
    int get_age();
    bool is_adult();
    bool is_baby();
};

#endif
