#include "../inc/Script.hpp"
#include <stdexcept>

// g++ -o StudentsInNUcsTest StudentsInNUcsTest.cpp ../src/Uc.cpp ../src/Student.cpp ../src/Lecture.cpp ../src/Script.cpp

void studentsInNUcsTesting(){
    Script script;

    std::cout << script.studentsInNUc(3) << std::endl;;
    std::cout << script.studentsInNUc(5) << std::endl;
    std::cout << script.studentsInNUc(-1) << std::endl;
    std::cout << script.studentsInNUc(10) << std::endl;

}

int main(){
    try{
        studentsInNUcsTesting();
        std::cout << std::endl << "Compilação finalizada, analisar resultados acima" << std::endl;
    }catch(const std::runtime_error &ex){
        std::cerr << "Erro: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
