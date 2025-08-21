#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        map<char, int> chars;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                char ch;
                cin >> ch;
                if (ch != '?')
                {
                    chars[ch]++;
                }
            }
        }
        for (auto &ch : chars)
        {
            if (ch.second < 3)
            {
                cout << ch.first;
            }
        }
        cout << endl;
    }
    return 0;
}

// can be solved using XOR as well
//  find the row which has question mark, suppose {B, ? , C}
// and XOR it with {'A','B','C'}