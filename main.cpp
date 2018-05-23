#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>


#include <fstream>// ifstream


using namespace std;

struct Data
{
    std::string username;
    std::string password;
    std::string role;
};

//take info -> checkinfo
void TakeInf();
Data CheckInf(Data d);

//Admin function
void ShowUser();

//login run
void StudentMenu(Data d);
void TeacherMenu(Data d);
void AdminMenu(Data d);


//display function
void AdminHelpMenu();
void TeacherHelpMenu();
void StudentHelpMenu();

//need to fix, the error is when we print the final line of file
void ShowInfo(char path[])
{
    ifstream file(path);

    if (!file.is_open())
    {
        std::cout << "ERROR: File Open" << '\n';
        return;
    }

    string id;
    string name;
    string age;
    string phone;
    string address;

    while(file.good())
    {

        getline(file, id, ',');
        getline(file, name, ',');
        getline(file, age, ',');
        getline(file, phone, ',');
        getline(file, address, '\n');

        std::cout << "id: " << id << std::endl;
        std::cout << "name: " << name << std::endl;
        std::cout << "birth: " << age << std::endl;
        std::cout << "phone: " << phone << std::endl;
        std::cout << "address: " << address << std::endl;
        std::cout << "-------------------" << '\n';
    }

    file.close();
}


int main()
{
    int choose = 0;

    do
    {
        std::cout << "1. Sign in\n2. Sign up\n0. Exit\n";
        std::cout << "Your number: ";
        std::cin >> choose;
        getchar();

        if (choose == 0)
            return 0;

        if (choose == 1)
        {
            //(1)
            TakeInf();
        }
        else if (choose == 2)
        {
            //(2)
        }
        else
        {
            std::cout << "Try agian\n";
        }

        system("cls");
    }
    while(1);

    return 0;
}

void TakeInf()
{
    Data d;

    std::cout << "ID: ";
    getline(cin, d.username);
    std::cout << "Password: ";
    getline(cin, d.password);

    d = CheckInf(d);
    if (d.role == "student")
    {
        system("cls"); // windows.h
        std::cout << "Login as student\n";//1713253
        StudentMenu(d);
        Sleep(2000);
    }
    else if (d.role == "teacher")
    {
        system("cls");
        std::cout << "Login as teacher\n";//S0951
        TeacherMenu(d);
        Sleep(2000);
    }
    else if (d.role == "admin")
    {
        system("cls");
        std::cout << "Login as admin\n";
        AdminMenu(d);
        Sleep(2000);
    }
    else
    {
        std::cout << "Error try again\n";
        Sleep(1000);
    }

}

Data CheckInf(Data d)
{
    char file[] = "data\\user.csv";
    ifstream inFile(file);

    if ( !inFile.is_open() )
    {
        std::cout << "Error file" << std::endl;
        exit(0);
    }

    std::string id;
    std::string pass;
    std::string role;

    while(inFile.good())
    {
        getline(inFile, id, ',');
        getline(inFile, pass, ',');
        getline(inFile, role, '\n');

        if (id == d.username && pass == d.password)
        {
            inFile.close();

            d.role = role;
            return d;
        }
    }
    inFile.close();

    d.password = "";
    d.role = "";
    d.username = "";
    return d;
}

void StudentMenu(Data s)
{
    int num = 0;

    do
    {
        std::cout << "1. Change password [p]        \n"
                  << "2. View my Coureses [c]       \n"
                  << "3. Search Course [scn]        \n"
                  << "4. Join Course [j]            \n"
                  << "5. Logout [l]                 \n"
                  << "6. Exit [q]                   \n"
                  << "7. Help? [h]                  \n" << std::endl;

        std::cout << "Your number : ";
        cin >> num;
        getchar();

        switch(num)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5: //logout
                return;
            case 6://exit
                exit(0);
            case 7: //help
                StudentHelpMenu();
                break;
            default:
                std::cout << "Try agian\n";
                break;
        }

        system("cls");
    }
    while(1);

    Sleep(10000);
}

//Code of VO Dong Ho
void AdminMenu(Data d)
{
    int num = 0;

    do
    {
        std::cout << "1. Show User              \n"
                  << "2. Search User            \n"
                  << "3. Add User               \n"
                  << "4. Delete User [dt] [ds]  \n"
                  << "5. Logout [l]             \n"
                  << "6. Exit [q]               \n"
                  << "7. Help?? [h]             \n" << std::endl;

        std::cout << "Your number : ";
        std::cin >> num;;
        getchar();

        switch(num)
        {
            case 1:
                ShowUser();
                break;
            case 2:
                //
                break;
            case 3:
                //
                break;
            case 4:
                //
                break;
            case 5:
                //
                return;
            case 6:
                //
                exit(0);
            case 7:
                AdminHelpMenu();
                break;
            default:
                std::cout << "try again\n";
                break;
        }

    }
    while(1);

    system("cls");

    Sleep(10000);

}

void TeacherMenu(Data d)
{
    int num = 0;

    do
    {
        std::cout << "1. Change password [p]            \n"
                  << "2. View my courses [c]            \n"
                  << "3. Search courses [scn]           \n"
                  << "4. Open course [o] [a]            \n"
                  << "5. Summarize Score [s] [sum]      \n"
                  << "6. Revise Score [r]               \n"
                  << "7. Logout [l]                     \n"
                  << "8. Exit [q]                       \n"
                  << "9. Help?? [h]                     \n" << std::endl;
        std::cout << "Your number : ";
        std::cin >> num;
        getchar();

        switch(num)
        {
            case 1:
                //
                break;
            case 2:
                //
                break;
            case 3:
                //
                break;
            case 4:
                //
                break;
            case 5:
                //
                break;
            case 6:
                //
                break;
            case 7:
                //
                return;
            case 8:
                //
                exit(0);
            case 9:
                TeacherHelpMenu();
                break;
            default:
                std::cout << "Try again\n";
                break;
        }
        system("cls");
    }
    while(1);

    Sleep(10000);
}
//above

//admin function
void ShowUser()
{
    int num = 0;

    do
    {
        std::cout << "1.Show all Faculties\n";
        std::cout << "2.Show all Students\n";

        std::cout << "Your number : ";
        std::cin >> num;
        getchar();

        switch(num)
        {
            case 1:
                ShowInfo("data\\teacher.csv");
                return;

            case 2:
                ShowInfo("data\\student.csv");
                return;

            default :
                std::cout << "Try again";
                break;
        }
    }
    while(1);

    std::cout << '\n';
}







//Intruction Menu
void AdminHelpMenu()
{
    cout << "*Change Password            [p]   [passwd]\n"
         << "\n*Show User\n"
         << "|___Show faculty            [f]   [t]     [1 1]  \n"
         << "|___Show Student            [s]           [1 1]  \n"
         << "\n*Search User by name\n"
         << "|___Search Faculty by name  [sfn] [stn]   [2 1]  \n"
         << "|___Search Student by name  [ssn]         [2 2]   \n"
         << "\n*Add User\n"
         << "|___Add Faculty             [af]  [at]    [3 1]    \n"
         << "|___Add Studdent            [as]          [2 2]    \n"
         << "\n*Delete User\n"
         << "|___Delete Falculty         [df]  [dt]    [4 1]     \n"
         << "|___Delete Student          [ds]          [4 2]      \n";

    cout << "Press enter to continue ......";
    getchar();
}

void TeacherHelpMenu()
{
    cout << "*Change\n\n"
         << "|___ Password             [p]    [passwd]\n\n"
         << "|___ Address              [ca]            \n\n"
         << "|___ Phone                [cp]            \n\n"
         << "*View all course          [c]             \n\n"
         << "|__View all student       [v]              \n"
         << "   in course                               \n"
         << "*Search course            [s]     [sc]      \n"
         << "|__Search course by name  [scn]           \n"
         << "|__Search course          [scn]            \n"
         << "   by falculty            [scf]   [sct]    \n\n"
         << "*Open course              [o]     [oc]      \n\n"
         << "*Summarize score          [s]     [sum]     \n\n"
         << "*Revise score             [r]     [revise]   \n\n";

    cout << "Press enter to continue ......";

    getchar();
}

void StudentHelpMenu()
{
    cout << "*Change Password            [p]    [passwd]  \n\n"
         << "*View all course            [c]             \n\n"
         << "|___View all student        [v]             \n"
         << "    in course                               \n\n"
         << "*Search course              [s]    [sc]      \n\n"
         << "|___Search course by name   [sfn]  [stn]     \n"
         << "|___Search course           [sct]           \n"
         << "    by faculty              [scf]  [sct]     \n\n"
         << "*Join course                [j]    [jc]      \n\n"
         << "*Summarize score            [s]    [sum]     \n\n";

    cout << "Press enter to continue ......";
    getchar();
}






