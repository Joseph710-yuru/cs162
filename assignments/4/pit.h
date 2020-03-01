#ifndef PIT_H
#define PIT_H

#include "event.h"

#include <string>

using namespace std;

class pit : public event {
  private:

  public:
    void percept();
    void encounter();
    string contain();
};

#endif
