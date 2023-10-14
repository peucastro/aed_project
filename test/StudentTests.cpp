#include "../inc/Student.hpp"
#include <stdexcept>

void testConstructor()
{
    Student student;
    if (student.getstudentCode() != "NO_CODE" || student.getstudentName() != "NO_NAME")
    {
        throw std::runtime_error("Teste do construtor padrão falhou.");
    }
}

void testConstructorWithParams()
{
    Student student("S123", "John Doe");
    if (student.getstudentCode() != "S123" || student.getstudentName() != "John Doe")
    {
        throw std::runtime_error("Teste do construtor com parâmetros falhou.");
    }
}

void testSetstudentCode()
{
    Student student;
    student.setstudentCode("S456");
    if (student.getstudentCode() != "S456")
    {
        throw std::runtime_error("Teste para definir código de estudante falhou.");
    }
}

void testSetstudentName()
{
    Student student;
    student.setstudentName("Jane Doe");
    if (student.getstudentName() != "Jane Doe")
    {
        throw std::runtime_error("Teste para definir nome de estudante falhou.");
    }
}

int main()
{
    try
    {
        testConstructor();
        testConstructorWithParams();
        testSetstudentCode();
        testSetstudentName();

        std::cout << "Todos os testes passaram." << std::endl;
    }
    catch (const std::runtime_error &ex)
    {
        std::cerr << "Erro: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
