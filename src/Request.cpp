#include "../inc/Request.hpp"
#include <iostream>
#include <fstream>
#include "../inc/Student.hpp"
#include "../inc/Script.hpp"
#include "../inc/Uc.hpp"
#include <stdexcept>
#include <set>
using namespace std;

#define MAXIMO 40

unsigned Request::currentId = 0;

Request::Request(string studentCode, char type) : id(currentId++), studentCode(studentCode), type(type)
{
    
    switch (type)
    {
    case '1':
    {
        string ucCodeDestination;
        cout << "Enter the code for the UC you want to enroll: ";
        cin >> ucCodeDestination;
        addUc(ucCodeDestination);
        break;
    }
    case '2':
       {
        string ucCode;
        cout << "Enter the code for the Uc you want to disenroll: ", cin >> ucCode, cout << endl;
        removeUc(ucCode);
        break;
       }
    case '3':
        //switchUc();
        break;
    case '4':
        //switchClass();
        break;
    
    }
}



bool Request::removeUc(string ucCode)
{
    ifstream read_file("../data/students_classes.csv");
    string line;
    queue<string> lines;
    bool flag = false;

    while (getline(read_file, line))
    {
        istringstream iss(line);
        string StudentCode, StudentName, UcCode, classCode;

        getline(getline(getline(getline(iss, StudentCode, ','), StudentName, ','), UcCode, ','), classCode, '\r');

        if (StudentCode == studentCode && UcCode == ucCode)
        {
            flag = true;
            continue;
        }

        lines.push(line);
    }
    read_file.close();

    size_t count = lines.size();
    ofstream write_file("../data/students_classes.csv");
    for (int i = 0; i < count; i++)
    {
        write_file << lines.front();
        lines.pop();
    }
    write_file.close();

    ofstream write_log("../requests_log.csv", ios::app);
    write_log << id << ',' << type << ',' << studentCode << ',' << ucCode << endl;
    write_log.close();

    return flag;
}

bool Request::addUc(string ucCodeDestination){
    Script script;
    Student newStudent = script.loadStudent(this->studentCode);
    /* condicional que checa se o estudante ja esta inscrito naquela uc, sempre retorna verdadeiro não sei pq
    if(newStudent.getSchedule().find(ucCodeDestination)!=newStudent.getSchedule().end()){
        throw runtime_error("Student already registered in this UC");
        return false;
    }
    */
    if(newStudent.getSchedule().size() >= 7){
        throw runtime_error("Student registered in maximum number of UC's");
        return false;
    }


    Uc destination(ucCodeDestination);
    script.loadClasses(destination);
    int max = 0;
    int min = 100;

    vector<string> eligibleClasses = {};
    for(string currClass : destination.getClasses()){
        int classSize = script.studentsinClass(destination.getUcCode(),currClass).size();        
        if(classSize + 1 > max){
            max = classSize + 1;

        }else if(classSize + 1 < min) {
            min = classSize + 1;
        }

        if (classSize + 1 <= MAXIMO && (max - classSize - 1) <= 4) {
            eligibleClasses.push_back(currClass);
        }


    }

    if(max>MAXIMO){
        throw runtime_error("All classes with maximum occupancy");
        return false;
    }

    if((max-min) > 4){
        throw runtime_error("Adding the student would affect the balance of classes in this UC");
        return false;
    }

    //StudentCode,StudentName,UcCode,ClassCode

    ofstream outFile("../data/students_classes.csv", ios::app);

    if(!outFile.is_open()){
        cerr << "Couldnt open file." << endl;
        return false;
    }

    outFile << newStudent.getstudentCode() << ',' << newStudent.getstudentName() << ',' << destination.getUcCode() << ',' << eligibleClasses[0] << endl;
    
    outFile.close();

    ofstream write_log("../requests_log.csv", ios::app);
    write_log << id << ',' << type << ',' << studentCode << ',' << destination.getUcCode() << ',' << eligibleClasses[0] << endl;
    write_log.close();


    return true;

}
