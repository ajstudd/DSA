// You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.

// Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.

// Example 1:

// Input: s = "aabaaaacaabc", k = 2
// Output: 8
// Explanation:
// Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
// Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
// A total of 3 + 5 = 8 minutes is needed.
// It can be proven that 8 is the minimum number of minutes needed.
// Example 2:

// Input: s = "a", k = 1
// Output: -1
// Explanation: It is not possible to take one 'b' or 'c' so return -1.

// Constraints:

// 1 <= s.length <= 10^5
// s consists of only the letters 'a', 'b', and 'c'.
// 0 <= k <= s.length

#include <iostream>
using namespace std;

class Solution
{
public:
    int takeCharacters(string s, int k)
    {
        // Step 1: Get the length of the string 's'
        int n = s.size();

        // Step 2: Count the total occurrences of 'a', 'b', and 'c' in the entire string.
        // These values represent the total available characters of each type in the string.
        int totalA = 0, totalB = 0, totalC = 0;
        for (char ch : s)
        {
            if (ch == 'a')
                totalA++; // Count the number of 'a's in the string
            else if (ch == 'b')
                totalB++; // Count the number of 'b's in the string
            else if (ch == 'c')
                totalC++; // Count the number of 'c's in the string
        }

        // Step 3: If the string doesn't have enough characters of 'a', 'b', or 'c', return -1.
        // This ensures that it is not possible to take k occurrences of each character.
        if (totalA < k || totalB < k || totalC < k)
        {
            return -1; // If there's not enough of any character, it's impossible to achieve the goal
        }

        // Step 4: Initialize sliding window variables.
        int l = 0, r = 0; // 'l' is the left pointer, 'r' is the right pointer of the window
        int ans = n;      // Set the initial answer to the largest possible value (the whole string length)

        // Step 5: Initialize counters for the characters in the sliding window
        int a = 0, b = 0, c = 0; // These will count occurrences of 'a', 'b', and 'c' in the current window

        // Step 6: Slide the right pointer 'r' across the string
        while (r < n)
        {
            // Include the character at the 'r' pointer in the current window
            if (s[r] == 'a')
                a++; // If the character at 'r' is 'a', increase the 'a' counter
            if (s[r] == 'b')
                b++; // If the character at 'r' is 'b', increase the 'b' counter
            if (s[r] == 'c')
                c++; // If the character at 'r' is 'c', increase the 'c' counter
            r++;     // Move the right pointer to expand the window

            // Step 7: Shrink the window from the left if we have more of a character than we need
            // We can shrink the window if the current window contains too many of any character
            while (a > totalA - k || b > totalB - k || c > totalC - k)
            {
                // If the window has more 'a's than needed, reduce the count of 'a'
                if (s[l] == 'a')
                    a--;
                // If the window has more 'b's than needed, reduce the count of 'b'
                if (s[l] == 'b')
                    b--;
                // If the window has more 'c's than needed, reduce the count of 'c'
                if (s[l] == 'c')
                    c--;
                l++; // Move the left pointer to shrink the window
            }

            // Step 8: Update the answer with the minimum number of characters to take
            // The current window is from 'l' to 'r', so the number of characters to remove is:
            // n - (r - l), where (r - l) is the current window size
            ans = min(ans, n - (r - l)); // We want the smallest window size that meets the condition
        }

        // Step 9: Return the final answer, which is the minimum number of characters to remove
        return ans;
    }
};
