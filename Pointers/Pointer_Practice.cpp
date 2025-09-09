#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a = 10;
    int *p = &a;
    int *dang;
    cout << "a: " << a << endl;
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;
    cout << "dang: " << dang << endl;
    cout << "*dang: " << *dang << endl;
    return 0;
}