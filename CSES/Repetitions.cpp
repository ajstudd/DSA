#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string st;
    cin >> st;
    int maxRepetition = 1;
    char last = st[0];
    for (int i = 1; i < st.length(); i++)
    {
        int count = 1;
        while (st[i] == last)
        {
            i++;
            count++;
        }
        maxRepetition = max(count, maxRepetition);
        last = st[i];
    }
    cout << maxRepetition;
    return 0;
}