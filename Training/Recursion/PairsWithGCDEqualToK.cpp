#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int GCDFinder(int a, int b)
{
    if (b == 0)
        return a;
    return GCDFinder(b, a % b);
}

int main()
{
    int start, end, target;
    cin >> start >> end >> target;

    vector<pair<int, int>> pairs;

    for (int i = start; i <= end; ++i)
    {
        for (int j = i; j <= end; ++j)
        {
            // checking if both numbers are divisible by target
            if (i % target == 0 && j % target == 0)
            {
                int b1 = i / target;
                int b2 = j / target;
                if (GCDFinder(b1, b2) == 1)
                {
                    pairs.push_back({i, j});
                }
            }
        }
    }

    for (auto &p : pairs)
    {
        cout << p.first << ", " << p.second << endl;
    }

    return 0;
}
