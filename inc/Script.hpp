#include "Uc.hpp"
#include "Class.hpp"
#include "Student.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

class Script
{
public:
    Student loadStudent(const string &studentCode);
};
