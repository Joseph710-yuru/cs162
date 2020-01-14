/********* Header Guard **********/
#ifndef STUDENT_DB_H
#define STUDENT_DB_H

/******** Dependencies **********/
#include <iostream>
#include <string>
using namespace std;

/******* Structs ********/
struct student {
  int id;
  string name;
  string major;
};

/******* Declarations **********/
student* create_student_db(int);
void get_student_db_info(student *, int, fstream &);
void delete_student_db_info(student **, int);

#endif
