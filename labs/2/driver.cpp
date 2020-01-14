#include <iostream>
#include <fstream>
#include <string>
#include "student_db.h"

using namespace std;

int main() {
  student std1;
  int num_of_students = 0, i=0;
  string temp_string;
  ifstream fin;

  // Open file stuff
  fin.open("inputs.txt");
  if (!fin.is_open()) {
    cout << "Error, unable to open file.\n";
    return 1;
  }

// file contents 2 struct
  getline(fin, temp_string, '\n');
  num_of_students = stoi(temp_string);
  while (i < num_of_students){
    getline(fin, temp_string, ' ');
    std1.id = stoi(temp_string);
    getline(fin, temp_string, ' ');
    std1.name += temp_string;
    getline(fin, temp_string, ' ');
    std1.name += temp_string;
    getline(fin, temp_string, '\n');
    std1.major = temp_string;

    i++;
  }
  cout << "ID: " << std1.id << endl;
  cout << "Name: " << std1.name << endl;
  cout << "Major: " << std1.major << endl;
  fin.close();
  return 0;
}
