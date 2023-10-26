#include "../inc/Request.hpp"
using namespace std;

#define MAXIMO 40

Request::Request(string studentCode, char type)
{
    this->studentCode = studentCode;
    this->type = type;

    ifstream log("../requests_log.csv");
    string line;
    char count = 0;
    while (getline(log, line))
        count++;
    this->id = count;
    log.close();

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
    {
        string ucOrigin, ucDestination;
        cout << "Enter the code for the Uc you want to disenroll: ", cin >> ucOrigin, cout << endl;
        cout << "Enter the code for the Uc you want to register for: ", cin >> ucDestination, cout << endl;
        switchUc(ucOrigin, ucDestination);
        break;
    }
    case '4':
        // switchClass();
        break;
    }
}

bool Request::removeUc(string ucCode)
{
    ifstream read_file("../data/students_classes.csv");
    string line;
    queue<string> lines;
    while (getline(read_file, line))
    {
        istringstream iss(line);
        string StudentCode, StudentName, UcCode, classCode;

        getline(getline(getline(getline(iss, StudentCode, ','), StudentName, ','), UcCode, ','), classCode, '\r');

        if (StudentCode == studentCode && UcCode == ucCode)
        {
            this->flag = true;
            continue;
        }

        lines.push(line);
    }
    read_file.close();

    if (this->flag)
    {
        ofstream write_log("../requests_log.csv", ios::app);
        write_log << id << ',' << type << ',' << studentCode << ',' << ucCode << endl;
        write_log.close();
    }
    else
    {
        throw runtime_error("You are not enrolled at this Uc.");
        return this->flag;
    }

    size_t count = lines.size();
    ofstream write_file("../data/students_classes.csv");
    for (int i = 0; i < count; i++)
    {
        write_file << lines.front() << endl;
        lines.pop();
    }
    write_file.close();

    return this->flag;
}

bool Request::addUc(string ucCodeDestination)
{
    Script script;
    Student newStudent = script.loadStudent(this->studentCode);
    map<std::string, std::string> new_schedule = newStudent.getSchedule();
    if(new_schedule.find(ucCodeDestination)!=new_schedule.end()){
        throw runtime_error("Student already registered in this UC");
        return this->flag;
    }

    if (newStudent.getSchedule().size() >= 7)
    {
        throw runtime_error("Student registered in maximum number of UC's");
        return this->flag;
    }

    Uc destination(ucCodeDestination);
    script.loadClasses(destination);
    int max = 0;
    int min = 100;

    vector<string> eligibleClasses = {};
    for (string currClass : destination.getClasses())
    {
        int classSize = script.studentsinClass(destination.getUcCode(), currClass).size();
        if (classSize + 1 > max)
        {
            max = classSize + 1;
        }
        else if (classSize + 1 < min)
        {
            min = classSize + 1;
        }

        if (classSize + 1 <= MAXIMO && (max - classSize - 1) <= 4)
        {
            eligibleClasses.push_back(currClass);
        }
    }

    if (max > MAXIMO)
    {
        throw runtime_error("All classes with maximum occupancy");
        return this->flag;
    }

    if ((max - min) > 4)
    {
        throw runtime_error("Adding the student would affect the balance of classes in this UC");
        return this->flag;
    }

    // StudentCode,StudentName,UcCode,ClassCode

    ofstream outFile("../data/students_classes.csv", ios::app);

    if (!outFile.is_open())
    {
        cerr << "Couldnt open file." << endl;
        return this->flag;
    }

    outFile << newStudent.getstudentCode() << ',' << newStudent.getstudentName() << ',' << destination.getUcCode() << ',' << eligibleClasses[0] << endl;

    outFile.close();

    ofstream write_log("../requests_log.csv", ios::app);
    write_log << id << ',' << type << ',' << studentCode << ',' << destination.getUcCode() << ',' << eligibleClasses[0] << endl;
    write_log.close();

    this->flag = true;
    return this->flag;
}

bool Request::switchUc(string ucOrigin, string ucDestination)
{
    ifstream read_file("../data/students_classes.csv");
    string line;
    queue<string> lines;
    while (getline(read_file, line))
    {
        istringstream iss(line);
        string StudentCode, StudentName, UcCode, classCode;

        getline(getline(getline(getline(iss, StudentCode, ','), StudentName, ','), UcCode, ','), classCode, '\r');

        if (StudentCode == studentCode && UcCode == ucOrigin)
        {
            this->flag = true;
            continue;
        }

        lines.push(line);
    }
    read_file.close();

    if (!(this->flag))
    {
        throw runtime_error("You are not enrolled at this Uc.");
        return this->flag;
    }

    size_t count = lines.size();
    ofstream write_file("../data/students_classes.csv");
    for (int i = 0; i < count; i++)
    {
        write_file << lines.front() << endl;
        lines.pop();
    }
    write_file.close();

    Script script;
    Student newStudent = script.loadStudent(this->studentCode);

    if (newStudent.getSchedule().size() >= 7)
    {
        throw runtime_error("Student registered in maximum number of UC's");
        return this->flag;
    }

    Uc destination(ucDestination);
    script.loadClasses(destination);
    int max = 0;
    int min = 100;

    vector<string> eligibleClasses = {};
    for (string currClass : destination.getClasses())
    {
        int classSize = script.studentsinClass(destination.getUcCode(), currClass).size();
        if (classSize + 1 > max)
        {
            max = classSize + 1;
        }
        else if (classSize + 1 < min)
        {
            min = classSize + 1;
        }

        if (classSize + 1 <= MAXIMO && (max - classSize - 1) <= 4)
        {
            eligibleClasses.push_back(currClass);
        }
    }

    if (max > MAXIMO)
    {
        throw runtime_error("All classes with maximum occupancy");
        return this->flag;
    }

    if ((max - min) > 4)
    {
        throw runtime_error("Adding the student would affect the balance of classes in this UC");
        return this->flag;
    }

    // StudentCode,StudentName,UcCode,ClassCode

    ofstream outFile("../data/students_classes.csv", ios::app);

    if (!outFile.is_open())
    {
        cerr << "Couldnt open file." << endl;
        return this->flag;
    }

    outFile << newStudent.getstudentCode() << ',' << newStudent.getstudentName() << ',' << destination.getUcCode() << ',' << eligibleClasses[0] << endl;

    outFile.close();

    ofstream write_log("../requests_log.csv", ios::app);
    write_log << id << ',' << type << ',' << studentCode << ',' << ucOrigin << ',' << destination.getUcCode() << ',' << eligibleClasses[0] << endl;
    write_log.close();

    this->flag = true;
    return this->flag;
}
