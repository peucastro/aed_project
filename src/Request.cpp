#include "Request.hpp"
using namespace std;

Request::Request(string studentCode, char type)
{
    this->id = currentId++;
    this->studentCode = studentCode;
    this->type = type;

    switch (id)
    {
    case 1:
        addUc();
        break;
    case 2:
        removeUc();
        break;
    case 3:
        switchUc();
        break;
    case 4:
        switchClass();
        break;
    }
}

unsigned Request::getId()
{
    return this->id;
}
