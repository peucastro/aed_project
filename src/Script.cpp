#include "../inc/Script.hpp"
#include <string>
#include <unordered_map>

using namespace std;

// Receives a student code and returns all the that the student is enrolled in.
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

        getline(getline(getline(getline(iss, studentCodeFromFile, ','), studentNameFromFile, ','), ucCodeFromFile, ','), classCodefromFile, '\r');

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

// Receives an UC and adds all the Classes of that UC
void Script::loadClasses(Uc &uc_)
{
    ifstream file;
    file.open("../data/classes_per_uc.csv", std::ios::in);

    if (!file.is_open())
        cout << "not open";
    string line;

    while (getline(file, line))
    {
        istringstream stream(line);
        string Code, ClassCode;

        if (getline(stream, Code, ','))
        {
            if (Code == uc_.getUcCode())
            {
                if (getline(stream, ClassCode))
                {
                    uc_.addClass(ClassCode);
                }
            }
        }
    }
    file.close();
}

// Receives a Lecture and adds all the students of that Lecture
void Script::studentsInClass(Lecture &oneLecture_)
{

    ifstream file("../data/students_classes.csv");
    if (!file.is_open())
    {
        cout << "Failed to open the file." << endl;
    }

    string line;

    while (getline(file, line))
    {
        istringstream iss(line);
        string StudentCode, StudentName, UcCode, classCode;

        getline(getline(getline(getline(iss, StudentCode, ','), StudentName, ','), UcCode, ','), classCode, '\r');

        if ((UcCode == oneLecture_.getUc().getUcCode()) && (classCode == oneLecture_.getClassCode()))
        {
            Student student(StudentCode, StudentName);
            oneLecture_.addStudent(student);
        }
    }

    file.close();
}

vector<Student> Script::studentsinUc(Uc &uc)
{
    vector<Student> students;

    ifstream file("../data/students_classes.csv");
    if (!file.is_open())
    {
        cout << "Failed to open the file." << endl;
    }

    string line;

    while (getline(file, line))
    {
        istringstream iss(line);
        string StudentCode, StudentName, UcCode, classCode;

        getline(getline(getline(getline(iss, StudentCode, ','), StudentName, ','), UcCode, ','), classCode, '\r');

        if (UcCode == uc.getUcCode())
        {
            Student student{StudentCode, StudentName};
            students.push_back(student);
        }
    }

    file.close();
    return students;
}

vector<Student> Script::studentsInYear(const std::string &year)
{
    vector<Student> students;
    ifstream file("../data/students_classes.csv");
    if (!file.is_open())
    {
        cout << "Failed to open the file." << endl;
    }

    string line;

    while (getline(file, line))
    {
        istringstream iss(line);

        if (line.substr(0, 4) == year)
        {
            string StudentCode, StudentName, UcCode, classCode;
            getline(getline(getline(getline(iss, StudentCode, ','), StudentName, ','), UcCode, ','), classCode, '\r');
            Student student{StudentCode, StudentName};

            if (find(students.begin(), students.end(), student) == students.end())
                students.push_back(student);
        }
    }

    file.close();
    return students;
}

//Consultar horário pelo número de estudante

vector<Lecture> Script::getSchedule(const string &studentCode_){
    Script script;
    Student oneStudent_ = script.loadStudent(studentCode_);
    vector<Lecture> result = {};

    ifstream file("../data/classes.csv");
    if (!file.is_open())
    {
        cout << "Failed to open the file." << endl;
        return result;
    }

    string line;

    while (getline(file, line))
    {
        istringstream iss(line);
        string ClassCode,UcCode,Weekday,strStarHour,strDuration,Type;
        double StartHour,Duration;
         //ClassCode,UcCode,Weekday,StartHour,Duration,Type;

        getline(getline(getline(getline(getline(getline(iss, ClassCode, ','), UcCode, ','), Weekday, ','), strStarHour, ','), strDuration, ','), Type, '\r');

        try {
        StartHour = stod(strStarHour);
        Duration = stod(strDuration);
        } catch (const std::invalid_argument& e) {
            //primeira linha de classes.csv sempre irá dar um erro
        } catch (const std::out_of_range& e) {
            std::cerr << "Erro: Conversão fora do alcance. O número é muito grande ou muito pequeno." << std::endl;
        }
        
        if(oneStudent_.inClass(UcCode, ClassCode)){
            
            Lecture lecture(UcCode,ClassCode,Weekday,StartHour,Duration,Type);
            result.push_back(lecture);
        }

    }

    file.close();

    return result;

}

//ADM 1 / CONSULTAR QUANTOS ESTUDANTES ESTÃO INSCRITOS EM PELO O MENOS N UC'S
int Script::studentsInNUc(int number){
    int result = 0;
    int aux = 0;
    ifstream file("../data/students_classes.csv");
    if (!file.is_open())
    {
        cout << "Failed to open the file." << endl;
    }

    unordered_map<string, unordered_map<string, bool>> studentUCs;
    string line;

    
    while (std::getline(file, line)) {
        istringstream iss(line);
        string studentCode, studentName, ucCode, classCode;
        getline(getline(getline(getline(iss, studentCode, ','), studentName, ','), ucCode, ','), classCode, '\r');
        
        studentUCs[studentCode][ucCode] = true;
        
    }

    int count = 0;

    // Contar estudantes inscritos em pelo menos N UCs
    for (const auto& student : studentUCs) {
        if (student.second.size() >= number) {
            count++;
        }
    }

    return count;

}

