#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
using namespace std;
int currentStudentIndex = -1;
const int num_admin = 3;
#define num_student 50
#define size 10
const int max_courses = 20;
int courseCount = 6;
int studentCount = 2;
double totalIncome=0;
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string CYAN = "\033[36m";
struct STUDENT {
    int studentID;
    string studentName;
    string studentPassword;
    int studentLevel;
    int registeredCOURSES[size];
    int num_registeredCOURSES;
    string visaPASSWORD;
    double budget;
}student[num_student];
struct COURSE {
    int ID;
    string Course_name;
    string Insructor_name;
    int Max_Capacity = 0;
    int Current_enrolled = 0;
    string day;
    int time;
    int CreditHours;
    double coursePRICE;
}course[max_courses];
struct ADMIN {
    int adminID;
    string adminName;
    string adminPassword;
}admin[num_admin];
void saveData();
void saveCourses();

string getPassword() {
    string password = "";
    char ch;
    while ((ch = _getch()) != 13) { //program run until user press enter 13 button enter of keyboard
        if (ch == 8) {
            if (password.length() > 0) {
                cout << "\b \b";//8 backspace and length password greater than zero delete
                password.pop_back();
            }
        }
        else {
            password += ch;//user enter letter then add it to the password
            cout << '*';//display it star
        }
    }
    cout << endl;
    return password;
}

void coursesPRICES() {//add 500 to courseprice
    for (int i = 7; i < max_courses - 3; i++) {
        course[i].coursePRICE += 500;
    }
}

void walletRECHARGE() {
    double deposit;
    bool x = false;
    string pass;
    cout << "Please Enter The Amount You Want To Deposit: \n";
    cin >> deposit;//if user want to deposit money
    if (deposit < 0) {//if user enter negative value
        cout << "ERROR! please enter another amount.\n";
        walletRECHARGE();//display the function again
    }
    else {
        cin.ignore(1000, '\n');
        cout << "Please Enter Your VISA Password to confirm: \n";//enter your visapassword
        pass = getPassword();
        if (pass == student[currentStudentIndex].visaPASSWORD) {
            x = true;
            student[currentStudentIndex].budget += deposit;
        }
        if (x == true) {
            cout << "SUCCESSFUL TRANSFORMATION! \n";//when user enter a true visapassword
            cout << "Your current balance is " << student[currentStudentIndex].budget << endl;
        }
        else//when user enter a nonvalid visapassword
            cout << "RECHARGING FAILED! \n" << "Invalid Visa Password please contact your bank.\n";

    }
}

bool buyCOURSE(int index) {
    string pass, ans;
    cout << "Course Price: " << course[index].coursePRICE << endl;//display courseprice
    cout << "Please Enter Your VISA Password to Pay for the Chosen Course: ";
    pass = getPassword();//student enter his visapassword
    cout << endl;
    if (pass == student[currentStudentIndex].visaPASSWORD) {
        if (student[currentStudentIndex].budget >= course[index].coursePRICE) {//if student has budget enough to buy this course
            student[currentStudentIndex].budget -= course[index].coursePRICE;//decrement from budget's student
            totalIncome += course[index].coursePRICE;//income from buying courses
            cout <<GREEN<< "SUCCESSFUL TRANSFORMATION! " <<GREEN<< "Course has been added to your courses.\n";
            cout << "Your Current Balance is " << student[currentStudentIndex].budget << endl;
            return true; 
        }
        else {
            cout << RED<<"PAYMENT FAILED! could not find enough balance.\n";
            cout << GREEN<<"Do You Want to Recharge Your Wallet? \n";//ask user if he wants to add money 
            cin >> ans;
            if (ans == "yes" || ans == "YES" || ans == "Yes") walletRECHARGE();
            else return false; 
        }
    }
    else if (pass != student[currentStudentIndex].visaPASSWORD) {
        cout << RED<<"FAILURE!\n" << RED<<"Invalid VISA Password please contact your bank.\n";
        return false;
    }
    saveData();
    saveCourses();
    return true;
    
}

void returnMONEY(int courseIndex) {
    student[currentStudentIndex].budget += course[courseIndex].coursePRICE;//if student drop course
    totalIncome -= course[courseIndex].coursePRICE;
    cout << GREEN<<"SUCCESSFUL TRANSFORMATION! \n";
    cout <<GREEN<< "Your Current Balance is " << student[currentStudentIndex].budget << endl;
    saveData();
    saveCourses();
}

void viewBALANCE() {
    cout << "Your Current Balance is: " << student[currentStudentIndex].budget << endl;//view your current balance
}

void viewTotalIncome() {
    cout <<BLUE<< "Total Income is: " << totalIncome << endl;
    saveData();
}

void student_initializer() {//initializers will be call in main so remaining functions can use the data stored in the arrays
    student[0] = { 2024567,"AYA AHMED","aya@",1,{7},4, "0001", 15000 };
    student[1] = { 2029876,"HABIBA ELSAYED","habiba@",2,{6},3, "1111", 10000 };
};
void course_initializer() {//at least 6 initializers
    course[0] = { 12,"Physics","YASMIN",50,0,"SUNDAY",3,3, 1000 };
    course[1] = { 19,"Algorithm","OMAR",50,0,"THURSDAY",12,3, 2500 };
    course[2] = { 5,"English","MUHAMMED",50,0,"SATURDAY",12,2, 1000 };
    course[3] = { 14,"Artificial Intelligence","MUHAMMED",50,0,"SUNDAY",5,3, 3000 };
    course[4] = { 11,"Cyber Security","SALSABIL",50,0,"TUESDAY",5,3, 3000 };
    course[5] = { 13,"Linear Algebra","YARA",50,0,"MONDAY",7,3, 1500 };
    course[6] = { 18,"Operating System","YOUSSEF",50,0,"TUESDAY",5,3, 2000 };
    courseCount = 7;
}
void admin_initializer() {//at least 2
    admin[0] = { 19,"MAHMOUD","mahmoud@" };
    admin[1] = { 29,"AHMED","ahmed@" };
}
void available_courses() {//show the user his available courses

    cout << "Available Courses:\n\n";
    for (int i = 0; i < courseCount; i++) {
        if (course[i].ID > 0) {
            cout << "Course ID: " << course[i].ID
                << " | Name: " << course[i].Course_name
                << " | Instructor: " << course[i].Insructor_name
                << " | Enrolled: " << course[i].Current_enrolled
                << "/" << course[i].Max_Capacity << endl;
        }
    }
}
void student_sign_up() {
    int id;
    string ch;
    bool ifFOUND = false;   
    if (studentCount < num_student) {
        cout << CYAN << "--- Student Sign Up ---\n";
        cout << "Enter ID: ";
        while (!(cin >> id)) {
            cout << RED << "Invalid ID! Please enter a numeric ID: ";
            cin.clear();           
            cin.ignore(1000, '\n');  
        }
        cout << endl;
        for (int i = 0; i < studentCount; i++) {
            if (id == student[i].studentID) {
                ifFOUND = true;
                break; //out from loop
            }
        }
        if (ifFOUND) {
            cout << RED << "Account already exists! Please log in.\n";
        }
        else {
            student[studentCount].studentID = id;
            cout << "Enter Name: ";
            cin.ignore(1000, '\n'); 
            getline(cin, student[studentCount].studentName);
            cout << "Enter Password: ";
            student[studentCount].studentPassword = getPassword();
            cout << "Enter Level: ";
            while (!(cin >> student[studentCount].studentLevel)) {
                cout << RED << "Invalid Level! Please enter a number: ";
                cin.clear();//delete wrong input
                cin.ignore(1000, '\n');//clear line 
            }
            cout << "Enter VISA Password: ";
            cin.ignore(1000, '\n'); 
            student[studentCount].visaPASSWORD = getPassword();
            student[studentCount].num_registeredCOURSES = 0;
            student[studentCount].budget = 0;
            currentStudentIndex = studentCount;
            cout << YELLOW << "Do You Want To Recharge Your Wallet? (yes/no): ";
            cin >> ch;
            if (ch == "yes" || ch == "YES" || ch == "Yes") {
                walletRECHARGE();
            }
            else {
                cout << RED << "Your Current Balance is ZERO! You can recharge it later from settings.\n";
            }

            studentCount++;
            currentStudentIndex = -1;
            cout << GREEN << "\nAccount created successfully! You can now login.\n";
        }
    }
    else {
        cout << RED << "System Full! Cannot add more students.\n";
    }

    
    saveData();
}
int student_login() {
    int id;
    string pass;
    cout << BLUE<<"--- Student Login ---\n";
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Password: ";
    pass = getPassword();
    cout << endl;
    for (int i = 0; i < studentCount; i++) {
        if (student[i].studentID == id && student[i].studentPassword == pass)
        {
            cout << GREEN<<"\nLogin Successful! WELCOME, " << student[i].studentName << endl;
            return i;
        }
    }
    cout <<RED<< "\nInvalid ID or Password!\n";
    return -1;//out from function
}


int Registerd_Courses() {
    int id;
    cout << " please enter id of  the course : ";
    cin >> id;
    int index = -1; 
    for (int i = 0; i < courseCount; i++) {
        if (course[i].ID == id) {
            index = i;
            break;//out from loop
        }
    }
    if (index == -1) {
        cout << RED<<"course not found \n";
        return -1; //out from function
    }
    for (int i = 0; i < student[currentStudentIndex].num_registeredCOURSES; i++) {
        if (student[currentStudentIndex].registeredCOURSES[i] == id) {
            cout << "You already registered this course!\n";
            return 0;//out from function
        }
    }
    if (course[index].Current_enrolled < course[index].Max_Capacity) {
        if (buyCOURSE(index)) {
            course[index].Current_enrolled++;
            int pos = student[currentStudentIndex].num_registeredCOURSES;
            student[currentStudentIndex].registeredCOURSES[pos] = id;
            student[currentStudentIndex].num_registeredCOURSES++;
        }

    }

    else {
        cout <<RED<< "Sorry! Course is full\n";
    }
    saveData();
    saveCourses();
    return course[index].Current_enrolled;
}
void viewMyCourses(int currentStudentIndex) { //need to explain
    if (student[currentStudentIndex].num_registeredCOURSES == 0) {
        cout << "No courses registered.\n";
    }
    else {
        cout << BLUE<<"My Registered Courses\n";
        for (int i = 0; i < student[currentStudentIndex].num_registeredCOURSES; i++) {
            int cid = student[currentStudentIndex].registeredCOURSES[i];
            for (int j = 0; j < courseCount; j++) {
                if (course[j].ID == cid) {
                    cout << CYAN<<"----------------------------------\n";
                    cout << "Course ID: " << course[j].ID << endl;
                    cout << "Course Name: " << course[j].Course_name << endl;
                    cout << "Instructor: " << course[j].Insructor_name << endl;
                    cout << "Day: " << course[j].day << endl;
                    cout << "Time: " << course[j].time << endl;
                    cout << "Capacity: " << course[j].Current_enrolled << "/" << course[j].Max_Capacity << endl;
                    cout << CYAN<<"----------------------------------\n";
                }
            }
        }
    }
}
void dropCourse() {
    int id;
    cout << "please enter course ID to drop : ";
    cin >> id;
    int courseIndex = -1;
    for (int i = 0; i < courseCount; i++) {
        if (course[i].ID == id) {
            courseIndex = i;
            break;
        }
    }
    if (courseIndex == -1) {
        cout <<RED<< "Invalid Course ID! " << "course dose not exist.\n";
        return;
    }
    int studentIndex = currentStudentIndex;
    int foundIndex = -1;
    for (int i = 0; i < student[studentIndex].num_registeredCOURSES; i++) {
        if (student[studentIndex].registeredCOURSES[i] == id) {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex == -1) {
        cout << " You are not registered in this course!\n";
        return;
    }
    for (int i = foundIndex; i < student[studentIndex].num_registeredCOURSES - 1; i++) {
        student[studentIndex].registeredCOURSES[i] = student[studentIndex].registeredCOURSES[i + 1];
    }
    student[studentIndex].num_registeredCOURSES--;
    course[courseIndex].Current_enrolled--;
    cout <<GREEN<< "Course dropped successfully\n";
    returnMONEY(courseIndex);
    saveData();
    saveCourses();
}
void menu() {
    int choice;
    while (true) {

        cout << GREEN << "** available options **\n";
        cout << "1. View Available Courses\n";
        cout << "2. Register Course\n";
        cout << "3. My Courses\n";
        cout << "4. Drop Course\n";
        cout << "5. Recharge your wallet\n";
        cout << "6. View Your Balance\n";
        cout << "7. Exit\n";
        cout << "please enter your choice\n";
        if (!(cin >> choice)) {
            cout << RED << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (choice == 7) {
            cout << YELLOW << "Logging out...\n";
            break;
        }

        switch (choice) {
        case 1: available_courses(); break;
        case 2: Registerd_Courses(); break;
        case 3: viewMyCourses(currentStudentIndex); break;
        case 4: dropCourse(); break;
        case 5: walletRECHARGE(); break;
        case 6: viewBALANCE(); break;
        default:
            cout << RED << "Invalid choice! Please enter a number from 1 to 7.\n";
            break;
        }
        if (choice != 1) {
            cout << RESET << "\nPress any key to return to menu...";
            _getch();
            system("CLS");
        }
        else {

            cout << CYAN << "\n---> You can now choose an option from above";
           
        }
    }
}

int adminLogin() {
    cout << CYAN << " ----ADMIN LOGIN----\n";
    int id;
    string pass;
    cout << "Enter Admin ID: ";
    while (!(cin >> id)) {//loop stop when id is valid
        cout << RED << "Invalid ID format! Please enter a numeric ID: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << "Enter Password: ";
    cin.ignore(1000, '\n');
    pass = getPassword();
    for (int i = 0; i < num_admin; i++) {
        if (admin[i].adminID == id && admin[i].adminPassword == pass) {
            cout << GREEN << "Admin login successful. Welcome " << admin[i].adminName << endl;
            return i;
        }
    }
    cout << RED << "Invalid admin login!" << endl;
    return -1;
}
void addCourse() {
    if (courseCount >= max_courses) {//if registeredcourses grater or equal from maxcourses available
        cout << "Max courses reached!\n";
        return;
    }
    cout << "Enter Course ID: ";//input id name instructor and course name day time credit hoursand courseprice
    cin >> course[courseCount].ID;
    cout << "Enter Course Name: ";
    cin.ignore();//delete enter remaining
    getline(cin, course[courseCount].Course_name);//make spaces bet words
    cout << "Enter Instructor Name: ";
    getline(cin, course[courseCount].Insructor_name);
    cout << "Enter Max Capacity: ";
    cin >> course[courseCount].Max_Capacity;
    cout << "Enter Day: ";
    cin >> course[courseCount].day;
    cout << "Enter Time (Hour): ";
    cin >> course[courseCount].time;
    course[courseCount].Current_enrolled = 0;
    cout << "Enter Credit Hours: ";
    cin >> course[courseCount].CreditHours;
    cout << "Enter Course Price: ";
    cin >> course[courseCount].coursePRICE;
    courseCount++;
    cout << "Course added successfully!\n";
    saveCourses();
}

void editCourse() {
    int cid;
    cout << "Enter Course ID to edit: ";
    cin >> cid;
    for (int i = 0; i < courseCount; i++) {
        if (course[i].ID == cid) {//if you want to edit course enter its id
            cout << "Found! Enter new Instructor Name: \n";
            cin.ignore();
            getline(cin, course[i].Insructor_name);//new instructor name
            cout << "Enter new Max Capacity: \n";//new maxcapacity
            cin >> course[i].Max_Capacity;
            cout << "Enter new price: \n";//new price
            cin >> course[i].coursePRICE;
            cout << "Course updated successfully!\n";
            saveCourses();
            return;
        }
    }
    cout << "Course not found!\n";
}

void deleteCourse() {
    int cid;
    cout << "Enter Course ID to delete: ";
    cin >> cid;
    for (int i = 0; i < courseCount; i++) {
        if (course[i].ID == cid) {
            if (course[i].Current_enrolled == 0) {
                for (int j = i; j < courseCount - 1; j++) {
                    course[j] = course[j + 1];
                }
                courseCount--;
                cout << GREEN<<"Course deleted successfully!\n";
                saveCourses();
                return;
            }
            else {
                cout << RED<<"Cannot delete course! Students are already enrolled.\n";
                return;
            }
        }
    }
    cout <<RED <<"Course not found!\n";
}

void viewAllStudents() {//display all students
    cout << "All Students:" << endl;
    for (int i = 0; i < studentCount; i++) {
        cout << student[i].studentID << " - " << student[i].studentName
            << " | Level: " << student[i].studentLevel << endl;
    }
}
void saveData() {

    ofstream output("Students Data.txt");

    if (!output.is_open()) return;

    output << studentCount << endl;

    for (int i = 0; i < studentCount; i++) {
        output << student[i].studentID << endl;
        output << student[i].studentName << endl;
        output << student[i].studentPassword << endl;
        output << student[i].studentLevel << endl;
        output << student[i].num_registeredCOURSES << endl;
        output << student[i].visaPASSWORD << endl;
        output << student[i].budget << endl;
        for (int j = 0; j < student[i].num_registeredCOURSES; j++) {
            output << student[i].registeredCOURSES[j] << endl;
        }
    }
    output << totalIncome << endl;
    output.close();
}

void callData() {
    ifstream input("Students Data.txt");
    if (!input.is_open()) return;
    string line;
    getline(input, line);
    if (line.empty()) return;
    studentCount = stoi(line);
    for (int i = 0; i < studentCount; i++) {
        getline(input, line); student[i].studentID = stoi(line);
        getline(input, student[i].studentName);
        if (!student[i].studentName.empty() && student[i].studentName.back() == '\r')
            student[i].studentName.pop_back();
        getline(input, student[i].studentPassword);
        if (!student[i].studentPassword.empty() && student[i].studentPassword.back() == '\r')
            student[i].studentPassword.pop_back();
        getline(input, line); student[i].studentLevel = stoi(line);
        getline(input, line); student[i].num_registeredCOURSES = stoi(line);
        getline(input, student[i].visaPASSWORD);
        if (!student[i].visaPASSWORD.empty() && student[i].visaPASSWORD.back() == '\r')
            student[i].visaPASSWORD.pop_back();
        getline(input, line); student[i].budget = stod(line);
        for (int j = 0; j < student[i].num_registeredCOURSES; j++) {
            getline(input, line);
            student[i].registeredCOURSES[j] = stoi(line);
        }
    }
    getline(input, line);
    totalIncome = stod(line);
    input.close();
}

void saveCourses() {
    ofstream file("courses.txt");
    file << courseCount << endl;
    for (int i = 0; i < courseCount; i++) {
        file << course[i].ID << "\n"
            << course[i].Course_name << "\n"
            << course[i].Insructor_name << "\n"
            << course[i].CreditHours << "\n"
            << course[i].Current_enrolled << "\n"
            << course[i].Max_Capacity << "\n"
            << course[i].day << "\n"
            << course[i].time << "\n"
            << course[i].coursePRICE << "\n";
    }
    file.close();
}

void loadCourses() {
    ifstream file("courses.txt");

    if (!file.is_open()) return;

    file >> courseCount;
    file.ignore();

    for (int i = 0; i < courseCount; i++) {
        file >> course[i].ID;
        file.ignore();
        getline(file, course[i].Course_name);
        getline(file, course[i].Insructor_name);
        file >> course[i].CreditHours;
        file >> course[i].Current_enrolled;
        file >> course[i].Max_Capacity;
        file.ignore();
        getline(file, course[i].day);
        file >> course[i].time;
        file >> course[i].coursePRICE;
        file.ignore();
    }
    file.close();
}


int main() {
    coursesPRICES();
    bool studentsLoaded = false;//sure that files exist
    bool coursesLoaded = false;
    ifstream testS("Students Data.txt");
    if (testS.is_open()) { testS.close(); studentsLoaded = true; }
    ifstream testC("courses.txt");
    if (testC.is_open()) { testC.close(); coursesLoaded = true; }
    callData();
    loadCourses();

    if (!studentsLoaded) {
        student_initializer();
        studentCount = 2;
    }
    if (!coursesLoaded) {
        course_initializer();
        courseCount = 7;
    }
    admin_initializer();
    while (true) {//program run until user choose exit
        int choice;
        cout << "\n====== COURSE REGISTRATION SYSTEM ======\n";
        cout << "1- Student\n";
        cout << "2- Admin\n";
        cout << "0- Exit\n";
        cout << "Enter choice: ";
        while (!(cin >> choice)) {
            cout << "Invalid input! Please enter 1, 2, or 0: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        if (choice == 0) {
            cout << "Goodbye!\n";
            break;
        }
        else if (choice == 2) {
            int idx = adminLogin();
            if (idx == -1) continue;
            int op;
            do {
                cout <<"\n--------Admin Menu:--------\n";
                cout << "1- Add Course\n";
                cout << "2- Edit Course\n";
                cout << "3- Delete Course\n";
                cout << "4- View All Students\n";
                cout << "5- View Total Income\n";
                cout << "0- Logout\n";
                cout << "Enter choice: ";
                while (!(cin >> op)) {
                    cout << "Invalid input! Please enter a number: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                switch (op) {
                case 1: addCourse(); break;
                case 2: editCourse(); break;
                case 3: deleteCourse(); break;
                case 4: viewAllStudents(); break;
                case 5: viewTotalIncome(); break;
                case 0: break;
                default: cout << "Invalid choice!\n";
                }
            } while (op != 0);
            cout << "Logged out successfully.\n";
        }
        else if (choice == 1) {
            int logchoice;
            cout << "1- Login\n2- Sign Up\n";
            cin >> logchoice;
            if (logchoice == 1) {
                currentStudentIndex = student_login();
                if (currentStudentIndex != -1) {
                    menu();
                    currentStudentIndex = -1;
                }
            }
            else if (logchoice == 2) {
                student_sign_up();
            }
            else {
                cout <<RED <<"Invalid choice!\n";
            }
        }
        else {
            cout << RED<<"Invalid choice! Please enter 0, 1, or 2.\n";
        }
        system("pause");//wait for the user
        system("CLS");//clear the screen
        saveData();
        saveCourses();
    }
    saveData();
    saveCourses();
    return 0;
}






   
