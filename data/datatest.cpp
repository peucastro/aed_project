#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
ifstream file("students_classes.csv");
string line;
while(getline(file,line)) cout << line << endl;


    return 0;
}