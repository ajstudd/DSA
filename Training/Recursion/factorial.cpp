#include <iostream>
using namespace std;
int facto(int n)
{
    if (n <= 0)
    {
        return 1;
    }
    return n * facto(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << facto(n);
    return 0;
}

/*
Worst Case Time Complexity: O(n)
The recursive function makes exactly n recursive calls: facto(n) → facto(n-1) → ... → facto(1) → facto(0).
Each call performs constant time operations (multiplication and comparison), so total time is proportional to n.
The recursion depth is also n, making the space complexity O(n) due to the call stack.
*/