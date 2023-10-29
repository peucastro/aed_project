#ifndef AED_PROJECT_REQUEST_H
#define AED_PROJECT_REQUEST_H

#include "../inc/Script.hpp"
#include <queue>
#include <list>

/**
 * @class Request
 * @brief Represents a request to perform various operations related to student enrollments.
 *
 * Request class provides methods for adding, removing, and switching courses and classes for students.
 */
class Request
{
public:
    /** @brief Default constructor for the Request class. */
    Request(){};

    /**
     * @brief Constructor for the Request class to create a new request.
     * @param studentCode The student's unique code.
     * @param type The type of request (1: Add Uc, 2: Remove Uc, 3: Switch Uc, 4: Switch Class).
     */
    Request(std::string studentCode, char type);

    /**
     * @brief Adds a student to a specified course and class.
     * @param ucCodeDestination The code of the course to add the student.
     * @return True if the student is successfully added, false otherwise.
     */
    bool addUc(std::string ucCodeDestination);

    /**
     * @brief Removes a student from a specified course.
     * @param ucCode The code of the course to remove the student from.
     * @return True if the student is successfully removed, false otherwise.
     */
    bool removeUc(std::string ucCode);

    /**
     * @brief Switches a student from one course to another, preserving their schedule.
     * @param ucOrigin The original course code.
     * @param ucDestination The destination course code.
     * @return True if the student's course is successfully switched, false otherwise.
     */
    bool switchUc(std::string ucOrigin, std::string ucDestination);

    /**
     * @brief Switches a student from one class to another within the same course.
     * @param uc The course code.
     * @param classOrigin The original class code.
     * @param classDestination The destination class code.
     * @return True if the student's class is successfully switched, false otherwise.
     */
    bool switchClass(std::string uc, std::string classOrigin, std::string classDestination);

    /**
     * @brief Displays the list of requests for a specific student.
     * @param studentCode The student's unique code.
     */
    void studentRequests(const std::string &studentCode);

    /** @brief Displays all admin requests. */
    void adminRequests();

    /**
     * @brief Undoes a specific request by its ID.
     * @param id The ID of the request to undo.
     */
    void undoRequest(unsigned id);

    bool classesCheck(std::string uc, std::queue<std::string> &eligibleClasses);
private:
    /** Unique ID of the request. */
    unsigned id;

    /** Student's unique code. */
    std::string studentCode;

    /** Type of request (1: Add Uc, 2: Remove Uc, 3: Switch Uc, 4: Switch Class). */
    char type;

    /** A flag indicating the success status of the request. */
    bool flag = false;
};

#endif
