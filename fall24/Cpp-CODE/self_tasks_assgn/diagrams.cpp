#include<iostream>


using namespace std;

int main(){
    int rows;
    cout<<"Please enter the number of rows: ";
    cin>>rows;
  
    int row_const = rows;
    for(int i=0; i<row_const; i++){

        for(int j=0; j<i; j++){
            cout<<" ";
    }
        
        for(int k = 0; k<rows+(rows-1);k++)
        {  cout<<"*";
        }
        
        rows -= 1;
        cout<<endl;
        
    }
        





    return 0;
}