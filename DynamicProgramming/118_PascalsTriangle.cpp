// INFO: Starting phase
//  Observation
//  given:
//  number of rows : n
//  Obviously starts with 1
//  every row has that many elements
//  Approach :
//  if i is row
//  j is the element of that row
//  j will start with 0 and go till j < i
//  each j is sum of [i-1][j-1]+[i-1][j]
//  condition check if [i-1][j-1] even exists.
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<int> previousRow;
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++)
        {
            previousRow[0] = 1;
            for (int j = 0; j < i; j++)
            {
                int sum = previousRow[j - 1] ? previousRow[j - 1] + previousRow[j] : previousRow[j];
                result[i].push_back(sum);
                previousRow.push_back(sum);
            }
        }
        return result;
    }
};

// REMARK: Needed just a minor fix
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> currentRow(i + 1, 1); // Initialize current row with 1's
            for (int j = 1; j < i; j++)
            {                                                            // Start from j = 1 to i-1
                currentRow[j] = result[i - 1][j - 1] + result[i - 1][j]; // Calculate the sum of previous row elements
            }
            result.push_back(currentRow); // Add the current row to the result
        }
        return result;
    }
};

// LABEL: Optimised code
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        vector<int> previousRow;

        for (int i = 0; i < numRows; i++)
        {
            vector<int> currentRow(i + 1, 1); // Initialize current row with 1's

            for (int j = 1; j < i; j++)
            {
                currentRow[j] = previousRow[j - 1] + previousRow[j]; // Calculate the sum of previous row elements
            }

            result.push_back(currentRow); // Add the current row to the result
            previousRow = currentRow;     // Update previousRow for the next iteration
        }

        return result;
    }
};