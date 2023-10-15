#include "../inc/Script.hpp"
using namespace std;

//Receives a student code and returns all the that the student is enrolled in. 
Student Script::loadStudent(const string &studentCode)
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

        if (studentCodeFromFile == studentCode)
        {
            student.setstudentCode(studentCodeFromFile);
            student.setstudentName(studentNameFromFile);
            student.addClass(pair{ucCodeFromFile, classCodefromFile});
        }
    }

    file.close();

    return student;
}


//Receives an UC and adds all the Classes of that UC
void Script::loadClasses(Uc &uc_){
    ifstream file;
    file.open("../data/classes_per_uc.csv", std::ios::in);

    if(!file.is_open()) cout << "not open";
    string line;

    while (getline(file, line)) {
        istringstream stream(line);
        string Code, ClassCode;

        if (getline(stream, Code, ',')) {
            if (Code == uc_.getUcCode()) {
                if (getline(stream, ClassCode)) {
                uc_.addClass(ClassCode);
                    }
            }
        }
    }
    file.close();
}


//Receives a Lecture and adds all the students of that Lecture
void Script::studentsInClass(Lecture &oneLecture_){


    ifstream file("../data/students_classes.csv");
    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;

    }

    string line;

    // Ler os dados do arquivo CSV
    while (getline(file, line)) {
        istringstream iss(line);
        string StudentCode, StudentName, UcCode, classCode;

        getline(getline(getline(getline(iss, StudentCode, ','), StudentName, ','), UcCode, ','), classCode, ',');
            
            if(UcCode == oneLecture_.getUc().getUcCode() && classCode.compare(oneLecture_.getClassCode())){
                Student student(StudentCode, StudentName);
                oneLecture_.addStudent(student);
                
            }
    }

    file.close();

}