#include<iostream>
#include<cmath>

using namespace std;



int factorial (int x)
{
    if (x<=1){
    return 1;}

return x*factorial(x-1);
}
double series(double x){
    double sinx = 0;
    double term;
    int n = 0;


    do{
        term = pow(-1, n)*pow(x, 2*n + 1)/factorial(2*n + 1);
        sinx += term;
        n++;

    }while (fabs(term) >=0.001);
        return sinx;    
}




int main(){
    double x;

    cout<<"Enter the value of x (in radidan): ";
    cin>>x;

    // double sinx = x - (pow(x,3)/(3*2*1))+(pow(x,5))/(5*4*3*2*1)+(pow(x,7))/(7*6*5*4*3*2*1);

    double result = series(x);

    cout<<"sin(" <<x<< ")=" << result <<endl;
    // cout<<sinx;
    return 0;

}