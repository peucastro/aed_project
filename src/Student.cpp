#include "../inc/Student.hpp"
using namespace std;

Student::Student()
{
    this->studentName = "NO_NAME";
    this->studentCode = "NO_CODE";
    this->schedule = {};
}

Student::Student(const Student &student_)
{
    this->studentName = student_.studentName;
    this->studentCode = student_.studentCode;
    this->schedule = student_.schedule;
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

    schedule.insert(Class);
}

bool Student::inClass(const string &ucCode_, const string &classCode_)
{
    auto it = schedule.find(ucCode_);
    if (it != schedule.end())
    {

        if (it->second == classCode_)
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}

bool Student::operator==(const Student &other) const
{
    return this->studentCode == other.studentCode && this->studentName == other.studentName;
}
