#include "blackbear.h"
#include <string>

using namespace std;
//constructor
blackbear::blackbear(){
  set_name("noname");
  set_age(-1);
}
// birth() - allocates name and sets age to zero
void blackbear::birth(){
  set_name(namegen());
  set_age(0);
}
// bought() - generates name and sets age to 48
void blackbear::bought(){
  set_name(namegen());
  set_age(48);
}
// namegen() - Randomly selects a name from array.
string blackbear::namegen() {
  /*
    i figured black bears needed sitcom and cartoon character names.
  */
  string names [40] = {
    "Grob Gob Glob Grod", "Prismo", "Abracadaniel", "N.E.P.T.R.", "Gunter",
    "Jane Lane", "Finn", "Jake", "Marceline the Vampire Queen", "Lemongrab",
    "Clarissa Darling", "Dean Pelton", "Britta Perry", "Abed Nadir", "Daria Morgendorffer",
    "Mentok the Mind-Taker", "Judy Ken Sebben", "X the Eliminator", "Topanga", "Feeny",
    "Brak", "Zorak", "Harvey Birdman", "Phil Ken Sebben", "Peanut",
    "Fran Katzenjammer", "Steve Smith", "Frank Smith", "Pony Merks", "Baby Cakes",
    "Manny Bianco", "Bernard Black", "Daggett", "Norbert", "Banana Joe",
    "Darwin Watterson", "Gumball Watterson", "Big Pete", "Little Pete", "Artie"
  };

  return names[rand() % 40];
}
