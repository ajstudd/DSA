#include <iostream>
using namespace std;

void printdata(int val, int limit)
{
    if (val > limit)
    {
        return;
    }
    cout << val;
    printdata(val + 1, limit);
}

int main()
{
    // objective initial to N
    int initial = 0;
    int N = 50;
    printdata(initial, N);
    return 0;
}
