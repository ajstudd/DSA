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
        vector<pair<int, int>> ordered_pairs;

        for (int a = 1; a < n; ++a)
        {
            int b = n - a;
            if (b >= 1 && b < n)
            {
                ordered_pairs.emplace_back(a, b);
            }
        }

        cout << ordered_pairs.size() << endl;
    }
    return 0;
}
