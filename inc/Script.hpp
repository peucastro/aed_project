#include "Uc.hpp"
#include "Student.hpp"
#include "Lecture.hpp"

class Script
{
public:
    Student loadStudent(const std::string &studentCode);
    void studentsInClass(Lecture &oneLecture_);
};
