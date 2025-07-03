#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> items(n);
        for (int i = 0; i < n; i++)
        {
            cin >> items[i];
        }
        int minimumMaxElement = items[0];
        for (int i = 1; i < n; i++)
        {
            minimumMaxElement = minimumMaxElement & items[i];
        }
        cout << minimumMaxElement << endl;
    }
    return 0;
}