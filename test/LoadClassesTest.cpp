#include "../inc/Script.hpp"
#include <stdexcept>

void printClasses()
{
    Script script;
    Uc uc = Uc("L.EIC001");
    script.loadClasses(uc);
    std::cout << "Número de turmas da Uc: " << uc.classesCount() << std::endl;
    uc.printClasses();
}

int main()
{
    try
    {
        printClasses();
        std::cout << std::endl << "Compilação finalizada, analisar resultados acima" << std::endl;
    }
    catch (const std::runtime_error &ex)
    {
        std::cerr << "Erro: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
