#include<iostream>

using namespace std;

int main(){
    for (int i = 1; i <= 8; i++)
    {
        for(int j = 1; j<=i; j++)
        {
            cout<<" ";
        }
        if(i%2 == 0)
        {
            cout<<"- "; 
        }
        else 
        {
            cout<<"* ";
        }
        if(i%2 == 0 && i<=6)
        {
            cout<<"* ";
        }
        else if(i%2!=0 && i<=6)
        {
            cout<<"- ";
        }
        for(int l =9; l>=(2*i)-1; l--)
        {
            cout<<" ";
        }
        if(i%2 == 0 && i<=5)
        {
            cout<<"* ";
        }
        else if(i%2!=0 && i<=5)
        {
            cout<<"- ";
        }
        if(i%2 == 0 && i <=7)
        {
            cout<<"-";
        }
        else if(i%2!=0 && i <=7)
        {
            cout<<"*";
        }
        cout<<endl;

    }
    return 0;
}