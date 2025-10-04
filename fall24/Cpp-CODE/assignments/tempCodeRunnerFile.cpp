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
        cout <<"error: "<< file_name << " does not exist" << endl
             << "exiting program" << endl;
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