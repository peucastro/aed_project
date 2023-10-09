#include "../inc/Uc.h"

Uc::Uc()
{
    UcCode = "NO_NAME";
    UcClasses;
}

Uc::Uc(const string &UcCode)
{
    this->UcCode = UcCode;
}

string Uc::getUcCode()
{
    return UcCode;
}

void Uc::addClass(const string &UcClass)
{
    for (vector<string>::iterator it = UcClasses.begin(); it != UcClasses.end(); it++)
        if (*it == UcClass)
            return;
    UcClasses.push_back(UcClass);
}

unsigned int Uc::classesCount()
{
    return UcClasses.size();
}
