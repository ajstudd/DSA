#include <iostream>
using namespace std;

void printdata(int val)
{
    if (val < 1)
    {
        return; // base case to stop recursion when val > 5
    }

    cout << val << " "; // print the current value
    printdata(val - 1); // recursive call with incremented value
}

int main()
{
    printdata(5); // start from 0
    return 0;
}
