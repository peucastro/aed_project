#ifndef AED_PROJECT_REQUEST_H
#define AED_PROJECT_REQUEST_H

#include "../inc/Script.hpp"
#include <queue>
#include <set>
#include <list>

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
    Request(){};
    Request(std::string studentCode, char type);
    bool addUc(std::string ucCodeDestination);
    bool removeUc(std::string ucCode);
    bool switchUc(std::string ucOrigin, std::string ucDestination);
    bool switchClass(std::string uc, std::string classOrigin, std::string classDestination);
    void studentRequests(const std::string &studentCode);

private:
    unsigned id;
    std::string studentCode;
    char type;
    bool flag = false;
};

#endif
