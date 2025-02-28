#include <iostream>
using namespace std;

int prodOfDigs(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return abs(n % 10) * prodOfDigs(n / 10);
}

int main()
{
    int n;
    cin >> n;
    int result = prodOfDigs(n);
    if (n == 0 && result == 1)
    {
        result = 0;
    }
    cout << "Product of digits: " << result;
    return 0;
}
