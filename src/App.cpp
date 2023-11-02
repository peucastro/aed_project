#include "../inc/App.hpp"
#include <iomanip>
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
    cout << "=================================================================================================" << endl;
    cout << "Welcome to the L.EIC Schedule Management System" << endl
         << endl;

    int option;
    cout << "Enter your option:" << endl
         << "[1] Student" << endl
         << "[2] Administrator" << endl
         << endl
         << "[0] Exit" << endl;
    cout << "=================================================================================================" << endl
         << endl;
    cout << "-> ", cin >> option;

    clearScreen();

    if (!(option == 0 or option == 1 or option == 2))
    {
        cout << "Invalid option! please try again:" << endl
             << endl;
        mainMenu();
    }

    switch (option)
    {
    case 1:
    {
        string studentCode;
        cout << "=================================================================================================" << endl;
        cout << "Enter your student code: " << endl;
        cout << "-> ", cin >> studentCode;
        clearScreen();
        studentMenu(studentCode);
        break;
    }
    case 2:
    {
        string login, pass;
        cout << "=================================================================================================" << endl;
        cout << "Enter your login: ", cin >> login, cout << endl;
        cout << "Enter your password: ", cin >> pass, cout << endl;
        clearScreen();
        if (login == "adm" && pass == "123")
        {
            clearScreen();
            adminMenu();
        }
        else
        {
            cout << "Wrong credentials! please try again:" << endl
                 << endl;
            mainMenu();
        }
        break;
    }
    case 0:
    {
        exit(EXIT_SUCCESS);
        break;
    }
    }
}

void App::studentMenu(string studentCode)
{

    this->student = Script().loadStudent(studentCode);
    if (this->student.getstudentName() == "NO_NAME")
    {
        cout << "Invalid student code, please try again:" << endl
             << endl;
        mainMenu();
    }

    cout << "=================================================================================================" << endl;
    cout << "Student menu" << endl
         << endl;

    int option;
    cout << "Enter your option: " << endl
         << "[1] Consult your schedule" << endl
         << "[2] Consult Uc" << endl
         << "[3] Consult students" << endl // consultar os estudantes em turma, ano e uc
         << "[4] Make a request" << endl   // tipo do request
         << "[5] Undo a request" << endl
         << "[6] Consult your requests" << endl
         << endl
         << "[0] Go back to the main menu" << endl;
    cout << "=================================================================================================" << endl
         << endl;
    cout << "-> ", cin >> option;

    clearScreen();

    if (!(option == 0 or option == 1 or option == 2 or option == 3 or option == 4 or option == 5 or option == 6))
    {
        cout << "Invalid option! please try again:" << endl
             << endl;
        studentMenu(this->student.getstudentCode());
    }

    switch (option)
    {
    case 1:
    {
        consultSchedule();
        break;
    }
    case 2:
    {
        consultUcSt();
        break;
    }
    case 3:
    {
        consultStudents();
        break;
    }
    case 4:
    {
        makeRequest();
        break;
    }
    case 5:
    {
        undoRequest();
        break;
    }
    case 6:
    {
        consultRequests();
        break;
    }
    case 0:
    {
        mainMenu();
        break;
    }
    }
}

void App::adminMenu()
{
    cout << "=================================================================================================" << endl;
    cout << "Administrator menu" << endl
         << endl;

    int option;

    cout << "Enter your option: " << endl
         << "[1] Consult Uc" << endl       // consultar ucs com mais estudantes, turmas da uc
         << "[2] Consult students" << endl // consultar o n de estudantes em pelo menos n ucs, turma, ano e uc
         << "[3] Consult requests" << endl
         << endl
         << "[0] Go back to the main menu" << endl;
    cout << "=================================================================================================" << endl
         << endl;
    cout << "-> ", cin >> option;

    clearScreen();

    if (!(option == 0 or option == 1 or option == 2 or option == 3))
    {
        cout << "Invalid option! please try again:" << endl
             << endl;
        adminMenu();
    }

    switch (option)
    {
    case 1:
    {
        consultUcAdm();
        break;
    }
    case 2:
    {
        consultStudentsAdmin();
        break;
    }
    case 3:
    {
        cout << "=================================================================================================" << endl;
        cout << "All requests listed:" << endl
             << endl;
        Request().adminRequests();
        cout << "=================================================================================================" << endl
             << endl;
        cout << "[0] Go back to the Administrator menu" << endl;

        while (true)
        {
            cout << "-> ", cin >> option;
            if (option == 0)
            {
                clearScreen();
                adminMenu();
                break;
            }
            else
            {
                cout << "Wrong option, try again" << endl
                     << endl;
            }
        }
        break;
    }
    case 0:
    {
        mainMenu();
        break;
    }
    }
}

void App::consultUcSt()
{
    cout << "=================================================================================================" << endl;
    cout << "Enter your option: " << endl
         << "[1] Consult the Uc's and classes enrolled" << endl
         << "[2] Consult all classes in a Uc" << endl
         << endl
         << "[0] Go back to student menu" << endl
         << "=================================================================================================" << endl
         << endl;
    int option;
    cout << "-> ", cin >> option;

    clearScreen();

    if (!(option == 0 or option == 1 or option == 2))
    {
        cout << "Invalid option! please try again:" << endl
             << endl;
        consultUcSt();
    }

    switch (option)
    {
    case 1:
    {
        clearScreen();
        cout << "=================================================================================================" << endl;
        cout << this->student.getstudentName() << "'s enrolled Uc's:" << endl
             << endl;
        map<string, string> old_schedule = this->student.getSchedule();
        int num = 0;
        for (pair<string, string> p : old_schedule)
        {
            num++;
            cout << "|" << p.first << " - " << p.second << "|" << endl;
            cout << "|" << setw(19) << "|" << endl;
        }
        cout << endl
             << "You are enrolled in " << num << " Uc's." << endl;
        cout << "=================================================================================================" << endl
             << endl;

        cout << "[0] Go back to the Student menu" << endl
             << endl;

        while (true)
        {
            cout << "-> ", cin >> option;
            if (option == 0)
            {
                clearScreen();
                studentMenu(this->student.getstudentCode());
            }
            else
                cout << "Invalid option, try again" << endl
                     << endl;
        }
        break;
    }
    case 2:
    {
        clearScreen();
        Script script;
        string uc, sortmethod;
        cout << "Enter the uc code: " << endl
             << "-> ",
            cin >> uc, cout << endl;

        Uc ucConsult = Uc(uc);
        script.loadClasses(ucConsult);
        if (ucConsult.classesCount() == 0)
        {
            clearScreen();
            cout << "Invalid UC code! Please try again:" << endl
                 << endl;
            consultUcSt();
        }
        cout << "Sort Method:" << endl
             << "[1] Ascending order" << endl
             << "[2] Descending order" << endl
             << "-> ";
        cin >> sortmethod;
        if (!(sortmethod == "1" or sortmethod == "2"))
        {
            clearScreen();
            cout << "Invalid sort method! Please try again:" << endl
                 << endl;
            consultUcSt();
        }

        clearScreen();
        cout << "=================================================================================================" << endl
             << "All classes at " << uc << ':' << endl;
        ucConsult.printClasses(sortmethod);
        cout << "=================================================================================================" << endl
             << endl;
        cout << "[0] Go back to the Student menu" << endl
             << endl;

        while (true)
        {
            cout << "-> ", cin >> option;
            if (option == 0)
            {
                clearScreen();
                studentMenu(this->student.getstudentCode());
            }
            else
                cout << "Invalid option, try again" << endl
                     << endl;
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

void App::consultUcAdm()
{
    cout << "=================================================================================================" << endl;
    cout << "Enter your option: " << endl
         << "[1] Consult the Uc's with most students" << endl
         << "[2] Consult all classes in a Uc" << endl
         << endl
         << "[0] Go back to the Administrator menu" << endl
         << "=================================================================================================" << endl
         << endl;
    int option;
    cout << "-> ", cin >> option;

    clearScreen();

    if (!(option == 0 or option == 1 or option == 2))
    {
        cout << "Invalid option! please try again:" << endl
             << endl;
        consultUcAdm();
    }

    switch (option)
    {
    case 1:
    {
        cout << "=================================================================================================" << endl
             << "Uc's with most students:" << endl
             << endl;
        vector<pair<string, int>> vec = Script().ucsWithMostStudents();
        for (const pair<string, int> &p : vec)
            cout << p.first << " - " << p.second << endl;
        cout << "=================================================================================================" << endl
             << endl
             << endl;
        cout << "[0] Go back to the Administrator menu" << endl
             << endl;

        while (true)
        {
            cout << "-> ", cin >> option;
            if (option == 0)
            {
                clearScreen();
                adminMenu();
            }
            else
                cout << "Invalid option, try again" << endl
                     << endl;
        }
        break;
    }
    case 2:
    {
        clearScreen();
        Script script;
        string uc, sortmethod;
        cout << "Enter the uc code: " << endl
             << "-> ",
            cin >> uc, cout << endl;

        Uc ucConsult = Uc(uc);
        script.loadClasses(ucConsult);
        if (ucConsult.classesCount() == 0)
        {
            clearScreen();
            cout << "Invalid UC code! Please try again:" << endl
                 << endl;
            consultUcSt();
        }
        cout << "Sort Method:" << endl
             << "[1] Ascending order" << endl
             << "[2] Descending order" << endl
             << "-> ";
        cin >> sortmethod;
        if (!(sortmethod == "1" or sortmethod == "2"))
        {
            clearScreen();
            cout << "Invalid sort method! Please try again:" << endl
                 << endl;
            consultUcSt();
        }

        clearScreen();
        cout << "=================================================================================================" << endl
             << "All classes at " << uc << ':' << endl;
        ucConsult.printClasses(sortmethod);
        cout << "=================================================================================================" << endl
             << endl;
        cout << "[0] Go back to the Administrator menu" << endl
             << endl;

        while (true)
        {
            cout << "-> ", cin >> option;
            if (option == 0)
            {
                clearScreen();
                adminMenu();
            }
            else
                cout << "Invalid option, try again" << endl
                     << endl;
        }
        break;
    }
    case 0:
    {
        adminMenu();
        break;
    }
    }
}

void App::consultSchedule()
{
    cout << "=================================================================================================" << endl
         << this->student.getstudentName() << "'s schedule:" << endl;
    set<Lecture> studentLectures;
    for (auto schedule : this->student.getSchedule())
    {
        for (Lecture lecture : Script().loadLecture(schedule.first, schedule.second))
        {
            studentLectures.insert(lecture);
        }
    }

    for (Lecture lecture : studentLectures)
    {
        cout << "UC: " << std::setw(8) << lecture.getUc().getUcCode() << "|"
             << " Class: " << std::setw(4) << lecture.getClassCode() << "|"
             << " Day: " << std::setw(9) << lecture.getWeekDay() << "|"
             << " Begin: " << std::setw(5) << lecture.getStartHour() << "|"
             << " Ends: " << std::setw(4) << lecture.getDuration() + lecture.getStartHour() << "|"
             << " Type: " << lecture.getType() << std::endl;
    }
    cout << "=================================================================================================" << endl
         << endl;

    cout << "[0] Go back to the Student menu" << endl
         << endl;

    int option;
    while (true)
    {
        cout << "-> ", cin >> option;
        if (option == 0)
        {
            clearScreen();
            studentMenu(this->student.getstudentCode());
        }
        else
            cout << "Invalid option, try again" << endl
                 << endl;
    }
}

void App::consultStudents()
{
    cout << "=================================================================================================" << endl;
    cout << "Enter your option: " << endl
         << "[1] Consult students by year" << endl
         << "[2] Consult students by UC" << endl
         << "[3] Consult students by class" << endl
         << endl
         << "[0] Go back to the student menu" << endl
         << "=================================================================================================" << endl
         << endl;
    int option;
    cout << "-> ", cin >> option;

    if (!(option == 0 or option == 1 or option == 2 or option == 3))
    {
        clearScreen();
        cout << "Invalid option! Please try again:" << endl
             << endl;
        consultStudents();
    }

    switch (option)
    {
    case 1:
    {
        clearScreen();
        string year;
        cout << "=================================================================================================" << endl;
        cout << "Enter the year: " << endl;
        cout << "-> ", cin >> year;
        for (Student student : Script().studentsInYear(year))
        {
            cout << "Student Code: " << std::setw(8) << student.getstudentCode() << "|"
                 << " Name: " << std::setw(3) << student.getstudentName() << setw(40 - student.getstudentName().size()) << "|" << endl;
        }
        cout << "=================================================================================================" << endl
             << endl
             << endl;

        cout << "[0] Go back to the Student menu" << endl
             << endl;

        while (true)
        {
            cout << "-> ", cin >> option;
            if (option == 0)
            {
                clearScreen();
                studentMenu(this->student.getstudentCode());
            }
            else
                cout << "Invalid option, try again" << endl
                     << endl;
        }
        break;
    }
    case 2:
    {
        clearScreen();
        string uc;
        cout << "=================================================================================================" << endl;
        cout << "Enter the UC code: " << endl;
        cout << "-> ", cin >> uc;
        Uc uc_(uc);
        Script().loadClasses(uc_);

        if (uc_.classesCount() == 0)
        {
            clearScreen();
            cout << "Invalid UC code! Please try again:" << endl
                 << endl;
            consultStudents();
        }

        for (Student student : Script().studentsinUc(uc_))
        {
            cout << "Student Code: " << std::setw(8) << student.getstudentCode() << "|"
                 << " Name: " << std::setw(3) << student.getstudentName() << setw(40 - student.getstudentName().size()) << "|" << endl;
        }
        cout << "=================================================================================================" << endl
             << endl
             << endl;

        cout << "[0] Go back to the Student menu" << endl
             << endl;

        while (true)
        {
            cout << "-> ", cin >> option;
            if (option == 0)
            {
                clearScreen();
                studentMenu(this->student.getstudentCode());
            }
            else
                cout << "Invalid option, try again" << endl
                     << endl;
        }
        break;
    }
    case 3:
    {
        clearScreen();
        string classCode, ucCode;
        cout << "=================================================================================================" << endl;
        cout << "Enter the UC code: " << endl;
        cout << "-> ", cin >> ucCode, cout << endl;

        Uc uc_(ucCode);
        Script().loadClasses(uc_);
        if (uc_.classesCount() == 0)
        {
            clearScreen();
            cout << "Invalid UC code! Please try again:" << endl
                 << endl;
            consultStudents();
        }

        cout << "Enter the class code: " << endl;
        cout << "-> ", cin >> classCode, cout << endl;

        vector<string>::iterator it = uc_.getClasses().begin();
        for (it; it != uc_.getClasses().end(); it++)
        {
            if (*it == classCode)
                break;
        }
        if (it == uc_.getClasses().end())
        {
            clearScreen();
            cout << "Invalid Class code! Please try again:" << endl
                 << endl;
            consultStudents();
        }

        clearScreen();
        cout << "=================================================================================================" << endl;
        cout << "Students at uc " << ucCode << " class " << classCode << ":" << endl;
        for (Student student : Script().studentsinClass(ucCode, classCode))
        {
            cout << "Student Code: " << std::setw(8) << student.getstudentCode() << "|"
                 << " Name: " << std::setw(3) << student.getstudentName() << setw(40 - student.getstudentName().size()) << "|" << endl;
        }
        cout << "=================================================================================================" << endl
             << endl
             << endl;

        cout << "[0] Go back to the Student menu" << endl
             << endl;

        while (true)
        {
            cout << "-> ", cin >> option;
            if (option == 0)
            {
                clearScreen();
                studentMenu(this->student.getstudentCode());
            }
            else
                cout << "Invalid option, try again" << endl
                     << endl;
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

void App::consultStudentsAdmin()
{

    cout << "=================================================================================================" << endl;
    cout << "Enter your option: " << endl
         << "[1] Consult students by year" << endl
         << "[2] Consult students by UC" << endl
         << "[3] Consult students by class" << endl
         << "[4] Consult the number of students registered in at lest N UC's"
         << endl
         << "[0] Go back to the Administrator menu" << endl
         << "=================================================================================================" << endl
         << endl;
    int option;
    cout << "-> ", cin >> option;

    if (!(option == 0 or option == 1 or option == 2 or option == 3 or option == 4))
    {
        clearScreen();
        cout << "Invalid option! please try again:" << endl
             << endl;
        consultStudentsAdmin();
    }

    switch (option)
    {
    case 1:
    {
        clearScreen();
        string year;
        cout << "=================================================================================================" << endl;
        cout << "Enter the year: " << endl;
        cout << "-> ", cin >> year;
        for (Student student : Script().studentsInYear(year))
        {
            cout << "Student Code: " << std::setw(8) << student.getstudentCode() << "|"
                 << " Name: " << std::setw(3) << student.getstudentName() << setw(40 - student.getstudentName().size()) << "|" << endl;
        }
        cout << "=================================================================================================" << endl
             << endl
             << endl;

        cout << "[0] Go back to the Administrator menu" << endl;

        while (true)
        {
            cout << "-> ", cin >> option;
            if (option == 0)
            {
                clearScreen();
                adminMenu();
            }
            else
                cout << "Invalid option, try again" << endl
                     << endl;
        }
        break;
    }
    case 2:
    {
        clearScreen();
        string uc;
        cout << "=================================================================================================" << endl;
        cout << "Enter the UC code: " << endl;
        cout << "-> ", cin >> uc;
        Uc uc_(uc);

        Script().loadClasses(uc_);
        if (uc_.classesCount() == 0)
        {
            clearScreen();
            cout << "Invalid Uc code! Please try again:" << endl
                 << endl;
            consultStudentsAdmin();
        }

        for (Student student : Script().studentsinUc(uc_))
        {
            cout << "Student Code: " << std::setw(8) << student.getstudentCode() << "|"
                 << " Name: " << std::setw(3) << student.getstudentName() << setw(40 - student.getstudentName().size()) << "|" << endl;
        }
        cout << "=================================================================================================" << endl
             << endl
             << endl;

        cout << "[0] Go back to the Administrator menu" << endl;

        while (true)
        {
            cout << "-> ", cin >> option;
            if (option == 0)
            {
                clearScreen();
                adminMenu();
            }
            else
                cout << "Invalid option, try again" << endl
                     << endl;
        }
        break;
    }
    case 3:
    {
        clearScreen();
        string classCode, ucCode;
        cout << "=================================================================================================" << endl;
        cout << "Enter the UC code: " << endl;
        cout << "-> ", cin >> ucCode, cout << endl;

        Uc uc_(ucCode);
        Script().loadClasses(uc_);
        if (uc_.classesCount() == 0)
        {
            clearScreen();
            cout << "Invalid UC code! Please try again:" << endl
                 << endl;
            consultStudentsAdmin();
        }

        cout << "Enter the class code: " << endl;
        cout << "-> ", cin >> classCode, cout << endl;

        vector<string>::iterator it = uc_.getClasses().begin();
        for (it; it != uc_.getClasses().end(); it++)
        {
            if (*it == classCode)
                break;
        }
        if (it == uc_.getClasses().end())
        {
            clearScreen();
            cout << "Invalid Class code! Please try again:" << endl
                 << endl;
            consultStudentsAdmin();
        }

        clearScreen();
        cout << "=================================================================================================" << endl;
        cout << "Students at uc " << ucCode << " class " << classCode << ":" << endl;
        for (Student student : Script().studentsinClass(ucCode, classCode))
        {
            cout << "Student Code: " << std::setw(8) << student.getstudentCode() << "|"
                 << " Name: " << std::setw(3) << student.getstudentName() << setw(40 - student.getstudentName().size()) << "|" << endl;
        }
        cout << "=================================================================================================" << endl
             << endl
             << endl;

        cout << "[0] Go back to the Administrator menu" << endl;

        while (true)
        {
            cout << "-> ", cin >> option;
            if (option == 0)
            {
                clearScreen();
                adminMenu();
            }
            else
                cout << "Invalid option, try again" << endl
                     << endl;
        }
        break;
    }
    case 4:
    {
        clearScreen();
        int n;
        cout << "=================================================================================================" << endl;
        cout << "Enter the number of UC's: " << endl;
        cout << "-> ", cin >> n;
        cout << endl
             << "There are " << Script().studentsInNUc(n) << " students registered in at least " << n << " Uc's." << endl;
        cout << "=================================================================================================" << endl
             << endl;

        cout << "[0] Go back to the Administrator menu" << endl;

        while (true)
        {
            cout << "-> ", cin >> option;
            if (option == 0)
            {
                clearScreen();
                adminMenu();
            }
            else
                cout << "Invalid option, try again" << endl
                     << endl;
        }
        break;
    }
    case 0:
    {
        clearScreen();
        adminMenu();
        break;
    }
    }
}

void App::makeRequest()
{
    cout << "=================================================================================================" << endl;
    cout << "Enter your option: " << endl
         << "[1] Enroll in a new Uc" << endl
         << "[2] Disenroll from a Uc" << endl
         << "[3] Switch Uc" << endl
         << "[4] Switch classes"
         << endl
         << endl
         << "[0] Go back to the Student menu" << endl
         << "=================================================================================================" << endl
         << endl;
    cout << "-> ";
    char option;
    cin >> option;

    if (!(option == '0' or option == '1' or option == '2' or option == '3' or option == '4'))
    {
        clearScreen();
        cout << "Invalid option! please try again:" << endl
             << endl;
        makeRequest();
    }

    switch (option)
    {
    case '1':
    {
        clearScreen();
        Request adduc = Request(this->student.getstudentCode(), option);
        string ucCodeDestination;

        map<string, string> old_schedule = this->student.getSchedule();
        cout << "======================== CURRENT SCHEDULE ======================== " << endl;
        for (pair<string, string> p : old_schedule)
            cout << p.first << " - " << p.second << endl;
        cout << "==================================================================" << endl
             << endl;

        cout << "Enter the code for the UC you want to enroll: ", cin >> ucCodeDestination, cout << endl;

        try
        {
            adduc.addUc(ucCodeDestination);
        }
        catch (const runtime_error &err)
        {
            clearScreen();
            cout << "Error: " << err.what() << endl
                 << endl;
            makeRequest();
        }

        Student newStudent = Script().loadStudent(this->student.getstudentCode());
        map<string, string> new_schedule = newStudent.getSchedule();
        cout << "======================== NEW SCHEDULE ============================ " << endl;
        for (pair<string, string> p : new_schedule)
            cout << p.first << " - " << p.second << endl;
        cout << "==================================================================" << endl
             << endl;

        cout << "[0] Go back to the Student menu" << endl
             << endl;
        while (true)
        {
            cout << "-> ", cin >> option;
            if (option == '0')
            {
                clearScreen();
                studentMenu(this->student.getstudentCode());
                break;
            }
            else
            {
                cout << "Invalid option, try again" << endl
                     << endl;
            }
        }
    }
    case '2':
    {
        clearScreen();
        Request removeuc = Request(this->student.getstudentCode(), option);
        string ucCode;

        map<string, string> old_schedule = this->student.getSchedule();
        cout << "======================== CURRENT SCHEDULE ======================== " << endl;
        for (pair<string, string> p : old_schedule)
            cout << p.first << " - " << p.second << endl;
        cout << "==================================================================" << endl
             << endl;
        cout << "Enter the code for the UC you want to disenroll: ", cin >> ucCode;
        cout << endl;

        try
        {
            removeuc.removeUc(ucCode);
        }
        catch (const runtime_error &err)
        {
            clearScreen();
            cout << "Error: " << err.what() << endl
                 << endl;
            makeRequest();
        }

        Student newStudent = Script().loadStudent(this->student.getstudentCode());
        map<string, string> new_schedule = newStudent.getSchedule();
        cout << "======================== NEW SCHEDULE ============================" << endl;
        for (pair<string, string> p : new_schedule)
            cout << p.first << " - " << p.second << endl;
        cout << "==================================================================" << endl
             << endl;
        cout << "[0] Go back to the Student menu" << endl
             << endl;
        while (true)
        {
            cout << "-> ", cin >> option;
            if (option == '0')
            {
                clearScreen();
                studentMenu(this->student.getstudentCode());
                break;
            }
            else
            {
                cout << "Invalid option, try again" << endl
                     << endl;
            }
        }
    }
    case '3':
    {
        clearScreen();
        Request switchuc = Request(this->student.getstudentCode(), option);
        string ucOrigin, ucDestination;

        map<string, string> old_schedule = this->student.getSchedule();
        cout << "======================== CURRENT SCHEDULE ======================== " << endl;
        for (pair<string, string> p : old_schedule)
            cout << p.first << " - " << p.second << endl;
        cout << "==================================================================" << endl
             << endl;
        cout << "Enter the code for the UC you want to disenroll: ", cin >> ucOrigin;
        cout << endl;
        cout << "Enter the code for the UC you want to enroll: ", cin >> ucDestination;
        cout << endl;

        try
        {
            switchuc.switchUc(ucOrigin, ucDestination);
        }
        catch (const runtime_error &err)
        {
            clearScreen();
            cout << "Error: " << err.what() << endl
                 << endl;
            makeRequest();
        }

        Student newStudent = Script().loadStudent(this->student.getstudentCode());
        map<string, string> new_schedule = newStudent.getSchedule();
        cout << "======================== NEW SCHEDULE ============================" << endl;
        for (pair<string, string> p : new_schedule)
            cout << p.first << " - " << p.second << endl;
        cout << "==================================================================" << endl
             << endl;
        cout << "[0] Go back to the Student menu" << endl
             << endl;
        while (true)
        {
            cout << "-> ", cin >> option;
            if (option == 0)
            {
                clearScreen();
                studentMenu(this->student.getstudentCode());
                break;
            }
            else
            {
                cout << "Wrong option, try again" << endl
                     << endl;
            }
        }
    }
    case '4':
    {
        clearScreen();
        Request switchclass = Request(this->student.getstudentCode(), option);
        string uc, classOrigin, classDestination;

        map<string, string> old_schedule = this->student.getSchedule();
        cout << "======================== CURRENT SCHEDULE ======================== " << endl;
        for (pair<string, string> p : old_schedule)
            cout << p.first << " - " << p.second << endl;
        cout << "==================================================================" << endl
             << endl;
        cout << "Enter the code for the UC you want to switch classes: ", cin >> uc;
        cout << endl;
        cout << "Enter the code for the class you want to disenroll: ", cin >> classOrigin;
        cout << endl;
        cout << "Enter the code for the class you want to enroll: ", cin >> classDestination;
        cout << endl;

        try
        {
            switchclass.switchClass(uc, classOrigin, classDestination);
        }
        catch (const runtime_error &err)
        {
            clearScreen();
            cout << "Error: " << err.what() << endl
                 << endl;
            makeRequest();
        }
        Student newStudent = Script().loadStudent(this->student.getstudentCode());
        map<string, string> new_schedule = newStudent.getSchedule();
        cout << "======================== NEW SCHEDULE ============================" << endl;
        for (pair<string, string> p : new_schedule)
            cout << p.first << " - " << p.second << endl;
        cout << "==================================================================" << endl
             << endl;
        cout << "[0] Go back to the Student menu" << endl
             << endl;
        while (true)
        {
            cout << "-> ", cin >> option;
            if (option == 0)
            {
                clearScreen();
                studentMenu(this->student.getstudentCode());
                break;
            }
            else
            {
                cout << "Wrong option, try again" << endl
                     << endl;
            }
        }
    }
    case '0':
    {
        clearScreen();
        studentMenu(this->student.getstudentCode());
        break;
    }
    }
    clearScreen();
}

void App::undoRequest()
{
    unsigned req_id;
    cout << "=================================================================================================" << endl
         << "Enter the request ID you want to undo: " << endl;
    cout << "-> ", cin >> req_id, cout << endl;
    cout << "=================================================================================================" << endl
         << endl;

    try
    {
        Request().undoRequest(req_id);
    }
    catch (const runtime_error &err)
    {
        clearScreen();
        cout << "Error: " << err.what() << endl
             << endl;
        studentMenu(this->student.getstudentCode());
    }

    int option;
    cout << "[0] Go back to the Student menu" << endl
         << endl;
    while (true)
    {
        cout << "-> ", cin >> option;
        if (option == 0)
        {
            clearScreen();
            studentMenu(this->student.getstudentCode());
            break;
        }
        else
        {
            cout << "Wrong option, try again" << endl
                 << endl;
        }
    }
}

void App::consultRequests()
{
    cout << "=================================================================================================" << endl
         << this->student.getstudentName() << "'s requests:" << endl;
    Request().studentRequests(this->student.getstudentCode());
    cout << "=================================================================================================" << endl
         << "[0] Go back to the Student menu" << endl
         << endl;

    int option;
    while (true)
    {
        cout << "-> ", cin >> option;
        if (option == 0)
        {
            clearScreen();
            studentMenu(this->student.getstudentCode());
            break;
        }
        else
        {
            cout << "Wrong option, try again" << endl
                 << endl;
        }
    }
}
