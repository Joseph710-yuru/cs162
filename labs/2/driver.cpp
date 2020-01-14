/***************Design******************
use fstream to open inputs.txt

read number of users from input.txt

call get_student_db_info() to extract student info from file
and write each respetive student's info to a student type array

struct student is comprised of int ID, string name and string Major

then a function to write each student's info,
sorted by name and again by Major into a new file.

***************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "student_db.h"

using namespace std;

int main() {
  int num_of_students;
  string temp_string;
  ifstream fin;

  // Open file stuff
  fin.open("inputs.txt");
  if (!fin.is_open()) {
    cout << "Error, unable to open file.\n";
    return 1;
  }
// get number of students in input.txt
  getline(fin, temp_string, '\n');
  num_of_students = stoi(temp_string);
  cout << "Number of Students: " << num_of_students << endl;

// file contents 2 struct
  student *studentdb = create_student_db(num_of_students);
  get_student_db_info(studentdb, num_of_students, fin);
  fin.close();

// sort and write to doc
  

  //delete_student_db_info(&studentdb, num_of_students);
  delete [] studentdb;

  return 0;
}
