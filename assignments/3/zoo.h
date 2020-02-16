#ifndef ZOO_H
#define ZOO_H

#include "tiger.h"
#include "blackbear.h"
#include "sealion.h"

class zoo {
  private:
    tiger *tigers;
    sealion *sealions;
    blackbear *blackbears;
    int n_tigers, n_sealions, n_blackbears, bank, boom, day;
    float food_base;
  public:
    zoo();
    ~zoo();
    //Accessors
    int get_n_tigers();
    int get_n_blackbears();
    int get_n_sealions();
    int get_bank();
    float get_food_base();
    int get_boom();
    //tiger, blackbear and sealion accessor/mutators need to be added
    //mutators
    void set_n_tigers(int);
    void set_n_blackbears(int);
    void set_n_sealions(int);
    void set_bank(int);
    void set_food_base(float);
    void set_boom(int);
    //sick functions
    void sick_animal(int);
    void sick_sealion();
    void sick_blackbear();
    void sick_tiger();
    //birth functions
    void birth_animal(int);
    void birth_tiger();
    void birth_sealion();
    void birth_blackbear();
    //kill functions
    void kill_tiger(int);
    void kill_sealion(int);
    void kill_blackbear(int);
    //buy animal functions
    void buy_animals();
    void buy_tigers();
    void buy_sealions();
    void buy_blackbears();
    //monthly operations
    void run_month();
    void buy_food();
    void revenue();
    void age();
    void special_event();
    bool bankrupt();
    //misc functions
    void clean(animal *, int);
    void swap_animal(animal &, animal &);
    void gimmean_int(int &);
};
#endif
