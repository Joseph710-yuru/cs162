#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class card {
  private:
    string suit;
    int rank;
  public:
    card();
    string get_suit() const;
    int get_rank() const;
    void set_suit(int);
    void set_rank(int);
};

#endif
