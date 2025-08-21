/*
    Competitive Programming Library - Comprehensive C++ STL and Techniques Demo

    This file contains examples and demonstrations of:
    1. Basic STL containers (vector, map, set, queue, stack, etc.)
    2. Advanced STL algorithms (sort, search, permutations, etc.)
    3. Priority queues (max heap, min heap, custom comparators)
    4. Hash-based containers (unordered_set, unordered_map)
    5. String manipulation techniques
    6. Mathematical functions and bit manipulation
    7. Common competitive programming patterns:
       - Sliding window technique
       - Two pointers technique
       - Kadane's algorithm (maximum subarray)
       - Prefix sum technique
       - Custom sorting with lambda functions
    8. Utility functions for Windows/MSVC compatibility

    Optimized for: Windows GCC 64-bit / MSVC compiler
    Compilation: cl.exe /EHsc libraries.cpp
*/

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

#include <unordered_set>
// For hash set functionality.

#include <deque>
// For double-ended queue.

#include <cctype>
// For character manipulation functions like toupper, tolower.

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
    q.push(3);
    cout << "Queue size: " << q.size() << endl;
    cout << "Queue front: " << q.front() << endl;
    cout << "Queue back: " << q.back() << endl;

    q.pop(); // Remove from queue
    cout << "After pop, queue front: " << q.front() << endl;
    cout << "Queue empty: " << (q.empty() ? "Yes" : "No") << endl;

    // Empty the queue
    while (!q.empty())
    {
        q.pop();
    }
    cout << "After emptying, queue empty: " << (q.empty() ? "Yes" : "No") << endl;

    // stack: LIFO data structure
    stack<int> st;
    st.push(100);
    st.push(200);
    st.push(300);
    cout << "Stack size: " << st.size() << endl;
    cout << "Stack top: " << st.top() << endl;

    st.pop(); // remove from stack
    cout << "After pop, stack top: " << st.top() << endl;
    cout << "Stack empty: " << (st.empty() ? "Yes" : "No") << endl;

    // Empty the stack
    while (!st.empty())
    {
        st.pop();
    }
    cout << "After emptying, stack empty: " << (st.empty() ? "Yes" : "No") << endl;

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

    // ==== ADDITIONAL COMPETITIVE PROGRAMMING TECHNIQUES ====

    // 1. STL ALGORITHMS - Advanced Usage
    cout << "\n=== STL Algorithms ===\n";
    vector<int> nums = {4, 2, 8, 1, 9, 3, 6, 5};

    // Finding min/max elements
    auto minIt = min_element(nums.begin(), nums.end());
    auto maxIt = max_element(nums.begin(), nums.end());
    cout << "Min: " << *minIt << ", Max: " << *maxIt << endl;

    // Count occurrences
    int countOfThree = count(nums.begin(), nums.end(), 3);
    cout << "Count of 3: " << countOfThree << endl;

    // Find first occurrence
    auto it = find(nums.begin(), nums.end(), 8);
    if (it != nums.end())
    {
        cout << "Found 8 at index: " << distance(nums.begin(), it) << endl;
    }

    // Lower and upper bound (for sorted arrays)
    sort(nums.begin(), nums.end());
    auto lower = lower_bound(nums.begin(), nums.end(), 5);
    auto upper = upper_bound(nums.begin(), nums.end(), 5);
    cout << "Lower bound of 5: " << distance(nums.begin(), lower) << endl;
    cout << "Upper bound of 5: " << distance(nums.begin(), upper) << endl;

    // Unique elements (removes consecutive duplicates)
    vector<int> dup = {1, 1, 2, 2, 2, 3, 3, 4};
    auto lastUnique = unique(dup.begin(), dup.end());
    dup.erase(lastUnique, dup.end());
    cout << "After unique: ";
    for (int x : dup)
        cout << x << " ";
    cout << endl;

    // Next permutation
    vector<int> perm = {1, 2, 3};
    cout << "Permutations: ";
    do
    {
        for (int x : perm)
            cout << x;
        cout << " ";
    } while (next_permutation(perm.begin(), perm.end()));
    cout << endl;

    // 2. PRIORITY QUEUE (MAX HEAP and MIN HEAP)
    cout << "\n=== Priority Queue ===\n";
    // Max heap (default)
    priority_queue<int> maxHeap;
    maxHeap.push(3);
    maxHeap.push(1);
    maxHeap.push(4);
    cout << "Max heap top: " << maxHeap.top() << endl;

    // Min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(4);
    cout << "Min heap top: " << minHeap.top() << endl;

    // Custom comparator for pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({3, 1});
    pq.push({1, 2});
    pq.push({2, 3});
    cout << "Min pair: (" << pq.top().first << ", " << pq.top().second << ")" << endl;

    // 3. UNORDERED_SET for O(1) operations
    cout << "\n=== Unordered Set ===\n";
    unordered_set<int> hashSet;
    hashSet.insert(1);
    hashSet.insert(2);
    hashSet.insert(3);
    cout << "Contains 2: " << (hashSet.count(2) > 0 ? "Yes" : "No") << endl;
    cout << "Set size: " << hashSet.size() << endl;

    // 4. DEQUE (Double-ended queue)
    cout << "\n=== Deque ===\n";
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(2);
    dq.push_back(3);
    cout << "Front: " << dq.front() << ", Back: " << dq.back() << endl;
    dq.pop_front();
    dq.pop_back();
    cout << "After pops, front: " << dq.front() << endl;

    // 5. MULTISET and MULTIMAP
    cout << "\n=== Multiset ===\n";
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    cout << "Count of 1 in multiset: " << ms.count(1) << endl;
    ms.erase(ms.find(1)); // Remove only one occurrence
    cout << "After erasing one 1: " << ms.count(1) << endl;

    // 6. STRING OPERATIONS AND TRICKS
    cout << "\n=== String Tricks ===\n";
    string str = "programming";

    // Check if string is palindrome
    string rev = str;
    reverse(rev.begin(), rev.end());
    cout << "Is palindrome: " << (str == rev ? "Yes" : "No") << endl;

    // String to number conversions
    string numStr1 = "123";
    int convertedInt = stoi(numStr1);
    string numStr2 = "45.67";
    double convertedDouble = stod(numStr2);
    cout << "String to int: " << convertedInt << endl;
    cout << "String to double: " << convertedDouble << endl;

    // Number to string
    int number = 789;
    string numberStr = to_string(number);
    cout << "Int to string: " << numberStr << endl;

    // Find substring
    string text = "hello world";
    size_t pos = text.find("world");
    if (pos != string::npos)
    {
        cout << "Found 'world' at position: " << pos << endl;
    }

    // Transform to uppercase/lowercase
    string upperStr = "hello";
    transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
    cout << "Uppercase: " << upperStr << endl;

    // 7. MATHEMATICAL FUNCTIONS AND TRICKS
    cout << "\n=== Math Tricks ===\n";

    // GCD and LCM
    int a = 48, b = 18;
    // Custom GCD function for MSVC compatibility
    auto gcd = [](int a, int b) -> int
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    };
    int gcdVal = gcd(a, b);
    int lcmVal = (a * b) / gcdVal;
    cout << "GCD(" << a << ", " << b << ") = " << gcdVal << endl;
    cout << "LCM(" << a << ", " << b << ") = " << lcmVal << endl;

    // Check if number is power of 2
    int num1 = 16;
    bool isPowerOf2 = (num1 & (num1 - 1)) == 0 && num1 > 0;
    cout << num1 << " is power of 2: " << (isPowerOf2 ? "Yes" : "No") << endl;

    // Count set bits
    int num2 = 13; // Binary: 1101
    // Custom popcount function for MSVC compatibility
    auto popcount = [](int n) -> int
    {
        int count = 0;
        while (n)
        {
            count += n & 1;
            n >>= 1;
        }
        return count;
    };
    int setBits = popcount(num2);
    cout << "Set bits in " << num2 << ": " << setBits << endl;

    // Fast exponentiation
    auto fastPower = [](long long base, long long exp, long long mod) -> long long
    {
        long long result = 1;
        while (exp > 0)
        {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    };
    cout << "2^10 mod 1000007 = " << fastPower(2, 10, 1000007) << endl;

    // 8. BIT MANIPULATION TRICKS
    cout << "\n=== Bit Manipulation ===\n";
    int n = 12; // Binary: 1100

    // Check if i-th bit is set
    int i = 2;
    bool isSet = (n >> i) & 1;
    cout << "Bit " << i << " in " << n << " is set: " << (isSet ? "Yes" : "No") << endl;

    // Set i-th bit
    int setBit = n | (1 << i);
    cout << "After setting bit " << i << ": " << setBit << endl;

    // Clear i-th bit
    int clearBit = n & ~(1 << i);
    cout << "After clearing bit " << i << ": " << clearBit << endl;

    // Toggle i-th bit
    int toggleBit = n ^ (1 << i);
    cout << "After toggling bit " << i << ": " << toggleBit << endl;

    // Get rightmost set bit
    int rightmostSet = n & (-n);
    cout << "Rightmost set bit of " << n << ": " << rightmostSet << endl;

    // 9. USEFUL COMPARATORS AND SORTING
    cout << "\n=== Custom Sorting ===\n";
    vector<pair<int, int>> pairs = {{3, 1}, {1, 3}, {2, 2}};

    // Sort by second element
    sort(pairs.begin(), pairs.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });
    cout << "Sorted by second element: ";
    for (auto p : pairs)
        cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;

    // Sort strings by length
    vector<string> words = {"cat", "elephant", "dog", "a"};
    sort(words.begin(), words.end(), [](const string &a, const string &b)
         { return a.length() < b.length(); });
    cout << "Sorted by length: ";
    for (string w : words)
        cout << w << " ";
    cout << endl;

    // 10. SLIDING WINDOW TECHNIQUE
    cout << "\n=== Sliding Window Example ===\n";
    vector<int> windowArr = {1, 4, 2, 9, 5, 10, 8, 2};
    int k = 3; // Window size

    // Find maximum in each window of size k
    deque<int> dq1;
    cout << "Maximum in each window of size " << k << ": ";
    for (int i = 0; i < windowArr.size(); i++)
    {
        // Remove elements outside current window
        while (!dq1.empty() && dq1.front() <= i - k)
        {
            dq1.pop_front();
        }

        // Remove smaller elements from rear
        while (!dq1.empty() && windowArr[dq1.back()] <= windowArr[i])
        {
            dq1.pop_back();
        }

        dq1.push_back(i);

        // Print maximum for current window
        if (i >= k - 1)
        {
            cout << windowArr[dq1.front()] << " ";
        }
    }
    cout << endl;

    // 11. TWO POINTERS TECHNIQUE
    cout << "\n=== Two Pointers Example ===\n";
    vector<int> sortedArr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 10;
    int left = 0, right = sortedArr.size() - 1;
    bool pairFound = false;

    while (left < right)
    {
        int sum = sortedArr[left] + sortedArr[right];
        if (sum == target)
        {
            cout << "Pair found: " << sortedArr[left] << " + " << sortedArr[right] << " = " << target << endl;
            pairFound = true;
            break;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    if (!pairFound)
        cout << "No pair found for target " << target << endl;

    // 12. COMMON PATTERNS AND TEMPLATES
    cout << "\n=== Useful Constants ===\n";
    const int MOD = 1000000007;
    const int INF = 1e9;
    const long long LINF = 1e18;
    cout << "MOD: " << MOD << ", INF: " << INF << ", LINF: " << LINF << endl;

    // Fast I/O (uncomment for competitive programming)
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // 13. ADDITIONAL USEFUL TECHNIQUES
    cout << "\n=== Additional CP Techniques ===\n";

    // Binary representation
    int binNum = 25;
    cout << "Binary of " << binNum << ": ";
    for (int bit = 7; bit >= 0; bit--)
    {
        cout << ((binNum >> bit) & 1);
    }
    cout << endl;

    // Check if all characters in string are unique
    string uniqueStr = "abcdef";
    bool allUnique = true;
    unordered_set<char> charSet;
    for (char c : uniqueStr)
    {
        if (charSet.count(c))
        {
            allUnique = false;
            break;
        }
        charSet.insert(c);
    }
    cout << "All characters unique in '" << uniqueStr << "': " << (allUnique ? "Yes" : "No") << endl;

    // Kadane's Algorithm (Maximum Subarray Sum)
    vector<int> kadaneArr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxSum = kadaneArr[0], currentSum = kadaneArr[0];
    for (int i = 1; i < kadaneArr.size(); i++)
    {
        currentSum = max(kadaneArr[i], currentSum + kadaneArr[i]);
        maxSum = max(maxSum, currentSum);
    }
    cout << "Maximum subarray sum (Kadane's): " << maxSum << endl;

    // Frequency counting
    string freqStr = "programming";
    map<char, int> freq;
    for (char c : freqStr)
        freq[c]++;
    cout << "Character frequencies in '" << freqStr << "': ";
    for (auto p : freq)
    {
        cout << p.first << ":" << p.second << " ";
    }
    cout << endl;

    // Prefix sum technique
    vector<int> prefixArr = {1, 2, 3, 4, 5};
    vector<int> prefix(prefixArr.size() + 1, 0);
    for (int i = 0; i < prefixArr.size(); i++)
    {
        prefix[i + 1] = prefix[i] + prefixArr[i];
    }
    cout << "Original array: ";
    for (int x : prefixArr)
        cout << x << " ";
    cout << "\nPrefix sum array: ";
    for (int x : prefix)
        cout << x << " ";
    cout << "\nSum from index 1 to 3: " << prefix[4] - prefix[1] << endl;

    // Check if array is sorted
    vector<int> sortedCheck = {1, 2, 3, 4, 5};
    bool isSorted = is_sorted(sortedCheck.begin(), sortedCheck.end());
    cout << "Array is sorted: " << (isSorted ? "Yes" : "No") << endl;

    // Rotate array
    vector<int> rotateArr = {1, 2, 3, 4, 5};
    int rotateBy = 2;
    rotate(rotateArr.begin(), rotateArr.begin() + rotateBy, rotateArr.end());
    cout << "Array after rotating by " << rotateBy << ": ";
    for (int x : rotateArr)
        cout << x << " ";
    cout << endl;

    cout << "\nLibrary demonstration completed!" << endl;
    return 0;
}
