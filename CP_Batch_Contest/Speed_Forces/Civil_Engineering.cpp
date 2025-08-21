#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
bool checkPerfectSquareExists(long long number)
{
    if (number == 0)
        return true;
    if (number < 0)
        return false;

    long long root = (long long)sqrt(number);

    if (root * root == number)
        return true;
    if ((root + 1) * (root + 1) == number)
        return true;

    return false;
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long total = 0;
        for (long long i = 0; i < n; i++)
        {
            long long number;
            cin >> number;
            total += number;
        }
        cout << (checkPerfectSquareExists(total) ? "YES" : "NO") << endl;
    }
    return 0;
}