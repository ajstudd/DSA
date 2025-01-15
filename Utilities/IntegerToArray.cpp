#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    // Convert an integer to an array of its digits
    int num = 12345;
    vector<int> digits;

    int temp = num;
    while (temp > 0)
    {
        digits.insert(digits.begin(), temp % 10); // Extract last digit
        temp /= 10;                               // Remove last digit
    }

    // Print the array of digits
    cout << "Array of digits: ";
    for (int digit : digits)
    {
        cout << digit << " ";
    }
    cout << endl;

    // Convert the array of digits back to the original number
    int reconstructedNum = 0;
    for (int digit : digits)
    {
        reconstructedNum = reconstructedNum * 10 + digit; // Reconstruct number
    }

    cout << "Reconstructed number: " << reconstructedNum << endl;

    return 0;
}
