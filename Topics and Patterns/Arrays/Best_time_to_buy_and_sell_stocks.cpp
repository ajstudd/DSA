// Problem 3: Best Time to Buy and Sell Stock

#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the max profit
int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices)
    {
        if (price < minPrice)
        {
            minPrice = price; // update minimum price
        }
        else if (price - minPrice > maxProfit)
        {
            maxProfit = price - minPrice; // update max profit
        }
    }
    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << maxProfit(prices) << endl;
    return 0;
}
