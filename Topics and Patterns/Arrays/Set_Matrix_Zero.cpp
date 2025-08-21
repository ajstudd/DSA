#include <iostream>
#include <vector>
using namespace std;

// Function to set matrix rows and columns to zero in-place
void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    bool row0 = false, col0 = false;

    // Step 1: Check if first row and column need to be zero
    for (int i = 0; i < m; i++)
        if (matrix[i][0] == 0)
            col0 = true;

    for (int j = 0; j < n; j++)
        if (matrix[0][j] == 0)
            row0 = true;

    // Step 2: Use first row and column as markers
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Step 3: Set matrix cells based on markers
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 4: Handle first row and column separately
    if (col0)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
        }
    }

    if (row0)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[0][j] = 0;
        }
    }
}

// Helper function to print the matrix
void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    setZeroes(matrix);

    cout << "\nMatrix After setZeroes:\n";
    printMatrix(matrix);

    return 0;
}
