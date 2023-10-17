#include "../inc/Lecture.hpp"
using namespace std;

//Implementation of class Lecture

Lecture::Lecture(const string &ucCode) : uc(ucCode)
{
}

Lecture::Lecture(const std::string &ucCode, const std::string &classCode, const std::string &weekDay, const double &startHour, const double &duration, const std::string &type) : uc(ucCode)
{
    this->uc.setUcCode(ucCode);
    this->uc.addClass(classCode);
    this->classCode = classCode;
    this->weekDay = weekDay;
    this->startHour = startHour;
    this->duration = duration;
    this->type = type;
}

string Lecture::getClassCode()
{
    return this->classCode;
}

Uc Lecture::getUc()
{
    return this->uc;
}

void Lecture::setUc(const Uc &uc)
{
    this->uc = uc;
}

void Lecture::addStudent(Student &student)
{
    for (auto it = this->students.begin(); it != this->students.end(); it++)
        if (*it == student)
            return;
    this->students.push_back(student);
}

void Lecture::removeStudent(const Student &student)
{
    int mark;
    for (size_t i = 0; i < this->students.size(); i++)
    {
        if (this->students.at(i) == student)
        {
            mark = i;
        }
    }
    auto it = this->students.begin();
    advance(it, mark);
    this->students.erase(it);
}

vector<Student> Lecture::getStudents()
{
    return this->students;
}

string Lecture::getWeekDay()
{
    return this->weekDay;
}

void Lecture::setWeekDay(const string &weekDay)
{
    this->weekDay = weekDay;
}

double Lecture::getStartHour()
{
    return this->startHour;
}

void Lecture::setStartHour(const double &startHour)
{
    this->startHour = startHour;
}

double Lecture::getDuration()
{
    return this->duration;
}

void Lecture::setDuration(const double &duration)
{
    this->duration = duration;
}

string Lecture::getType()
{
    return this->type;
}

void Lecture::setType(const string &type)
{
    this->type = type;
}

bool Lecture::operator==(Lecture &other)
{
    if ((this->uc.getUcCode() == other.getUc().getUcCode()) && (this->classCode == other.getClassCode()))
    {
        return true;
    }
    else
        return false;
}
