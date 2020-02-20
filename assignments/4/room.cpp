/*************************************
file: room.cpp
description: implementation for room class
*************************************/

/*************************************
room() - default constructor for room
*************************************/
room::room(){
  x = -1;
  y = -1;
  event = NULL;
}
/*************************************
room(int, int) - same as default constructor,
                except specifies room location
*************************************/
room::room(int rx, int ry){
  x = rx;
  y = ry;
  event = NULL;
}
