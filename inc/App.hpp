#ifndef AED_PROJECT_APP_H
#define AED_PROJECT_APP_H

#include "Student.hpp"
#include "Request.hpp"
#include <cstdlib>

void clearScreen();

class App
{
public:
    App();
    void mainMenu();
    void studentMenu(std::string studentCode);
    void adminMenu();

private:
    Student student;
};

#endif
