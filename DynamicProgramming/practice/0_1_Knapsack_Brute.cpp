#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<pair<int, int>> &priceAndWeight, int item, int netWeight, int capacity)
{
    if (item >= priceAndWeight.size())
        return 0;

    int profitIfPick = 0;
    if (netWeight + priceAndWeight[item].second <= capacity)
    {
        profitIfPick = priceAndWeight[item].first + maxProfit(priceAndWeight, item + 1, netWeight + priceAndWeight[item].second, capacity);
    }

    int profitIfNotPick = maxProfit(priceAndWeight, item + 1, netWeight, capacity);

    return max(profitIfPick, profitIfNotPick);
}

int main()
{
    int capacity, numOfItems;
    cin >> capacity >> numOfItems;

    vector<int> itemWeight(numOfItems);
    vector<int> itemProfit(numOfItems);
    vector<pair<int, int>> priceAndWeight(numOfItems);

    for (int i = 0; i < numOfItems; i++)
        cin >> itemWeight[i];

    for (int i = 0; i < numOfItems; i++)
        cin >> itemProfit[i];

    for (int i = 0; i < numOfItems; i++)
        priceAndWeight[i] = {itemProfit[i], itemWeight[i]};

    cout << maxProfit(priceAndWeight, 0, 0, capacity);

    return 0;
}
