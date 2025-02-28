// #include <iostream>
// using namespace std;

// int reverseANum(int n)
// {
//     if (n < 0)
//     {
//         return 0;
//     }

//     return ((n % 10) * 10) + reverseANum(n / 10);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     cout << reverseANum(n);
//     return 0;
// }
#include <iostream>
using namespace std;

int reverseHelper(int n, int rev)
{
    if (n == 0)
        return rev;

    return reverseHelper(n / 10, rev * 10 + (n % 10));
}

int reverseANum(int n)
{
    if (n < 0)
        return -reverseHelper(-n, 0);
    return reverseHelper(n, 0);
}

int main()
{
    int n;
    cin >> n;
    cout << reverseANum(n) << endl;
    return 0;
}
