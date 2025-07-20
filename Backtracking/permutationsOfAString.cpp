#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @brief Generates all permutations of a string using backtracking algorithm
 *
 * This function recursively generates all possible permutations of the input string
 * by swapping characters at different positions. It uses backtracking to explore
 * all possible arrangements and then backtracks by undoing the swap.
 *
 * @param s Reference to the string to permute (modified during recursion)
 * @param index Current position/index being processed in the recursion
 * @param perms Reference to vector that stores all generated permutations
 *
 * @note The function modifies the input string during execution but restores
 *       it to original state due to backtracking mechanism
 * @note Time complexity: O(n! * n) where n is the length of string
 * @note Space complexity: O(n) for recursion stack depth
 */
void permutations(string &s, int index, vector<string> &perms)
{
    if (index >= s.length())
    {
        perms.push_back(s);
        return;
    }
    for (int i = index; i < s.length(); i++)
    {
        swap(s[index], s[i]);
        permutations(s, index + 1, perms);
        swap(s[index], s[i]);
    }
}

int main()
{
    string s;
    cin >> s;
    vector<string> perms;
    permutations(s, 0, perms);
    for (int i = 0; i < perms.size(); i++)
    {
        cout << perms[i] << endl;
    }
    return 0;
}
