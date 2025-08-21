#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

// Summation of i = 1 to N(Summation of j = 1 to M(max(a(x)(y)) - min(a(x)(y)))) where 1 <= x <= i, 1 <= y <= j
// This means that we consider n⋅m subtables with the upper left corner in (1,1) and the bottom right corner in (i,j) (1≤i≤n), (1≤j≤m), for each such subtable calculate the difference of the maximum and minimum elements in it, then sum up all these differences. You should maximize the resulting sum.

// Help her find the maximal possible value, you don't need to reconstruct the table itself.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int totalSize = n * m;
        vector<int> values(totalSize);
        for (int i = 0; i < totalSize; i++)
        {
            cin >> values[i];
        }
        sort(values.begin(), values.end());

        // Calculate contribution of each position
        vector<pair<int, pair<int, int>>> contributions;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int contribution = i * j - (n - i + 1) * (m - j + 1);
                contributions.push_back({contribution, {i, j}});
            }
        }
        sort(contributions.begin(), contributions.end());

        vector<vector<int>> matrix(n + 1, vector<int>(m + 1));
        for (int k = 0; k < totalSize; k++)
        {
            int i = contributions[k].second.first;
            int j = contributions[k].second.second;
            matrix[i][j] = values[k];
        }
        int diff = 0;
        int maxSum = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int maxElem = INT_MIN;
                int minElem = INT_MAX;
                for (int x = 1; x <= i; x++)
                {
                    for (int y = 1; y <= j; y++)
                    {
                        maxElem = max(maxElem, matrix[x][y]);
                        minElem = min(minElem, matrix[x][y]);
                    }
                }
                diff = maxElem - minElem;
                maxSum += diff;
            }
        }
        cout << maxSum << endl;
    }
    return 0;
}

// Test: #1, time: 30 ms., memory: 40 KB, exit code: 0, checker exit code: 1, verdict: WRONG_ANSWER
// Input
// 5
// 2 2
// 1 3 1 4
// 2 2
// -1 -1 -1 -1
// 2 3
// 7 8 9 -3 10 8
// 3 2
// 4 8 -3 0 -7 1
// 4 3
// -32030 59554 16854 -85927 68060 -64460 -79547 90932 85063 82703 -12001 38762
// Output
// 5
// 0
// 39
// 48
// 1475002
// Answer
// 9
// 0
// 64
// 71
// 1933711
// Checker Log
// wrong answer 1st numbers differ - expected: '9', found: '5'