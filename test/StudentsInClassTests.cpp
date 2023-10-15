#include "../inc/Lecture.hpp"
#include "../inc/Script.hpp"
#include <stdexcept>

using namespace std;

void printStudents(){
    Lecture oneClass("L.EIC002", "1LEIC05","Monday",10.5,2,"TP");
    Script script;
    script.studentsInClass(oneClass);

    for(Student student : oneClass.getStudents()){
        cout << student.getstudentCode() << student.getstudentName() << endl;
    }
}


//g++ -o StudentsInClassTests StudentsInClassTests.cpp ../src/Lecture.cpp ../src/Script.cpp ../src/Student.cpp ../src/Uc.cpp
int main(){
    try{
        printStudents();
    }catch (const std::runtime_error &ex)
    {
        std::cerr << "Erro: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}