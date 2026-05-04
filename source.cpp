#include <iostream>
#include <cmath>
using namespace std;
struct PRODUCT{
  int pnum;
  string pname;
  float pprice;
  int pquantity;
};
void input(PRODUCT *product,int size){
  for(int i=0;i<size;i++){
     cout<<"information of product"<<i+1;
    cout<<"name:";
    cin>>product[i].pname;
    cout<<"number:";
    cin>>product[i].pnum;
    cout<<"quantity: ";
  cin>> product[i].pquantity;
   cout<<"price:";cin>> product[i].pprice;
  }
}
void totalprice(PRODUCT *product,int size){
  float totalprice=0;
  for(int i=0;i<size;i++){
    totalprice=product[i].pquantity*product[i].pprice;
  }cout<<"total price="<<totalprice;
}

int main(){
  int size;
  cout<<"how many products?";
  cin>>size;
PRODUCT *product= new PRODUCT[size];
input(product,size);
totalprice(product,size);
return 0;
}




























   
