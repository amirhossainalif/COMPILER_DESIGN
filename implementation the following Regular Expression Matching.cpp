/*Write a C++ Program to implement the following Regular Expression Matching
1. abc*= ab, abc, abcc, abcccc ……
2. abc+ = abc, abcc, abcccc …..
3. [abc]= “a”, “b”, “c”
4. a(bc)? = “a”, “abc” */


#include <iostream>
#include <string>
using namespace std;


///   abc*= ab, abc, abcc, abcccc ……
bool check(const string& s)
{
    int i = 0;

    while (i < s.length() && s[i] == 'a')
    {
        i++;
    }
    if (i >= s.length() || s[i] != 'b')
    {
        return false;
    }
    i++;

    while (i < s.length() && s[i] == 'c')
    {
        i++;
    }

    return i == s.length();
}


///    abc+ = abc, abcc, abcccc
bool check1(const string& input)
{
    int i = 0;
    int len = input.length();

    if (i < len && input[i] == 'a')
    {
        i++;

        if (i < len && input[i] == 'b')
        {
            i++;

            while (i < len && input[i] == 'c')
            {
                i++;
            }
        }
    }

    return (i == len);
}


///     [abc]= “a”, “b”, “c”

bool check2(const string& input)
{
    for (char c : input)
    {
        if (c != 'a' && c != 'b' && c != 'c')
        {
            return false;
        }
    }
    return true;
}


///   a(bc)? = “a”, “abc”

bool check3(const string &input)
{
    int n = input.length();

    if (n == 0)
    {
        return false;
    }

    if (input[0] != 'a')
    {
        return false;
    }

    if (n == 1)
    {
        return true;
    }

    if (n == 2 && input[1] == 'b')
    {
        return true;
    }

    if (n == 3 && input[1] == 'b' && input[2] == 'c')
    {
        return true;
    }

    return false;
}


int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    cout << "----------1st---------" << endl;
    if (check(input))
    {
        cout << "'abc*' matches the input string." << endl << endl;
    }
    else
    {
        cout << "'abc*' does not match the input string." << endl << endl;
    }

    cout << "----------2nd---------" << endl;
    if (check1(input))
    {
        cout << "'abc+' matches the input string." << endl << endl;
    }
    else
    {
        cout << "'abc+' does not match the input string." << endl << endl;
    }

    cout << "----------3rd---------" << endl;
    string pattern = "[abc]";
    string input1;

    cout << "Enter a string to match: ";
    cin >> input1;

    if (check2(input1))
    {
        cout << "Pattern '" << pattern << "' matches the input" << endl << endl;
    }
    else
    {
        cout << "Pattern '" << pattern << "' does not match the input" << endl << endl;
    }

    cout << "----------4th---------" << endl;
    string input2;
    cout << "Enter a string: ";
    cin >> input2;

    if (check3(input2))
    {
        cout << "Pattern matched!" << endl;
    }
    else
    {
        cout << "Pattern not matched." << endl;
    }

    return 0;
}


