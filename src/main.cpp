#include "Uc.cpp"
#include <iostream>
int main(){
    Uc uc = Uc("L.EIC001");
    cout <<uc.classesCount() << endl;
    uc.getClasses();
}