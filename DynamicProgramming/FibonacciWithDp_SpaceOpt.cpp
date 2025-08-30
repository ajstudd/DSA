#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int a = 0, b = 1;

    cout << "Fibonacci till n=" << n << " :" << endl;
    cout << "fib(0) = " << a << endl;
    if (n >= 1)
        cout << "fib(1) = " << b << endl;

    for (int i = 2; i <= n; i++)
    {
        int c = a + b;
        cout << "fib(" << i << ") = " << c << endl;
        a = b;
        b = c;
    }

    return 0;
}
