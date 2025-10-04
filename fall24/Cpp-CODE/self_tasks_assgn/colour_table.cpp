#include<iostream>
#include<iomanip>

using namespace std;

    

// int main() {
    // *********bar chart***************
    
    // int num1,num2,num3,num4,num5;
    // cout<<"N1: ";
    // cin>>num1;
    
    // cout<<"N2: ";
    // cin>>num2;
    
    // cout<<"N3: ";
    // cin>>num3;
    
    // cout<<"N4: ";
    // cin>>num4;
    
    // cout<<"N5: ";
    // cin>>num5;
    
    

    

    // cout<<"N1: "<<setfill('*')<<left<<setw(num1)<<""<<endl;
    // cout<<"N2: "<<setfill('*')<<left<<setw(num2)<<""<<endl;
    // cout<<"N3: "<<setfill('*')<<left<<setw(num3)<<""<<endl;
    // cout<<"N4: "<<setfill('*')<<left<<setw(num4)<<""<<endl;
    // cout<<"N5: "<<setfill('*')<<left<<setw(num5)<<""<<endl;

    

    // *************magic date************
    
    
    // int day, month, year;


    // cout<<"Please enter the month (in numeric form): ";
    // cin>>month;
    // cout<<"Please enter the day: ";
    // cin>>day;
    // cout<<"Please enter the year (in two digits): ";
    // cin>>year;

    // if(month*day == year)
    //     cout<<"The date is magic.";
    // else
    //     cout<<"The date is not magic. ";



    //              ***************max and sec max*************** 

    // int num1,num2, num3,num4;
    // cout<<"Enter the numbers: ";
    // cin>>num1>>num2>>num3>>num4;

    // int numbers[4]= {num1,num2,num3,num4};
    // int max = num1, max2 = num2;
    
    
    // for(int i=0; i < 4;i++){
    //     if(max<numbers[i])
    //         max = numbers[i];}
    
    
    // for(int j = 0; j<4; j++){
        
    //     if (numbers[j] != max)
    //         if( max2 < numbers[j] )
    //             max2 = numbers[j];
        
            
        

    // }
    // cout<<"The maximum value is: "<<max<<endl;
    // cout<<"The second maximum is: "<<max2;

    
    
    
    
    //     *****************colour*************
    
    
int main(){
    int num1,num2;


    cout<<"ENTER THE TWO NUMBERS (1-36): ";
    cin>>num1>>num2;

    int green[] = {1,6,7,12,17,20,28,33};
    int red[] = {2,11,13,18,19,24,29,32};
    int blue[] = {3,10,14,23,25,30,31,36};
    int orange[] = {4,9,15,22,26,35};
    int grey[] = {5,8,16,21,27,34};


    for(int i = 0 ; i < 8; i++)
    if (num1 == green[i]){
        for(int j = 0 ; j < 8; j++)
        {   if (num2 == green[j]){
            cout<<"Same colour";
            return 0;
        }

        }      
        cout<<"Different";
        




    }
    for(int i = 0 ; i < 8; i++)
    if (num1 == red[i]){
        for(int j = 0 ; j < 8; j++)
        {   if (num2 == red[j]){
            cout<<"Same colour";
            return 0;
        }

        }      
        cout<<"Different";
        




    }
    for(int i = 0 ; i < 8; i++)
    if (num1 == blue[i]){
        for(int j = 0 ; j < 8; j++)
        {   if (num2 == blue[j]){
            cout<<"Same colour";
            return 0;
        }

        }      
        cout<<"Different";
        




    }
    for(int i = 0 ; i < 8; i++)
    if (num1 == orange[i]){
        for(int j = 0 ; j < 8; j++)
        {   if (num2 == orange[j]){
            cout<<"Same colour";
            return 0;
        }

        }      
        cout<<"Different";
        




    }
    for(int i = 0 ; i < 8; i++)
    if (num1 == grey[i]){
        for(int j = 0 ; j < 8; j++)
        {   if (num2 == grey[j]){
            cout<<"Same colour";
            return 0;
        }

        }      
        cout<<"Different";
        




    }
}

//******using functions**** */

// bool isSame(int num1,int num2, int color[], int size){
//     bool foundNum1 = false;
//     bool foundNum2 = false;

//     for(int i = 0; i < size ; i++){
//         if (num1 == color[i]){
//             foundNum1 = true;
// }
//         if(num2 == color[i]){
//             foundNum2 = true;
//         } 

//     }
//     return foundNum1 && foundNum2;
// }

// int main(){
//     int num1,num2;
//     cout<<"numbers: ";
//     cin>>num1>>num2;

//     int green[] = {1, 6, 7, 12, 17, 20, 28, 33};
//     int red[] = {2, 11, 13, 18, 19, 24, 29, 32};
//     int blue[] = {3, 10, 14, 23, 25, 30, 31, 36};
//     int orange[] = {4, 9, 15, 22, 26, 35};
//     int grey[] = {5, 8, 16, 21, 27, 34};

//     const int sizeGreen = sizeof(green) / sizeof(green[0]);
//     const int sizeRed = sizeof(red) / sizeof(red[0]);
//     const int sizeBlue = sizeof(blue) / sizeof(blue[0]);
//     const int sizeOrange = sizeof(orange) / sizeof(orange[0]);
//     const int sizeGrey = sizeof(grey) / sizeof(grey[0]);

//     if (isSame(num1, num2, green, sizeGreen) ||
//         isSame(num1, num2, red, sizeRed) ||
//         isSame(num1, num2, blue, sizeBlue) ||
//         isSame(num1, num2, orange, sizeOrange) ||
//         isSame(num1, num2, grey, sizeGrey)) {
//         cout << "Same colour" << endl;
//     } else {
//         cout << "Different" << endl;
//     }






//     return 0;
// }




