#ifndef AED_PROJECT_UC_H
#define AED_PROJECT_UC_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class Uc
{
public:
    Uc();
    Uc(const std::string &UcCode);
    std::string getUcCode();
    void setUcCode(const std::string &UcCode);
    void addClass(const std::string &UcClass);
    void printClasses();
    unsigned int classesCount();

private:
    std::string UcCode;
    std::vector<std::string> UcClasses;
};

#endif
