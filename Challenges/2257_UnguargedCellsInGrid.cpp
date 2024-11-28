// You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.

// A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.

// Return the number of unoccupied cells that are not guarded.

// Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
// Output: 7
// Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
// There are a total of 7 unguarded cells, so we return 7.

// NOTE: My Way of solving the question , got into time limit exceeded

class Solution
{
public:
    void gridInspector(vector<vector<int>> &grid, int &ugCellCount, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Mark all cells visible by guards
        for (auto &guard : guards)
        {
            int row = guard[0];
            int col = guard[1];

            // Mark north direction
            for (int i = row - 1; i >= 0 && grid[i][col] != 2; i--)
            {
                if (grid[i][col] == 0)
                {
                    grid[i][col] = 1; // Mark as guarded
                    ugCellCount--;
                }
            }

            // Mark south direction
            for (int i = row + 1; i < m && grid[i][col] != 2; i++)
            {
                if (grid[i][col] == 0)
                {
                    grid[i][col] = 1; // Mark as guarded
                    ugCellCount--;
                }
            }

            // Mark west direction
            for (int j = col - 1; j >= 0 && grid[row][j] != 2; j--)
            {
                if (grid[row][j] == 0)
                {
                    grid[row][j] = 1; // Mark as guarded
                    ugCellCount--;
                }
            }

            // Mark east direction
            for (int j = col + 1; j < n && grid[row][j] != 2; j++)
            {
                if (grid[row][j] == 0)
                {
                    grid[row][j] = 1; // Mark as guarded
                    ugCellCount--;
                }
            }
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        // Initialize the grid with 0 (unguarded cells)
        vector<vector<int>> grid(m, vector<int>(n, 0));
        int ugCells = m * n;

        // Place guards (mark as 1)
        for (auto &guard : guards)
        {
            grid[guard[0]][guard[1]] = 1;
            ugCells--; // Guard cells are not unguarded
        }

        // Place walls (mark as 2)
        for (auto &wall : walls)
        {
            grid[wall[0]][wall[1]] = 2;
            ugCells--; // Wall cells are not unguarded
        }

        // Mark guarded cells and count unguarded
        gridInspector(grid, ugCells, guards, walls);

        return ugCells;
    }
};

// INFO: Optimised code with gpt
class Solution
{
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        // Directions for north, south, west, east
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Initialize the grid:
        // 0 = unguarded cell
        // 1 = guarded cell
        // 2 = guard position
        // 3 = wall position
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // Count of unguarded cells (initially all cells are unguarded)
        int ugCells = m * n;

        // Mark guards and walls on the grid
        for (auto &guard : guards)
        {
            grid[guard[0]][guard[1]] = 2; // Guard's position
            ugCells--;                    // Guard cells are not unguarded
        }
        for (auto &wall : walls)
        {
            grid[wall[0]][wall[1]] = 3; // Wall's position
            ugCells--;                  // Wall cells are not unguarded
        }

        // Propagate guard visibility in all four cardinal directions
        for (auto &guard : guards)
        {
            int row = guard[0]; // Row position of the guard
            int col = guard[1]; // Column position of the guard

            // Check each direction: north, south, west, and east
            for (auto &dir : directions)
            {
                int r = row + dir.first;  // Next row in the current direction
                int c = col + dir.second; // Next column in the current direction

                // Move in the current direction until a wall or guard is encountered
                while (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] != 3 && grid[r][c] != 2)
                {
                    // If the cell is unguarded, mark it as guarded
                    if (grid[r][c] == 0)
                    {
                        grid[r][c] = 1; // Mark cell as guarded
                        ugCells--;      // Reduce count of unguarded cells
                    }
                    // Continue moving in the current direction
                    r += dir.first;
                    c += dir.second;
                }
            }
        }

        // Return the count of unguarded cells
        return ugCells;
    }
};
