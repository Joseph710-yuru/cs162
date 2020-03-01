#ifndef EVENT_H
#define EVENT_H

#include <string>

using namespace std;

class event {
  private:

  public:
    virtual void percept();
    virtual void encounter();
    string contain();
    bool wake_up();
};

#endif
