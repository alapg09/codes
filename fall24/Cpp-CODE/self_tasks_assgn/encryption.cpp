#include<iostream>

using namespace std;

int main(){
int n;
cout<<"Number: ";
cin>>n;

double result = (((((((2082%11)+200)*n)/(2082%11))*17)-5)/(2082%9))+3;
cout<<"The encrypted number is: "<<result;




return 0;
}