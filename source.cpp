#include <iostream>
#include <cmath>
using namespace std;
struct Class{
  float length;
  float width;
};
struct school{
  int id;
  Class cl[3];
  float area;
}sch[2];
void calcarea(){
  for(int j=0;j<2;j++){sch[j].area=1;
  for(int i=0;i<3;i++){
  sch[j].area+=sch[i].cl[j].length*sch[i].cl[j].width;
}//return sch[j].area;
  }
}
void greatesrarea(){
int max=-1;
for(int i=0;i<3;i++){
  if(sch[i].area>max)
max=sch[i].area;
int index=i;
cout<<"largest room:"<<index;
cout<<"id:"<<sch[i].id;
cout<<"area:"<<sch[i].area;
}
}
int main(){
for(int i=0;i<2;i++){
cout<<"info school "<<i+1 <<endl;
cin>>sch[i].id;
for(int i=0;i<3;i++){
cout<<"class:"<<i+1<< " " ;cin>>sch[i].cl[i].length;
cin>>sch[i].cl[i].width;
}}
calcarea();
greatesrarea();

 return 0;
}





   
