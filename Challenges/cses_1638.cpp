// You are given an integer n. On each step, you may subtract one of the digits from the number.
// How many steps are required to make the number equal to 0?
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

void numberOfPaths(int &count, vector<vector<char>> grid, int x, int y, int n, vector<vector<int>> &dp)
{
    if (y >= n || x >= n || grid[x][y] == '*')
    {
        return;
    }
    if (y == n - 1 && x == n - 1)
    {
        count = count + 1;
        return;
    }
    if (dp[x][y] != -1)
    {
        count = dp[x][y];
        return;
    }
    numberOfPaths(count, grid, x, y + 1, n, dp);
    numberOfPaths(count, grid, x + 1, y, n, dp);
    dp[x][y] = count;
}

int main()
{
    int n;
    int modulo = 1000000007;
    cin >> n;
    int count = 0;
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    numberOfPaths(count, grid, 0, 0, n, dp);
    cout << count % modulo;
    return 0;
}
