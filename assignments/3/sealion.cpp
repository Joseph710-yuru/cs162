#include "sealion.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

sealion::sealion(){
  set_name(namegen());
  set_age(0);
}

string sealion::namegen() {
  srand(time(0));

  /*
    pulled as many names of sea lions at zoos and rescues as i could find
    plus a couple others
  */
  string names [40] = {
    "Mermaid Dog", "Seapup", "Mr. Morton Slumber", "Lupe Lamora", "Kwang",
    "Domino", "Silver", "Honey Rider", "Blofield", "Max Zorin",
    "May Day", "Inga Bergstrom", "Goldfinger", "Zuri", "Nabi",
    "Gemini", "Isla", "Shiva", "Leopold", "Hanno",
    "Oakley", "Shelby", "Bixby", "Toby", "Lavender",
    "Flax", "Larkspur", "Sunflower", "Buttercup", "Josephine",
    "Lion McLionface", "Salty", "Storm", "Dr. Niles Crane", "Dr. Frasier Crane",
    "Nami", "Coralia", "Eddie", "Roz Doyle", "Daphne Moon"
  };

  return names[rand() % 40];
}
