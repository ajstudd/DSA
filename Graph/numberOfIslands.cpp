#include <iostream>
#include <vector>
using namespace std;
// solve using dfs
void numOfIslands(vector<vector<int>> &area, vector<vector<bool>> &visited, int x, int y, int rsize, int csize)
{
    if (x < 0 || y < 0 || x >= rsize || y >= csize || visited[x][y] || area[x][y] == 0)
        return;
    // order of conditions is also necessary,
    // like we need to check overflow of x and y before checking if visited[x][y] or area[x][y]

    visited[x][y] = true;
    // up = x-1 , y
    // down = x+1 , y
    // left = x, y-1;
    // right = x, y+1
    numOfIslands(area, visited, x - 1, y, rsize, csize);
    numOfIslands(area, visited, x + 1, y, rsize, csize);
    numOfIslands(area, visited, x, y - 1, rsize, csize);
    numOfIslands(area, visited, x, y + 1, rsize, csize);
}

int main()
{
    vector<vector<int>> area =
        {
            {1, 0, 1, 1, 1},
            {0, 0, 0, 0, 1},
            {1, 0, 1, 1, 0},
            {0, 0, 0, 0, 0},
        };
    int rowSize, colSize;
    rowSize = area.size();
    colSize = area[0].size();
    vector<vector<bool>> visited(rowSize, vector<bool>(colSize, false));
    int count = 0;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            if (area[i][j] == 1 && !visited[i][j])
            {
                numOfIslands(area, visited, i, j, rowSize, colSize);
                count++;
            }
        }
    }
    cout << "number of islands: " << count;
    return 0;
}
