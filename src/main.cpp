#include "../inc/Uc.hpp"
#include <iostream>
#include "../inc/Script.hpp"

using namespace std;

int main(){
    Uc uc = Uc("L.EIC001");
    cout << uc.classesCount() << endl;
    uc.printClasses();

}