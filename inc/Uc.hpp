#ifndef AED_PROJECT_UC_H
#define AED_PROJECT_UC_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Uc
{
public:
    Uc();
    Uc(const string &UcCode);
    string getUcCode();
    void setUcCode(const string &UcCode);
    void addClass(const string &UcClass);
    void printClasses();
    unsigned int classesCount();
private:
    string UcCode;
    vector<string> UcClasses;
};

#endif
