game::game(){
  player_x = 0;
  player_y = 0;
  alive = 1;
  rooms = 4;
  r = new room [rooms];
}

game::game(int ro) {
  player_x = 0;
  player_y = 0;
  alive = 1;
  rooms = ro;
  r = new room [rooms];
}
