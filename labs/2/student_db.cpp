#include "student_db.h"

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
void get_student_db_info(student *student_record, int num, fstream &file){

}
/*******************************************************************
Function:
Description:
Parameters:
Pre-Conditions:
Post-Conditions:
********************************************************************/
void delete_student_db_info(student **student_record, int num){
  for (int i=0; i<num; i++){
    delete [] student_record;
  }

  delete [] student_record;
}
