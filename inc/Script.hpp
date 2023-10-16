#include "Lecture.hpp"

class Script
{
public:
    Student loadStudent(const std::string &studentCode);
    void studentsInClass(Lecture &oneLecture_);
    void loadClasses(Uc &uc_);
};
