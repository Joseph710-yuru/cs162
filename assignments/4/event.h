#ifndef EVENT_H
#define EVENT_H

#include <string>

using namespace std;

class event {
  private:
    string name;
    string percept;
    int ent;
  public:
    event();
    void set_ent(int);
    int get_ent();
    string get_name();
    void set_name(string);
    string get_percept();
    void set_percept(string);
    char get_symbol();
    virtual void encounter();
};

#endif
