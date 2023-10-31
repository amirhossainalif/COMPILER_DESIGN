/*Write a program that would analyze the following:
1. To detect whether the function is properly declared.
2. To detect whether the function is properly defined*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool FDeclaration(const string &line)
{
    return line.find('(') != string::npos && line.find(')') != string::npos;
}

bool FDefinition(const string &line)
{
    return line.find('{') != string::npos && line.find('}') != string::npos;
}

int main()
{
    bool fDeclaration = false;
    bool fDefinition = false;
    string line;

    ifstream inputFile("function.txt");
    if (!inputFile)
    {
        cerr << "Error opening source code file." << endl;
        return 1;
    }

    while (getline(inputFile, line))
    {
        if (FDeclaration(line))
        {
            fDeclaration = true;
            fDefinition = false;
            if (FDefinition(line))
            {
                fDefinition = true;
                fDeclaration = true;
            }
        }
        else if (FDefinition(line))
        {
            fDefinition = true;
            fDeclaration = false;
            if (FDeclaration(line))
            {
                fDeclaration = true;
                fDefinition = true;
            }
        }

        if (fDeclaration==true && fDefinition==true)
        {
            cout << "Function is properly declared and defined." << endl << endl;
            fDeclaration = false;
            fDefinition = false;
        }
        else if (fDeclaration==true)
        {
            cout << "Function is declared but not defined." << endl << endl;
            fDeclaration = false;
        }
        else if (fDefinition==true)
        {
            cout << "Function is defined but not properly declared." << endl << endl;
            fDefinition = false;
        }
    }

    inputFile.close();
    return 0;
}
