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
    virtual void encounter();
    string get_percept();
    void set_percept();
    bool wake_up();
};

#endif
