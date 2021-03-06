//next time


//add user using C not C++


#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>


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
void ShowInfoTeacher(char path[]);//deprecated conversion from string
void ShowInfoStudent(char path[]);
void SearchUser();
void AddUser();

//Delete function,Delete both in their file and user.csv
void DeleteUser();
string CheckRole(string);
void DeleteInfoTeacher(string name);
void DeleteInfoStudent(string name);
void DeleteInUser(string name);

void StoreInTemp();


//Teacher function
void TeachersOwnCourse(string id);
void SearchCoursesByName();
void SearchCoursesName(string temp);

//Student function
void StudentsOwnCourse(string id);

//login run
void StudentMenu(Data d);
void TeacherMenu(Data d);
void AdminMenu(Data d);


//display function
void AdminHelpMenu();
void TeacherHelpMenu();
void StudentHelpMenu();


//add student
void AddUser();
void AddTeacher();
void AddStudent();


//change password
void ChangePassword(Data d);
void StoreInMain(string, string, string);

//Admin Search
void SearchUser();
void SearchByName();
void SearchName(string temp);

void SearchByAddress();
void SearchAddress(string temp);

void SearchByPhone();
void SearchPhone(string temp);


//Join Course
void JoinCourseByID();
void JoinCourseID(string temp);
void StoreInTemp(string teacher_id, string subject_id, string subject_name, int n_student, string slot, string credit);

int main()
{
    int choose = 0;

    do
    {
        std::cout << "1. Sign in\n2. Exit\n";
        std::cout << "Your number: ";
        std::cin >> choose;
        getchar();

        if (choose == 2)
            return 0;

        else if (choose == 1)
        {
            TakeInf();
        }
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
    }
    else if (d.role == "teacher")
    {
        system("cls");
        std::cout << "Login as teacher\n";//S0951
        TeacherMenu(d);
    }
    else if (d.role == "admin")
    {
        system("cls");
        std::cout << "Login as admin\n";
        AdminMenu(d);
    }
    else
    {
        std::cout << "Press enter to try again\n";
        getchar();
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
                ChangePassword(s);
                break;
            case 2:
                StudentsOwnCourse(s.username);
                break;
            case 3:
                SearchCoursesByName();
                break;
            case 4:
                JoinCourseByID();//after Search take the id of course
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
        //system("cls");
    }
    while(1);
}

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
                  << "7. Help?? [h]             \n"
                  << "8. Change Password        \n" << std::endl;

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
                SearchUser();
                break;
            case 3:
                AddUser();
                break;
            case 4:
                //
                DeleteUser();
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
            case 8:
                ChangePassword(d);
                break;
            default:
                std::cout << "try again\n";
                break;
        }

    }
    while(1);

    system("cls");
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
                ChangePassword(d);
                break;
            case 2:
                TeachersOwnCourse(d.username);
                break;
            case 3:
                SearchCoursesByName();
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
    }
    while(1);
}


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
                ShowInfoTeacher("data\\teacher.csv");
                return;

            case 2:
                ShowInfoStudent("data\\student.csv");
                return;

            default :
                std::cout << "Try again";
                break;
        }
    }
    while(1);

    std::cout << '\n';
}

void ShowInfoTeacher(char path[])
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

    getline(file, id, ',');
    getline(file, name, ',');
    getline(file, age, ',');
    getline(file, phone, ',');
    getline(file, address, '\n');

    while(file.good())
    {
        std::cout << "id: " << id << std::endl;
        std::cout << "name: " << name << std::endl;
        std::cout << "birth: " << age << std::endl;
        std::cout << "phone: " << phone << std::endl;
        std::cout << "address: " << address << std::endl;
        std::cout << "-------------------" << '\n';

        getline(file, id, ',');
        getline(file, name, ',');
        getline(file, age, ',');
        getline(file, phone, ',');
        getline(file, address, '\n');
    }

    file.close();
}

void ShowInfoStudent(char path[])
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
    string address;

    getline(file, id, ',');
    getline(file, name, ',');
    getline(file, age, ',');
    getline(file, address, '\n');

    while(file.good())
    {
        std::cout << "id: " << id << std::endl;
        std::cout << "name: " << name << std::endl;
        std::cout << "birth: " << age << std::endl;
        std::cout << "address: " << address << std::endl;
        std::cout << "-------------------" << '\n';

        getline(file, id, ',');
        getline(file, name, ',');
        getline(file, age, ',');
        getline(file, address, '\n');
    }

    file.close();
}


//AddUser call Addteacher or AddStudent
void AddUser()
{
    string choice;

    std::cout << "1.Add Student [as] \n";
    std::cout << "2.Add Teacher [at]\n";

    do
    {
        getline(cin, choice);

        if (choice == "1" || choice  == "as")
        {
            AddStudent();
            break;
        }
        else if (choice == "2" || choice == "at")
        {
            AddTeacher();
            break;
        }
    }
    while(1);
}

void AddStudent()
{
    system("cls");

    char username[100] = "", name[100] = "",
         date[50] = "", address[100] = "";

    std::cout << "User name | Name | Date of birth | Address: "  << '\n';

    gets(username);
    gets(name);
    gets(date);
    gets(address);

    FILE *fdata;

    //store in student.csv
    fdata = fopen("data\\student.csv", "a");

    if (fdata == NULL)
    {
        printf("error when opening file");
        return;
    }

    fprintf(fdata, "%s", username);
    fprintf(fdata, ",");
    fprintf(fdata, "%s", name);
    fprintf(fdata, ",");
    fprintf(fdata, "%s", date);
    fprintf(fdata, ",");
    fprintf(fdata, "%s\n", address);

    fclose(fdata);

    //store in user.csv
    fdata = fopen("data\\user.csv", "a");

    if (fdata == NULL)
    {
        printf("error when opening file");
        return;
    }

    fprintf(fdata, "%s", username);
    fprintf(fdata, ",");
    fprintf(fdata, "%s", username);
    fprintf(fdata, ",");
    fprintf(fdata, "%s\n", "student");

    fclose(fdata);

    std::cout << "Create user " << username << " sucess\n";
}

void AddTeacher()
{
    system("cls");

    char username[100] = "", name[100] = "", phone[100] = "",
         date[50] = "", address[100] = "";

    std::cout << "User name | Name | Date of birth | Phone | Address: "  << '\n';

    gets(username);
    gets(name);
    gets(date);
    gets(phone);
    gets(address);

    FILE *fdata;

    //store in teacher.csv
    fdata = fopen("data\\teacher.csv", "a");

    if (fdata == NULL)
    {
        printf("error when opening file");
        return;
    }

    fprintf(fdata, "%s", username);
    fprintf(fdata, ",");
    fprintf(fdata, "%s", name);
    fprintf(fdata, ",");
    fprintf(fdata, "%s", date);
    fprintf(fdata, ",");
    fprintf(fdata, "%s", phone);
    fprintf(fdata, ",");
    fprintf(fdata, "%s\n", address);

    fclose(fdata);

    //store in user.csv
    fdata = fopen("data\\user.csv", "a");

    if (fdata == NULL)
    {
        printf("error when opening file");
        return;
    }

    fprintf(fdata, "%s", username);
    fprintf(fdata, ",");
    fprintf(fdata, "%s", username);
    fprintf(fdata, ",");
    fprintf(fdata, "%s\n", "teacher");

    fclose(fdata);

    std::cout << "Create user " << username << "sucess" << std::endl;
}

//teacher function
void TeachersOwnCourse(string id)
{
    system("cls");

    ifstream file("data\\course.csv");

    if (!file.is_open())
    {
        std::cout << "ERROR: File Open" << '\n';
        return;
    }

    string teacher_id;
    string subject_id;
    string subject_name;
    string n_student;
    string slot;
    string credit;

    getline (file, teacher_id, ',');
    getline(file, subject_id, ',');
    getline(file, subject_name, ',');
    getline(file, n_student, ',');
    getline(file, slot, ',');
    getline(file, credit, '\n');

    int i = 1;
    while(file.good())
    {
        if (teacher_id == id)
        {
            std::cout << "STT: " << i << std::endl;
            std::cout << "Subject ID: " << subject_id << std::endl;
            std::cout << "Subject Name: " << subject_name << std::endl;
            std::cout << "Student / Slot: " << n_student << " / "<< slot << std::endl;
            std::cout << "credit: " << credit << std::endl;
            std::cout << "-------------------" << '\n';

            i++;
        }

        getline (file, teacher_id, ',');
        getline(file, subject_id, ',');
        getline(file, subject_name, ',');
        getline(file, n_student, ',');
        getline(file, slot, ',');
        getline(file, credit, '\n');
    }

    file.close();
}


//student function 2.View course
void StudentsOwnCourse(string id)
{
    system("cls");

    ifstream file("data\\object.csv");

    if (!file.is_open())
    {
        std::cout << "ERROR: File Open" << '\n';
        return;
    }

    string subject_id;
    string student_id;
    string teacher_id;
    string score;

    getline(file, subject_id, ',');
    getline(file, student_id, ',');
    getline(file, teacher_id, ',');
    getline(file, score, '\n');

    int i = 1;
    while(file.good())
    {
        if (student_id == id)
        {
            std::cout << "STT: " << i << std::endl;
            std::cout << "Subject ID: " << subject_id << std::endl;
            std::cout << "Teacher ID: " << teacher_id << std::endl;
            std::cout << "Score: " << score << std::endl;
            std::cout << "-------------------" << '\n';
            i++;
        }

        getline(file, subject_id, ',');
        getline(file, student_id, ',');
        getline(file, teacher_id, ',');
        getline(file, score, '\n');
    }

    file.close();
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
    system("cls");

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

    system("cls");
}

void StudentHelpMenu()
{
    system("cls");

    std::cout << "*Change Password            [p]    [passwd]  \n\n"
         << "*View all course            [c]             \n\n"
         << "|___View all student        [v]             \n"
         << "    in course                               \n\n"
         << "*Search course              [s]    [sc]      \n\n"
         << "|___Search course by name   [sfn]  [stn]     \n"
         << "|___Search course           [sct]           \n"
         << "    by faculty              [scf]  [sct]     \n\n"
         << "*Join course                [j]    [jc]      \n\n"
         << "*Summarize score            [s]    [sum]     \n\n";

    std::cout << "Press enter to continue ......";
    getchar();
}



//change password function
void StoreInTemp(string id, string name, string role)
{
    ofstream file("data\\temp.csv",ios::out | ios::app | ios::binary);

    if (!file.is_open())
    {
        std::cout << "ERROR: File Open" << '\n';
        return;
    }

    file << id << ","  << name << "," << role <<"\n";

    file.close();
}

void ChangePassword(Data user)
{
    ifstream f("data\\user.csv");

    string id ;
    string password;
    string role;

    if (!f.is_open())
    {
        std::cout << "ERROR: File Open" << '\n';
        return;
    }

    string newpassword;

    std::cout << "Your new password: ";
    getline(cin, newpassword);

    while(f.good())
    {
        getline(f, id , ',');
        getline(f, password, ',');
        getline(f, role, '\n');

        if (id == user.username )
        {
            password = newpassword;
        }

        StoreInTemp(id, password, role);
    }

    f.close();

    //remove and rename file user after changing
    remove("data\\user.csv");
    rename("data\\temp.csv", "data\\user.csv");

}


//DeleteUser gets the id  then call the CheckRole
void DeleteUser()
{
    string name;
    cout << "Enter the ID: ";
    getline(cin, name);

    string role;

    role = CheckRole(name);
    if (role == "")
    {
        std::cout << "Not Found\n";
        return;
    }

    if (role == "teacher")
    {
        DeleteInfoTeacher(name);
        DeleteInUser(name);
    }
    else if (role == "student")
    {
        DeleteInfoStudent(name);
        DeleteInUser(name);
    }

}

string CheckRole(string _id)
{
    ifstream file("data\\user.csv");

    if (!file.is_open())
    {
        std::cout << "ERROR: File Open" << '\n';
        return "";
    }

    string id;
    string pas;
    string role;

    getline(file, id, ',');
    getline(file, pas, ',');
    getline(file, role, '\n');

    while(file.good())
    {
        if (id == _id)
        {
            return role;
        }
        getline(file, id, ',');
        getline(file, pas, ',');
        getline(file, role, '\n');
    }

    file.close();

    return "";
}

//delete function,only for teacher
void StoreInTemp(string id, string name, string age, string phone, string address)
{
    ofstream file("data\\temp.csv",ios::out | ios::app | ios::binary);

    if (!file.is_open())
    {
        std::cout << "ERROR: File Open" << '\n';
        return;
    }

    file << id << ","  << name << "," << age <<"," << phone << "," << address << "\n";

    file.close();
}

void DeleteInfoTeacher(string _name)
{
    ifstream file("data\\teacher.csv");

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

    getline(file, id, ',');
    getline(file, name, ',');
    getline(file, age, ',');
    getline(file, phone, ',');
    getline(file, address, '\n');

    while(file.good())
    {
        if (id != _name)// data
        {
            StoreInTemp(id, name, age, phone, address);
        }

        getline(file, id, ',');
        getline(file, name, ',');
        getline(file, age, ',');
        getline(file, phone, ',');
        getline(file, address, '\n');
    }

    file.close();

    remove( "data\\teacher.csv" );
    rename("data\\temp.csv", "data\\teacher.csv");
}

//delete functuon, only for student
void StoreInTemp(string id, string name, string age, string address)
{
    ofstream file("data\\temp.csv",ios::out | ios::app | ios::binary);

    if (!file.is_open())
    {
        std::cout << "ERROR: File Open" << '\n';
        return;
    }

    file << id << ","  << name << "," << age << "," << address << "\n";

    file.close();
}

void DeleteInfoStudent(string _name)
{
    ifstream file("data\\student.csv");

    if (!file.is_open())
    {
        std::cout << "ERROR: File Open" << '\n';
        return;
    }

    string id;
    string name;
    string age;
    string address;

    getline(file, id, ',');
    getline(file, name, ',');
    getline(file, age, ',');
    getline(file, address, '\n');

    while(file.good())
    {
        if (id != _name)// data
        {
            StoreInTemp(id, name, age, address);
        }

        getline(file, id, ',');
        getline(file, name, ',');
        getline(file, age, ',');
        getline(file, address, '\n');
    }

    file.close();

    remove( "data\\student.csv" );
    rename("data\\temp.csv", "data\\student.csv");
}


void DeleteInUser(string _name)
{
    ifstream file("data\\user.csv");

    if (!file.is_open())
    {
        std::cout << "ERROR: File Open" << '\n';
        return;
    }

    string id;
    string pas;
    string role;

    getline(file, id, ',');
    getline(file, pas, ',');
    getline(file, role, '\n');

    while(file.good())
    {
        if (id != _name)
        {

            StoreInTemp(id, pas, role);

        }

        getline(file, id, ',');
        getline(file, pas, ',');
        getline(file, role, '\n');
    }

    file.close();

    remove("data\\user.csv");
    rename("data\\temp.csv", "data\\user.csv");

}

//Search in Admin
void SearchUser()
{
    std::string choice;

    do
    {
        std::cout << "1.Search by name \n";
        std::cout << "2.Search by phone \n";
        std::cout << "3.Search by address \n";

        std::getline(std::cin, choice);

        if (choice == "1")
        {
            SearchByName();
            break;
        }
        else if (choice == "2")
        {
            SearchByPhone();
            break;
        }
        else if (choice == "3")
        {
            SearchByAddress();
            break;
        }
        else
        {
            std::cout <<"Try Agian : ";
        }

        std::cout << endl;
    }
    while(1);
}

void SearchByName()
{
    std::string name;

    std::cout << "Enter your keyword: ";
    std::getline(std::cin, name);
    SearchName(name);
}

void SearchName(string temp)
{
    ifstream file("data\\teacher.csv");

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

    getline(file, id, ',');
    getline(file, name, ',');
    getline(file, age, ',');
    getline(file, phone, ',');
    getline(file, address, '\n');

    int found;
    while(file.good())
    {
        found = name.find(temp);
        if (found != -1)
        {
            std::cout << "id: " << id << std::endl;
            std::cout << "name: " << name << std::endl;
            std::cout << "birth: " << age << std::endl;
            std::cout << "phone: " << phone << std::endl;
            std::cout << "address: " << address << std::endl;
            std::cout << "-------------------" << '\n';
        }

        getline(file, id, ',');
        getline(file, name, ',');
        getline(file, age, ',');
        getline(file, phone, ',');
        getline(file, address, '\n');
    }

    file.close();

    ifstream file_2("data\\student.csv");
    if (!file_2.is_open())
    {
        std::cout << "ERROR: File Open" << '\n';
        return;
    }

    getline(file_2, id, ',');
    getline(file_2, name, ',');
    getline(file_2, age, ',');
    getline(file_2, address, '\n');

    while(file_2.good())
    {
        found = name.find(temp);

        if (found != -1)
        {
            std::cout << "id: " << id << std::endl;
            std::cout << "name: " << name << std::endl;
            std::cout << "birth: " << age << std::endl;
            std::cout << "address: " << address << std::endl;
            std::cout << "-------------------" << '\n';
        }

        getline(file_2, id, ',');
        getline(file_2, name, ',');
        getline(file_2, age, ',');
        getline(file_2, address, '\n');
    }

    file_2.close();
}

void SearchByPhone()
{
    std::string phone;

    std::cout << "Enter your keyword: ";
    std::getline(std::cin, phone);
    SearchPhone(phone);

}

void SearchPhone(string temp)
{
    ifstream file("data\\teacher.csv");

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

    getline(file, id, ',');
    getline(file, name, ',');
    getline(file, age, ',');
    getline(file, phone, ',');
    getline(file, address, '\n');

    int found;
    while(file.good())
    {
        found = phone.find(temp);
        if (found != -1)
        {
            std::cout << "id: " << id << std::endl;
            std::cout << "name: " << name << std::endl;
            std::cout << "birth: " << age << std::endl;
            std::cout << "phone: " << phone << std::endl;
            std::cout << "address: " << address << std::endl;
            std::cout << "-------------------" << '\n';
        }

        getline(file, id, ',');
        getline(file, name, ',');
        getline(file, age, ',');
        getline(file, phone, ',');
        getline(file, address, '\n');
    }

    file.close();
}

void SearchByAddress()
{
    std::string address;

    std::cout << "Enter your keyword: ";
    std::getline(std::cin, address);

    SearchAddress(address);
}

void SearchAddress(string temp)
{
    ifstream file("data\\teacher.csv");

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

    getline(file, id, ',');
    getline(file, name, ',');
    getline(file, age, ',');
    getline(file, phone, ',');
    getline(file, address, '\n');

    int found;
    while(file.good())
    {
        found = address.find(temp);
        if (found != -1)
        {
            std::cout << "id: " << id << std::endl;
            std::cout << "name: " << name << std::endl;
            std::cout << "birth: " << age << std::endl;
            std::cout << "phone: " << phone << std::endl;
            std::cout << "address: " << address << std::endl;
            std::cout << "-------------------" << '\n';
        }

        getline(file, id, ',');
        getline(file, name, ',');
        getline(file, age, ',');
        getline(file, phone, ',');
        getline(file, address, '\n');
    }

    file.close();

    ifstream file_2("data\\student.csv");
    if (!file_2.is_open())
    {
        std::cout << "ERROR: File Open" << '\n';
        return;
    }

    getline(file_2, id, ',');
    getline(file_2, name, ',');
    getline(file_2, age, ',');
    getline(file_2, address, '\n');

    while(file_2.good())
    {
        found = address.find(temp);

        if (found != -1)
        {
            std::cout << "id: " << id << std::endl;
            std::cout << "name: " << name << std::endl;
            std::cout << "birth: " << age << std::endl;
            std::cout << "address: " << address << std::endl;
            std::cout << "-------------------" << '\n';
        }

        getline(file_2, id, ',');
        getline(file_2, name, ',');
        getline(file_2, age, ',');
        getline(file_2, address, '\n');
    }

    file_2.close();
}

//function for Teacher and Student
void SearchCoursesByName()
{
    string name;
    std::cout << "Enter the name : ";
    getline(cin , name);

    SearchCoursesName(name);

}

void SearchCoursesName(string temp)
{
    //system("cls");

    ifstream file("data\\course.csv");

    if (!file.is_open())
    {
        std::cout << "ERROR: File Open" << '\n';
        return;
    }

    string teacher_id;
    string subject_id;
    string subject_name;
    string n_student;
    string slot;
    string credit;

    getline(file, teacher_id, ',');
    getline(file, subject_id, ',');
    getline(file, subject_name, ',');
    getline(file, n_student, ',');
    getline(file, slot, ',');
    getline(file, credit, '\n');

    int i = 1;
    int found ;
    while(file.good())
    {
        found = subject_name.find(temp);
        if (found != -1)
        {
            std::cout << "STT: " << i << std::endl;
            std::cout << "Subject ID: " << subject_id << std::endl;
            std::cout << "Subject Name: " << subject_name << std::endl;
            std::cout << "Student / Slot: " << n_student << " / "<< slot << std::endl;
            std::cout << "credit: " << credit << std::endl;
            std::cout << "-------------------" << '\n';

            i++;
        }

        getline(file, teacher_id, ',');
        getline(file, subject_id, ',');
        getline(file, subject_name, ',');
        getline(file, n_student, ',');
        getline(file, slot, ',');
        getline(file, credit, '\n');
    }

    file.close();
}

//Function for student
void JoinCourseByID()
{
    std::string id;
    std::cout << "Enter course ID: ";
    std::getline(std::cin, id);

    JoinCourseID(id);

    std::cout << "Join Course Succeed\n";
}

void JoinCourseID(string id)
{
    ifstream file("data\\course.csv");

    if (!file.is_open())
    {
        std::cout << "ERROR: File Open" << '\n';
        return;
    }

    string teacher_id;
    string subject_id;
    string subject_name;
    string n_student;
    string slot;
    string credit;
    int x = 0;

    while(file.good())
    {
        getline(file, teacher_id, ',');
        getline(file, subject_id, ',');
        getline(file, subject_name, ',');
        getline(file, n_student, ',');
        getline(file, slot, ',');
        getline(file, credit, '\n');

        if (id == subject_id)
        {
            stringstream num(n_student);
            num >> x;

            x = x + 1;
        }

        StoreInTemp(teacher_id, subject_id, subject_name, x, slot, credit);
    }

    file.close();

    remove("data\\course.csv");
    rename("data\\temp.csv", "data\\course.csv");
}

void StoreInTemp(string teacher_id, string subject_id, string subject_name, int n_student, string slot, string credit)
{
    ofstream file("data\\temp.csv",ios::out | ios::app | ios::binary);

    if (!file.is_open())
    {
        std::cout << "ERROR: File Open" << '\n';
        return;
    }

    file << teacher_id << ","  << subject_id << "," << subject_name << "," << n_student << "," << slot << "," << credit << "\n";

    file.close();
}
