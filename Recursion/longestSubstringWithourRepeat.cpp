#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> lastSeen;
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < s.length(); end++)
    {

        char currentChar = s[end];
        if (lastSeen.count(currentChar) && lastSeen[currentChar] >= start)
        {
            start = lastSeen[currentChar] + 1;
        }

        lastSeen[currentChar] = end;
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main()
{
    string s = "abcabcbb";
    cout << "Length of Longest Substring Without Repeating Characters: "
         << lengthOfLongestSubstring(s) << endl;
    return 0;
}
