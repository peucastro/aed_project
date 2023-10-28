#ifndef AED_PROJECT_LECTURE_H
#define AED_PROJECT_LECTURE_H

#include "Student.hpp"

/**
 * @class Lecture
 * @brief Represents a lecture.
 */
class Lecture
{
public:
    /**
     * @brief Constructor for Lecture with a UcCode.
     * @param ucCode The UcCode associated with the lecture.
     */
    Lecture(const std::string &ucCode);

    /**
     * @brief Constructor for Lecture with specific details.
     * @param ucCode The UcCode associated with the lecture.
     * @param classCode The class code.
     * @param weekDay The day of the week when the lecture occurs.
     * @param startHour The starting hour of the lecture.
     * @param duration The duration of the lecture.
     * @param type The type of lecture.
     */
    Lecture(const std::string &ucCode, const std::string &classCode, const std::string &weekDay,
            const double &startHour, const double &duration, const std::string &type);

    /**
     * @brief Get the Uc associated with this lecture.
     * @return The Uc object.
     */
    Uc getUc();

    /**
     * @brief Get the class code of the lecture.
     * @return The class code as a string.
     */
    std::string getClassCode();

    /**
     * @brief Set the Uc object associated with this lecture.
     * @param uc The Uc object to set.
     */
    void setUc(const Uc &uc);

    /**
     * @brief Add a student to the lecture.
     * @param student The student to add.
     */
    void addStudent(Student &student);

    /**
     * @brief Remove a student from the lecture.
     * @param student The student to remove.
     */
    void removeStudent(const Student &student);

    /**
     * @brief Get a vector of students enrolled in the lecture.
     * @return A vector of Student objects.
     */
    std::vector<Student> getStudents();

    /**
     * @brief Get the day of the week when the lecture occurs.
     * @return The week day as a string.
     */
    std::string getWeekDay() const;

    /**
     * @brief Set the day of the week when the lecture occurs.
     * @param weekDay The week day to set.
     */
    void setWeekDay(const std::string &weekDay);

    /**
     * @brief Get the starting hour of the lecture.
     * @return The start hour as a double.
     */
    double getStartHour() const;

    /**
     * @brief Set the starting hour of the lecture.
     * @param startHour The start hour to set.
     */
    void setStartHour(const double &startHour);

    /**
     * @brief Get the duration of the lecture.
     * @return The duration as a double.
     */
    double getDuration() const;

    /**
     * @brief Set the duration of the lecture.
     * @param duration The duration to set.
     */
    void setDuration(const double &duration);

    /**
     * @brief Get the type of the lecture.
     * @return The type as a string.
     */
    std::string getType() const;

    /**
     * @brief Set the type of the lecture.
     * @param type The type to set.
     */
    void setType(const std::string &type);

    /**
     * @brief Overloaded equality operator to compare two lectures for equality.
     * @param other The lecture to compare with.
     * @return True if the lectures are equal, otherwise false.
     */
    bool operator==(Lecture &other);

    /**
     * @brief Compare two lectures to determine their order.
     * @param other The lecture to compare with.
     * @return True if this lecture is less than the other, otherwise false.
     */
    bool operator<(const Lecture &other) const;

    /**
     * @brief Check if this lecture's time slot overlaps with another lecture's time slot.
     * @param other The other lecture to check for overlap.
     * @return True if there is an overlap, otherwise false.
     */
    bool overlay(Lecture &other);

private:
    /** The Uc associated with the lecture. */
    Uc uc;

    /** The class code of the lecture. */
    std::string classCode;

    /** The list of students enrolled in the lecture. */
    std::vector<Student> students;

    /** The day of the week when the lecture occurs. */
    std::string weekDay;

    /** The starting hour of the lecture. */
    double startHour;

    /** The duration of the lecture. */
    double duration;

    /** The type of lecture. */
    std::string type;
};

#endif
