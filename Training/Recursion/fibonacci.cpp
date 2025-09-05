#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int fib = fibonacci(n - 1) + fibonacci(n - 2);
    return fib;
}

int main()
{
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}

/*
Worst Case Time Complexity: O(2^n)
This naive recursive approach recalculates the same Fibonacci numbers multiple times.
For fibonacci(n), it makes fibonacci(n-1) + fibonacci(n-2) calls, creating a binary tree of recursion.
Each call spawns two more calls, leading to exponential growth: approximately 2^n function calls.
This is highly inefficient for large n; dynamic programming reduces this to O(n).
*/