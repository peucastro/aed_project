#include "../inc/Uc.hpp"
#include "../inc/Script.hpp"
#include <stdexcept>

using namespace std;

void printClasses(){
    Uc uc = Uc("L.EIC001");
    cout << uc.classesCount() << endl;
    uc.printClasses();
}

int main(){
try{
        printClasses();
        cout << "Código passou!" << endl;
    }catch (const std::runtime_error &ex)
    {
        std::cerr << "Erro: " << ex.what() << std::endl;
        return 1;
    }
    
    return 0;
}