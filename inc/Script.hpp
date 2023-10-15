#include "Uc.hpp"
#include "Student.hpp"
#include "Lecture.hpp"
#include "Uc.hpp"

class Script
{
public:
    Student loadStudent(const std::string &studentCode);
    void studentsInClass(Lecture &oneLecture_);
    void loadClasses(Uc &uc_);
};
