#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        int length, numOfCharCanRemove;
        cin >> length >> numOfCharCanRemove;
        map<char, int> charCount;
        string st;
        cin >> st;

        for (char c : st)
        {
            charCount[c]++;
        }

        int oddCount = 0;
        for (auto &pair : charCount)
        {
            if (pair.second % 2 == 1)
            {
                oddCount++;
            }
        }

        int remainingLength = length - numOfCharCanRemove;
        if (remainingLength % 2 == 0)
        {
            if (oddCount <= numOfCharCanRemove)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            if (oddCount <= numOfCharCanRemove + 1)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}