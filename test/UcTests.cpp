#include "../inc/Uc.hpp"
#include <stdexcept>

// g++ - o UcTests UcTests.cpp../ src / Uc.cpp

void testConstructor()
{
    Uc uc;
    if (uc.classesCount() != 0)
    {
        throw std::runtime_error("Teste do construtor padrão falhou.");
    }
}

void testConstructorWithCode()
{
    Uc uc("Uc123");
    if (uc.getUcCode() != "Uc123")
    {
        throw std::runtime_error("Teste do construtor com código falhou.");
    }
}

void testAddClass()
{
    Uc uc;
    uc.addClass("Classe1");
    if (uc.classesCount() != 1)
    {
        throw std::runtime_error("Teste para adicionar classe falhou.");
    }
}

void testClassesCount()
{
    Uc uc;
    uc.addClass("Classe1");
    uc.addClass("Classe2");

    if (uc.classesCount() != 2)
    {
        throw std::runtime_error("Teste para obter a contagem de classes falhou.");
    }
}

void testSetUcCode()
{
    Uc uc;
    uc.setUcCode("Uc123");
    if (uc.getUcCode() != "Uc123")
    {
        throw std::runtime_error("Teste para definir código Uc falhou.");
    }
}

int main()
{
    try
    {
        testConstructor();
        testConstructorWithCode();
        testAddClass();
        testClassesCount();
        testSetUcCode();

        std::cout << "Todos os testes passaram." << std::endl;
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
