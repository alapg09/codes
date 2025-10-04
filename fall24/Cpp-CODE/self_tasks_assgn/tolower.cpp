#include<iostream>
#include<cctype>


using namespace std;

int main(){
    string alpha;
    cout<<"Enter the alphabet: ";
    cin>>alpha;

    bool valid = true;

    while (true){
        if(isalpha(alpha[0]) && alpha.length() == 1 ){
            valid = true;
            char lower = tolower(alpha[0]);
            cout<<"The lowercase alphabet is: "<<lower;
            break;
            
        }else{
            cout<<"Invalid Input. Please enter an alphabetical character: ";
            cin>>alpha;
        }
    }
    return 0;
} 