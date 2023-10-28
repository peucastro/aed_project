#include "../inc/Script.hpp"
#include <stdexcept>

// g++ - o LoadLectureTest LoadLectureTests.cpp../ src / Uc.cpp../ src / Lecture.cpp../ src / Student.cpp../ src / Script.cpp

void loadLectureTest()
{
    Script script;
    
        for(Lecture lecture : script.loadLecture("L.EIC001","1LEIC11")){

            std::cout << lecture.getUc().getUcCode() << "-" << lecture.getClassCode() << "-" << lecture.getWeekDay() << "-" << lecture.getStartHour() << "-" << lecture.getDuration() << "-" << lecture.getType() << std::endl;
        
    }

}

int main(){
    try{
        loadLectureTest();
        std::cout << std::endl << "Compilação finalizada, analisar resultados acima" << std::endl;
    }catch(const std::runtime_error &ex){
        std::cerr << "Erro: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}