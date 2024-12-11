Press **Ctrl + K** then **V** to show preview or **Ctrl+Shift+V** for direct preview
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
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // Minimum price seen so far
        int maxProfit = 0;      // Maximum profit calculated

        for (int price : prices) {
            // Update the minimum price
            if (price < minPrice) {
                minPrice = price;
            }

            // Calculate the profit if sold today and update maxProfit
            int profit = price - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }

        return maxProfit;
    }
};
```

---

### Explanation:

1. **Tracking Minimum Price**:

   - Use a variable `minPrice` to store the smallest price encountered so far.
   - Update it as you iterate through the `prices` array.

2. **Calculate Profit**:

   - For each price in the array, calculate the profit as `price - minPrice`.
   - Update `maxProfit` if the calculated profit is greater than the current `maxProfit`.

3. **Time Complexity**:

   - The loop runs once through the `prices` array, making the time complexity \(O(n)\).

4. **Space Complexity**:
   - The solution uses only two additional variables, making the space complexity \(O(1)\).

---

### Example Walkthrough:

Input:

```cpp
prices = [7, 1, 5, 3, 6, 4]
```

Execution:

- **Initialization**: `minPrice = INT_MAX`, `maxProfit = 0`
- Day 1: `price = 7`, `minPrice = 7`, `profit = 0`, `maxProfit = 0`
- Day 2: `price = 1`, `minPrice = 1`, `profit = 0`, `maxProfit = 0`
- Day 3: `price = 5`, `minPrice = 1`, `profit = 4`, `maxProfit = 4`
- Day 4: `price = 3`, `minPrice = 1`, `profit = 2`, `maxProfit = 4`
- Day 5: `price = 6`, `minPrice = 1`, `profit = 5`, `maxProfit = 5`
- Day 6: `price = 4`, `minPrice = 1`, `profit = 3`, `maxProfit = 5`

Output:

```cpp
return 5;  // Maximum profit
```

---

This approach is efficient and avoids the time limit error, making it suitable for competitive programming and large inputs.

`INT_MAX` is a constant in C++ defined in the `<climits>` header file (or `<limits.h>` in older code). It represents the **maximum value that an integer (`int`) can hold** on the platform the code is running on.

### Key Points About `INT_MAX`:

- It's used as an initial "impossible" large value when searching for minimums in algorithms.
- Its value depends on the size of an integer on the platform.
  - Typically, for a 32-bit integer, `INT_MAX` is \(2^{31} - 1 = 2147483647\).

### Code Example:

```cpp
#include <climits> // Required for INT_MAX

int main() {
    int maxValue = INT_MAX;
    std::cout << "The maximum value of int is: " << maxValue << std::endl;
    return 0;
}
```

### Output:

```
The maximum value of int is: 2147483647
```

---

### Why Use `INT_MAX` in Your Code?

In the provided code:

```cpp
int minPrice = INT_MAX;  // Minimum price seen so far
```

- `minPrice` is initialized to `INT_MAX` to ensure that any actual stock price encountered in the array will be smaller, allowing the algorithm to correctly find the minimum price.
- As the loop runs, `minPrice` is updated with smaller prices, ensuring the algorithm works correctly.

Without this initialization, `minPrice` would default to an undefined value, which could lead to incorrect behavior.
