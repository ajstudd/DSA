// Ugly Numbers: numbers whose only prime factors are 2, 3 or 5.
// This program reads an integer n and prints the n-th ugly number.
// Sample Input:
// 10
// Sample Output:
// 12

#include <iostream>
using namespace std;

// Returns true if num is an ugly number
bool isUgly(int num)
{
    if (num <= 0)
        return false;
    // new way to create and iterate array simultaneously
    for (int p : {2, 3, 5})
    {
        while (num % p == 0)
            num /= p;
    }
    return num == 1;
}

// Naive method: iterate numbers and count how many are ugly until we reach n
int nthUglyNumber(int n)
{
    int count = 0, num = 0;
    while (count < n)
    {
        num++;
        if (isUgly(num))
            count++;
    }
    return num;
}

int main()
{
    int n;
    if (!(cin >> n))
        return 0;
    cout << nthUglyNumber(n) << '\n';
    return 0;
}
