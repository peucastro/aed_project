#include "../inc/Uc.hpp"
using namespace std;

Uc::Uc()
{
    UcCode = "NO_NAME";
    UcClasses = vector<string>();
}

Uc::Uc(const string &UcCode) : UcCode(UcCode)
{
    ifstream file;
    file.open("../data/classes_per_uc.csv", std::ios::in);

    string line;

    while (getline(file, line))
    {
        istringstream stream(line);
        string Code, ClassCode;

        if (getline(stream, Code, ','))
        {
            if (Code == UcCode)
            {
                if (getline(stream, ClassCode, ','))
                {
                    UcClasses.push_back(ClassCode);
                }
            }
        }
    }
    file.close();
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
