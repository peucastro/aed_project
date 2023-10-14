#include "../inc/Class.hpp"
using namespace std;

Class::Class(const string &ucCode)
{

}

Class::Class(const std::string &ucCode, const std::string &classCode, const std::string &weekDay, const double &startHour, const double &duration, const std::string &type)
{
    this->uc.setUcCode(ucCode);
    this->uc.addClass(classCode);
    this->weekDay = weekDay;
    this->startHour = startHour;
    this->duration = duration;
    this->type = type;
}

string Class::getClassCode()
{
    return this->classCode;
}

Uc Class::getUc()
{
    return this->uc;
}

void Class::setUc(const Uc &uc)
{
    this->uc = uc;
}

void Class::addStudent(Student &student)
{
    Student new_student = Student(student.getstudentCode(), student.getstudentName());
    this->students.push_back(new_student);
}

void Class::removeStudent(const Student &student)
{
    int mark;
    for (int i = 0; i < this->students.size(); i++)
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

vector<Student> Class::getStudents()
{
    return this->students;
}

string Class::getWeekDay()
{
    return this->weekDay;
}

void Class::setWeekDay(const string &weekDay)
{
    this->weekDay = weekDay;
}

double Class::getStartHour()
{
    return this->startHour;
}

void Class::setStartHour(const double &startHour)
{
    this->startHour = startHour;
}

double Class::getDuration()
{
    return this->duration;
}

void Class::setDuration(const double &duration)
{
    this->duration = duration;
}

string Class::getType()
{
    return this->type;
}

void Class::setType(const string &type)
{
    this->type = type;
}

bool Class::operator==(Class &other)
{
    if ((this->uc.getUcCode() == other.getUc().getUcCode()) && (this->classCode == other.getClassCode()))
    {
        return true;
    }
    else
        return false;
}
