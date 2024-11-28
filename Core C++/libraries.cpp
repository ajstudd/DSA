#include <iostream>
// For input and output operations.

#include <string>
// For handling strings and string manipulations.

#include <vector>
// For dynamic arrays (vectors).

#include <algorithm>
// Provides standard algorithms like sorting, reversing, etc.

#include <map>
// For key-value pairs (associative arrays).

#include <set>
// For unique elements container.

#include <queue>
// Provides queue and priority queue functionality.

#include <stack>
// Provides stack functionality.

#include <unordered_map>
// Provides hash map-like functionality.

#include <cmath>
// Provides common mathematical functions.

#include <ctime>
// For date and time functions.

#include <iomanip>
// For manipulating input/output format.

#include <fstream>
// For file input/output operations.

#include <bitset>
// For handling bits and bit operations.

#include <regex>
// For regular expressions and pattern matching.

#include <array>
// For fixed-size arrays.

#include <random>
// For random number generation.

#include <numeric>
// Provides numeric algorithms like accumulate, iota, etc.

#include <sstream>
// For string stream operations, used for conversions between strings and numbers.

#include <tuple>
// For grouping multiple values of different types.

using namespace std;

int main()
{
    // iostream: Input and output operations
    cout << "Enter a number: ";
    int input;
    cin >> input;
    cout << "You entered: " << input << endl;

    // string: String manipulations
    string s = "Hello";
    s.append(" World");
    cout << "Concatenated string: " << s << endl;
    cout << "String length: " << s.length() << endl;
    s.replace(0, 5, "Hi");
    cout << "Replaced string: " << s << endl;

    // vector: Dynamic arrays
    vector<int> v = {3, 1, 4, 1, 5};
    v.push_back(4);   // Add element at end
    cout << v.size(); // Get vector size
    v.pop_back();     // Remove last element
    cout << endl;

    // algorithm: Algorithms like sort, reverse
    sort(v.begin(), v.end());                          // Sort elements
    reverse(v.begin(), v.end());                       // Reverse elements
    bool found = binary_search(v.begin(), v.end(), 4); // Binary search
    cout << endl;

    // map: Associative arrays for key-value pairs
    map<string, int> age;
    age["Alice"] = 25;
    age["Bob"] = 30;
    cout << "Alice's age: " << age["Alice"] << endl;

    // set: Unique elements
    set<int> s1 = {
        1,
        2,
        2,
        3,
        3,
        3,
        4,
        5,
        6,
        7,
        7,
        7,
        7,
        7,
    };
    s1.insert(4); // Insert element
    s1.erase(2);  // Remove element
    cout << "Set size (unique elements): " << s1.size() << endl;
    // print the set
    for (int a : s1)
    {
        cout << a << " , ";
    }

    // queue: FIFO data structure
    queue<int> q;
    q.push(1); // Add to queue
    q.push(2);
    q.pop();           // Remove from queue
    cout << q.front(); // Access front element
    cout << "Queue front: " << q.front() << endl;

    // stack: LIFO data structure
    stack<int> st;
    st.push(100);
    st.push(200);
    st.pop(); // remove from stack
    cout << "Stack top: " << st.top() << endl;

    // unordered_map: Hash map for fast lookup
    unordered_map<string, int> fruit;
    fruit["apple"] = 3;
    fruit["banana"] = 5;
    cout << "Apple count: " << fruit["apple"] << endl;

    // cmath: Math functions
    double x = sqrt(16);  // Square root
    double y = pow(2, 3); // Power
    double z = abs(-5);   // Absolute value
    cout << "Square root of 16: " << sqrt(16) << endl;

    // ctime: Time functions
    time_t now = time(0);
    char *dt = ctime(&now); // Convert to string
    cout << "Current time: " << ctime(&now);

    // iomanip: Formatting output
    double pi = 3.14159;
    cout << fixed << setprecision(2) << "Formatted pi: " << pi << endl;

    // fstream: File input/output
    ofstream ofs("example.txt");
    ofs << "File example content";
    ofs.close();
    ifstream ifs("example.txt");
    string content;
    ifs >> content;
    cout << "File content: " << content << endl;

    // bitset: Bit manipulation
    bitset<8> bits(5); // Binary: 00000101
    bits.flip(2);      // Flip 3rd bit
    cout << "Bitset after flip: " << bits << endl;

    // regex: Pattern matching
    string test = "2024";
    regex re("\\d{4}");
    bool match = regex_match(test, re);
    cout << "Regex match (four digits): " << (match ? "Yes" : "No") << endl;

    // array: Fixed-size array
    array<int, 5> arr = {1, 2, 3, 4, 5};
    cout << arr[2];     // Access element at index 2
    cout << arr.size(); // Size of the array

    // random: Random number generation
    random_device rd;                        // Seed generator
    mt19937 gen(rd());                       // Mersenne Twister generator
    uniform_int_distribution<> dist(1, 100); // Range [1, 100]
    cout << dist(gen);                       // Generate random number

    // numeric: For numeric algorithms like accumulate, iota, etc.
    vector<int> vectro = {1, 2, 3, 4};
    int sum = accumulate(vectro.begin(), vectro.end(), 0); // Sum of elements
    iota(vectro.begin(), vectro.end(), 1);                 // Fill with 1, 2, 3, ...

    // sstream: For string stream operations (e.g., convert between strings and numbers).
    int num = 42;
    stringstream ss;
    ss << num;
    string numStr = ss.str();
    cout << "String converted from int: " << numStr << endl;

    // tuple: Grouping multiple values
    tuple<int, string, double> person = make_tuple(25, "Alice", 70.5);
    cout << "Tuple person age: " << get<0>(person) << endl;

    return 0;
}
