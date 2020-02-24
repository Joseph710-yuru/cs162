#ifndef PIT_H
#define PIT_H

#include "event.h"

using namespace std;

class pit : public event {
  private:

  public:
    void percept();
    void encounter();
};

#endif
