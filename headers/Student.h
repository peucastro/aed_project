//
// Created by marcelmedeiros1 on 09/10/23.
//

#ifndef AED_STUDENT_H
#define AED_STUDENT_H
#include "Uc.h"

class Student{
public:
 Student();
 Student(const string &studentCode, const string &studentName);
 string getstudentCode();
 void setstudentCode(const string &studentCode);
 string getstudentName();
 void setstudentName(const string &studentName);


private:
string studentCode;
string studentName;
Schedule studentSchedule;
};



#endif //AED_STUDENT_H
