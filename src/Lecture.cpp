#include "../inc/Lecture.hpp"
using namespace std;

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

string Lecture::getWeekDay() const
{
    return this->weekDay;
}

void Lecture::setWeekDay(const string &weekDay)
{
    this->weekDay = weekDay;
}

double Lecture::getStartHour() const
{
    return this->startHour;
}

void Lecture::setStartHour(const double &startHour)
{
    this->startHour = startHour;
}

double Lecture::getDuration() const
{
    return this->duration;
}

void Lecture::setDuration(const double &duration)
{
    this->duration = duration;
}

string Lecture::getType() const
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

bool Lecture::operator<(const Lecture &other) const
{
std::map<std::string, int> dayValues = {
            {"Monday", 0},
            {"Tuesday", 1},
            {"Wednesday", 2},
            {"Thursday", 3},
            {"Friday", 4},
            {"Saturday", 5},
            {"Sunday", 6}
        };

if(weekDay != other.getWeekDay()){
    return dayValues.at(weekDay) < dayValues.at(other.getWeekDay());
}
return startHour < other.getStartHour();
}

bool Lecture::overlay(Lecture &other){
    if(weekDay != other.getWeekDay()) return false;

    string o_type = other.getType();
    if((type == "TP" && o_type == "TP") || (type == "PL" && o_type == "PL") || (type == "TP" && o_type == "PL") || (type == "PL" && o_type == "TP")){
        if((startHour >= other.getStartHour()) && startHour < (other.getStartHour()+other.getDuration())) return true;
    }
    
    return false;
}