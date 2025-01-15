#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Convert string to character array
    string str = "Hello";
    const char *charArray = str.c_str(); // Get C-style character array
    cout << "Character array: " << charArray << endl;

    // Convert character array back to string
    string backToString = string(charArray);
    cout << "Converted back to string: " << backToString << endl;

    return 0;
}
