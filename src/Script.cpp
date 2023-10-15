#include "../inc/Script.hpp"
using namespace std;

Student Script::loadStudent(const string &studenCode)
{
    Student student;

    ifstream file("../data/students_classes.csv");

    if (!file.is_open())
    {
        return student;
    }

    string line;
    getline(file, line);

    while (getline(file, line))
    {
        istringstream iss(line);
        string studentCodeFromFile, studentNameFromFile, ucCodeFromFile, classCodefromFile;

        getline(getline(getline(getline(iss, studentCodeFromFile, ','), studentNameFromFile, ','), ucCodeFromFile, ','), classCodefromFile, ',');

        if (studentCodeFromFile == studenCode)
        {
            student.setstudentCode(studentCodeFromFile);
            student.setstudentName(studentNameFromFile);
            student.addClass(pair{ucCodeFromFile, classCodefromFile});
        }
    }

    file.close();

    return student;
}

void Script::studentsInClass(Lecture &oneLecture_){


    ifstream file("../data/students_classes.csv");
    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;

    }

    string line;

    // Ler os dados do arquivo CSV
    while (getline(file, line)) {
        istringstream iss(line);
        string StudentCode, StudentName, UcCode, ClassCode;

        if (getline(iss, StudentCode, ',') &&
            getline(iss, StudentName, ',') &&
            getline(iss, UcCode, ',') &&
            getline(iss, ClassCode)) {
            
            cout << ClassCode << " - " << oneLecture_.getClassCode() << endl;
            if(UcCode == oneLecture_.getUc().getUcCode() && oneLecture_.getClassCode() == ClassCode){
                Student student(StudentCode, StudentName);
                oneLecture_.addStudent(student);
                


            }
        }
    }

    file.close();

}