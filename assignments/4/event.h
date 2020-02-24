#ifndef EVENT_H
#define EVENT_H

using namespace std;

class event {
  private:

  public:
    virtual void percept();
    virtual void encounter();
    bool wake_up();
};

#endif
