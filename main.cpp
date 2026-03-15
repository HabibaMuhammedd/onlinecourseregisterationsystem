#include <iostream>
#include <cmath>
#include<string>
#define num 50
#define size 10
#define cap 20
#define number 3
using namespace std;
struct student{
   int ID;
   string name;
   string password;
   int level;
   int Registered_course[size];
   int Number_Of_Registeredcourses;
};
struct course{
int ID;
string Course_name;
string Insructor_name;
int Max_Capacity;
int Current_enrolled;
string day;
int time;
};
 struct admin{
   int ID;
   string name;
   string password;
 };
int main(){
 student stud[num]={
{2023456,"Nour","Nour2003",3,7,4},
{2023478,"Laila","lai123",2,6,3}
 };
 course cos[cap]={
   {21,"physics","Omar",150,90,"Sunday",3},
{17,"algorithm","Amr",250,120,"Wednesday",6},
 {33,"artificial intelligence","Yasmin",180,90,"Tuesday",2}
 };
 admin ad[number]={2023567,"Muhammed","mu12345"};
 int choice;
  cout<<"press 1 for Student\npress 2 for Admin";
  cin>>choice;
  if(choice==1){
    //diplay student function
  }else if(choice==2){
     //diplay admin function
  }else{
    cout<<"Error! Please enter a valid number";
  }
 

 return 0;
}





   
