/// Write a C/C++ program to design an NFA for the following RE. (aUc)*aca


#include <iostream>
using namespace std;

bool isMatch(string str)
{
    int currentState = 0;
    int len = str.length();

    for (int i = 0; i < len; ++i)
    {
        char symbol = str[i];

        switch (currentState)
        {
        case 0:
            if (symbol == 'a')
            {
                currentState = 1;
            }
            else if (symbol == 'c')
            {
                currentState = 2;
            }
            else
            {
                return false;
            }
            break;
        case 1:
            if (symbol == 'a' || symbol == 'c')
            {
                currentState = 1;
            }
            else
            {
                return false;
            }
            break;
        case 2:
            if (symbol == 'a')
            {
                currentState = 3;
            }
            else if (symbol == 'c')
            {
                currentState = 2;
            }
            else
            {
                return false;
            }
            break;
        case 3:
            return false;
        }
    }

    return true;
}

int main()
{
    string input = "aaca";
    cout << "Enter the input string: aaca"<<endl;


    if (isMatch(input))
    {
        cout << "Accepted" << endl;
    }
    else
    {
        cout << "Rejected" << endl;
    }

    return 0;
}
