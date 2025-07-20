#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false; // 0 and 1 are not prime

    for (int i = 2; i * i <= n; i++)
    { // Check till sqrt(n)
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPrime(num))
        cout << num << " is a prime number." << endl;
    else
        cout << num << " is not a prime number." << endl;

    return 0;
}
