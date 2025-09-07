#include <iostream>
#include <string> // Required for std::string and its functions
using namespace std;

int main()
{
    // -------------------------------
    // 1. String Initialization
    // -------------------------------
    string str1 = "Hello";           // Direct initialization
    string str2("World");            // Constructor initialization
    string str3 = str1 + " " + str2; // Concatenation using '+'

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3 (concatenation): " << str3 << endl;

    // -------------------------------
    // 2. String Size & Length
    // -------------------------------
    cout << "Length of str3: " << str3.length() << endl; // length of string
    cout << "Size of str3: " << str3.size() << endl;     // size() same as length()

    // -------------------------------
    // 3. Accessing Characters
    // -------------------------------
    cout << "First char in str3: " << str3[0] << endl;                 // using operator[]
    cout << "Last char in str3: " << str3.at(str3.size() - 1) << endl; // using at()

    // -------------------------------
    // 4. Modifying Strings
    // -------------------------------
    str1.append(" Everyone"); // append() adds at the end
    cout << "After append: " << str1 << endl;

    str1.push_back('!'); // push_back() adds one char at end
    cout << "After push_back: " << str1 << endl;

    str1.pop_back(); // pop_back() removes last character
    cout << "After pop_back: " << str1 << endl;

    str1.insert(5, " Dear"); // insert at position
    cout << "After insert: " << str1 << endl;

    str1.erase(5, 5); // erase starting at pos, count chars
    cout << "After erase: " << str1 << endl;

    str1.replace(0, 5, "Hi"); // replace(pos, len, newStr)
    cout << "After replace: " << str1 << endl;

    // -------------------------------
    // 5. Substring
    // -------------------------------
    string sub = str3.substr(0, 5); // substr(pos, length)
    cout << "Substring of str3: " << sub << endl;

    // -------------------------------
    // 6. Finding in Strings
    // -------------------------------
    size_t found = str3.find("World"); // find substring
    if (found != string::npos)
    {
        cout << "'World' found at: " << found << endl;
    }

    found = str3.find("XYZ"); // not found
    if (found == string::npos)
    {
        cout << "'XYZ' not found in str3" << endl;
    }

    // -------------------------------
    // 7. Compare Strings
    // -------------------------------
    cout << "Comparing str1 and str2: " << str1.compare(str2) << endl;
    // compare() returns:
    // 0 if equal, <0 if str1 < str2, >0 if str1 > str2

    // -------------------------------
    // 8. Swapping Strings
    // -------------------------------
    cout << "Before swap - str1: " << str1 << ", str2: " << str2 << endl;
    str1.swap(str2);
    cout << "After swap - str1: " << str1 << ", str2: " << str2 << endl;

    // -------------------------------
    // 9. String Iteration
    // -------------------------------
    cout << "Iterating through str2 (after swap): ";
    for (char c : str2)
    {
        cout << c << " ";
    }
    cout << endl;

    // -------------------------------
    // 10. Conversion Functions
    // -------------------------------
    string numStr = "12345";
    int num = stoi(numStr); // convert string -> int
    cout << "stoi(numStr): " << num << endl;

    double dnum = stod("123.456"); // convert string -> double
    cout << "stod(\"123.456\"): " << dnum << endl;

    string fromNum = to_string(789); // convert int -> string
    cout << "to_string(789): " << fromNum << endl;

    // -------------------------------
    // 11. Clear, Empty
    // -------------------------------
    string temp = "Temporary";
    cout << "Before clear, temp: " << temp << endl;
    temp.clear(); // remove all contents
    cout << "After clear, temp is empty? " << temp.empty() << endl;

    return 0;
}
