#ifndef AED_PROJECT_SCRIPT_H
#define AED_PROJECT_SCRIPT_H

#include "Lecture.hpp"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <set>

class Script
{
public:
    Student loadStudent(const std::string &studentCode);
    void loadClasses(Uc &uc_);
    void studentsInLecture(Lecture &oneLecture_);
    std::set<Lecture> getSchedule(const std::string &studentCode);
    std::vector<Student> studentsinUc(Uc &uc);
    std::vector<Student> studentsinClass(std::string ucCode_, std::string classCode_);
    std::unordered_set<Student, Student::Hash> studentsInYear(const std::string &year);
    int studentsInNUc(int number);
};

#endif
