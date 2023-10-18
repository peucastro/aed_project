#include "../inc/Script.hpp"
#include <vector>

using namespace std;

void studentsInNUcsTesting(){
    Script script;

    cout << script.studentsInNUc(3) << endl;;
    cout << script.studentsInNUc(5) << endl;
    cout << script.studentsInNUc(-1) << endl;
    cout << script.studentsInNUc(10) << endl;

}

int main(){
    try{
        studentsInNUcsTesting();
        cout << std::endl << "Compilação finalizada, analisar resultados acima" << endl;
    }catch(const std::runtime_error &ex){
        cerr << "Erro: " << ex.what() << endl;
        return 1;
    }
    return 0;
}