#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<pair<int, int>> abc = {{1, 2}, {1, 5}, {6, 7}, {9, 1}, {4, 3}};
    sort(abc.begin(), abc.end(), [](auto &a, auto &b)
         { return a.second < b.second; });
    for (auto &item : abc)
    {
        cout << item.first << "=>" << item.second;
        cout << endl;
    }
    return 0;
}