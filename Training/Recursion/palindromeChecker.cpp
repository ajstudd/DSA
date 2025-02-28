// #include <iostream>
// #include <string>
// #include <cmath>
// using namespace std;
// int reverser(int n, int rev)
// {
//     if (n == 0)
//         return rev;

//     return reverser(n / 10, rev * 10 + (n % 10));
// }
// int countDigitsString(int n)
// {
//     return to_string(n).length();
// }

// int main()
// {
//     int n;
//     cin >> n;
//     int halfPoint = 0;
//     int size = countDigitsString(n);
//     halfPoint = (size / 2);
//     // REMARK: THERE WAS SOME ISSUE IN HANDLING THE ODD LENGTH NUMBER
//     //  Fix 🔥
//     //  If the number length is odd:
//     // Just divide by pow(10, (size / 2) + 1) instead of pow(10, size / 2)
//     int divisor = (size % 2 == 0) ? pow(10, halfPoint) : pow(10, halfPoint + 1);
//     int firstHalf = n / divisor;
//     int rev = reverser((n % divisor), 0);
//     cout << firstHalf << endl
//          << rev << endl;
//     if (rev == firstHalf)
//     {
//         cout << "Palindrome";
//     }
//     else
//     {
//         cout << "Not Palindrome";
//     }
//     return 0;
// }

// LABEL: Directly checking with last digit
#include <iostream>
#include <cmath>
using namespace std;

bool isPalindromeHelper(int n, int &temp)
{
    if (n == 0)
    {
        return true;
    }

    if (!isPalindromeHelper(n / 10, temp))
    {
        return false;
    }

    int lastDigit = temp % 10;
    temp = temp / 10;

    return (n % 10 == lastDigit);
}

bool isPalindrome(int n)
{
    int temp = n;
    return isPalindromeHelper(n, temp);
}

int main()
{
    int n;
    cin >> n;

    if (isPalindrome(n))
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }

    return 0;
}
