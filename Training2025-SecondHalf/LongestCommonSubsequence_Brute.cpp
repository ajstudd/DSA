#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

void findSubsequences(int index, string &current, string &sentence, unordered_map<string, string> &result)
{
    if (index >= sentence.size())
    {
        result[current] = current;
        return;
    }
    current.push_back(sentence[index]);
    findSubsequences(index + 1, current, sentence, result);
    current.pop_back();
    findSubsequences(index + 1, current, sentence, result);
}

int main()
{
    string sentence = "hello";
    string sentence2 = "halloween";
    unordered_map<string, string> result;
    unordered_map<string, string> result2;
    string current = "";
    findSubsequences(0, current, sentence, result);
    current = "";
    findSubsequences(0, current, sentence2, result2);
    int longestCommonSub = 0;
    for (const auto &sub : result)
    {
        if (result2.find(sub.first) != result2.end())
        {
            longestCommonSub = max(longestCommonSub, (int)sub.first.length());
        }
    }
    cout << longestCommonSub;

    return 0;
}