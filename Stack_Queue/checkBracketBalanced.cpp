/**
 * @file checkBracketBalanced.cpp
 * @brief check if given string of brackets are balanced
 *
 * @author Mayur Aggarwal
 * @bug No known bugs. 
 * Contact: aga.mayur@gmail.com
 *
 */
#include <iostream>
#include <stack>

using namespace std;

int isMathcingPair(char a, char b)
{
    if (a == '{' && b == '}')
        return 1;
    else if (a == '(' && b == ')')
        return 1;
    else if (a == '[' && b == ']')
        return 1;
    else 
        return 0;
}

int areBracketBalanced(char* str)
{
    stack<int> s;
    int i = 0;
    char popped = '$';
    while (str[i] != '\0')
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            s.push(str[i]);
        }
        if (str[i] == '}' || str[i] == ')' || str[i] == ']')
        {
            popped = '$';   // init before popping the elem from stack
            if(!s.empty()){ // pop only if elem is present in stack
                popped = s.top();
                s.pop();
            }
            if (!isMathcingPair(popped, str[i]))
            {
                return 0;
            }
        }
        i++;
    }
    if(s.empty())
        return 1;
    else
        return 0;
}

int main()
{
    char expr[10] = "{()}[]";
    if (areBracketBalanced(expr))
    {
        cout << "Balanced\n";
    }
    else
    {
        cout << "Not Balanced\n";
    }
    return 0;
}
