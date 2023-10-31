//Write a C/C++ program to perform the following operations with any strings.
//Remove all the repeated characters.
//Remove all the blank space in any sentence.
//Count the total string length.
//print any string where it give output 1st row just one character then it increase to printing character randomly


#include <iostream>
#include <string>
using namespace std;

string remove_repeated_characters(string c)
{
    string result = "";
    for (int i = 0; i < c.length(); i++)
    {
        bool isDuplicate = false;
        for (int j = 0; j < result.length(); j++)
        {
            if (c[i] == result[j])
            {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate)
        {
            result += c[i];
        }
    }
    return result;
}

string remove_blank_space(string s)
{
    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            result += s[i];
        }
    }
    return result;
}

int string_length(const char* str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

void string_rows(string input)
{
    for (int i = 1; i <= input.length(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << input[j];
        }
        cout << endl;
    }
}

int main()
{
    string c;
    cout << "Enter a string: ";
    getline(cin, c);

    string result = remove_repeated_characters(c);
    cout << result << endl << endl;

    string result1 = remove_blank_space(result);
    cout << result1 << endl << endl;

    const char* in="Hello world";
    cout << "string: " << in << endl;
    int result2 = string_length(in);
    cout << "Total string length: " << result2 << endl << endl;
    cout << "String rows: " << endl;
    string_rows(in);

    return 0;
}

