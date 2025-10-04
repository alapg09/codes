#include<iostream>

using namespace std;

int main(){

    for( int i = 0; i < 16; i++) 
    {      
        for(int k = 0; k<32; k++)
        {
            if( k == 31)
            {
                cout<<'*';
            }
            if( k == 5 && ( i == 14 || i == 13 || i == 12))
            {
                cout<<'*';
            }
            else if((k>5 && k<=10) && (i == 12))
            {
                cout<<'*';
            }
            else if( k == 10 && ( i == 11 || i == 10 || i == 9))
            {
                cout<<'*';
            }
            else if((k>10 && k<=15) && (i == 9))
            {
                cout<<'*';
            }
            else if( k == 15 && ( i == 8 || i == 7 || i == 6))
            {
                cout<<'*';
            }
            else if((k>15 && k<=20) && (i == 6))
            {
                cout<<'*';
            }
            else if( k == 20 && ( i == 5 || i == 4 || i == 3))
            {
                cout<<'*';
            }
            else if((k>20 && k<=25) && (i == 3))
            {
                cout<<'*';
            }
            else if( k == 25 && ( i == 2 || i == 1 || i == 0))
            {
                cout<<'*';
            }
            else if((k>25 && k<=30) && (i == 0))
            {
                cout<<'*';
            }
            else if(i == 15)
            {
                if(k<31)
                cout<<"*";
            }
            else
            {
                cout<<' ';
            }

        }
        
        cout<<endl;
    }
return 0;
}


