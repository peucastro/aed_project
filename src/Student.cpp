#include "../inc/Student.hpp"

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
void Student::addLecture(const pair<string, string> &lecture)
{
    schedule.insert(lecture);
}

bool Student::operator==(const Student &other)
{
    return this->studentCode == other.studentCode && this->studentName == other.studentName;
}
