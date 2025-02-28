#include <iostream>

using namespace std;

// Function for AND operation
bool AND(bool a, bool b)
{
    return a & b;
}

// Function for OR operation
bool OR(bool a, bool b)
{
    return a | b;
}

// Function for NOT operation
bool NOT(bool a)
{
    return !a;
}

// Function for XOR operation
bool XOR(bool a, bool b)
{
    return a ^ b;
}

// Function for NAND operation
bool NAND(bool a, bool b)
{
    return !(a & b);
}

// Function for NOR operation
bool NOR(bool a, bool b)
{
    return !(a | b);
}

// Function for XNOR operation
bool XNOR(bool a, bool b)
{
    return !(a ^ b);
}

int main()
{
    bool a, b;

    // Taking input
    cout << "Enter two boolean values (0 or 1): ";
    cin >> a >> b;

    // Displaying results
    cout << "AND: " << AND(a, b) << endl;
    cout << "OR: " << OR(a, b) << endl;
    cout << "NOT A: " << NOT(a) << " | NOT B: " << NOT(b) << endl;
    cout << "XOR: " << XOR(a, b) << endl;
    cout << "NAND: " << NAND(a, b) << endl;
    cout << "NOR: " << NOR(a, b) << endl;
    cout << "XNOR: " << XNOR(a, b) << endl;

    return 0;
}
