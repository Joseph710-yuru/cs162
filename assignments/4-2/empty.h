#ifndef EMPTY_H
#define EMPTY_H

#include "event.h"

#include <string>

using namespace std;

class empty : public event {
  public:
    empty();
    int encounter();
};

#endif
