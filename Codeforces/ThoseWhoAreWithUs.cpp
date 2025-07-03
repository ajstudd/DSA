#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void minimumPossibleMax(int m, int n, vector<vector<int>> &matrix)
{
    int max_element = 0;
    int freq_max_element = 0;
    vector<int> max_frq_row(m);
    vector<int> max_frq_col(n);
    for (int j = 0; j < m; j++)
    {
        for (int k = 0; k < n; k++)
        {
            max_element = max(matrix[j][k], max_element);
        }
    }
    for (int j = 0; j < m; j++)
    {
        for (int k = 0; k < n; k++)
        {
            if (matrix[j][k] == max_element)
            {
                freq_max_element += 1;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (matrix[i][j] == max_element)
            {
                max_frq_row[i]++;
                max_frq_col[j]++;
            }
        }
    }
    bool answer = false;
    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (max_frq_row[r] + max_frq_col[c] - (matrix[r][c] == max_element) == freq_max_element)
            {
                answer = true;
                // reason for (a[r][c]==max_element) is that to discard the count of overlapping element, in intesection of r and c
            }
        }
    }
    if (answer)
    {
        cout << max_element - 1 << endl;
    }
    else
    {
        cout << max_element << endl;
    }
};

int main()
{
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> matrix(m, vector<int>(n));
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> matrix[j][k];
            }
        }
        minimumPossibleMax(m, n, matrix);
    }
}