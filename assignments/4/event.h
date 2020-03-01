#ifndef EVENT_H
#define EVENT_H

#include <string>

using namespace std;

class event {
  private:
    string name;
    string percept;
  public:
    event();
    virtual int encounter();
    string get_name();
    void set_name(string);
    string get_percept();
    void set_percept(string);
    bool wake_up();
};

#endif
