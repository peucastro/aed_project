#ifndef AED_STUDENT_H
#define AED_STUDENT_H

#include "Uc.h"
#include "Schedule.h"

class Student
{
public:

    Student();

    Student(const string &studentCode, const string &studentName);

    string getstudentCode();

    void setstudentCode(const string &studentCode);

    string getstudentName();

    void setstudentName(const string &studentName);

    bool operator==(const Student& other);
    

private:
    string studentCode;
    string studentName;
    Schedule studentSchedule;
};

#endif // AED_STUDENT_H
