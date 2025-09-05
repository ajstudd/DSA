#include <iostream>
using namespace std;

int main()
{
    cout << (~5);

    return 0;
}

/*
Worst Case Time Complexity: O(1)
Bitwise NOT operation (~) is a single CPU instruction that flips all bits.
The operation works on fixed-size integers (typically 32 or 64 bits) in constant time.
No loops or recursive calls are involved, making it a constant-time operation.
Output operation is also O(1) for printing a single integer value.
*/
