#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int size, queries;
    cin >> size >> queries;
    vector<vector<int>> matrix(size, vector<int>(size));
    vector<vector<int>> prefixSum2D(size, vector<int>(size));
    char input;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> input;
            matrix[i][j] = (input == '*') ? 1 : 0;
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int top = (i > 0) ? prefixSum2D[i - 1][j] : 0;
            int left = (j > 0) ? prefixSum2D[i][j - 1] : 0;
            int topleft = (i > 0 && j > 0) ? prefixSum2D[i - 1][j - 1] : 0;
            prefixSum2D[i][j] = matrix[i][j] + top + left - topleft;
        }
    }
    for (int i = 0; i < queries; i++)
    {
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--, x1--, y2--, x2--; // converting the input as per my own 2D Prefix Sum matrix, which is 0 based not 1 based, no extra row and column
        int topRight = (y1 > 0) ? prefixSum2D[y1 - 1][x2] : 0;
        int bottomLeft = (x1 > 0) ? prefixSum2D[y2][x1 - 1] : 0;
        int diagonal = (x1 > 0 && y1 > 0) ? prefixSum2D[y1 - 1][x1 - 1] : 0;
        int numberOfOnesInRange = prefixSum2D[y2][x2] - topRight - bottomLeft + diagonal;
        cout << numberOfOnesInRange << endl;
    }
    return 0;
}
