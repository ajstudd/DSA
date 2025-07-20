#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;

string minimalGridPath(int x, int y, vector<vector<char>> &grid, int &n, string st)
{
    if (x >= n || y >= n)
    {
        return st;
    }
    char right = y + 1 < n ? grid[x][y + 1] : 'Z' + 1;
    char bottom = x + 1 < n ? grid[x + 1][y] : 'Z' + 1;
    // nah we need all options, change the logic
    st += right > bottom ? grid[x + 1][y] : grid[x][y + 1];
    return min(minimalGridPath(x + 1, y, grid, n, st),
               minimalGridPath(x, y + 1, grid, n, st));
}

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << minimalGridPath(0, 0, grid, n, "");
    return 0;
}
