#include "../headers/Uc.h"

Uc::Uc() : UcCode("NO_NAME") {}

Uc::Uc(const string &UcCode) : UcCode(UcCode) {}

string Uc::getUcCode()
{
    return UcCode;
}
