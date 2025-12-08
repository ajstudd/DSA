#include <iostream>
#include <string>

using namespace std;

int main()
{
    string st;
    cin >> st;
    int length = st.length();
    if (length < 7)
    {
        cout << "NO" << endl;
        return 0;
    }

    int matchCount = 1;
    char candidate = st[0];
    int index = 1;

    while (index < length)
    {
        if (st[index] == candidate)
        {
            ++matchCount;
            if (matchCount >= 7)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
        else
        {
            candidate = st[index];
            matchCount = 1;
        }
        index++;
    }

    cout << "NO" << endl;
    return 0;
}