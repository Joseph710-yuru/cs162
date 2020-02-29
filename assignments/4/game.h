#ifndef GAME_H
#define GAME_H

#include "room.h"

#include <iostream>
#include <vector>

using namespace std;

class game {
  private:
<<<<<<< HEAD
    int player_x, player_y, arrows, n_rooms, debug;
    vector<room> rooms;
=======
    int player_x, player_y,alive,rooms;
    
>>>>>>> 6f73821374d6f600bc88663863c8f26f9e51cdc3
  public:
    game();
    game(int);
    ~game();
    //accessors and mutators
    int get_player_x();
    int get_player_y();
    int get_arrows();
    int get_rooms();
    void set_player_x(int);
    void set_player_y(int);
    void set_arrows(int);
    void set_rooms(int);
    //movement
    void move_north();
    void move_south();
    void move_east();
    void move_west();
    //other
    void print_map();
};

#endif
