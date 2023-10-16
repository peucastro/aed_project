#include "../inc/Script.hpp"
#include <stdexcept>

void testLoadCode()
{
    Script script;
    if (script.loadStudent("202025232").getstudentCode() != "202025232")
    {
        throw std::runtime_error("Teste de carregamento do studentCode falhou.");
    }
}

void testLoadName()
{
    Script script;
    if (script.loadStudent("202031607").getstudentName() != "Gisela")
    {
        throw std::runtime_error("Teste de carregamento do studentName falhou.");
    }
}

void testLoadCompoundName()
{
    Script script;
    if (script.loadStudent("202079037").getstudentName() != "Jose Jesualdo")
    {
        throw std::runtime_error("Teste de carregamento do studentName com nome composto falhou.");
    }
}

int main()
{
    try
    {
        testLoadCode();
        testLoadName();
        testLoadCompoundName();
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
