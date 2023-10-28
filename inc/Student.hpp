#ifndef AED_PROJECT_STUDENT_H
#define AED_PROJECT_STUDENT_H

#include "Uc.hpp"
#include <map>

/**
 * @class Student
 * @brief Represents a student.
 */
class Student
{
public:
    /** @brief Default constructor for the Student class. */
    Student();

    /**
     * @brief Copy constructor for the Student class.
     * @param student_ The student to copy.
     */
    Student(const Student &student_);

    /**
     * @brief Constructor for the Student class with a student code and name.
     * @param studentCode The code associated with the student.
     * @param studentName The name of the student.
     */
    Student(const std::string &studentCode, const std::string &studentName);

    /**
     * @brief Get the student code associated with this student.
     * @return The student code as a string.
     */
    std::string getstudentCode();

    /**
     * @brief Set the student code for this student.
     * @param studentCode The student code to set.
     */
    void setstudentCode(const std::string &studentCode);

    /**
     * @brief Get the name of the student.
     * @return The student name as a string.
     */
    std::string getstudentName();

    /**
     * @brief Get the schedule of the student as a map of UcCode to classCode.
     * @return A map representing the student's schedule.
     */
    std::map<std::string, std::string> getSchedule();

    /**
     * @brief Set the name of the student.
     * @param studentName The name to set for the student.
     */
    void setstudentName(const std::string &studentName);

    /**
     * @brief Add a class to the student's schedule.
     * @param Class A pair of UcCode and classCode to add to the schedule.
     */
    void addClass(const std::pair<std::string, std::string> &Class);

    /**
     * @brief Check if the student is enrolled in a specific class.
     * @param ucCode The UcCode to check.
     * @param classCode The classCode to check.
     * @return True if the student is enrolled in the class, otherwise false.
     */
    bool inClass(const std::string &ucCode, const std::string &classCode);

    /**
     * @brief Overloaded equality operator to compare two students for equality.
     * @param other The student to compare with.
     * @return True if the students are equal, otherwise false.
     */
    bool operator==(const Student &other) const;

    /**
     * @struct Hash
     * @brief Hash function for Student objects.
     */
    struct Hash
    {
        std::size_t operator()(const Student &student) const
        {
            // Combine the hash values of studentCode and studentName to create a unique hash for each student.
            return std::hash<std::string>{}(student.studentCode) ^
                   std::hash<std::string>{}(student.studentName);
        }
    };

private:
    /** The code associated with the student. */
    std::string studentCode;

    /** The name of the student. */
    std::string studentName;

    /** The student's schedule, mapping UcCode to classCode. */
    std::map<std::string, std::string> schedule;
};

#endif
