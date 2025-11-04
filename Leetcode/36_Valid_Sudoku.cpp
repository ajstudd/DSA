#include <vector>
#include <unordered_set>

// Assuming 'using namespace std;' is active, based on your preferences
// for C++ and STL in competitive programming.

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        // --- 1. Check Rows ---
        // Iterate through each row (i)
        for (int i = 0; i < 9; i++)
        {
            // Create a new set for *each* row
            unordered_set<char> seen;
            for (int j = 0; j < 9; j++)
            {
                char val = board[i][j];

                // FIX 2: Ignore empty cells
                if (val == '.')
                {
                    continue;
                }

                // FIX 1: Check if the *value* is already in the set
                if (seen.count(val))
                {
                    return false; // Found a duplicate in this row
                }
                seen.insert(val); // Add the new value to the set
            }
        }

        // --- 2. Check Columns ---
        // Iterate through each column (j)
        for (int j = 0; j < 9; j++)
        {
            // Create a new set for *each* column
            unordered_set<char> seen;
            for (int i = 0; i < 9; i++)
            {
                char val = board[i][j];

                // FIX 2: Ignore empty cells
                if (val == '.')
                {
                    continue;
                }

                // FIX 1: Check if the *value* is already in the set
                if (seen.count(val))
                {
                    return false; // Found a duplicate in this column
                }
                seen.insert(val);
            }
        }

        // --- 3. Check 3x3 Grids ---
        // FIX 3: Correctly iterate through all 9 boxes
        // (boxRow, boxCol) iterates 3x3 times, selecting one of the 9 boxes
        for (int boxRow = 0; boxRow < 3; boxRow++)
        {
            for (int boxCol = 0; boxCol < 3; boxCol++)
            {
                // Create a new set for *each* 3x3 box
                unordered_set<char> seen;

                // (i, j) iterate 3x3 times *inside* the selected box
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {

                        // Calculate the actual row and column on the board
                        int row = boxRow * 3 + i;
                        int col = boxCol * 3 + j;
                        char val = board[row][col];

                        // FIX 2: Ignore empty cells
                        if (val == '.')
                        {
                            continue;
                        }

                        // FIX 1: Check if the *value* is already in the set
                        if (seen.count(val))
                        {
                            return false; // Found a duplicate in this 3x3 box
                        }
                        seen.insert(val);
                    }
                }
            }
        }

        // If all three checks pass without returning false, the board is valid
        return true;
    }
};