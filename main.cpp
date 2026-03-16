#include <iostream>
#include <string>
using namespace std;
#define studentNUM 50
#define size 10
#define cap 20
#define number 3
struct STUDENT {
    int studentID;
    string studentName;
    string studentPassword;
    int studentLevel;
    int registeredCOURSES[size]; // ERINY'S PART
    int num_registeredCOURSES = 0;        // ERINY'S PART
}student[studentNUM];
struct COURSE{
int ID;
string Course_name;
string Insructor_name;
int Max_Capacity=0;
int Current_enrolled=0;
string day;
int time;
}course[cap];
struct ADMIN {
    int adminID;
    string adminName;
   string adminPassword;
}admin[number];
void student_initializer() {
  STUDENT stud[studentNUM]={
    {2024567,"AYA AHMED","aya2007",1,7,4},
    {2029876,"HABIBA ELSAYED","habiba1234",2,6,3}
 };
}
void admin_initializer() {
ADMIN admin[number]={
  {2029345,"MAHMOUD","mah@123"},{2345609,"AHMED","ah2345"}
 };
}
int userCHOICE(){
  int choice;
    const int starsNUM = 10;
    for (int i = 0; i < starsNUM; i++)
        cout << "*";
    cout << " Welcome to Our Online Course Registration ";
    for (int i = 0; i < starsNUM; i++)
        cout << "*";
    cout << endl;
    cout << "Press 1 For Student" << endl;
    cout << "Press 2 For Admin" << endl;
    cin >> choice;
    cout << endl;
    return choice;
};
int signUP_OR_logIN(){
 int choice;
    cout << "----- Student Portal -----" << endl;
    cout << "1. Login (If you already have an account)" << endl;
    cout << "2. Sign Up (For new students)" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    return choice;
};
void studentLogin(){
    int id, password;
    cout << "Enter ID: ";
    cin >> id;
    cout << endl;
    cout << "Enter Password: ";
    cin >> password;
    cout << endl;
    bool data = false;
    int index = -1;
    for (int i = 0; i < studentNUM; i++) {
        if (student[i].studentID == id && student[i].studentPassword == password) {
            data = true;
            index = i;
            break;
        }
    }
    if (data == true) {
        cout << "Login Successful!" << endl;
        cout << "Welcome, " << student[index].studentName << "." << endl;
        // TO ERINY you should display the menu of that student if the data entered is correct
    }
    if (data == false)
        cout << "Login Failed!" << endl << "Incorrect Data." << endl;
};
void studentSignUp(){
    if (studentNUM != studentNUM) {
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, student[studentNUM].studentName);
        cout << endl;
        cout << "Enter your ID: ";
        cin >> student[studentNUM].studentID;
        cout << endl;
        cout << "Enter your password: ";
        cin >> student[studentNUM].studentPassword;
        cout << endl;
        cout << "Enter your level: ";
        cin >> student[studentNUM].studentLevel;
        cout << endl;
        cout << "Account created successfully!" << endl;
        studentNUM++;
    }
    else
        cout << "Sorry! Maximum student capacity reached." << endl;
};
void available_courses(){
  if(course[cap].Current_enrolled< course[cap].Max_Capacity){
    cout<<"Physics\n"<<"English\n"<<"ALGORITHM\n"<<"Artificial Intelligence\n"<<"Linear algebra\n"<<"Business";
  }
}
int Registerd_Courses(){
  int count=0;
  cout<<"Enter id of the course: ";
  cin>>course[cap].ID;
    cin>>course[cap].Max_Capacity;
  if(course[cap].Current_enrolled< course[cap].Max_Capacity){
  course[cap].Current_enrolled++;
  student[studentNUM].registeredCOURSES[count]=course[cap].Current_enrolled;
  count++;
  cout<<"Registeration Successfully ";
  }else{
    cout<<"Sorry! Course is full\n";
  }
  return course[cap].Current_enrolled ;
}
void adminLogin(){
   int id, password;
    cout << "----- Admin Portal -----" << endl;
    cout << "Enter Admin ID: ";
    cin >> id;
    cout << endl;
    cout << "Enter Admin Password: ";
    cin >> password;
    cout << endl;
    bool data = false;
    int index = -1;
    for (int i = 0; i < number; i++) {
        if (admin[i].adminID == id && admin[i].adminPassword == password) {
         data = true;
            index = i;
            break;
        }
    }
    if (data == true) {
        cout << "Login Successful!" << endl;
        cout << "Welcome, Admin " << admin[index].adminName << "." << endl;
    }
    else if (data == false)
        cout << "Login Failed!" << endl << "Incorrect Data." << endl;
};
int main() {
    student_initializer();
    admin_initializer();
    int USERchoice = userCHOICE();
    if (USERchoice == 1) {
        int signORlog = signUP_OR_logIN();
        if (signORlog == 1) {
            studentLogin();
            available_courses();
            Registerd_Courses();
        }
        else if (signORlog == 2) {
            studentSignUp();
        }
    }
    else if (USERchoice == 2) {
        adminLogin();
    }

    return 0;
}


  








   
