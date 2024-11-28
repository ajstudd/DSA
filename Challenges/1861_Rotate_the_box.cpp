class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int rowSize = box.size();    // Number of rows in the original box
        int colSize = box[0].size(); // Number of columns in the original box

        // Step 1: Simulate gravity for each row
        for (int i = 0; i < rowSize; ++i)
        {
            int emptyPos = colSize - 1; // Initialize the empty position to the rightmost column
            for (int j = colSize - 1; j >= 0; --j)
            { // Traverse the row from right to left
                if (box[i][j] == '*')
                {
                    // If an obstacle ('*') is found, reset the empty position to just before the obstacle
                    emptyPos = j - 1;
                }
                else if (box[i][j] == '#')
                {
                    // If a stone ('#') is found, move it to the nearest empty position
                    swap(box[i][j], box[i][emptyPos]);
                    // Update the empty position to the next available spot (to the left)
                    --emptyPos;
                }
                // If the cell is empty ('.'), do nothing
            }
        }

        // Step 2: Rotate the matrix 90 degrees clockwise
        // The rotated matrix will have 'colSize' rows and 'rowSize' columns
        vector<vector<char>> rotated(colSize, vector<char>(rowSize, '.')); // Initialize with empty cells
        for (int i = 0; i < rowSize; ++i)
        { // Traverse the original rows
            for (int j = 0; j < colSize; ++j)
            { // Traverse the original columns
                // Map (i, j) in the original matrix to (j, rowSize - i - 1) in the rotated matrix
                rotated[j][rowSize - i - 1] = box[i][j];
            }
        }

        // Step 3: Return the rotated matrix
        return rotated;
    }
};
