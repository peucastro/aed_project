#ifndef AED_PROJECT_STUDENT_H
#define AED_PROJECT_STUDENT_H

#include "Uc.hpp"
#include <map>

class Student
{
public:
    Student();

    Student(const Student &student_);

    Student(const std::string &studentCode, const std::string &studentName);

    std::string getstudentCode();

    void setstudentCode(const std::string &studentCode);

    std::string getstudentName();

    void setstudentName(const std::string &studentName);

    void addClass(const std::pair<std::string, std::string> &Class);

    bool inClass(const std::string &ucCode, const std::string &classCode);

    bool operator==(const Student &other);

private:
    std::string studentCode;
    std::string studentName;
    std::map<std::string, std::string> schedule;
};

#endif
