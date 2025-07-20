#include <iostream>
#include <string>
using namespace std;

char kthCharacter(int k)
{
    char ch = 'a';
    string st = "a";
    while (st.length() <= k)
    {
        int currentLength = st.length();
        for (int i = 0; i < currentLength; i++)
        {
            char temp = st[i];
            temp++;
            if (temp > 122)
            {
                temp -= 26;
            }
            st += temp;
        }
    }
    return st[k - 1];
}

int main()
{
    int k;
    cin >> k;
    cout << kthCharacter(k);
    return 0;
}