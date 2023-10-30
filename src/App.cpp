#include "../inc/App.hpp"
using namespace std;

void App::mainMenu()
{
    cout << "Welcome to the L.EIC Schedule Management System" << endl
         << endl;

    int option;
    cout << "Enter your option:" << endl
         << "[1] Student" << endl
         << "[2] Administratot" << endl;
    cin >> option;

    clearScreen();

    switch (option)
    {
    case 1:
    {
        string studentCode;
        cout << "Enter your student code: " << endl, cin >> studentCode;
        studentMenu(studentCode);
        break;
    }
    case 2:
    {
        string login, pass;
        cout << "Enter your login: ", cin >> login, cout << endl;
        cout << "Enter your password: ", cin >> pass, cout << endl;

        if (login == "adm" && pass == "123")
            adminMenu();
        else
        {
            cout << "Wrong credentials, try again" << endl;
            mainMenu();
        }
        break;
    }
    }
}

void App::studentMenu(string studentCode)
{
    cout << "Student menu" << endl
         << endl;

    this->student = Script().loadStudent(studentCode);

    int option;
    cout << "Enter your option: " << endl
         << "[1] Consult your schedule" << endl
         << "[2] Consult Uc" << endl
         << "[3] Consult students" << endl // consultar os estudantes em turma, ano e uc
         << "[4] Make a request" << endl   // tipo do request
         << "[5] Undo a request" << endl
         << "[6] Consult your requests" << endl
         << "[0] Go back to the main menu" << endl;
    cin >> option;

    clearScreen();

    switch (option)
    {
    case 1:
    {
    }
    case 2:
    {
    }
    case 3:
    {
    }
    case 4:
    {
    }
    case 5:
    {
    }
    case 6:
    {
    }
    }
}

void App::adminMenu()
{
    cout << "Administrator menu" << endl
         << endl;

    int option;
    cout << "Enter your option: " << endl
         << "[1] Consult Uc" << endl       // consultar ucs com mais estudantes, turmas da uc
         << "[2] Consult students" << endl // consultar o n de estudantes em pelo menos n ucs, turma, ano e uc
         << "[3] Consult requests" << endl;
    cin >> option;

    clearScreen();

    switch (option)
    {
    case 1:
    {
    }
    case 2:
    {
    }
    case 3:
    {
    }
    }
}
