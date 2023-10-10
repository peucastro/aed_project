#ifndef AED_PROJECT_CLASS_H
#define AED_PROJECT_CLASS_H

#include <vector>
#include "Uc.h"
#include "Student.h"
using namespace std;

class Class
{
public:
    
    Class(string ucCode, string classCode, string weekDay, double startHour, double duration, string type);
    Uc getUc();
    string getClass();
    void setUc(const Uc &uc);
    void addStudent(Student student);
    void removeStudent(Student student);
    vector<Student> getStudents();

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
