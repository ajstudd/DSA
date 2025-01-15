#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

// LABEL: Unoptimised but working Code
class Solution
{
public:
    bool startAndEndWithVowel(string s)
    {
        char start = s[0];
        char end = s[s.length() - 1];
        start = tolower(start);
        end = tolower(end);

        if ((start == 'a' || start == 'e' || start == 'i' || start == 'o' ||
             start == 'u') &&
            (end == 'a' || end == 'e' || end == 'i' || end == 'o' ||
             end == 'u'))
        {
            return true;
        }
        else
        {
            return false;
        }
    };
    vector<int> vowelStrings(vector<string> &words,
                             vector<vector<int>> &queries)
    {
        vector<int> result;
        int count = 0;
        for (int i = 0; i < queries.size(); i++)
        {
            count = 0;
            for (int j = queries[i][0]; j <= queries[i][1]; j++)
            {
                if (startAndEndWithVowel(words[j]))
                {
                    count++;
                }
            }
            result.push_back(count);
        }

        return result;
    }
};

// REMARK: My own optimised attempt, still time limit exceeded
class Solution
{
public:
    bool startAndEndWithVowel(string s)
    {
        char start = s[0];
        char end = s[s.length() - 1];
        start = tolower(start);
        end = tolower(end);

        if ((start == 'a' || start == 'e' || start == 'i' || start == 'o' ||
             start == 'u') &&
            (end == 'a' || end == 'e' || end == 'i' || end == 'o' ||
             end == 'u'))
        {
            return true;
        }
        else
        {
            return false;
        }
    };

    // new strategy: precalculate the words which end with vowel and maintain an array
    //  same index, just keep 0 if the word end with vowel and 1 if it does not.
    //  and we will add this as per the range.
    //  can even use prefix sum algorithm
    vector<int> vowelStrings(vector<string> &words,
                             vector<vector<int>> &queries)
    {
        vector<int> result;
        vector<int> precal;
        int count = 0;
        for (int i = 0; i < words.size(); i++)
        {
            if (startAndEndWithVowel(words[i]))
            {
                precal.push_back(1);
            }
            else
            {
                precal.push_back(0);
            }
        }
        for (int i = 0; i < queries.size(); i++)
        {
            count = 0;
            for (int j = queries[i][0]; j <= queries[i][1]; j++)
            {
                count += precal[j];
            }
            result.push_back(count);
        }
        return result;
    }
};

// INFO: Optimised code
class Solution
{
    // my own logic but with prefix sum part by chat gpt.

    // new initial strategy was: precalculate the words which end with vowel and maintain an array
    //  same index, just keep 0 if the word end with vowel and 1 if it does not.
    //  and we will add this as per the range.
    //  can even use prefix sum algorithm
public:
    bool startAndEndWithVowel(string s)
    {
        char start = tolower(s[0]);
        char end = tolower(s[s.length() - 1]);

        return ((start == 'a' || start == 'e' || start == 'i' || start == 'o' || start == 'u') &&
                (end == 'a' || end == 'e' || end == 'i' || end == 'o' || end == 'u'));
    }

    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        int n = words.size();
        vector<int> precal(n, 0);
        vector<int> prefixSum(n + 1, 0); // Prefix sum array with an extra 0 at the start

        // Build precal array
        for (int i = 0; i < n; ++i)
        {
            precal[i] = startAndEndWithVowel(words[i]) ? 1 : 0;
        }
        // precal: [1,0,1,1,1]

        // Build prefix sum array
        for (int i = 1; i <= n; ++i)
        {
            prefixSum[i] = prefixSum[i - 1] + precal[i - 1];
        }
        // prefixSum : [0,1,1,2,3,4]

        // Answer queries
        vector<int> result;
        for (const auto &query : queries)
        {
            int l = query[0];
            int r = query[1];
            result.push_back(prefixSum[r + 1] - prefixSum[l]);
        }

        return result;
    }
};
