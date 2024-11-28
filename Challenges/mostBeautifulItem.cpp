// You are given a 2D integer array items where items[i] = [pricei, beautyi] denotes the price and beauty of an item respectively.

// You are also given a 0-indexed integer array queries. For each queries[j], you want to determine the maximum beauty of an item whose price is less than or equal to queries[j]. If no such item exists, then the answer to this query is 0.

// Return an array answer of the same length as queries where answer[j] is the answer to the jth query.

// Example 1:

// Input: items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
// Output: [2,4,5,5,6,6]
// Explanation:
// - For queries[0]=1, [1,2] is the only item which has price <= 1. Hence, the answer for this query is 2.
// - For queries[1]=2, the items which can be considered are [1,2] and [2,4].
//   The maximum beauty among them is 4.
// - For queries[2]=3 and queries[3]=4, the items which can be considered are [1,2], [3,2], [2,4], and [3,5].
//   The maximum beauty among them is 5.
// - For queries[4]=5 and queries[5]=6, all items can be considered.
//   Hence, the answer for them is the maximum beauty of all items, i.e., 6.
// Example 2:

// Input: items = [[1,2],[1,2],[1,3],[1,4]], queries = [1]
// Output: [4]
// Explanation:
// The price of every item is equal to 1, so we choose the item with the maximum beauty 4.
// Note that multiple items can have the same price and/or beauty.
// Example 3:

// Input: items = [[10,1000]], queries = [5]
// Output: [0]
// Explanation:
// No item has a price less than or equal to 5, so no item can be chosen.
// Hence, the answer to the query is 0.

// Constraints:

// 1 <= items.length, queries.length <= 10^5
// items[i].length == 2
// 1 <= pricei, beautyi, queries[j] <= 10^9

// INFO: My Initial Unoptimised code :
class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        vector<int> output;
        int itemSize = items.size();
        int qSize = queries.size();
        int maxBeauty = 0;
        for (int i = 0; i < qSize; i++)
        {
            maxBeauty = 0;
            for (int j = 0; j < itemSize; j++)
            {
                if (items[j][0] <= queries[i] && maxBeauty < items[j][1])
                {
                    maxBeauty = items[j][1];
                }
            }
            output.push_back(maxBeauty);
        }
        return output;
    }
};

// INFO: Optimised code with gpt using binary search and sorting the array

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        // Step 1: Sort items by price
        sort(items.begin(), items.end());

        // Step 2: Precompute maximum beauty up to each item's price
        int n = items.size();
        vector<int> maxBeauty(n);
        maxBeauty[0] = items[0][1];

        for (int i = 1; i < n; ++i)
        {
            maxBeauty[i] = max(maxBeauty[i - 1], items[i][1]);
        }

        // Step 3: Process each query
        vector<int> output;
        for (int q : queries)
        {
            // Use binary search to find the max price within the query's budget
            auto it = upper_bound(items.begin(), items.end(), vector<int>{q, INT_MAX}) - items.begin() - 1;

            // If no valid item is found, add 0 to output
            if (it >= 0)
            {
                output.push_back(maxBeauty[it]);
            }
            else
            {
                output.push_back(0);
            }
        }

        return output;
    }
};

// In C++, the auto keyword is used to automatically deduce the type of a variable based on its initializer.
// This is particularly useful for complex types, such as iterators,
// or when the exact type might be verbose or cumbersome to write.

// example:
//  auto it = upper_bound(items.begin(), items.end(), vector<int>{q, INT_MAX}) - items.begin() - 1;

// example:
// vector<int> numbers = {1, 2, 3, 4, 5};

// // Instead of writing vector<int>::iterator, we can use auto.
// for (auto it = numbers.begin(); it != numbers.end(); ++it) {
//     cout << *it << " ";
// }
