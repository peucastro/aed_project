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
    void addClass(const string &UcClass);
    void getClasses();
    unsigned int classesCount();
    void setUcCode(string &ucCode);
    

private:
    string UcCode;
    vector<string> UcClasses;
};

#endif
