#ifndef AED_PROJECT_LECTURE_H
#define AED_PROJECT_LECTURE_H

#include "Student.hpp"
class Lecture
{
public:
    Lecture(const std::string &ucCode);
    Lecture(const std::string &ucCode, const std::string &classCode, const std::string &weekDay, const double &startHour, const double &duration, const std::string &type);
    Uc getUc();
    std::string getClassCode();
    void setUc(const Uc &uc);
    void addStudent(Student &student);
    void removeStudent(const Student &student);
    std::vector<Student> getStudents();
    std::string getWeekDay();
    void setWeekDay(const std::string &weekDay);
    double getStartHour();
    void setStartHour(const double &startHour);
    double getDuration();
    void setDuration(const double &duration);
    std::string getType();
    void setType(const std::string &type);
    bool operator==(Lecture &other);

private:
    Uc uc;
    std::string classCode;
    std::vector<Student> students;
    std::string weekDay;
    double startHour;
    double duration;
    std::string type;
};

#endif
