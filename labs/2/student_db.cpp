#include "student_db.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
student* create_student_db(int num){
  student *student_record = new student [num];
  return student_record;
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void get_student_db_info(student *student_record, int num, ifstream &fin){
  int i=0;
  string temp_string;
    while (i < num){
      getline(fin, temp_string, ' ');
      student_record[i].id = stoi(temp_string);
      cout << student_record[i].id << endl;

      getline(fin, temp_string, ' ');
      student_record[i].name += temp_string;
      getline(fin, temp_string, ' ');
      student_record[i].name += temp_string;
      cout << student_record[i].name << endl;

      getline(fin, temp_string, '\n');
      student_record[i].major = temp_string;
      cout << student_record[i].major << endl;

      i++;
    }
}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void delete_student_db_info(student **student_record, int num){
/*
  for (int i=0; i<num; i++){
    delete student_record;
  }
*/
  delete [] student_record;
}


void sortwrite_student_db(student *studentdb, int num){


}
