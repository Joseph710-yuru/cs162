#include "animal.h"
#include <string>

using namespace std;

animal::animal(){
  name = "Unnamed";
  age = "0";
}

void animal::set_name(string a){
  name = a;
}

void animal::set_age(int a){
  age = a;
}

string animal::get_name(){
  return name;
}

int animal::get_age(){
  return age;
}

bool animal::is_adult(){
  if (age >= 48) return true;
  else return false;
}

bool animal::is_baby(){
  if (age <= 6) return true;
  else return false;
}
