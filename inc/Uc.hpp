#ifndef AED_PROJECT_UC_H
#define AED_PROJECT_UC_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

/**
 * @class Uc
 * @brief Represents a Uc.
 */
class Uc
{
public:
    /** @brief Default constructor for the Uc class. */
    Uc();

    /**
     * @brief Constructor for the Uc class with a given UcCode.
     * @param UcCode The code associated with this Uc.
     */
    Uc(const std::string &UcCode);

    /**
     * @brief Get the UcCode associated with this Uc.
     * @return The UcCode as a string.
     */
    std::string getUcCode();

    /**
     * @brief Set the UcCode for this Uc.
     * @param UcCode The UcCode to set.
     */
    void setUcCode(const std::string &UcCode);

    /**
     * @brief Add a class to the Uc.
     * @param UcClass The name of the class to add.
     */
    void addClass(const std::string &UcClass);

    /**
     * @brief Print the list of classes in this Uc, sorted by SortMethod.
     * @param SortMethod The method for sorting classes ("1" for ascending and "2" for descending).
     */
    void printClasses(const std::string &SortMethod);

    /**
     * @brief Get the number of classes in this Uc.
     * @return The number of classes as an unsigned integer.
     */
    unsigned int classesCount();

    /**
     * @brief Get a vector of class codes associated with this Uc.
     * @return A vector of strings containing class codes.
     */
    std::vector<std::string> getClasses();

private:
    /* The code associated with this Uc. */
    std::string UcCode;

    /* The list of classes within this Uc. */
    std::vector<std::string> UcClasses;
};

#endif
