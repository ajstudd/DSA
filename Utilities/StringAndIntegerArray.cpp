#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // String to character array and back
    string str = "HelloWorld";
    const char *charArray = str.c_str();
    cout << "Character array: " << charArray << endl;
    string backToString = string(charArray);
    cout << "Back to string: " << backToString << endl;

    // Integer to array of digits and back
    int num = 98765;
    vector<int> digits;

    int temp = num;
    while (temp > 0)
    {
        digits.insert(digits.begin(), temp % 10);
        temp /= 10;
    }

    cout << "Array of digits: ";
    for (int digit : digits)
    {
        cout << digit << " ";
    }
    cout << endl;

    int reconstructedNum = 0;
    for (int digit : digits)
    {
        reconstructedNum = reconstructedNum * 10 + digit;
    }
    cout << "Reconstructed number: " << reconstructedNum << endl;

    return 0;
}
