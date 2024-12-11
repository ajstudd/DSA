// INFO: My initial code with some wrong mapping but logic makes sense
//  Observations:
//  - prices array , list of prices , any order but as per the date, so it means I cannot buy lower amount in future date and sell in higher in previous date
//  Requiremnets :
//  choose single day
//  buy on different day
//  sell on different day
//  max profit
//  return 0 if anot applicable
//  How max profit
//  - sell high
//  - buy low
//  relation :
//  pick ith price , and check if the future date has higher amount, choose the highest amount,
//  also store it.
//  need an array to store
//  need an optimal solution, cannot afford to create array of length 10^5

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> maxProfitMap(100001, 0);
        int size = prices.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size; j++)
            {
                if (prices[i] < prices[j] && prices[maxProfitMap[i]] < prices[j])
                {
                    maxProfitMap[prices[i]] = j;
                }
            }
        }
        int maxProfitDate;
        int lastProfit = 0;
        for (int i = 0; i < size; i++)
        {
            if ((prices[maxProfitMap[prices[i]]] - prices[i]) > lastProfit)
            {
                lastProfit = prices[maxProfitMap[prices[i]]] - prices[i];
                maxProfitDate = maxProfitMap[prices[i]];
            }
        }
        return maxProfitDate;
    }
};

// LABEL: Same code with fixed mappings
// INFO: Passing just the base cases, giving time limit exceed
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> maxProfitMap(prices.size(), 0);
        int size = prices.size();

        // Initialize mapping of the best day to sell for each day
        for (int i = 0; i < size; i++)
        {
            maxProfitMap[i] = i; // Initialize to itself
            for (int j = i + 1; j < size; j++)
            { // Start from i+1
                if (prices[j] > prices[maxProfitMap[i]])
                {
                    maxProfitMap[i] = j;
                }
            }
        }

        // Calculate the maximum profit
        int maxProfit = 0;
        for (int i = 0; i < size; i++)
        {
            int profit = prices[maxProfitMap[i]] - prices[i];
            if (profit > maxProfit)
            {
                maxProfit = profit;
            }
        }

        return maxProfit;
    }
};

INFO: Optimised code 
The given code has a **time complexity of \(O(n^2)\)** due to the nested loop that calculates the best day to sell for each day. This is inefficient for large input sizes, as it will result in a **time limit exceeded (TLE)** error.

### Optimized Approach
To optimize the solution, we can use a **single pass approach** with a **linear time complexity (\(O(n)\))**. The idea is simple:
1. Keep track of the **minimum price seen so far**.
2. At each step, calculate the profit if the stock is sold on the current day.
3. Update the maximum profit if the calculated profit is greater than the current maximum.

This eliminates the need for the `maxProfitMap` entirely.

---

### Optimized Code:
```cpp
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX; // Minimum price seen so far
        int maxProfit = 0;      // Maximum profit calculated

        for (int price : prices)
        {
            // Update the minimum price
            if (price < minPrice)
            {
                minPrice = price;
            }

            // Calculate the profit if sold today and update maxProfit
            int profit = price - minPrice;
            if (profit > maxProfit)
            {
                maxProfit = profit;
            }
        }

        return maxProfit;
    }
};
```

        -- -

        ## #Explanation : 1. *
        *Tracking Minimum Price ** : -Use a variable `minPrice` to store the smallest price encountered so far.-
    Update it as you iterate through the `prices` array.

        2. *
        *Calculate Profit ** : -For each price in the array,
    calculate the profit as `price - minPrice`.- Update `maxProfit` if the calculated profit is greater than the current `maxProfit`.

                                                     3. *
                                                     *Time Complexity ** : -The loop runs once through the `prices` array,
    making the time complexity \(O(n)\).

        4. *
        *Space Complexity ** : -The solution uses only two additional variables,
    making the space complexity \(O(1)\).

    -- -

    ## #Example Walkthrough : Input :
```cpp
    prices = [ 7, 1, 5, 3, 6, 4 ]
```

    Execution : -**Initialization ** : `minPrice = INT_MAX`, `maxProfit = 0` - Day 1 : `price = 7`, `minPrice = 7`, `profit = 0`, `maxProfit = 0` - Day 2 : `price = 1`, `minPrice = 1`, `profit = 0`, `maxProfit = 0` - Day 3 : `price = 5`, `minPrice = 1`, `profit = 4`, `maxProfit = 4` - Day 4 : `price = 3`, `minPrice = 1`, `profit = 2`, `maxProfit = 4` - Day 5 : `price = 6`, `minPrice = 1`, `profit = 5`, `maxProfit = 5` - Day 6 : `price = 4`, `minPrice = 1`, `profit = 3`, `maxProfit = 5`

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           Output :
```cpp
    return 5; // Maximum profit
```

---

This approach is efficient and avoids the time limit error, making it suitable for competitive programming and large inputs.