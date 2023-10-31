/*Write a program that would analyse the following:
1. Detect the variable is properly declared or not
2. Detect whether the given mathematical expression is properly parenthesized or not.*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValidVariableName(const string& token)
{
    if (!isalpha(token[0]) && token[0] != '_')
        return false;

    for (char c : token)
    {
        if (!isalnum(c) && c != '_')
            return false;
    }

    return true;
}

bool isProperlyParenthesized(const string& expression)
{
    stack<char> stack;

    for (char c : expression)
    {
        if (c == '(')
        {
            stack.push(c);
        }
        else if (c == ')')
        {
            if (stack.empty() || stack.top() != '(')
            {
                return false;
            }
            stack.pop();
        }
    }

    return stack.empty();
}

int main()
{
    string input;
    cout << "Enter a C++ code snippet: ";
    getline(cin, input);

    stack<string> variableStack;
    size_t pos = 0;
    while ((pos = input.find(" ")) != string::npos)
    {
        string token = input.substr(0, pos);
        input.erase(0, pos + 1);

        if (isValidVariableName(token))
        {
            variableStack.push(token);
        }
    }
    if (!variableStack.empty())
    {
        cout << "Properly declared variables: ";
        while (!variableStack.empty())
        {
            cout << variableStack.top() << " ";
            variableStack.pop();
        }
        cout << endl;
    }
    else
    {
        cout << "No valid variables declared." << endl;
    }

    cout << "Enter a mathematical expression: ";
    string expression;
    getline(cin, expression);

    if (isProperlyParenthesized(expression))
    {
        cout << "The expression is properly parenthesized." << endl;
    }
    else
    {
        cout << "The expression is not properly parenthesized." << endl;
    }

    return 0;
}
