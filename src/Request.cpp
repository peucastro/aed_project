#include "../inc/Request.hpp"
using namespace std;

unsigned Request::currentId = 0;

Request::Request(std::string studentCode, char type)
    : id(currentId++), studentCode(studentCode), type(type)
{

    switch (type)
    {
    case '1':
    {
        // addUc();
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
        // switchUc();
        break;
    }
    case '4':
    {
        // switchClass();
        break;
    }
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

    ofstream write_log("../requests_log.csv");
    write_log << id << ',' << type << ',' << studentCode << ',' << ucCode << endl;
    write_log.close();

    return flag;
}
