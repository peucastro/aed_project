#include "../inc/Script.hpp"
#include <stdexcept>

// g++ - o GetScheduleTests GetScheduleTests.cpp../ src / Uc.cpp../ src / Lecture.cpp../ src / Student.cpp../ src / Script.cpp

void getScheduleTest()
{
    Script script;
    std::string input = "202025232";

    if(script.getSchedule(input).size() != 2){
        throw std::runtime_error("Teste falhou");

    }else{
        std::cout << "ESTUDANTE 202025232 :" << std::endl;
        for(Lecture lecture : script.getSchedule(input)){

            std::cout << lecture.getUc().getUcCode() << "-" << lecture.getClassCode() << "-" << lecture.getWeekDay() << "-" << lecture.getStartHour() << "-" << lecture.getDuration() << "-" << lecture.getType() << std::endl;
        }
    }

    input = "202024127";

    if(script.getSchedule(input).size() != 7){
        throw std::runtime_error("Teste falhou");

    }else{
        std::cout << "---------------------------------------" << std::endl << std::endl;
        std::cout << "ESTUDANTE 202024127 :" << std::endl;
        for(Lecture lecture : script.getSchedule(input)){

            std::cout << lecture.getUc().getUcCode() << "-" << lecture.getClassCode() << "-" << lecture.getWeekDay() << "-" << lecture.getStartHour() << "-" << lecture.getDuration() << "-" << lecture.getType() << std::endl;
        }
    }
}

int main(){
    try{
        getScheduleTest();
        std::cout << std::endl << "Compilação finalizada, analisar resultados acima" << std::endl;
    }catch(const std::runtime_error &ex){
        std::cerr << "Erro: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
