#include <iostream>
#include <stack>
using namespace std;

char bfinder(char ch)
{
    switch (ch)
    {
    case '(':
        return ')';
    case '[':
        return ']';
    case '{':
        return '}';
    default:
        break;
    }
    return '_';
}

int main()
{
    string str = "(1+2)/3";
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (!st.empty() && bfinder(st.top()) == str[i])
        {
            st.pop();
        }
        else
        {
            char elem = str[i];
            if (elem == '(' || elem == ')' || elem == '{' || elem == '}' || elem == '[' || elem == ']')
            {
                st.push(elem);
            }
        }
    }
    if (!st.empty())
    {
        cout << "UNBALANCED";
    }
    else
    {
        cout << "BALANCED";
    }
    return 0;
}