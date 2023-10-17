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

void Uc::printClasses(const string &SortMethod)
{
    if (SortMethod == "1") {
        for (const string &turma : UcClasses)
            cout << turma << endl;
    } else if (SortMethod == "2") {
        for (auto it = UcClasses.rbegin(); it != UcClasses.rend(); ++it)
            cout << *it << endl;
    } else {
        cout << "Selecione um método de ordenação válido" << endl;
    }
}

unsigned int Uc::classesCount()
{
    return UcClasses.size();
}
