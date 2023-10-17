#include "../inc/Script.hpp"
#include <vector>

using namespace std;

void getScheduleTest(){
    Script script;
    string input = "202025232";
    
    if(script.getSchedule(input).size() != 2){
        throw std::runtime_error("Teste falhou");

    }else{
        cout << "ESTUDANTE 202025232 :" << endl;
        for(Lecture lecture : script.getSchedule(input)){
        
            cout << lecture.getUc().getUcCode() << "-" << lecture.getClassCode() << "-" << lecture.getWeekDay() << "-" << lecture.getStartHour() << "-" << lecture.getDuration() << "-" << lecture.getType() << endl;
        }
    }

    input = "202024127";

    if(script.getSchedule(input).size() != 7){
        throw std::runtime_error("Teste falhou");

    }else{
        cout << "---------------------------------------" << endl << endl;
        cout << "ESTUDANTE 202024127 :" << endl;
        for(Lecture lecture : script.getSchedule(input)){
        
            cout << lecture.getUc().getUcCode() << "-" << lecture.getClassCode() << "-" << lecture.getWeekDay() << "-" << lecture.getStartHour() << "-" << lecture.getDuration() << "-" << lecture.getType() << endl;
        }
    }

    

}

int main(){
    try{
        getScheduleTest();
        cout << std::endl << "Compilação finalizada, analisar resultados acima" << endl;
    }catch(const std::runtime_error &ex){
        cerr << "Erro: " << ex.what() << endl;
        return 1;
    }
    return 0;
}