#include <iostream>
#include <vector>
using namespace std;

// Function to generate Pascal's Triangle
vector<vector<int>> generatePascalTriangle(int numRows)
{
    vector<vector<int>> triangle;

    for (int i = 0; i < numRows; ++i)
    {
        vector<int> row(i + 1, 1); // initialize row with 1s

        for (int j = 1; j < i; ++j)
        {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]; // fill inner elements
        }

        triangle.push_back(row);
    }

    return triangle;
}

// Helper function to print Pascal's Triangle
void printTriangle(const vector<vector<int>> &triangle)
{
    for (const auto &row : triangle)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main()
{
    int numRows = 5;
    vector<vector<int>> result = generatePascalTriangle(numRows);

    cout << "Pascal's Triangle up to " << numRows << " rows:\n";
    printTriangle(result);

    return 0;
}
