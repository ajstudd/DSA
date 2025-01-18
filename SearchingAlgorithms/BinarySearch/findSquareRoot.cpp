int squareRoot(int x)
{
    int low = 0, high = x, result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid * mid == x)
            return mid; // Perfect square
        else if (mid * mid < x)
        {
            result = mid;  // Store potential answer
            low = mid + 1; // Search right half
        }
        else
        {
            high = mid - 1; // Search left half
        }
    }
    return result;
}

// this is easy to understand no need example
