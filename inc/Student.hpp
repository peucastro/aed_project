#ifndef AED_PROJECT_STUDENT_H
#define AED_PROJECT_STUDENT_H

#include "Uc.hpp"

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

#endif // AED_PROJECT_STUDENT_H
