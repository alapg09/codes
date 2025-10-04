#include<iostream>
#include<cctype>

using namespace std;

int main(){
    string num;
    int num2;

    cout<<"Please enter a number between 1 and 9: ";
    cin>>num;
    
    while(true){
        if( num.length() == 1 && isdigit(num[0])){
            num2 = stoi(num);
                if(num2 >0 && num2<10){
                    cout<<"The polar opposite is: "<<10-num2;
                    break;
                }        
        }
        else{
            cout<<"Invalid Please enter an integer(1-9): ";
            cin>>num;
        }
    }
    return 0;
}