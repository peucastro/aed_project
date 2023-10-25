#include "../inc/Request.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

// g++ -o RequestAddUcTest RequestAddUcTest.cpp ../src/Request.cpp ../src/Uc.cpp ../src/Student.cpp ../src/Lecture.cpp ../src/Script.cpp

void addUcRequestTest()
{
    Request newRequest("202031607", '1');

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
