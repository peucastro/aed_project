#include "../inc/Uc.hpp"
using namespace std;

Uc::Uc()
{
    UcCode = "NO_NAME";
    UcClasses = vector<string>();
}

Uc::Uc(const string &UcCode) : UcCode(UcCode)
{
}

string Uc::getUcCode()
{
    return UcCode;
}

void Uc::setUcCode(const string &UcCode)
{
    this->UcCode = UcCode;
}

void Uc::addClass(const string &UcClass)
{
    for (vector<string>::iterator it = UcClasses.begin(); it != UcClasses.end(); it++)
        if (*it == UcClass)
            return;
    UcClasses.push_back(UcClass);
    sort(UcClasses.begin(), UcClasses.end());
}

void Uc::printClasses()
{
    for (string turma : UcClasses)
        cout << turma << endl;
}

unsigned int Uc::classesCount()
{
    return UcClasses.size();
}
