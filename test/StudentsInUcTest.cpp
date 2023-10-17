#include "../inc/Script.hpp"
#include <stdexcept>

// g++ -o StudentsInUcTest StudentsInUcTest.cpp ../src/Uc.cpp ../src/Student.cpp ../src/Lecture.cpp ../src/Script.cpp

void testStudentsInUc()
{
    Script script;
    Uc uc{"L.EIC001"};
    std::vector<Student> students = script.studentsinUc(uc);

    unsigned short int count = 0;
    for (Student &s : students)
    {
        std::cout << s.getstudentCode() << " - " << s.getstudentName() << std::endl;
        count++;
    }
    std::cout << "Numero total de estudantes nesta Uc: " << count << std::endl;
}

int main()
{
    try
    {
        testStudentsInUc();
        std::cout << "Compilação finalizada, analisar resultados acima" << std::endl;
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
