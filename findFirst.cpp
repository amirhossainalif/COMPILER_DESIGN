/*E  -> TE'  
E'  -> +TE'| #  
T  -> FT'  
T'  -> *FT' | # 
F  -> (E) | id | a | b 

Write a C/C++ program to calculate the First set only.*/


#include<iostream>
#include<vector>
#include<set>

using namespace std;

void findFirst(char, int, int);

vector<set<char>> calc_first(10);

vector<string> production{"E=TE'", "E'=+TE'|#", "T=FT'", "T'=*FT'|#", "F=(E)|id|a|b"};

int count = 5;
int n = 0;

int main()
{
    int point1 = 0, point2, x;

    for (int k = 0; k < count; k++)
    {
        char c = production[k][0];
        point2 = 0;
        x = 0;

        findFirst(c, 0, 0);

        cout << "\n First(" << c << ") = { ";
        calc_first[point1].insert(c);

        for (char firstSet : calc_first[point1])
        {
            cout << firstSet << ", ";
        }
        cout << "}\n";

        point1++;
    }

    return 0;
}

void findFirst(char c, int q1, int q2)
{
    if (!(isupper(c)))
    {
        calc_first[n].insert(c);
    }
    else
    {
        for (int j = 0; j < count; j++)
        {
            if (production[j][0] == c)
            {
                if (production[j][2] == '#')
                {
                    if (production[q1][q2] == '\0')
                    {
                        calc_first[n].insert('#');
                    }
                    else if (production[q1][q2] != '\0' && (q1 != 0 || q2 != 0))
                    {
                        findFirst(production[q1][q2], q1, (q2 + 1));
                    }
                    else
                    {
                        calc_first[n].insert('#');
                    }
                }
                else if (!isupper(production[j][2]))
                {
                    calc_first[n].insert(production[j][2]);
                }
                else
                {
                    findFirst(production[j][2], j, 3);
                }
            }
        }
    }
}




