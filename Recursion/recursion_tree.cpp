#include <iostream>

using namespace std;

void func(int x)
{
    cout << x << endl;
    if (x >= 3)
        return;
    func(x + 1);
    func(x + 2);
}

int main()
{
    func(0);
    return 0;
}

// *Output :
// 0
// 1
// 2
// 3
// 4
// 3
// 2
// 3
// 4