#include "../inc/Uc.hpp"
#include <iostream>
Uc::Uc()
{
    UcCode = "NO_NAME";
    UcClasses = vector<string>();
}

Uc::Uc(const string &UcCode)
{
    this->UcCode = UcCode;
    UcClasses = vector<string>();

    ifstream file;
    file.open("../data/classes_per_uc.csv", std::ios::in);

    string line;
    while(getline(file, line)){
        std::istringstream stream(line);
        string Code, ClassCode;
        cout << line << endl;
         if (std::getline(stream, Code, ',')) {
            if(Code != UcCode) break;
            if (std::getline(stream, ClassCode, ',')) {
                UcClasses.push_back(ClassCode);
            }
        }
    }
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

string Uc::getUcClass(const int &i){
    return UcClasses[i];
}

unsigned int Uc::classesCount()
{
    return UcClasses.size();
}