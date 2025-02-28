// You are given an integer n. On each step, you may subtract one of the digits from the number.
// How many steps are required to make the number equal to 0?
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

int maxPagePurchased(int index, vector<vector<int>> &dp, int amount, vector<int> bookPrices, vector<int> pages)
{
    for (int i =)
}
int main()
{

    int amount, n;
    cin >> n >> amount;
    vector<int> bookPrices(n);
    vector<int> pages(n);
    vector<vector<int>> dp(n, vector<int>(amount, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> bookPrices[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    cout << maxPagePurchased(0, dp, amount, bookPrices, pages);
    return 0;
}
