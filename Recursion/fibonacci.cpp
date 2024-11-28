#include <iostream>
using namespace std;

int fibo(int num)
{
    if (num <= 1)
    {
        return num;
    }
    return fibo(num - 1) + fibo(num - 2);
}

int main()
{
    int l = 5;
    for (int i = 0; i <= l; ++i)
    {
        cout << fibo(i) << ", ";
    }

    return 0;
}
