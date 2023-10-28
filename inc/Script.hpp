#ifndef AED_PROJECT_SCRIPT_H
#define AED_PROJECT_SCRIPT_H

#include "Lecture.hpp"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <list>

class Script
{
public:
    /**
     * @brief Loads a student based on the student code.
     * @param studentCode The student code to load.
     * @return The loaded Student object.
     * @details Time complexity: O(N), where N is the number of lines in the students_classes.csv file.
     */
    Student loadStudent(const std::string &studentCode);

    /**
     * @brief Loads a list of lectures for a specific UC and class code.
     * @param ucCode_ The UC code.
     * @param classCode_ The class code.
     * @return A list of loaded Lecture objects.
     * @details Time complexity: O(N), where N is the number of lines in the classes.csv file.
     */
    std::list<Lecture> loadLecture(std::string ucCode_, std::string classCode_);

    /**
     * @brief Loads classes into a Uc object.
     * @param uc_ The Uc object to load classes into.
     * @details Time complexity: O(N), where N is the number of lines in the classes_per_uc.csv file.
     */
    void loadClasses(Uc &uc_);

    /**
     * @brief Populates a lecture with students who are enrolled in it.
     * @param oneLecture_ The lecture to populate with students.
     * @details Time complexity: O(N), where N is the number of lines in the students_classes.csv file.
     */
    void studentsInLecture(Lecture &oneLecture_);

    /**
     * @brief Gets the schedule of lectures for a student based on their student code.
     * @param studentCode_ The student code.
     * @return A set of Lecture objects representing the student's schedule.
     * @details Time complexity: O(N), where N is the number of lines in the classes.csv file.
     */
    std::set<Lecture> getSchedule(const std::string &studentCode);

    /**
     * @brief Retrieves a list of students enrolled in a specific UC.
     * @param uc The Uc object representing the UC.
     * @return A vector of Student objects.
     * @details Time complexity: O(N), where N is the number of lines in the students_classes.csv file.
     */
    std::vector<Student> studentsinUc(Uc &uc);

    /**
     * @brief Retrieves a list of students enrolled in a specific class.
     * @param ucCode_ The UC code.
     * @param classCode_ The class code.
     * @return A vector of Student objects.
     * @details Time complexity: O(N), where N is the number of lines in the students_classes.csv file.
     */
    std::vector<Student> studentsinClass(std::string ucCode_, std::string classCode_);

    /**
     * @brief Retrieves a set of students based on their enrollment year.
     * @param year The year for which to retrieve students.
     * @return An unordered set of Student objects.
     * @details Time complexity: O(N), where N is the number of lines in the students_classes.csv file.
     */
    std::unordered_set<Student, Student::Hash> studentsInYear(const std::string &year);

    /**
     * @brief Counts the number of students enrolled in at least 'number' UCs.
     * @param number The minimum number of UCs for a student to be counted.
     * @return The count of students meeting the criteria.
     * @details Time complexity: O(N), where N is the number of lines in the students_classes.csv file.
     */
    int studentsInNUc(int number);

    /**
     * @brief Retrieves a list of UCs with the most students, along with the number of students in each UC.
     * @return A vector of pairs, where the first element is the UC code, and the second element is the number of students.
     * @details Time complexity: O(N log N), where N is the number of lines in the students_classes.csv file.
     */
    std::vector<std::pair<std::string, int>> ucsWithMostStudents();
};

#endif
