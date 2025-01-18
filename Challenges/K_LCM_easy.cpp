#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t; // Number of test cases

    while (t--)
    {
        long long n;
        int k;
        cin >> n >> k;
        if (n % 2 == 1)
        {
            cout << 1 << " " << n / 2 << " " << n / 2 << "\n";
        }
        else if ((n / 2) % 2 == 1)
        {
            cout << n / 2 - 1 << " " << n / 2 - 1 << " " << 2 << "\n";
        }
        else
        {
            cout << n / 2 << " " << n / 4 << " " << n / 4 << "\n";
        }
    }
}