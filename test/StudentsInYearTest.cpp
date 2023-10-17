#include "../inc/Script.hpp"
#include <stdexcept>

// g++ -o StudentsInYearTest StudentsInYearTest.cpp ../src/Uc.cpp ../src/Student.cpp ../src/Lecture.cpp ../src/Script.cpp

void testStudentsInYear()
{
    Script script;
    std::vector<Student> students = script.studentsInYear("2019");

    if (students.size() != 10)
    {
        throw std::runtime_error("Teste para mostrar o numero de estuantes de um ano falhou.");
    }
}

int main()
{
    try
    {
        testStudentsInYear();
        std::cout << "Compilação finalizada, todos os testes passaram." << std::endl;
    }
    catch (const std::runtime_error &ex)
    {
        std::cerr << "Erro: " << ex.what() << std::endl;
        return 1;
    }
    catch (const std::invalid_argument &ex)
    {
        std::cerr << "Erro: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
