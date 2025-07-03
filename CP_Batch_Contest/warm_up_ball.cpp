#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int tcases;
    cin >> tcases;
    for (int i = 0; i < tcases; i++)
    {
        int n;
        cin >> n;
        // we are having combination of 1 to n-1 for a
        // and n-1 to 1 for b
        // total combinations n-1
        vector<pair<int, int>> ordered_pairs;
        for (int j = 1; j < n; j++)
        {
            for (int k = n - 1; k >= 1; k--)
            {
                if (j == n - k)
                {
                    ordered_pairs.push_back({j, k});
                }
            }
        }
        for (int i = 0; i < ordered_pairs.size(); i++)
        {
            cout << ordered_pairs[i].first << "," << ordered_pairs[i].second << endl;
        }
    }
    return 0;
}