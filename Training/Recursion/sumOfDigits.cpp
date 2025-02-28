// #include <iostream>
// using namespace std;
// REMARK: This code is good but does not handle negative digits
// int sumOfDigs(int n)
// {
//     if (n <= 0)
//     {
//         return 0;
//     }
//     return (n % 10) + sumOfDigs(n / 10);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     cout << "sum of digits" << sumOfDigs(n);
//     return 0;
// }

// LABEL: NEW IMPROVISED CODE
#include <iostream>
using namespace std;

int sumOfDigs(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return abs(n % 10) + sumOfDigs(n / 10);
}

int main()
{
    int n;
    cin >> n;
    cout << "Sum of digits: " << sumOfDigs(n) << endl;
    return 0;
}
