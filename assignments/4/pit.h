#ifndef PIT_H
#define PIT_H

#include "event.h"

#include <string>

using namespace std;

class pit : public event {
  public:
    pit();
    void encounter();
};

#endif
