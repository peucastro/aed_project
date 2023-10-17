#include "../inc/Script.hpp"
#include <stdexcept>

// g++ -o StudentsInClassTests StudentsInClassTests.cpp ../src/Uc.cpp ../src/Student.cpp ../src/Lecture.cpp ../src/Script.cpp

void printStudents()
{
    Lecture oneClass("L.EIC002", "1LEIC05", "Monday", 10.5, 2, "TP");
    Script script;
    script.studentsInClass(oneClass);

    for (Student student : oneClass.getStudents())
    {
        std::cout << student.getstudentCode() << " - " << student.getstudentName() << std::endl;
    }
}

int main()
{
    try
    {
        printStudents();
        std::cout << std::endl << "Compilação finalizada, analisar resultados acima" << std::endl;
    }
    catch (const std::runtime_error &ex)
    {
        std::cerr << "Erro: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
