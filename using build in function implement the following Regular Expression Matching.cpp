/*Write a C++ Program to using build in function implement the following Regular Expression Matching
1. abc*= ab, abc, abcc, abcccc ……
2. abc+ = abc, abcc, abcccc …..
3. [abc]= “a”, “b”, “c”
4. a(bc)? = “a”, “abc” */

#include <iostream>
#include <regex>
#include <string>

bool isMatch(const std::string& s)
{
    int i = 0;

    if (i < s.size() && s[i] == 'a')
    {
        i++;

        if (i < s.size() && s[i] == 'b')
        {
            i++;

            while (i < s.size() && s[i] == 'c')
            {
                i++;
            }

            if (i == s.size())
            {
                return true;
            }
        }
    }

    return false;
}


bool isMatching(const std::string &input)
{
    std::regex pattern("abc+");

    return std::regex_search(input, pattern);
}

bool isMatch1(const std::string &input)
{
    std::regex pattern("[abc]");
    return std::regex_match(input, pattern);
}


bool isMatch2(const std::string &text, const std::string &pattern)
{
    if (pattern.empty())
    {
        return text.empty();
    }
    if (pattern.size() >= 2 && pattern[1] == '(' && pattern[2] == 'b' && pattern[3] == 'c' && pattern[4] == ')')
    {
        // Attempt two possibilities: one without 'bc' and one with 'bc'.
        return (isMatch2(text, pattern.substr(5)) || (text.size() >= 1 && text[0] == 'a' && isMatch2(text.substr(1), pattern.substr(5))));
    }
    else
    {
        if (text.empty() || text[0] != 'a')
        {
            return false;
        }
        return isMatch2(text.substr(1), pattern.substr(1));
    }
}


int main()
{
    std::string in;
    std::cout << "Enter a string: ";
    std::cin >> in;

    if (isMatch(in))
    {
        std::cout << "Matched 'abc*' pattern." << std::endl;
    }
    else
    {
        std::cout << "Did not match 'abc*' pattern." << std::endl;
    }

    std::string in1;

    std::cout << "Enter a string: ";
    std::cin >> in1;

    if (isMatching(in1))
    {
        std::cout << "The input matches the pattern 'abc+'.\n";
    }
    else
    {
        std::cout << "The input does not match the pattern 'abc+'.\n";
    }

    std::string in2;
    std::cout << "Enter a character: ";
    std::cin >> in2;

    if (isMatch1(in2))
    {
        std::cout << "Input matches the pattern [abc]." << std::endl;
    }
    else
    {
        std::cout << "Input does not match the pattern [abc]." << std::endl;
    }

    std::string text;
    std::cout << "Enter a string: ";
    std::cin >> text;
    std::string pattern = "a(bc)?";

    if (isMatch2(text, pattern))
    {
        std::cout << "Matched!" << std::endl;
    }
    else
    {
        std::cout << "Not matched!" << std::endl;
    }

    return 0;
}
