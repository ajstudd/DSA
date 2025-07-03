#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int tcases;
    cin >> tcases;
    while (tcases--)
    {
        int n;
        cin >> n;
        vector<int> items(n);
        for (int i = 0; i < n; i++)
        {
            cin >> items[i];
        }
        int maxWindow = 0, currentWindow = 0;
        for (int i = 0; i < n; i++)
        {
            if (items[i] == 1)
            {
                currentWindow = 0;
            }
            else
            {
                currentWindow++;
            }
            maxWindow = max(maxWindow, currentWindow);
        }
        cout << maxWindow << endl;
    }
    return 0;
}
