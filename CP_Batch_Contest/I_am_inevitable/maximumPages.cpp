#include <iostream>
#include <vector>
using namespace std;

void maxPages(vector<int> &bookPages, vector<int> &bookPrices, vector<int> &dp, int price, int size)
{
    if (dp[price] != -1)
    {
        return;
    }
    for (int i = 0; i < bookPrices.size(); i++)
    {
        dp[bookPrices[i]] = max(maxPages(bookPages));
    }
}

int main()
{
    int books, budget;
    vector<int> bookPrices(books);
    vector<int> bookPages(books);
    vector<int> dp(1001, -1);
    cin >> books >> budget;
    for (int i = 0; i < books; i++)
    {
        cin >> bookPrices[i];
    }
    for (int i = 0; i < books; i++)
    {
        cin >> bookPages[i];
    }
    return 0;
}