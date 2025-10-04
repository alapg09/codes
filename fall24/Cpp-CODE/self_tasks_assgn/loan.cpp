#include<iostream>
#include<cmath>

using namespace std;

int main(){

    int factor, balance, monthly;
    float interest, time;
    
    factor = 30;
    
    cout<<"Please enter the balance: ";
    cin>>balance;
    
    cout<<"Please enter the monthly payment: ";
    cin>>monthly;
    
    cout<<"Please enter the yearly interest rate: ";
    cin>>interest;

    float interest_perday = (interest/100)/365;


    float intermediate = (balance/monthly)*(1-(pow(1+interest_perday,factor)));
    float numerator = -log(1+(intermediate));
    float denominator = (log(1+interest/36500))*30;

    time = numerator/denominator;

    cout<<"It will take "<<time<<" months to pay off the loan";



    return 0;
}