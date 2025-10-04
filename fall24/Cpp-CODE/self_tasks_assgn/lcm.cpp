#include<iostream>

using namespace std;

int main(){
    int num1,num2, greater;

    cout<<"Enter the first natural number: ";
    cin>>num1;

    cout<<"Enter the second natural number: ";
    cin>>num2;

    if(num1 <= 0 || num2 <= 0){
        cout<<"Please rerun the program enter a natural number";
    return 0;
    }
    
    if(num1>num2){
        greater = num1;
    }
    else   
        greater = num2;

    


    do{
        if((greater % num1) == 0 && (greater % num2) == 0)
        {   cout<<"LCM is "<<greater;
            break;
        }
        else
            ++greater;
    }while(true);


    return 0;
    }




