#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int a,b,c;
    cout<<"please entter a, b and c of quadratic eq: ";
    cin>>a>>b>>c;

    double D = sqrt((b*b)-4*(a*c));


    double x1 = (-b+D)/2*a , x2 = (-b-D)/2*a;

    cout<<"the roots are :"<<x1<<" , "<<x2;




    return 0;
}