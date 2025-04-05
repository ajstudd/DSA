// #include <iostream>
// #include <vector>
// using namespace std;

// // LABEL: My Approach

// void spiralParser(int x, int y, int rows, int cols, vector<vector<int>> &matrice, vector<int> &parsedMat)
// {
//     if (cols == x && rows == y)
//     {
//         return;
//     }
//     int initialX = x;
//     int initialY = y;
//     while (y < cols)
//     {
//         parsedMat.push_back(matrice[x][y]);
//         y++;
//     }
//     while (x < rows)
//     {
//         parsedMat.push_back(matrice[x][y]);
//         x++;
//     }
//     while (y >= 0)
//     {
//         parsedMat.push_back(matrice[x][y]);
//         y--;
//     }
//     while (x > initialX)
//     {
//         parsedMat.push_back(matrice[x][y]);
//         x--;
//     }
//     spiralParser(x, y + 1, rows - 1, cols - 1, matrice, parsedMat);
// }

// int main()
// {
//     vector<vector<int>> matrice(6, vector<int>({1, 2, 3, 4, 5, 6}));
//     vector<int> parsedMat;
//     int rows = matrice.size();
//     int cols = matrice[0].size();
//     spiralParser(0, 0, rows, cols, matrice, parsedMat);
//     for (int i = 0; i < parsedMat.size(); i++)
//     {
//         cout << parsedMat[i] << ", ";
//     }
//     return 0;
// }

// LABEL: GPT Solution

#include <iostream>
#include <vector>
using namespace std;

void spiralParser(int top, int left, int bottom, int right, vector<vector<int>> &matrix, vector<int> &result)
{
    // Base case: if out of bounds
    if (top > bottom || left > right)
        return;

    // Top row (left to right)
    for (int i = left; i <= right; i++)
    {
        result.push_back(matrix[top][i]);
    }

    // Right column (top+1 to bottom)
    for (int i = top + 1; i <= bottom; i++)
    {
        result.push_back(matrix[i][right]);
    }

    // Bottom row (right-1 to left), only if top != bottom
    if (top != bottom)
    {
        for (int i = right - 1; i >= left; i--)
        {
            result.push_back(matrix[bottom][i]);
        }
    }

    // Left column (bottom-1 to top+1), only if left != right
    if (left != right)
    {
        for (int i = bottom - 1; i > top; i--)
        {
            result.push_back(matrix[i][left]);
        }
    }

    // Recursive call for the inner sub-matrix
    spiralParser(top + 1, left + 1, bottom - 1, right - 1, matrix, result);
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36}};

    vector<int> result;
    spiralParser(0, 0, matrix.size() - 1, matrix[0].size() - 1, matrix, result);

    for (int val : result)
    {
        cout << val << " ";
    }

    return 0;
}
