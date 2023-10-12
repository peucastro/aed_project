#ifndef AED_PROJECT_CLASS_H
#define AED_PROJECT_CLASS_H

#include <vector>
#include <string>
#include "Student.hpp"
using namespace std;

class Class
{
public:

    Class(string ucCode, string classCode, string weekDay, double startHour, double duration, string type);
    Uc getUc();
    string getClassCode();
    void setUc(const Uc &uc);
    void addStudent(Student student);
    void removeStudent(Student student);
    vector<Student> getStudents();
    string getWeekDay();
    void setWeekDay(const string &weekDay);
    double getStartHour();
    void setStartHour(const double &startHour);
    double getDuration();
    void setDuration(double const &duration);
    string getType();
    void setType(const string &type);
    bool operator==(Class& other);

private:
    Uc uc;
    string classCode;
    vector<Student> students;
    string weekDay;
    double startHour;
    double duration;
    string type;
};

#endif // AED_PROJECT_CLASS_H
