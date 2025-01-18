int findFirstOccurrence(int arr[], int n, int target)
{
    int low = 0, high = n - 1, result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            result = mid;   // Record potential answer
            high = mid - 1; // Search in left half
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}

// suppose arr = [1,2,2,2,2,7,9]
// n = 7
// low = 0
// high = 6
// result = -1
// --- instance 1 ---
// mid = 3
// arr[3] == target [2]
// result = 3
// high = 2
// --- instance 2 ---
// mid = 1
// arr[1] == target [2]
// result = 1
// high = 0
// --- instance 3 ---
// mid = 0
// arr[0] < target [2]
// low = 1
// --- instance 4 ---
// low !<= high
// return result 1;
