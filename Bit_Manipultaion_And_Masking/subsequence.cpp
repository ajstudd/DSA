#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a = {5, 7, 8, 9, 4, 3};
    vector<vector<int>> sub;
    int size = a.size();
    //(1<<n) basically means binary of n size whose 1st bit is on.
    // so it is 2^n

    for (int mask = 0; mask < (1 << size); mask++)
    {
        vector<int> series;
        for (int j = 0; j < size; j++)
        {
            // mask & (1<<j) checking if the jth bit of mask is 1
            if (mask & (1 << j))
                series.push_back(a[j]);
            ;
        }
        sub.push_back(series);
    }

    for (int i = 0; i < sub.size(); i++)
    {
        for (int j = 0; j < sub[i].size(); j++)
        {
            cout << sub[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}