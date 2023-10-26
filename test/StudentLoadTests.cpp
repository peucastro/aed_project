#include "../inc/Script.hpp"
#include <stdexcept>
#include <iostream>

// g++ -o StudentLoadTests StudentLoadTests.cpp ../src/Script.cpp ../src/Uc.cpp ../src/Student.cpp ../src/Lecture.cpp


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

void testLoadSchedule(){
    Student student_new = Script().loadStudent("202030247");
    std::map<std::string, std::string> new_schedule = student_new.getSchedule();
    std::string uccode = "L.EIC004";
    if(new_schedule.find(uccode)!=new_schedule.end()){
        std::cout << "found"<< std::endl;
    }
    std::cout << "HORARIO NOVO: " << std::endl;
    for (std::pair<std::string, std::string> p : new_schedule)
        std::cout << p.first << " - " << p.second << std::endl;
}

int main()
{
    try
    {
        testLoadSchedule();
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
