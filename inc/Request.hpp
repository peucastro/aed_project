#ifndef AED_PROJECT_REQUEST_H
#define AED_PROJECT_REQUEST_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>


/*
    Request types:
    1 -> Add Uc
    2 -> Remove Uc
    3 -> Switch Uc
    4 -> Switch Class

*/

class Request
{
public:
    Request(std::string studentCode, char type);
    bool removeUc(std::string ucCode);
    unsigned getId();
    bool addUc(std::string ucCodeDestination);
    bool switchUc();
    bool switchClass();

private:
    unsigned id;
    static unsigned currentId;
    std::string studentCode;
    char type;
};

#endif
