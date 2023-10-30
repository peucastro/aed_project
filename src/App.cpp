#include "../inc/App.hpp"
using namespace std;

void clearScreen()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

App::App()
{
    clearScreen();
    mainMenu();
}

void App::mainMenu()
{
    cout << "Welcome to the L.EIC Schedule Management System" << endl
         << endl;

    int option;
    cout << "Enter your option:" << endl
         << "[1] Student" << endl
         << "[2] Administrator" << endl;
    cin >> option;

    clearScreen();

    switch (option)
    {
    case 1:
    {
        string studentCode;
        cout << "Enter your student code: " << endl, cin >> studentCode;
        clearScreen();
        studentMenu(studentCode);
        break;
    }
    case 2:
    {
        string login, pass;
        cout << "Enter your login: ", cin >> login, cout << endl;
        cout << "Enter your password: ", cin >> pass, cout << endl;
        clearScreen();
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
        consultUcSt();
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
    case 0:
    {
        mainMenu();
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

void App::consultUcSt()
{
    cout << "Enter your option: " << endl
         << "[1] Consult the Uc's and classes enrolled" << endl
         << "[2] Consult all classes in a Uc" << endl << endl
         << "[0] Go back to student menu" << endl << endl;
    int option; cin >> option;

    switch (option)
    {
    case 1:
    {
        map<string, string> old_schedule = this->student.getSchedule();
        int num=0;
        for (pair<string, string> p : old_schedule){
        num++;
        cout << p.first << " - " << p.second << endl;
        cout << endl;}
        cout << "You are enrolled in " << num << " Uc's." << endl;

        string back;
        cout << "Press 0 to go back to student menu: ", cin >> back, cout << endl;
        if(back == "0"){
            clearScreen();
            studentMenu(this->student.getstudentCode());
        }
        break;
    }
    case 2:
    {
        Script script;
        string uc, sortmethod, back;
        cout << "Enter uc code: ", cin >> uc, cout << endl << endl;
        Uc ucConsult = Uc(uc);
        script.loadClasses(ucConsult);
        cout << "Sort Method:" << endl
        << "[1] Ascending order" << endl
        << "[2] Descending order" << endl << endl;
        cin >> sortmethod;


        ucConsult.printClasses(sortmethod);

        cout << "Press 0 to go back to student menu: ", cin >> back, cout << endl;
        if(back == "0"){
            clearScreen();
            studentMenu(this->student.getstudentCode());
        }
        break;
    }
    case 0:
    {
        clearScreen();
        studentMenu(this->student.getstudentCode());
        break;
    }
    }
}