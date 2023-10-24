#include <string>

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
    unsigned getId();
    bool addUc();
    bool removeUc();
    bool switchUc();
    bool switchClass();

private:
    static unsigned currentId;
    unsigned id;
    std::string studentCode;
    char type;
};

unsigned Request::currentId = 0;
