#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

void IslandMarkerByBFS(int x, int y, vector<vector<int>> &grid, vector<pair<int, int>> &moves)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    grid[x][y] = 0;
    while (!q.empty())
    {
        auto &node = q.front();
        int current_col = node.second;
        int current_row = node.first;
        q.pop();
        for (int i = 0; i < moves.size(); i++)
        {
            int next_row = current_row + moves[i].first;
            int next_col = current_col + moves[i].second;
            if (next_row < grid.size() && next_col < grid[0].size() && next_row >= 0 && next_col >= 0 && grid[next_row][next_col] == 1)
            {
                q.push({next_row, next_col});
                grid[next_row][next_col] = 0;
            }
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int numOfIslands = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                numOfIslands++;
                IslandMarkerByBFS(i, j, grid, moves);
            }
        }
    }
    cout << "number of islands: " << numOfIslands;
    return 0;
}