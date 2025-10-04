#include<iostream>
#include<limits>

using namespace std;

int main(){

    int num;

    cout<<"Please enter a number between 1 and 9: ";
    cin>>num;
    
    while(true){
        if( num >= 1 && num <= 9 ){
            cout<<"The polar opposite is: "<<10-num;
            break;   
    }
    else if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Invalid Input, Please enter an integer (1-9)";
        cin>>num;
        

    }
    else{
        cout<<"Invalid Input. Please enter an integer between 1 and 9: ";
        cin>>num;
    }


    }


    return 0;
}