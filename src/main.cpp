#include "Uc.cpp"
#include <iostream>
int main(){
    Uc uc = Uc("L.EIC001");
     ifstream file;
    file.open("../data/classes_per_uc.csv", std::ios::in);

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }
    string line;
    while(getline(file, line)){
        cout << line << endl;
    }
}