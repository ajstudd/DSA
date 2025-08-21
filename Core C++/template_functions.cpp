#include <bits/stdc++.h>
using namespace std;

// 1. Generic Max Function
template <typename T>
T maxValue(T a, T b)
{
    return (a > b) ? a : b;
}

// 2. Generic Min Function
template <typename T>
T minValue(T a, T b)
{
    return (a < b) ? a : b;
}

// 3. Fast Exponentiation (Binary Power Modulo)
template <typename T>
T binpow(T a, T b, T mod)
{
    T res = 1;
    a %= mod;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// 4. Custom Comparator (for sorting pairs by second value)
template <typename T>
bool pairSecondCmp(pair<T, T> a, pair<T, T> b)
{
    return a.second < b.second;
}

// 5. Generic Swap Function
template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 6. Variadic Template Print Function (for debugging)
template <typename T>
void print(T val)
{
    cout << val << "\n";
}

template <typename T, typename... Args>
void print(T first, Args... rest)
{
    cout << first << " ";
    print(rest...);
}

// 7. Template Function to Print Vector
template <typename T>
void printVector(const vector<T> &vec)
{
    for (const T &val : vec)
        cout << val << " ";
    cout << "\n";
}

int main()
{
    // 1. maxValue & minValue
    cout << "Max of 10 and 20: " << maxValue(10, 20) << "\n";
    cout << "Min of 10.5 and 7.2: " << minValue(10.5, 7.2) << "\n";

    // 2. binpow
    cout << "2^10 % 1000: " << binpow(2LL, 10LL, 1000LL) << "\n";

    // 3. Sorting using comparator
    vector<pair<int, int>> v = {{1, 3}, {2, 2}, {3, 1}};
    sort(v.begin(), v.end(), pairSecondCmp<int>);
    cout << "Sorted pairs by second:\n";
    for (auto [a, b] : v)
        cout << a << "," << b << "  ";
    cout << "\n";

    // 4. Swap
    int a = 5, b = 10;
    mySwap(a, b);
    cout << "After swap: a = " << a << ", b = " << b << "\n";

    // 5. Debug print with variadic templates
    print("Debug =>", "Max:", maxValue(30, 40), "Min:", minValue(30, 40));

    // 6. Print Vector
    vector<double> dv = {1.1, 2.2, 3.3};
    print("Vector values:");
    printVector(dv);

    return 0;
}
