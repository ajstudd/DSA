// TODO: complete without gpt assistance
class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        // Hash map to count the frequency of each normalized pattern
        unordered_map<string, int> patternCount;
        int maxRows = 0; // To store the maximum number of rows that can be made identical

        // Iterate over each row in the matrix
        for (const auto &row : matrix)
        {
            string pattern, complement; // Strings to store the row's pattern and its complement

            // Normalize the row based on its first element
            for (int val : row)
            {
                // If the first element of the row is 0, keep the pattern as is
                // Otherwise, flip the pattern (treat the row as its complement)
                if (row[0] == 0)
                {
                    pattern += (val == 0 ? '0' : '1');
                    complement += (val == 0 ? '1' : '0');
                }
                else
                {
                    pattern += (val == 0 ? '1' : '0');
                    complement += (val == 0 ? '0' : '1');
                }
            }

            // Increment the count of the normalized pattern in the hash map
            patternCount[pattern]++;

            // Update the maximum number of rows with identical patterns
            maxRows = max(maxRows, patternCount[pattern]);
        }

        // Return the maximum number of rows that can be made identical
        return maxRows;
    }
};
