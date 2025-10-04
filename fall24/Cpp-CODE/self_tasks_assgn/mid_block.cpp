#include<iostream>

using namespace std;

int main(){
   for(int m = 1; m<=5; m++)
   {
    if(m == 1)
    {
        cout<<" ";
    }
    else if(m%2 == 0 && m!=1 ) 
    {
        cout<<"*";
    }
    else
    {
        cout<<"-";
    }
    if(m==1)
    {
        cout<<"-";
    }

    if(m%2 == 0 && m!=1)
    {
        cout<<" -";
    }
    else 
    {
        cout<<" *";
    }
    if(m!=1)
    {
        cout<<" ";
    }
    for (int b = 4; b >= m; b--) {
            cout << "*";
        }

        for (int b = 1; b <= m; b++) {
            cout << b;
        }

        for (int b = m - 1; b >= 1; b--) {
            cout << b;
        }

        for (int b = 4; b >= m; b--) {
            cout << "*";
        }
    if(m == 1)
    {
        cout<<"";
    }
    else if(m%2 == 0 && m!=1 ) 
    {
        cout<<" -";
    }
    else
    {
        cout<<" *";
    }
    if(m==1)
    {
        cout<<"*";
    }

    if(m%2 == 0 && m!=1)
    {
        cout<<" *";
    }
    else 
    {
        cout<<" -";
    }
    if(m!=1)
    {
        cout<<" ";
    }
        
    cout<<endl;
   } 
    for (int a = 1; a <= 5-1; a++) {

    if(a%2 == 0  ) 
    {
        cout<<"*";
    }
    else
    {
        cout<<"-";
    }

    if(a%2 == 0 )
    {
        cout<<" - ";
    }
    else 
    {
        cout<<" * ";
    }
        for (int b = 1; b <= a; b++) {
            cout << "*";
        }

        for (int b = 1; b <= 5-a; b++) {
            cout << b;
        }
        
        for(int b = 1; b<=(5-a)-1; b++)
        {
            cout<<" ";
        }

        for (int b = 1; b <= a; b++) {
            cout << "*";
        }
    if(a%2 == 0  ) 
    {
        cout<<" *";
    }
    else
    {
        cout<<" -";
    }

    if(a%2 == 0)
    {
        cout<<" -";
    }
    else 
    {
        cout<<" *";
    }

        cout << endl;
    }

return 0;
}