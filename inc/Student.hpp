#ifndef AED_PROJECT_STUDENT_H
#define AED_PROJECT_STUDENT_H

#include "Uc.hpp"
#include <map>

class Student
{
public:
    Student();

    Student(const string &studentCode, const string &studentName);

    string getstudentCode();

    void setstudentCode(const string &studentCode);

    string getstudentName();

    void setstudentName(const string &studentName);

    void addLecture(const pair<string, string> &lecture);

    bool operator==(const Student &other);

private:
    string studentCode;
    string studentName;
    std::map<string, string> schedule;
};

#endif // AED_PROJECT_STUDENT_H
