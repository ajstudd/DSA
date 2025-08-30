#include <iostream>
using namespace std;

void printFibonacci(int n, int a = 0, int b = 1)
{
    if (n == 0)
        return;                      // stop when no terms left
    cout << a << " ";                // print current term
    printFibonacci(n - 1, b, a + b); // recursive call with next pair
}

int main()
{
    cout << "Fibonacci till n=5:" << endl;
    printFibonacci(6); // prints first 6 terms
    cout << endl;
    return 0;
}
