// TASK 3

// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;
// void showState(const fstream &);
// int main()
// {
//     fstream inout;
//     // Create an output file
//     inout.open("temp.txt", ios::out);
//     inout << "Dallas";
//     cout << "Normal operation (no errors)" << endl;
//     showState(inout);
//     inout.close();
//     // Create an input file
//     inout.open("temp.txt", ios::in);
//     // Read a string
//     string city;
//     inout >> city;
//     cout << "End of file (no errors)" << endl;
//     showState(inout);
//     inout.close();
//     // Attempt to read after file closed
//     inout >> city;
//     cout << "Bad operation (errors)" << endl;
//     showState(inout);
//     return 0;
// }
// void showState(const fstream &stream)
// {
//     cout << "Stream status: " << endl;
//     cout << " eof(): " << stream.eof() << endl;
//     cout << " fail(): " << stream.fail() << endl;
//     cout << " bad(): " << stream.bad() << endl;
//     cout << " good(): " << stream.good() << endl;
// }

// TASK 4

// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

// int main()
// {

//     fstream file("file.txt", ios::in);

//     if (!file)
//     {
//         cout << "File does not exist." << endl;
//         return 1;
//     }

//     char ch;
//     int char_count = 0;

//     while (file.get(ch))
//     {
//         char_count++;
//     }
//     file.close();

//     file.open("file.txt", ios::out | ios::app);
//     if (file)
//     {
//         file << "\nTotal Characters: " << char_count << endl;
//         cout << "The file contains " << char_count << " characters. The count has been appended to the file." << endl;
//     }
//     else
//     {
//         cout << "Error opening the file for writing." << endl;
//     }

//     file.close();
//     return 0;
// }

// TASK 5

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
bool is_vowel(char c)
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main()
{
    string file_name;

    cout << "Enter the file name: ";
    cin >> file_name;

    ifstream input(file_name.c_str());

    if (!input)
    {
        cout << "error: " << file_name << " does not exist" << endl
             << "exitin g program" << endl;
        return 0;
    }
    char c;
    int count = 0;
    while (input.get(c))
    {
        if (is_vowel(c))
        {
            count++;
        }
    }
    input.close();

    cout << "There are " << count << " vowels in the file." << endl;

    return 0;
}