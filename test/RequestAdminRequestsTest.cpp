#include "../inc/Request.hpp"

// g++ -o RequestAdminRequestsTest RequestAdminRequestsTest.cpp ../src/Request.cpp ../src/Uc.cpp ../src/Student.cpp ../src/Lecture.cpp ../src/Script.cpp

using namespace std;

void addUcRequestTest()
{
    Student student_old = Script().loadStudent("202030247");
    std::map<std::string, std::string> old_schedule = student_old.getSchedule();
    std::cout << "HORARIO ANTIGO: " << std::endl;
    for (std::pair<std::string, std::string> p : old_schedule)
        std::cout << p.first << " - " << p.second << std::endl;
    std::cout << std::endl;

    string ucCodeDestination;
    cout << "Enter the code for the UC you want to enroll: ";
    cin >> ucCodeDestination;
    Request("202030247", '1').addUc(ucCodeDestination);

    Student student_new = Script().loadStudent("202030247");
    std::map<std::string, std::string> new_schedule = student_new.getSchedule();
    std::cout << "HORARIO NOVO: " << std::endl;
    for (std::pair<std::string, std::string> p : new_schedule)
        std::cout << p.first << " - " << p.second << std::endl;
}

void testRemoveUc()
{
    Student student_old = Script().loadStudent("202030247");
    std::map<std::string, std::string> old_schedule = student_old.getSchedule();
    std::cout << "HORARIO ANTIGO: " << std::endl;
    for (std::pair<std::string, std::string> p : old_schedule)
        std::cout << p.first << " - " << p.second << std::endl;
    std::cout << std::endl;

    std::string ucCode;
    std::cout << "Enter the code for the Uc you want to disenroll: ", std::cin >> ucCode, std::cout << std::endl;
    Request("202030247", '2').removeUc(ucCode);

    Student student_new = Script().loadStudent("202030247");
    std::map<std::string, std::string> new_schedule = student_new.getSchedule();
    std::cout << "HORARIO NOVO: " << std::endl;
    for (std::pair<std::string, std::string> p : new_schedule)
        std::cout << p.first << " - " << p.second << std::endl;
}

void testSwitchUc()
{
    Student student_old = Script().loadStudent("202030247");
    std::map<std::string, std::string> old_schedule = student_old.getSchedule();
    std::cout << "HORARIO ANTIGO: " << std::endl;
    for (std::pair<std::string, std::string> p : old_schedule)
        std::cout << p.first << " - " << p.second << std::endl;
    std::cout << std::endl;

    std::string ucOrigin, ucDestination;
    std::cout << "Enter the code for the Uc you want to disenroll: ", std::cin >> ucOrigin, std::cout << std::endl;
    std::cout << "Enter the code for the Uc you want to register for: ", std::cin >> ucDestination, std::cout << std::endl;
    Request("202030247", '3').switchUc(ucOrigin, ucDestination);

    Student student_new = Script().loadStudent("202030247");
    std::map<std::string, std::string> new_schedule = student_new.getSchedule();
    std::cout << "HORARIO NOVO: " << std::endl;
    for (std::pair<std::string, std::string> p : new_schedule)
        std::cout << p.first << " - " << p.second << std::endl;
}

void testStudentRequests()
{
    testRemoveUc();
    addUcRequestTest();
    testSwitchUc();
    Request().adminRequests();
}

int main()
{
    try
    {
        testStudentRequests();
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