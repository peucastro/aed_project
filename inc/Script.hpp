#include "Lecture.hpp"
#include <vector>
class Script
{
public:
    Student loadStudent(const std::string &studentCode);
    void loadClasses(Uc &uc_);
    void studentsInClass(Lecture &oneLecture_);
    std::vector<Lecture> getSchedule(const std::string &studentCode);
};
