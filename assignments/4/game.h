#ifndef GAME_H
#define GAME_H

#include "room.h"

#include <iostream>
#include <vector>

using namespace std;

class game {
  private:
    int player_x, player_y, alive, rooms, debug, arrows;
    vector<vector<room>> r;
  public:
    game();
    game(int, bool);
    ~game();
    //accessors and mutators
    int get_player_x();
    int get_player_y();
    int get_arrows();
    int get_rooms();
    bool get_debug();
    void set_player_x(int);
    void set_player_y(int);
    void set_arrows(int);
    void set_rooms(int);
    void set_debug(bool);
    //movement
    void move_north();
    void move_south();
    void move_east();
    void move_west();
    //arrow stuff
    void arrow_north();
    void arrow_south();
    void arrow_east();
    void arrow_west();
    //allocate events
    void assign_events();
    void assign_wumpus();
    void assign_pit();
    void assign_bats();
    void assign_gold();
    //other
    void print_map();

};

#endif
