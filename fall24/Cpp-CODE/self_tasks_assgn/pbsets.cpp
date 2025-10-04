#include<iostream>
#include<iomanip>

using namespace std;

int main(){


    // i am checking github
    // ************waterbil*******


    int gallons;
    float bill;
    cout<<"Please enter the number of gallons: ";
    cin>>gallons;


    if ( gallons <= 100 ){
        bill = gallons*0.45;
    }
    else if ( gallons > 100 && gallons <= 350)
        bill = (100*0.45) + ((gallons-100)*0.85);
    else if( gallons>350 && gallons<=600)
        bill = (100*0.45)+(250*0.85)+(gallons-350)*1.45;
    else if(gallons>600)
        bill = (100*0.45)+(250*0.85)+(250*1.45 ) + ((gallons - 600)*2.6);
    else if(gallons<0)
        cout<<"Invalid input";

    float serv_chg = 0.14*bill;

    cout<< fixed <<setprecision(2);
    cout<<"The water bill is: "<< bill<<endl;
    cout<<"The total bill is: "<< bill+serv_chg;
        







    return 0;
}