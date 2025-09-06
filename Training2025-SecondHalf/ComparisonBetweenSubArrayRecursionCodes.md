The **first option is significantly better** from a software design and flexibility standpoint, even though both have the same time complexity.

The main reasons are its **excellent separation of concerns** and its **avoidance of global variables**.

---

### Side-by-Side Comparison

| Feature             | Code 1 (Two Functions)                                                                                                                                           | Code 2 (Single Function)                                                                                                                        | Winner     |
| :------------------ | :--------------------------------------------------------------------------------------------------------------------------------------------------------------- | :---------------------------------------------------------------------------------------------------------------------------------------------- | :--------- |
| **Software Design** | **Excellent.** Avoids global variables by passing data as parameters. Cleanly separates logic into distinct functions.                                           | **Poor.** Relies on a global variable `arr`, which is bad practice and can lead to bugs in larger programs.                                     | **Code 1** |
| **Flexibility**     | **High.** It _generates_ the data into a `vector`. You can then decide to print it, count it, filter it, or do anything else with it later.                      | **Low.** The generation logic is tied directly to printing. If you wanted to _count_ the subarrays instead, you'd have to rewrite the function. | **Code 1** |
| **Readability**     | **High.** The function names `generateAllSubarrays` and `generateSubarraysFromStart` clearly state their purpose, making the code's intent easy to follow.       | **Medium.** The logic within the single `generate` function is more condensed and can be harder to trace mentally.                              | **Code 1** |
| **Time Complexity** | **$O(N^3)$**. The two recursive functions act like two loops, and the `for` loop inside `generateSubarraysFromStart` to build the subarray acts as a third loop. | **$O(N^3)$**. The recursive calls act like two loops, and the `for` loop inside `printSubarray` acts as a third loop.                           | **Tie**    |

---

### The O(N²) Optimal Recursive Solution

While your first solution has a better design, both are suboptimal in performance ($O(N^3)$). As we discussed previously, this problem can be solved in $O(N^2)$.

Here is how you would write the **best of both worlds**: a clean, recursive solution with optimal $O(N^2)$ performance. It uses the principles of Code 1 (good design) but improves the efficiency.

```cpp
#include <iostream>
#include <vector>

void generateSubarraysFromStart(int start_index, int end_index,
                                std::vector<int>& current_subarray, // Pass by reference
                                const std::vector<int>& arr,
                                std::vector<std::vector<int>>& result) {
    // Base Case: Inner loop finishes
    if (end_index >= arr.size()) {
        return;
    }

    // Add the current element to build the subarray incrementally
    current_subarray.push_back(arr[end_index]);
    result.push_back(current_subarray); // Save this version

    // Recurse for the next element (like j++)
    generateSubarraysFromStart(start_index, end_index + 1, current_subarray, arr, result);
}

void generateAllSubarrays(int start_index, const std::vector<int>& arr, std::vector<std::vector<int>>& result) {
    // Base Case: Outer loop finishes
    if (start_index >= arr.size()) {
        return;
    }

    // For each starting point, create a new empty vector to build upon
    std::vector<int> current_subarray;
    generateSubarraysFromStart(start_index, start_index, current_subarray, arr, result);

    // Recurse for the next starting point (like i++)
    generateAllSubarrays(start_index + 1, arr, result);
}

int main() {
    std::vector<int> arr = {1, 2, 4};
    std::vector<std::vector<int>> result;
    generateAllSubarrays(0, arr, result);

    // Print the result
    for (const auto& sub : result) {
        std::cout << "[ ";
        for (int item : sub) {
            std::cout << item << " ";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}
```

This version eliminates the innermost `for` loop by passing the `current_subarray` by reference and building it one element at a time, achieving the optimal **$O(N^2)$** complexity.
