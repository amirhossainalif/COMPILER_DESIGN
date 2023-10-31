/*Write a C/C++ program to perform the following operations
Make the input file
Read the input file
Identify the comment lines
Identify the identifiers
Identify the literals
Print all the results as a tabular form.*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool isCommentLine(const string &line)
{
    if (line.length() < 2)
        return false;
    return line[0] == '/' && line[1] == '/';
}

bool isIdentifier(const string &token)
{
    if (token.empty() || isdigit(token[0]))
        return false;
    for (char c : token)
    {
        if (!isalnum(c) && c != '_')
            return false;
    }
    return true;
}

bool isLiteral(const string &token)
{
    if (token.empty())
        return false;

    if ((token[0] == '"' && token[token.length() - 1] == '"') ||
            (token[0] == '\'' && token[token.length() - 1] == '\''))
    {
        return true;
    }

    bool decimalPointSeen = false;
    for (char c : token)
    {
        if (!isdigit(c))
        {
            if (c == '.' && !decimalPointSeen)
                decimalPointSeen = true;
            else
                return false;
        }
    }
    return true;
}

int main()
{
    string filename = "input.txt";

    ofstream inputFile(filename);
    if (!inputFile.is_open())
    {
        cerr << "Failed to create input file: " << filename << endl;
        return 1;
    }

    inputFile << "#include<iostream>\n";
    inputFile << "#using namespace std;\n";
    inputFile << "int main() \n";
    inputFile << "{\n";
    inputFile << "    int a = 2;\n";
    inputFile << "    int b = 3;\n";
    inputFile << "    int sum = a + b; \n";
    inputFile << "    cout << \"sum: \"<< sum;\n";
    inputFile << "    return 0;\n";
    inputFile << "}\n";
    inputFile << "// This is a comment line\n";
    inputFile << "12345 // Not a comment\n";
    inputFile.close();


    ifstream inputReadFile(filename);

    vector<string> lines;
    string line;
    while (getline(inputReadFile, line))
    {
        lines.push_back(line);
    }
    inputReadFile.close();

    vector<string> comments, identifiers, literals;
    for (const string &inputLine : lines)
    {
        if (isCommentLine(inputLine))
        {
            comments.push_back(inputLine);
        }
        else
        {
            string token = "";
            for (char c : inputLine)
            {
                if (isalnum(c) || c == '_')
                {
                    token += c;
                }
                else
                {
                    if (!token.empty())
                    {
                        if (isIdentifier(token))
                        {
                            identifiers.push_back(token);
                        }
                        else if (isLiteral(token))
                        {
                            literals.push_back(token);
                        }
                        token = "";
                    }
                }
            }
            if (!token.empty())
            {
                if (isIdentifier(token))
                {
                    identifiers.push_back(token);
                }
                else if (isLiteral(token))
                {
                    literals.push_back(token);
                }
            }
        }
    }


    cout << "Line\t\tComment\t\tIdentifiers\tLiterals\n";
    for (size_t i = 0; i < lines.size(); i++)
    {
        cout << i + 1 << "\t\t" << (isCommentLine(lines[i]) ? "Yes" : "No") << "\t\t";
        if (i < identifiers.size())
        {
            cout << identifiers[i];
        }
        cout << "\t\t";
        if (i < literals.size())
        {
            cout << literals[i];
        }
        cout << "\n";
    }

    return 0;
}

