#include "../inc/Script.hpp"
#include <stdexcept>

// g++ -o StudentsInUcTest StudentsInUcTest.cpp ../src/Uc.cpp ../src/Student.cpp ../src/Lecture.cpp ../src/Script.cpp

void testStudentsInUc()
{
    Script script;
    Uc uc{"L.EIC001"};
    std::vector<Student> students = script.studentsinUc(uc);

    if (students.size() != 32)
    {
        throw std::runtime_error("Teste para mostrar o numero de estuantes de uma Uc falhou.");
    }
}

int main()
{
    try
    {
        testStudentsInUc();
        std::cout << "Compilação finalizada, todos os testes passaram" << std::endl;
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
