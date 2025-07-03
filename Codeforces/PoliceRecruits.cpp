#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> events(n);
    int police = 0, crimes = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> events[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (events[i] == -1)
        {
            if (police > 0)
            {
                police -= 1;
            }
            else
            {
                crimes += 1;
            }
        }
        else
        {
            police += events[i];
        }
    }
    cout << crimes;
    return 0;
}