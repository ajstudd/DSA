# Template Functions in C++

This document covers various template functions commonly used in competitive programming and general C++ development.

## Code Examples

```cpp
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
```

---

## 💡 Understanding Template Type Inference

### 🔍 How `maxValue(10, 20)` works without explicitly specifying `T`

When you call:

```cpp
maxValue(10, 20);
```

You're **not** specifying the type `T` manually. But C++ **infers** it from the **types of the arguments** passed into the function.

### ⚙️ Behind the Scenes (Simplified)

1. You defined:

   ```cpp
   template <typename T>
   T maxValue(T a, T b)
   ```

2. You called:

   ```cpp
   maxValue(10, 20);
   ```

3. The compiler sees:

   - `10` is of type `int`
   - `20` is also of type `int`

4. So it deduces:

   ```cpp
   T = int
   ```

5. And compiles this into:
   ```cpp
   int maxValue(int a, int b) { return (a > b) ? a : b; }
   ```

### 🧪 What if you mix types?

```cpp
maxValue(10, 20.5);  // Error or implicit promotion
```

- This causes **type mismatch**: `int` vs `double`
- Compiler can't deduce a single `T`
- You'll get a compilation error **unless** there's an implicit conversion

✅ You can fix it by casting:

```cpp
maxValue<double>(10, 20.5);  // T is explicitly set to double
```

## ✅ Summary: Type Deduction

- The compiler **automatically deduces** the type of `T` based on arguments.
- All arguments must be of **the same deducible type** unless explicitly specified.
- You can override deduction like this:

  ```cpp
  maxValue<long long>(10, 20);
  ```

---

Let’s dive into an example where **template type deduction fails**, and then explore **how to fix it**.

## ❌ Case: Type Deduction Fails

```cpp
#include <iostream>
using namespace std;

template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    auto result = maxValue(10, 20.5);  // int and double
    cout << "Max: " << result << endl;
    return 0;
}
```

### ❗ Compilation Error:

```
error: no matching function for call to 'maxValue(int, double)'
```

> Because the compiler **cannot deduce a single `T`** — one is `int`, the other is `double`.

---

## ✅ Fix 1: Use Explicit Type to Resolve Conflict

```cpp
auto result = maxValue<double>(10, 20.5);
```

**Explanation**: Now both `10` and `20.5` are treated as `double`, and `T` is explicitly defined as `double`.

---

## ✅ Fix 2: Use `decltype` + auto return (C++14+)

If you want to handle **mixed types automatically**, modern C++ lets you write:

```cpp
template <typename T1, typename T2>
auto maxValue(T1 a, T2 b) -> decltype((a > b) ? a : b) {
    return (a > b) ? a : b;
}
```

Now it can handle:

```cpp
maxValue(10, 20.5);         // OK: returns double
maxValue(30.5, 12);         // OK: returns double
maxValue(100L, 200);        // OK: returns long
```

---

## ✅ Fix 3: Use `std::common_type` (C++11+)

Even more robust:

```cpp
#include <type_traits>

template <typename T1, typename T2>
typename std::common_type<T1, T2>::type
maxValue(T1 a, T2 b) {
    return (a > b) ? a : b;
}
```

This uses the **common type** of both arguments safely and portably.

---

## 🔚 Conclusion

| Problem                         | Fix                                                 |
| ------------------------------- | --------------------------------------------------- |
| Mixed types: `int`, `double`    | Use explicit type: `maxValue<double>(10, 20.5)`     |
| Auto detect correct return type | Use `auto` + `decltype` or `std::common_type`       |
| Want safety & modern features   | Prefer C++14+ methods for mixed-type template logic |

---

We do need to declare `template <typename T>` for **each independent function or class** where we're introducing a **new template parameter**.

---

## ✅ When You Must Write `template <typename T>`

Any time you're writing a **standalone function** that introduces a **template parameter**, you need to declare it like this:

```cpp
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}
```

Each such function gets its **own template context**. There is no shared scope for templates like there is for namespaces or classes.

---

## 🧠 But There Are Exceptions...

You **don’t have to repeat** the `template <typename T>` in these cases:

---

### ✅ 1. **Inside a Template Class**

If you're inside a template class, you **don’t** have to redeclare the template for every method:

```cpp
template <typename T>
class MyStack {
    vector<T> data;
public:
    void push(T val) {
        data.push_back(val);
    }

    T top() {
        return data.back();
    }
};
```

Here, both `push()` and `top()` know `T` because they're inside the class that already declared `T`.

---

### ✅ 2. **Inline Helper Functions Inside Template Functions**

If you're writing a helper inside a template function (like a lambda or nested function), you might not need to re-template if it's not generic itself.

---

### ❌ Not Shared Across Functions

This **doesn’t work**:

```cpp
template <typename T>
T add(T a, T b) { return a + b; }

T sub(T a, T b) { return a - b; }  // ❌ Error: T is not known here
```

To fix it:

```cpp
template <typename T>
T sub(T a, T b) { return a - b; }
```

Each function must declare its own template if it's generic.

---

### ✅ Tip: Use Macros or Snippets for Competitive Programming

If you're using templates a lot in CP, define macros to reduce repetition:

```cpp
#define tpl template <typename T>
tpl T maxValue(T a, T b) { return (a > b) ? a : b; }
tpl T minValue(T a, T b) { return (a < b) ? a : b; }
```

Or set up code snippets in your IDE/editor.

---

### ✅ Summary Table

| Situation                        | Do You Need `template <typename T>`? |
| -------------------------------- | ------------------------------------ |
| Standalone generic function      | ✅ Yes                               |
| Another function using same `T`  | ✅ Yes, must re-declare              |
| Inside a template class          | ❌ No                                |
| Template lambda or nested helper | 🔁 Depends on usage                  |

---
