#include "../inc/Student.hpp"
using namespace std;

Student::Student()
{
    this->studentName = "NO_NAME";
    this->studentCode = "NO_CODE";
    this->schedule = {};
}
Student::Student(const string &studentCode, const string &studentName)
{
    this->studentCode = studentCode;
    this->studentName = studentName;
    this->schedule = {};
}
string Student::getstudentCode()
{
    return this->studentCode;
}
void Student::setstudentCode(const string &studentCode)
{
    this->studentCode = studentCode;
}
string Student::getstudentName()
{
    return this->studentName;
}
void Student::setstudentName(const string &studentName)
{
    this->studentName = studentName;
}
void Student::addClass(const pair<string, string> &Class)
{
    for (map<string, string>::iterator it = schedule.begin(); it != schedule.end(); it++)

        schedule.insert(Class);
}

bool Student::operator==(const Student &other)
{
    return this->studentCode == other.studentCode && this->studentName == other.studentName;
}
