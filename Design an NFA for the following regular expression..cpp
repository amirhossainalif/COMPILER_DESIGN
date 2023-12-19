/* Design an NFA for the following regular expression.
     (a|b)*abbc
*/

#include <iostream>
#include <string>
using namespace std;

bool NFA(const string& input)
{
    int cs = 0;
    int n = input.size();

    for (int i = 0; i < n; ++i)
    {
        char c = input[i];

        switch (cs)
        {
        case 0:
            if (c == 'a' || c == 'b')
            {
                cs = 0;
                return true;
            }
            else
                return false;
            break;
        case 1:
            if (c == 'a' || c == 'b')
            {
                cs = 0;
                return true;
            }
            else
                return false;
            break;
        case 2:
            if (c == 'a' || c == 'b')
            {
                cs = 0;
                return true;
            }
            else
                return false;
            break;
        case 3:
            if (c == 'a' || c == 'b')
            {
                cs = 0;
                return true;
            }
            else
                return false;
            break;
        case 4:
            if (c == 'a')
            {
                cs = 1;
                return true;
            }
            else
                return false;
            break;
        case 5:
            if (c == 'b')
            {
                cs = 2;
                return true;
            }
            else
                return false;
            break;
        case 6:
            if (c == 'b')
            {
                cs = 3;
                return true;
            }
            else
                return false;
            break;
        case 7:
            if (c == 'c')
            {
                cs = 4;
                return true;
            }
            else
                return false;
            break;
        default:
            return false;
        }
    }

    return cs == 4;
}

int main()
{
    string input = "aabbabbc";
    cout << "The regular expression (a|b)*abbc and the input string is " << input << endl << endl;

    if (NFA(input))
    {
        cout << "Accepted" << endl;
    }
    else
    {
        cout << "Rejected" << endl;
    }

    return 0;
}

