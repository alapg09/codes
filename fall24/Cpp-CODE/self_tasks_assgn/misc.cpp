
#include<iostream>

#include<iomanip>

using namespace std;

int main(){

    int colmns=32, coloumns2=32;

    for( int i=16;i>=1;--i)
    { 
        cout<<setw(33)<<"*\r";
    
    if(i==16||i==13||i==10||i==7||i==4)
    {
        for(int j=1;j<=colmns-6;++j)
        {
            cout<<" ";
        } 
        
        for(int k=1;k<=6;++k)
        {
            cout<<"*";
        }

     colmns=colmns-6;

     cout<<endl;
     }
    
    if(i==1)
    {
        cout<<setw(32)<<setfill('*')<<"*"<<setfill(' ');
    }

    if(i==15||i==14||i==12||i==11||i==9||i==8||i==6||i==5||i==3||i==2)
    {

        if(i==12||i==9||i==6||i==3)
        {
            coloumns2=coloumns2-6;
        }

        for(int L=1;L<=coloumns2-6;++L)
        {
            cout<<" ";
        }

        for(int m=1;m==1;++m)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    }

     return 0;
}