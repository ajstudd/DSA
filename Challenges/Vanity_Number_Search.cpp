using namespace std;
#include <bits/stdc++.h>

string convertWord(string w)
{
    unordered_map<char, char> mp = {
        {'A', '2'}, {'B', '2'}, {'C', '2'}, {'D', '3'}, {'E', '3'}, {'F', '3'}, {'G', '4'}, {'H', '4'}, {'I', '4'}, {'J', '5'}, {'K', '5'}, {'L', '5'}, {'M', '6'}, {'N', '6'}, {'O', '6'}, {'P', '7'}, {'Q', '7'}, {'R', '7'}, {'S', '7'}, {'T', '8'}, {'U', '8'}, {'V', '8'}, {'W', '9'}, {'X', '9'}, {'Y', '9'}, {'Z', '9'}};

    string res = "";
    for (char c : w)
    {
        char upperC = toupper(c);
        res.push_back(mp[upperC]);
    }
    return res;
}

vector<string> vanitySearch(vector<string> keywords, vector<string> phones)
{
    vector<string> patterns;
    for (string w : keywords)
    {
        patterns.push_back(convertWord(w));
    }

    vector<string> ans;
    for (string ph : phones)
    {
        for (string p : patterns)
        {
            // npos means not found
            if (ph.find(p) != string::npos)
            {
                ans.push_back(ph);
                break;
            }
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<string> keywords = {"JUN", "AHM"};
    vector<string> phones = {"9876543210", "5862349000", "5555861234"};
    vector<string> result = vanitySearch(keywords, phones);
    for (string item : result)
    {
        cout << item << endl;
    }
    return 0;
}