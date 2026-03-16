#include <iostream>
#include <string>
using namespace std;
int studentNUM = 2;
int count=0;
int courseNUM=7;
#define num_student 50
#define size 10
#define num_courses 20
#define num_admin 3
struct STUDENT {
    int studentID;
    string studentName;
    int studentPassword;
    int studentLevel;
    int registeredCOURSES[size]; // ERINY'S PART
    int num_registeredCOURSES = 0;
          // ERINY'S PART
}student[num_student];
struct COURSE{
int ID;
string Course_name;
string Insructor_name;
int Max_Capacity=0;
int Current_enrolled=0;
string day;
int time;
}course[num_courses];
struct ADMIN {
    int adminID;
    string adminName;
  int adminPassword;
}admin[num_admin];
int userCHOICE();
int signUP_OR_logIN();
void student_initializer();
void course_initializer();
void admin_initializer();
void studentLogin();
void studentSignUp();
void available_courses();
int Registerd_Courses();
void adminLogin();

int main() {
    student_initializer();
   course_initializer();
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
void student_initializer() {

  student[0] = {2024567,"AYA AHMED",1234,1,7,4};
  student[1] = {2029876,"HABIBA ELSAYED",4321,2,6,3};

 };
void course_initializer(){

    course[0] = {12,"Physics","YASMIN",300,180,"SUNDAY",3};
    course[1] = {19,"Algorithm","OMAR",500,300,"THURSDAY",12};int ID;
     course[2] = {5,"English","MUHAMMED",750,500,"SATURDAY",12};
     course[3] = {14,"Artificial Intelligence","MUHAMMED",450,200,"SUNDAY",5};
   course[4] = {11,"Cyber Security","SALSABIL",650,400,"TUESDAY",5};
   course[5] = {13,"Linear Algebra","YARA",450,300,"MONDAY",7};
   course[6] = {18,"Operating System","YOUSSED",450,200,"TUESDAY",5};

};
void admin_initializer() {
admin[0]={19,"MAHMOUD",23456};
admin[1]={29,"AHMED",12345};
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
        cout << "Welcome, " << student[index].studentName << ".\n\n\n" << endl;
        // TO ERINY you should display the menu of that student if the data entered is correct
    }
    if (data == false)
        cout << "Login Failed!" << endl << "Incorrect Data." << endl;
};
void studentSignUp(){
    if (studentNUM != num_student) {
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
      cout<<"Available Courses:\n\n";
    for(int i = 0; i < courseNUM; i++){
        cout << "Course ID: " << course[i].ID 
             << " - " << course[i].Course_name << endl;
    }
};
int Registerd_Courses(){
    int registeredcount=0;
  int id;
  cout<<"Enter id of the course: ";
  cin>>id;

  int index = -1;
  for(int i = 0; i < num_courses; i++){
    if(course[i].ID == id){
      index = i;
      break;
    }
  }
  if(index == -1){
    cout<<"INVALID ID! Sorry you can't register\n";
    return 0;
  }
  if(course[index].Current_enrolled < course[index].Max_Capacity){
    course[index].Current_enrolled++;

    student[studentNUM].registeredCOURSES[registeredcount] = id;
    registeredcount++;

    cout<<"Registration Successfully\n";
  }
  else{
    cout<<"Sorry! Course is full\n";
  }

  return course[index].Current_enrolled;
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
    for (int i = 0; i < num_admin; i++) {
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
  








   
