#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Convert a number to a string
    int num = 42;
    string numStr = to_string(num);
    cout << "String representation: " << numStr << endl;

    // Convert the string back to a number
    int numBack = stoi(numStr); // For integers
    cout << "Converted back to number: " << numBack << endl;

    // Example for floating-point numbers
    double doubleNum = 3.14159;
    string doubleStr = to_string(doubleNum);
    cout << "String representation (double): " << doubleStr << endl;

    double doubleBack = stod(doubleStr); // For doubles
    cout << "Converted back to double: " << doubleBack << endl;

    return 0;
}
