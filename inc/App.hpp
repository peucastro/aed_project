#ifndef AED_PROJECT_APP_H
#define AED_PROJECT_APP_H

#include "Request.hpp"
#include <cstdlib>

void clearScreen()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

class App
{
public:
    void mainMenu();
    void studentMenu(std::string studentCode);
    void adminMenu();

private:
    Student student;
};

#endif
