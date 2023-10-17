#include "Lecture.hpp"
#include <algorithm>

class Script
{
public:
    Student loadStudent(const std::string &studentCode);
    void loadClasses(Uc &uc_);
    void studentsInClass(Lecture &oneLecture_);
    std::vector<Student> studentsinUc(Uc &uc);
    std::vector<Student> studentsInYear(const std::string &year);
};
