#include <iostream>
#include <climits> // For INT_MIN
using namespace std;
int maxSubarraySum(int arr[], int n)
{
    int maxSum = arr[0], currentSum = arr[0];

    for (int i = 1; i < n; i++)
    {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Maximum Subarray Sum: " << maxSubarraySum(arr, n) << std::endl;

    return 0;
}

/*
Worst Case Time Complexity: O(n)
This implements Kadane's algorithm which processes each array element exactly once.
In each iteration, we perform constant time operations: two max comparisons and assignments.
The algorithm scans through the array linearly, making it optimal for the maximum subarray problem.
This is much better than the O(n³) brute force approach that checks all possible subarrays.
*/
