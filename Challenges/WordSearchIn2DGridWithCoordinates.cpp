#include <iostream>
#include <vector>

using namespace std;

bool validCheck(int x, int y, int m, int n)
{
    return x >= 0 && x < m && y >= 0 && y < n;
}

vector<int> dirX = {-1, 1, 0, 0, -1, -1, 1, 1};
vector<int> dirY = {0, 0, -1, 1, -1, 1, -1, 1};

bool wordSearch(string &word, int index, vector<vector<char>> &grid,
                int x, int y, int m, int n,
                vector<vector<int>> &visited,
                vector<pair<int, int>> &path)
{
    if (!validCheck(x, y, m, n))
        return false;

    if (grid[x][y] != word[index])
        return false;

    if (visited[x][y])
        return false;

    path.push_back({x, y});

    if (index == word.length() - 1)
        return true;

    visited[x][y] = 1;

    for (int i = 0; i < 8; i++)
    {
        if (wordSearch(word, index + 1, grid,
                       x + dirX[i], y + dirY[i],
                       m, n, visited, path))
        {
            visited[x][y] = 0;
            return true;
        }
    }

    visited[x][y] = 0;

    path.pop_back();
    return false;
}

int main()
{
    int m, n;
    cin >> m >> n;

    string word;
    cin >> word;

    vector<vector<char>> grid(m, vector<char>(n));
    vector<vector<int>> visited(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vector<pair<int, int>> path;
            if (wordSearch(word, 0, grid, i, j, m, n, visited, path))
            {
                cout << "Word Found\n";
                cout << "Coordinates:\n";

                for (auto &p : path)
                {
                    cout << "(" << p.first << ", " << p.second << ")\n";
                }

                return 0;
            }
        }
    }

    cout << "Word Not Found";
    return 0;
}
