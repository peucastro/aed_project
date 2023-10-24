#include "../inc/Request.hpp"

// g++ -o RequestRemoveUcTests RequestRemoveUcTests.cpp ../src/Request.cpp

void testRemoveUc()
{
    std::string studentCode = "202031607";

    char requestType = '2';

    Request(studentCode, requestType);
}

int main()
{
    try
    {
        testRemoveUc();
        std::cout << std::endl
                  << "Compilação finalizada, analisar os resultados." << std::endl;
    }
    catch (const std::runtime_error &ex)
    {
        std::cerr << "Erro: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
