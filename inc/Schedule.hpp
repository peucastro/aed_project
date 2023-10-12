#ifndef AED_PROJECT_SCHEDULE_H
#define AED_PROJECT_SCHEDULE_H

#include <vector>
#include <string>
#include "Student.hpp"
#include "Class.hpp"
using namespace std;

class Schedule
{
public:
    Schedule();
    void addClass(Class &class_);
    void removeClass(Class &class_);


private:
    vector<Class> studentClasses;
    bool classesCrash(Class &class1, Class &class2);

};

#endif
