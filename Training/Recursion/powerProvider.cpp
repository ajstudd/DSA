// #include <iostream>
// using namespace std;

// int power(int a, int b)
// {
//     if (b == 0)
//     {
//         return 1;
//     }
//     if (b % 2 == 0)
//     {
//         return power(a, b / 2) * power(a, b / 2);
//     }
//     else
//     {
//         return a * power(a, b - 1);
//     }
// }

// int main()
// {
//     int a, b;
//     cin >> a >> b;
//     cout << power(a, b);
//     return 0;
// }

// ISSUE:
//  What's the Issue Here? ⚠️
//  Your code is making two recursive calls for even powers:

// cpp
// Copy
// Edit
// power(a, b / 2) * power(a, b / 2);
// You're calling the same subproblem twice — which is increasing the time complexity to O(2^log(b)).

// CHANGED:
//  int halfPower = power(a, b / 2);
//  return halfPower * halfPower;

#include <iostream>
using namespace std;

int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b % 2 == 0)
    {
        int halfPower = power(a, b / 2);
        return halfPower * halfPower;
    }
    else
    {
        return a * power(a, b - 1);
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << power(a, b);
    return 0;
}