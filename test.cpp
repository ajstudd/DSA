#include <iostream>
using namespace std;

int main()
{
    // INFO:
    //  The value 4678080 is the memory address where "junaid" is stored.
    //  Your casting (int)"junaid" converts this address from a pointer to an integer, resulting in the numeric value you see.
    //  However, avoid such casts in real-world code as they may lead to undefined behavior on some systems.
    string s = "abc";
    // cout << (int)s; will throw error
    cout << (int)"junaid";
    return 0;
}