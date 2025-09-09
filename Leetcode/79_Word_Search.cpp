#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool wordTraceDFS(int i, int j, int index, vector<vector<char>> &board,
                      string &word, vector<pair<int, int>> &moves)
    {
        if (index >= word.length())
        {
            return true;
        }
        int current_row = i;
        int current_col = j;
        char temp = board[i][j];
        board[i][j] = '#';
        for (int k = 0; k < moves.size(); k++)
        {
            int next_row = current_row + moves[k].first;
            int next_col = current_col + moves[k].second;
            if (next_row >= 0 && next_col >= 0 && next_row < board.size() &&
                next_col < board[0].size() &&
                board[next_row][next_col] == word[index])
            /*
            INFO: I wanted to add one more condition here -> board[next_row][next_col] != '#'
            But I guess that is not necessary because we are already marking/modifying the cells with # above
            and checking if the board[next_row][next_col] == word[index]
            so if a cell is matching the char that means it is not explored yet.
            */
            {
                if (wordTraceDFS(next_row, next_col, index + 1, board, word,
                                 moves))
                {
                    board[i][j] = temp; // optional to restore the original board
                    return true;
                }
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<pair<int, int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    if (wordTraceDFS(i, j, 1, board, word, moves))
                        return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    vector<vector<char>> board1 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word1 = "ABCCED";
    cout << "Test 1 - Board: " << endl;
    for (const auto &row : board1)
    {
        for (char c : row)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << "Word: " << word1 << endl;
    cout << "Result: " << (solution.exist(board1, word1) ? "Found" : "Not Found") << endl;
    cout << endl;

    // Test case 2
    vector<vector<char>> board2 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word2 = "SEE";
    cout << "Test 2 - Board: " << endl;
    for (const auto &row : board2)
    {
        for (char c : row)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << "Word: " << word2 << endl;
    cout << "Result: " << (solution.exist(board2, word2) ? "Found" : "Not Found") << endl;
    cout << endl;

    // Test case 3
    vector<vector<char>> board3 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word3 = "ABCB";
    cout << "Test 3 - Board: " << endl;
    for (const auto &row : board3)
    {
        for (char c : row)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << "Word: " << word3 << endl;
    cout << "Result: " << (solution.exist(board3, word3) ? "Found" : "Not Found") << endl;

    return 0;
}