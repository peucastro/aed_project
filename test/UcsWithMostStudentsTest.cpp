#include "../inc/Script.hpp"

// g++ -o UcsWithMostStudentsTest UcsWithMostStudentsTest.cpp ../src/Uc.cpp ../src/Student.cpp ../src/Lecture.cpp ../src/Script.cpp

void testUcsWithMostStudents()
{
    std::vector<std::pair<std::string, int>> vec = Script().ucsWithMostStudents();
    for (std::pair<std::string, int> p : vec)
        std::cout << p.first << " - " << p.second << std::endl;
}

int main()
{
    try
    {
        testUcsWithMostStudents();
        std::cout << std::endl
                  << "Compilação finalizada, analisar resultados acima" << std::endl;
    }
    catch (const std::runtime_error &ex)
    {
        std::cerr << "Erro: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
