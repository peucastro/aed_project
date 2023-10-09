#include "../headers/Uc.h"

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
    UcClasses.push_back(UcClass);
}
