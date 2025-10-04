#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int a,b,c;

    cout<<"please enter the lengths of sides of the triangle: ";
    cin>>a>>b>>c;

    float p = (a+b+c)/2;


    double area = sqrt(p*(p-a)*(p-b)*(p-c));

    cout<<"the area is: "<<area;




    return 0;
}