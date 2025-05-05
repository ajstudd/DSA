#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    string st = "autodesk";
    unordered_map<char, int> charcount;
    for (int i = 0; i < st.size(); i++)
    {
        charcount[st[i]]++;
    }
    for (const auto &item : charcount)
    {
        cout << item.first << " : " << item.second << endl;
    }
    return 0;
}