#include "../inc/Lecture.hpp"

// g++ -o LectureTests LectureTests.cpp ../src/Uc.cpp ../src/Student.cpp ../src/Lecture.cpp

void AttributeStudentTests()
{
    Lecture lecture("L.EIC001", "1LEIC01", "Monday", 10.5, 1.5, "TP");
    Student check("202200041", "Leonardo");
    lecture.addStudent(check);
    bool conditionCheck = true;
    for (Student student : lecture.getStudents())
    {
        if (student == check)
            conditionCheck = false;
    }
    if (conditionCheck)
    {
        throw std::runtime_error("Teste addStudent falhou.");
    }
    lecture.removeStudent(check);
    for (Student student : lecture.getStudents())
    {
        if (student == check)
            conditionCheck = true;
    }
    if (conditionCheck)
    {
        throw std::runtime_error("Teste removeStudent falhou.");
    }
}

void LectureFullConstructorTest()
{
    Lecture lecture("L.EIC001", "1LEIC01", "Monday", 10.5, 1.5, "TP");
    if (lecture.getUc().getUcCode() != "L.EIC001" || lecture.getClassCode() != "1LEIC01" || lecture.getWeekDay() != "Monday" || lecture.getDuration() != 1.5 || lecture.getStartHour() != 10.5 || lecture.getType() != "TP")
    {
        throw std::runtime_error("Teste do Full Constructor do lecture falhou.");
    }
}

void LectureConstructorTest()
{
    Lecture lecture("L.EIC001");
    if (lecture.getUc().getUcCode() != "L.EIC001")
    {
        throw std::runtime_error("Teste do constructor default falhou.");
    }
}

int main()
{
    try
    {
        LectureConstructorTest();
        LectureFullConstructorTest();
        AttributeStudentTests();
        std::cout << std::endl
                  << "Compilação finalizada, todos os testes passaram!" << std::endl;
    }
    catch (const std::runtime_error &ex)
    {
        std::cerr << "Erro: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
