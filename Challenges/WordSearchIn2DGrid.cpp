#include <iostream>
#include <vector>

using namespace std;

bool validCheck(int x, int y, int m, int n)
{
    return x >= 0 && x < m && y >= 0 && y < n;
}

// Up (x − 1, y)
// Down (x + 1, y)
// Left (x, y − 1)
// Right (x, y + 1)
// Up Left (x − 1, y − 1)
// Up Right (x − 1, y + 1)
// Down Left (x + 1, y − 1)
// Down Right (x + 1, y + 1)
vector<int> dirX = {-1, 1, 0, 0, -1, -1, 1, 1};
vector<int> dirY = {0, 0, -1, 1, -1, 1, -1, 1};

bool wordSearch(string &word, int index, vector<vector<char>> &grid, int x, int y, int m, int n, vector<vector<int>> &visited)
{
    if (!validCheck(x, y, m, n))
    {
        return false;
    }
    if (grid[x][y] != word[index])
    {
        return false;
    }
    if (visited[x][y])
    {
        return false;
    }
    if (index == word.length() - 1)
    {
        return true;
    }
    visited[x][y] = 1;

    for (int i = 0; i < 8; i++)
    {
        if (wordSearch(word, index + 1, grid, x + dirX[i], y + dirY[i], m, n, visited))
        {
            visited[x][y] = 0;
            return true;
        }
    }
    visited[x][y] = 0;
    return false;
};

int main()
{
    int m, n;
    cin >> m >> n;
    string word;
    cin >> word;
    vector<vector<char>> grid(m, vector<char>(n));
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (wordSearch(word, 0, grid, i, j, m, n, visited))
            {
                cout << "Word Found";
                return 0;
            }
        }
    }
    return 0;
}