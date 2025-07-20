#include <bits/stdc++.h>
using namespace std;

int findMaxRegexMatch(string sourceString, string pattern)
{
    int n = sourceString.length();
    int m = pattern.length();

    int wildcardPos = -1;
    for (int i = 0; i < m; i++)
    {
        if (pattern[i] == '*')
        {
            wildcardPos = i;
            break;
        }
    }

    string prefix = pattern.substr(0, wildcardPos);
    string suffix = pattern.substr(wildcardPos + 1);

    int prefixLen = prefix.length();
    int suffixLen = suffix.length();
    int maxLen = -1;
    if (prefixLen == 0 && suffixLen == 0)
    {
        return n > 0 ? n : -1;
    }

    for (int i = 0; i <= n - prefixLen; i++)
    {
        bool prefixMatch = true;
        for (int j = 0; j < prefixLen; j++)
        {
            if (sourceString[i + j] != prefix[j])
            {
                prefixMatch = false;
                break;
            }
        }

        if (!prefixMatch)
            continue;

        for (int k = i + prefixLen; k <= n - suffixLen; k++)
        {
            bool suffixMatch = true;
            for (int j = 0; j < suffixLen; j++)
            {
                if (sourceString[k + j] != suffix[j])
                {
                    suffixMatch = false;
                    break;
                }
            }

            if (suffixMatch)
            {
                int totalLen = (k + suffixLen) - i;
                maxLen = max(maxLen, totalLen);
            }
        }
    }

    return maxLen;
}

int main()
{
    // Test cases
    string sourceString1 = "hackerrank";
    string pattern1 = "ack*r";
    // Expected: "ackerr" -> length 6
    cout << "Test 1: " << findMaxRegexMatch(sourceString1, pattern1) << endl;

    string sourceString2 = "programming";
    string pattern2 = "r*in";
    // Expected: "rogrammin" -> length 9
    cout << "Test 2: " << findMaxRegexMatch(sourceString2, pattern2) << endl;

    string sourceString3 = "debug";
    string pattern3 = "ug*eb";
    // Expected: -1 (no match)
    cout << "Test 3: " << findMaxRegexMatch(sourceString3, pattern3) << endl;

    string sourceString4 = "apple";
    string pattern4 = "*"; // Wildcard only
    // Expected: 5
    cout << "Test 4: " << findMaxRegexMatch(sourceString4, pattern4) << endl;

    string sourceString5 = "";
    string pattern5 = "*"; // Wildcard only, empty source
    // Expected: -1
    cout << "Test 5: " << findMaxRegexMatch(sourceString5, pattern5) << endl;

    string sourceString6 = "banana";
    string pattern6 = "b*a";
    // Expected: "banana" -> 6
    cout << "Test 6: " << findMaxRegexMatch(sourceString6, pattern6) << endl;

    string sourceString7 = "test";
    string pattern7 = "t*t";
    // Expected: "test" -> 4
    cout << "Test 7: " << findMaxRegexMatch(sourceString7, pattern7) << endl;

    string sourceString8 = "aaaaa";
    string pattern8 = "a*a";
    // Expected: "aaaaa" -> 5
    cout << "Test 8: " << findMaxRegexMatch(sourceString8, pattern8) << endl;

    string sourceString9 = "xyz";
    string pattern9 = "x*z";
    // Expected: "xyz" -> 3
    cout << "Test 9: " << findMaxRegexMatch(sourceString9, pattern9) << endl;

    string sourceString10 = "abcdef";
    string pattern10 = "a*g";
    // Expected: -1
    cout << "Test 10: " << findMaxRegexMatch(sourceString10, pattern10) << endl;

    string sourceString11 = "ab";
    string pattern11 = "a*c";
    // Expected: -1
    cout << "Test 11: " << findMaxRegexMatch(sourceString11, pattern11) << endl;

    return 0;
}