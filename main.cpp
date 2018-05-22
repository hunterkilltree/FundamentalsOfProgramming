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

void StudentMenu(Data d);



//display function
void AdminHelpMenu();
void TeacherHelpMenu();
void StudentHelpMenu();

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
        std::cout << "Login as student\n";//1713253
        StudentMenu(d);
        Sleep(2000);
    }
    else if (d.role == "teacher")
    {
        std::cout << "Login as teacher\n";//S0951
        TeacherHelpMenu();
        Sleep(2000);
    }
    else if (d.role == "admin")
    {
        std::cout << "Login as admin\n";
        AdminHelpMenu();
        Sleep(2000);
    }
    else
    {
        std::cout << "Error try agian\n";
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
    /*std::cout << "1. Change password [p]        \n"
              << "2. View my Coureses [c]       \n"
              << "3. Search Course [scn]        \n"
              << "4. Join Course [j]            \n"
              << "5. Logout [l]                 \n"
              << "6. Exit [q]                   \n"
              << "7. Help? [h]                  \n" << std::endl;*/

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
