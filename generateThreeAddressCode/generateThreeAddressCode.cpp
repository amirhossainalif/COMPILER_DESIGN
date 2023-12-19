#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


void generateThreeAddressCode(const char* expression)
{

    char temp1[100], temp2[100], temp3[100];


    char* token = strtok((char*)expression, " ");
    strcpy(temp1, token);

    while (token != NULL)
    {
        token = strtok(NULL, " ");

        if (token == NULL) break;

        if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
        {

            sprintf(temp2, "%s %s %s", temp1, token, strtok(NULL, " "));


            printf("%s = %s\n", temp3, temp2);

            strcpy(temp1, temp3);
        }
        else
        {

            sprintf(temp3, "%s %s %s", temp1, token, strtok(NULL, " "));


            printf("%s = %s\n", temp1, temp3);
        }
    }
}

int main()
{

    ifstream inputFile("expression.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    string expression;
    getline(inputFile, expression);


    inputFile.close();


    const char* charExpression = expression.c_str();


    generateThreeAddressCode(charExpression);

    return 0;
}


