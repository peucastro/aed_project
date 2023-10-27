#ifndef AED_PROJECT_UC_H
#define AED_PROJECT_UC_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
class Uc
{
public:
    Uc();
    Uc(const std::string &UcCode);
    std::string getUcCode();
    void setUcCode(const std::string &UcCode);
    void addClass(const std::string &UcClass);
    void printClasses(const std::string &SortMethod);
    unsigned int classesCount();
    std::vector<std::string> getClasses();

private:
    std::string UcCode;
    std::vector<std::string> UcClasses;
};

#endif
