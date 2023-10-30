#include "../inc/App.hpp"

using namespace std;

//g++ -o AppTests AppTests.cpp ../src/Uc.cpp ../src/Lecture.cpp ../src/Student.cpp ../src/Script.cpp ../src/Request.cpp ../src/App.cpp


void consultScheduletest(){
    App();
}

int main(){
    try
    {
        consultScheduletest();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}