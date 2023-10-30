#include "../inc/Uc.hpp"
#include "../inc/Student.hpp"
#include "../inc/Lecture.hpp"
#include "../inc/Script.hpp"
#include "../inc/Request.hpp"
#include "../inc/App.hpp"


//g++ -o main main.cpp Uc.cpp Lecture.cpp Student.cpp Script.cpp Request.cpp App.cpp


int main()
{
    App app;
    app.mainMenu();
    return 0;
}
