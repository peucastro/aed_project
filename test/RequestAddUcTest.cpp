#include "../inc/Request.hpp"

// g++ -o RequestAddUcTest RequestAddUcTest.cpp ../src/Request.cpp ../src/Uc.cpp ../src/Student.cpp ../src/Lecture.cpp ../src/Script.cpp

void addUcRequestTest()
{
    Student student_old = Script().loadStudent("202030247");
    std::map<std::string, std::string> old_schedule = student_old.getSchedule();
    std::cout << "HORARIO ANTIGO: " << std::endl;
    for (std::pair<std::string, std::string> p : old_schedule)
        std::cout << p.first << " - " << p.second << std::endl;
    std::cout << std::endl;

    std::string ucCodeDestination;
    std::cout << "Enter the code for the UC you want to enroll: ";
    std::cin >> ucCodeDestination;
    Request("202030247", '1').addUc(ucCodeDestination);

    Student student_new = Script().loadStudent("202030247");
    std::map<std::string, std::string> new_schedule = student_new.getSchedule();
    std::cout << "HORARIO NOVO: " << std::endl;
    for (std::pair<std::string, std::string> p : new_schedule)
        std::cout << p.first << " - " << p.second << std::endl;
}

int main(){
    try{
        addUcRequestTest();
        std::cout << std::endl << "Compilação finalizada, analisar resultados acima" << std::endl;
    }catch(const std::runtime_error &ex){
        std::cerr << "Erro: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
