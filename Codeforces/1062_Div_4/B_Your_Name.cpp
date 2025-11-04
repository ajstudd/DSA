#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string line;
        cin >> line;
        unordered_set<int> chars;
        for (int i = 0; i < n; i++)
        {
            chars.insert(line[i]);
        }
        for (int i = n + 1; i < n + n; i++)
        {
            auto itr = chars.find(line[i]);
            if (itr == chars.end())
            {
                cout << "NO" << endl;
                break;
            }
        }
        cout << "YES" << endl;
    }
    return 0;
}