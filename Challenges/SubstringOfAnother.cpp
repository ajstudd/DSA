#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string st = "Hello World";
    string substr = "World";
    int n = st.length();
    int m = substr.length();
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (substr[j] != st[i + j])
            {
                break;
            }
        }
        if (j == m)
        {
            cout << "found substr at: " << i;
            return 0;
        }
    }
    cout << "Substring not found";
    return 0;
}