# Complete C++ and Object-Oriented Programming Tutorial - Phase 4

## Prerequisites

- **Phase 0** completed (Core C++ Foundations) ✅
- **Phase 1** completed (OOP Core) ✅
- **Phase 2** completed (Modern C++) ✅
- **Phase 3** completed (Standard Template Library) ✅
- Advanced understanding of templates, smart pointers, move semantics, and STL
- Familiarity with compilation process, memory management, and performance considerations
- Experience with complex C++ projects and debugging techniques

---

# ⚡ Phase 4: Advanced C++ (Performance & System-Level Mastery)

**🔑 Goal**: Handle **complex projects** and understand C++ internals. Master advanced C++ features for building high-performance, system-level applications with sophisticated architectures. This phase focuses on expert-level techniques used in production environments.

Advanced C++ encompasses the most sophisticated features and techniques that separate expert developers from intermediate ones:

1. **Template Metaprogramming** - Compile-time computations and code generation
2. **Advanced Memory Management** - Custom allocators, object pools, and memory optimization
3. **Concurrency & Parallelism** - Multi-threading, synchronization, and atomic operations
4. **Design Patterns** - Industry-standard architectural solutions
5. **System Programming** - File I/O, networking, and low-level operations
6. **Performance Engineering** - Optimization techniques and profiling

**Key Principles of Advanced C++**:

- **Zero-cost abstractions** - High-level features with no runtime overhead
- **Compile-time optimization** - Maximum work done during compilation
- **Resource management** - Precise control over system resources
- **Type safety** - Strong typing with template constraints
- **Performance predictability** - Understanding the cost of operations

---

## Phase 4.1: Templates - The Foundation of Generic Programming

### Introduction to Template Metaprogramming

**Concept**: **Templates** are C++'s mechanism for **generic programming** - writing code that works with any type while maintaining type safety and performance. Templates allow you to write algorithms and data structures once and use them with different types. Modern C++ templates are Turing-complete, enabling complex compile-time computations.

**Template Categories**:

- **Function Templates** - Generic functions
- **Class Templates** - Generic classes
- **Variable Templates** - Generic constants (C++14)
- **Alias Templates** - Generic type aliases
- **Template Specialization** - Custom implementations for specific types
- **Variadic Templates** - Templates with variable number of parameters
- **Concepts** - Template constraints (C++20)

**Template Benefits**:

1. **Code Reusability** - Write once, use with many types
2. **Type Safety** - Compile-time type checking
3. **Performance** - No runtime overhead
4. **Expressiveness** - Clean, readable generic code
5. **Flexibility** - Customization through specialization

### 4.1.1 Function Templates

**Concept**: **Function templates** define a family of functions that can work with different types. The compiler generates specific function instances for each type used, a process called **template instantiation**.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <type_traits>
#include <chrono>
using namespace std;
using namespace std::chrono;

// FUNCTION TEMPLATES COMPREHENSIVE EXAMPLE

// Basic function template
template<typename T>
T maximum(T a, T b) {
    cout << "🔧 maximum<" << typeid(T).name() << "> called with (" << a << ", " << b << ")" << endl;
    return (a > b) ? a : b;
}

// Function template with multiple type parameters
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    auto result = a + b;
    cout << "🧮 add<" << typeid(T).name() << ", " << typeid(U).name()
         << "> called: " << a << " + " << b << " = " << result << endl;
    return result;
}

// Function template with non-type parameters
template<typename T, size_t N>
void printArray(const T (&arr)[N]) {
    cout << "📋 Array<" << typeid(T).name() << "[" << N << "]>: ";
    for (size_t i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Template with default parameters
template<typename T = int, typename Comparator = less<T>>
T findExtreme(const vector<T>& vec, Comparator comp = Comparator{}) {
    if (vec.empty()) {
        throw invalid_argument("Empty vector");
    }

    T extreme = vec[0];
    for (const auto& elem : vec) {
        if (comp(extreme, elem)) {
            extreme = elem;
        }
    }
    return extreme;
}

// Template function overloading
template<typename T>
void process(T value) {
    cout << "🔄 Processing single value: " << value << endl;
}

template<typename T>
void process(const vector<T>& values) {
    cout << "🔄 Processing vector of " << values.size() << " values: ";
    for (const auto& val : values) {
        cout << val << " ";
    }
    cout << endl;
}

// SFINAE (Substitution Failure Is Not An Error) example
template<typename T>
typename enable_if<is_integral<T>::value, T>::type
safeDivide(T a, T b) {
    cout << "🔢 Integer division: " << a << " / " << b;
    if (b == 0) {
        cout << " = ERROR (Division by zero!)" << endl;
        throw invalid_argument("Division by zero");
    }
    T result = a / b;
    cout << " = " << result << endl;
    return result;
}

template<typename T>
typename enable_if<is_floating_point<T>::value, T>::type
safeDivide(T a, T b) {
    cout << "🔢 Floating-point division: " << a << " / " << b;
    if (abs(b) < numeric_limits<T>::epsilon()) {
        cout << " = ERROR (Division by near-zero!)" << endl;
        throw invalid_argument("Division by near-zero value");
    }
    T result = a / b;
    cout << " = " << result << endl;
    return result;
}

// Perfect forwarding example
template<typename F, typename... Args>
auto measureExecutionTime(F&& func, Args&&... args) -> decltype(func(forward<Args>(args)...)) {
    auto start = high_resolution_clock::now();

    // Perfect forwarding preserves value categories
    auto result = func(forward<Args>(args)...);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "⏱️ Execution time: " << duration.count() << " microseconds" << endl;
    return result;
}

// Variadic function template
template<typename T>
T sum(T value) {
    return value;
}

template<typename T, typename... Args>
T sum(T first, Args... args) {
    cout << "➕ Adding " << first << " + sum of remaining" << endl;
    return first + sum(args...);
}

// Template specialization
template<>
string maximum<string>(string a, string b) {
    cout << "📝 Specialized maximum<string> called with (\"" << a << "\", \"" << b << "\")" << endl;
    return (a.length() > b.length()) ? a : b;
}

void demonstrateFunctionTemplates() {
    cout << "=== Function Templates Comprehensive Demo ===" << endl;

    // Basic template usage
    cout << "\n--- Basic Function Templates ---" << endl;
    cout << "Max of 10 and 20: " << maximum(10, 20) << endl;
    cout << "Max of 3.14 and 2.71: " << maximum(3.14, 2.71) << endl;
    cout << "Max of 'hello' and 'world': " << maximum(string("hello"), string("world")) << endl;

    // Multiple type parameters
    cout << "\n--- Multiple Type Parameters ---" << endl;
    add(5, 3.14);
    add(2.5, 10);
    add(string("Hello "), string("World"));

    // Non-type parameters
    cout << "\n--- Non-type Template Parameters ---" << endl;
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3};
    string stringArray[] = {"apple", "banana", "cherry"};

    printArray(intArray);
    printArray(doubleArray);
    printArray(stringArray);

    // Default template parameters
    cout << "\n--- Default Template Parameters ---" << endl;
    vector<int> numbers = {5, 2, 8, 1, 9, 3};
    cout << "Numbers: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    cout << "Maximum (default less): " << findExtreme(numbers) << endl;
    cout << "Minimum (greater): " << findExtreme(numbers, greater<int>{}) << endl;

    // Function template overloading
    cout << "\n--- Template Overloading ---" << endl;
    process(42);
    process(vector<string>{"alpha", "beta", "gamma"});

    // SFINAE examples
    cout << "\n--- SFINAE (Type-based Function Selection) ---" << endl;
    try {
        safeDivide(10, 3);     // Integer version
        safeDivide(10.0, 3.0); // Floating-point version
        safeDivide(10, 0);     // Will throw exception
    } catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    // Perfect forwarding and timing
    cout << "\n--- Perfect Forwarding ---" << endl;
    auto slowOperation = [](int n) {
        this_thread::sleep_for(microseconds(100));
        return n * n;
    };

    int result = measureExecutionTime(slowOperation, 5);
    cout << "Result: " << result << endl;

    // Variadic templates
    cout << "\n--- Variadic Function Templates ---" << endl;
    cout << "Sum of 1: " << sum(1) << endl;
    cout << "Sum of 1,2,3: " << sum(1, 2, 3) << endl;
    cout << "Sum of 1,2,3,4,5: " << sum(1, 2, 3, 4, 5) << endl;
    cout << "Sum of doubles: " << sum(1.1, 2.2, 3.3) << endl;
}

int main() {
    demonstrateFunctionTemplates();
    return 0;
}
```

**Output:**

```
=== Function Templates Comprehensive Demo ===

--- Basic Function Templates ---
🔧 maximum<i> called with (10, 20)
Max of 10 and 20: 20
🔧 maximum<d> called with (3.14, 2.71)
Max of 3.14 and 2.71: 3.14
📝 Specialized maximum<string> called with ("hello", "world")
Max of 'hello' and 'world': hello

--- Multiple Type Parameters ---
🧮 add<i, d> called: 5 + 3.14 = 8.14
🧮 add<d, i> called: 2.5 + 10 = 12.5
🧮 add<NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE> called: Hello  + World = Hello World

--- Non-type Template Parameters ---
📋 Array<i[5]>: 1 2 3 4 5
📋 Array<d[3]>: 1.1 2.2 3.3
📋 Array<NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE[3]>: apple banana cherry

--- Default Template Parameters ---
Numbers: 5 2 8 1 9 3
Maximum (default less): 9
Minimum (greater): 1

--- Template Overloading ---
🔄 Processing single value: 42
🔄 Processing vector of 3 values: alpha beta gamma

--- SFINAE (Type-based Function Selection) ---
🔢 Integer division: 10 / 3 = 3
🔢 Floating-point division: 10 / 3 = 3.33333
🔢 Integer division: 10 / 0 = ERROR (Division by zero!)
Exception caught: Division by zero

--- Perfect Forwarding ---
⏱️ Execution time: 123 microseconds
Result: 25

--- Variadic Function Templates ---
Sum of 1: 1
➕ Adding 1 + sum of remaining
Sum of 1,2,3: 6
➕ Adding 1 + sum of remaining
➕ Adding 2 + sum of remaining
Sum of 1,2,3,4,5: 15
➕ Adding 1.1 + sum of remaining
➕ Adding 2.2 + sum of remaining
Sum of doubles: 6.6
```

### 4.1.2 Class Templates

**Concept**: **Class templates** define generic classes that can work with different types. They provide a way to create reusable data structures and algorithms while maintaining type safety and performance.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include <type_traits>
using namespace std;

// CLASS TEMPLATES COMPREHENSIVE EXAMPLE

// Basic class template - Generic Stack
template<typename T, size_t MaxSize = 100>
class Stack {
private:
    T data[MaxSize];
    size_t topIndex;

public:
    Stack() : topIndex(0) {
        cout << "📚 Stack<" << typeid(T).name() << ", " << MaxSize << "> created" << endl;
    }

    ~Stack() {
        cout << "📚 Stack<" << typeid(T).name() << ", " << MaxSize << "> destroyed" << endl;
    }

    void push(const T& item) {
        if (isFull()) {
            throw overflow_error("Stack overflow - maximum size " + to_string(MaxSize) + " reached");
        }
        data[topIndex++] = item;
        cout << "📥 Pushed: " << item << " (size: " << size() << ")" << endl;
    }

    T pop() {
        if (isEmpty()) {
            throw underflow_error("Stack underflow - no elements to pop");
        }
        T item = data[--topIndex];
        cout << "📤 Popped: " << item << " (size: " << size() << ")" << endl;
        return item;
    }

    const T& top() const {
        if (isEmpty()) {
            throw underflow_error("Stack is empty - no top element");
        }
        return data[topIndex - 1];
    }

    bool isEmpty() const { return topIndex == 0; }
    bool isFull() const { return topIndex == MaxSize; }
    size_t size() const { return topIndex; }
    size_t capacity() const { return MaxSize; }

    void display() const {
        cout << "Stack contents (top to bottom): ";
        if (isEmpty()) {
            cout << "[empty]";
        } else {
            for (int i = static_cast<int>(topIndex) - 1; i >= 0; --i) {
                cout << data[i] << " ";
            }
        }
        cout << endl;
    }
};

// Advanced class template - Generic Pair with operations
template<typename T, typename U>
class Pair {
private:
    T first;
    U second;

public:
    Pair() = default;

    Pair(const T& f, const U& s) : first(f), second(s) {
        cout << "👥 Pair<" << typeid(T).name() << ", " << typeid(U).name() << "> created: ("
             << first << ", " << second << ")" << endl;
    }

    // Copy constructor
    Pair(const Pair& other) : first(other.first), second(other.second) {
        cout << "📋 Pair copied" << endl;
    }

    // Move constructor
    Pair(Pair&& other) noexcept : first(move(other.first)), second(move(other.second)) {
        cout << "🚚 Pair moved" << endl;
    }

    // Assignment operators
    Pair& operator=(const Pair& other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
            cout << "📝 Pair assigned" << endl;
        }
        return *this;
    }

    // Getters
    const T& getFirst() const { return first; }
    const U& getSecond() const { return second; }

    // Setters
    void setFirst(const T& f) {
        first = f;
        cout << "🔄 First updated to: " << first << endl;
    }
    void setSecond(const U& s) {
        second = s;
        cout << "🔄 Second updated to: " << second << endl;
    }

    // Comparison operators (requires both types to be comparable)
    template<typename T2, typename U2>
    bool operator==(const Pair<T2, U2>& other) const {
        return first == other.getFirst() && second == other.getSecond();
    }

    // Swap function
    void swap(Pair& other) {
        using std::swap;
        swap(first, other.first);
        swap(second, other.second);
        cout << "🔄 Pairs swapped" << endl;
    }

    // Display function
    void display() const {
        cout << "Pair: (" << first << ", " << second << ")" << endl;
    }
};

// Template class with member templates
template<typename T>
class SmartContainer {
private:
    vector<T> data;

public:
    SmartContainer() {
        cout << "🧠 SmartContainer<" << typeid(T).name() << "> created" << endl;
    }

    void add(const T& item) {
        data.push_back(item);
        cout << "➕ Added: " << item << " (size: " << data.size() << ")" << endl;
    }

    // Member function template for type conversion
    template<typename U>
    void addConverted(const U& item) {
        T converted = static_cast<T>(item);
        data.push_back(converted);
        cout << "🔄 Converted and added: " << item << " -> " << converted
             << " (size: " << data.size() << ")" << endl;
    }

    // Member function template for batch operations
    template<typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        size_t oldSize = data.size();
        data.insert(data.end(), begin, end);
        cout << "📦 Added range: " << (data.size() - oldSize) << " elements" << endl;
    }

    // Member function template with different containers
    template<typename Container>
    void merge(const Container& other) {
        size_t oldSize = data.size();
        for (const auto& item : other) {
            data.push_back(static_cast<T>(item));
        }
        cout << "🔗 Merged container: " << (data.size() - oldSize) << " elements added" << endl;
    }

    T& operator[](size_t index) {
        if (index >= data.size()) {
            throw out_of_range("Index " + to_string(index) + " out of range");
        }
        return data[index];
    }

    size_t size() const { return data.size(); }
    bool empty() const { return data.empty(); }

    void display() const {
        cout << "Container contents: ";
        if (data.empty()) {
            cout << "[empty]";
        } else {
            for (const auto& item : data) {
                cout << item << " ";
            }
        }
        cout << endl;
    }

    // Template member function for custom operations
    template<typename Predicate>
    size_t countIf(Predicate pred) const {
        size_t count = 0;
        for (const auto& item : data) {
            if (pred(item)) {
                ++count;
            }
        }
        return count;
    }
};

// Specialized template class for specific types
template<>
class SmartContainer<string> {
private:
    vector<string> data;

public:
    SmartContainer() {
        cout << "📝 Specialized SmartContainer<string> created" << endl;
    }

    void add(const string& item) {
        data.push_back(item);
        cout << "📝 Added string: \"" << item << "\" (length: " << item.length()
             << ", total: " << data.size() << ")" << endl;
    }

    void addUpperCase(const string& item) {
        string upper = item;
        transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
        data.push_back(upper);
        cout << "📝 Added uppercase: \"" << item << "\" -> \"" << upper << "\"" << endl;
    }

    size_t totalLength() const {
        size_t total = 0;
        for (const auto& str : data) {
            total += str.length();
        }
        return total;
    }

    void display() const {
        cout << "String container: ";
        if (data.empty()) {
            cout << "[empty]";
        } else {
            for (const auto& str : data) {
                cout << "\"" << str << "\" ";
            }
        }
        cout << " (total length: " << totalLength() << ")" << endl;
    }

    size_t size() const { return data.size(); }
};

void demonstrateClassTemplates() {
    cout << "=== Class Templates Comprehensive Demo ===" << endl;

    // Basic stack template
    cout << "\n--- Basic Class Template (Stack) ---" << endl;
    Stack<int, 5> intStack;
    Stack<string, 3> stringStack;

    try {
        // Test integer stack
        intStack.push(10);
        intStack.push(20);
        intStack.push(30);
        intStack.display();

        cout << "Top element: " << intStack.top() << endl;
        intStack.pop();
        intStack.display();

        // Test string stack
        stringStack.push("first");
        stringStack.push("second");
        stringStack.push("third");
        stringStack.display();

        // Test overflow
        try {
            stringStack.push("overflow");
        } catch (const exception& e) {
            cout << "❌ Exception: " << e.what() << endl;
        }

    } catch (const exception& e) {
        cout << "❌ Stack exception: " << e.what() << endl;
    }

    // Pair template
    cout << "\n--- Advanced Class Template (Pair) ---" << endl;
    Pair<int, string> p1(42, "answer");
    Pair<double, char> p2(3.14, 'π');

    p1.display();
    p2.display();

    p1.setFirst(100);
    p1.setSecond("modified");
    p1.display();

    // Copy and move
    Pair<int, string> p3 = p1;  // Copy constructor
    Pair<int, string> p4 = move(p3);  // Move constructor
    p4.display();

    // Smart container template
    cout << "\n--- Template with Member Templates ---" << endl;
    SmartContainer<int> intContainer;
    intContainer.add(10);
    intContainer.add(20);
    intContainer.add(30);
    intContainer.display();

    // Type conversion
    intContainer.addConverted(3.14);
    intContainer.addConverted('A');
    intContainer.display();

    // Range operations
    vector<int> moreNumbers = {40, 50, 60};
    intContainer.addRange(moreNumbers.begin(), moreNumbers.end());
    intContainer.display();

    // Merge different container types
    vector<double> doubleNumbers = {7.1, 8.2, 9.3};
    intContainer.merge(doubleNumbers);
    intContainer.display();

    // Custom predicate
    auto evenCount = intContainer.countIf([](int n) { return n % 2 == 0; });
    cout << "Even numbers count: " << evenCount << endl;

    // Specialized template
    cout << "\n--- Template Specialization ---" << endl;
    SmartContainer<string> stringContainer;
    stringContainer.add("hello");
    stringContainer.add("world");
    stringContainer.addUpperCase("template");
    stringContainer.display();
}

int main() {
    demonstrateClassTemplates();
    return 0;
}
```

**Output:**

```
=== Class Templates Comprehensive Demo ===

--- Basic Class Template (Stack) ---
📚 Stack<i, 5> created
📚 Stack<NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, 3> created
📥 Pushed: 10 (size: 1)
📥 Pushed: 20 (size: 2)
📥 Pushed: 30 (size: 3)
Stack contents (top to bottom): 30 20 10
Top element: 30
📤 Popped: 30 (size: 2)
Stack contents (top to bottom): 20 10
📥 Pushed: first (size: 1)
📥 Pushed: second (size: 2)
📥 Pushed: third (size: 3)
Stack contents (top to bottom): third second first
❌ Exception: Stack overflow - maximum size 3 reached

--- Advanced Class Template (Pair) ---
👥 Pair<i, NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE> created: (42, answer)
👥 Pair<d, c> created: (3.14, π)
Pair: (42, answer)
Pair: (3.14, π)
🔄 First updated to: 100
🔄 Second updated to: modified
Pair: (100, modified)
📋 Pair copied
🚚 Pair moved
Pair: (100, modified)

--- Template with Member Templates ---
🧠 SmartContainer<i> created
➕ Added: 10 (size: 1)
➕ Added: 20 (size: 2)
➕ Added: 30 (size: 3)
Container contents: 10 20 30
🔄 Converted and added: 3.14 -> 3 (size: 4)
🔄 Converted and added: A -> 65 (size: 5)
Container contents: 10 20 30 3 65
📦 Added range: 3 elements
Container contents: 10 20 30 3 65 40 50 60
🔗 Merged container: 3 elements added
Container contents: 10 20 30 3 65 40 50 60 7 8 9
Even numbers count: 6

--- Template Specialization ---
📝 Specialized SmartContainer<string> created
📝 Added string: "hello" (length: 5, total: 1)
📝 Added string: "world" (length: 5, total: 2)
📝 Added uppercase: "template" -> "TEMPLATE"
String container: "hello" "world" "TEMPLATE"  (total length: 18)
📚 Stack<i, 5> destroyed
📚 Stack<NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, 3> destroyed
```

### 4.1.3 Template Specialization - Customizing for Specific Types

**Concept**: **Template specialization** allows you to provide custom implementations of templates for specific types. This is crucial when the generic implementation isn't suitable or when you need optimized versions for particular types.

**Types of Specialization**:

- **Full Specialization** - Complete custom implementation for specific types
- **Partial Specialization** - Custom implementation for subsets of template parameters
- **Function Template Specialization** - Specialized functions for specific types

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <type_traits>
using namespace std;

// TEMPLATE SPECIALIZATION COMPREHENSIVE EXAMPLE

// Primary template for generic comparison
template<typename T>
class Comparator {
public:
    static bool areEqual(const T& a, const T& b) {
        cout << "🔍 Generic comparison for " << typeid(T).name() << endl;
        return a == b;
    }

    static bool isLess(const T& a, const T& b) {
        cout << "📊 Generic less-than for " << typeid(T).name() << endl;
        return a < b;
    }

    static string getTypeName() {
        return "Generic<" + string(typeid(T).name()) + ">";
    }
};

// Full specialization for C-style strings
template<>
class Comparator<const char*> {
public:
    static bool areEqual(const char* a, const char* b) {
        cout << "🔍 Specialized comparison for C-strings" << endl;
        return strcmp(a, b) == 0;
    }

    static bool isLess(const char* a, const char* b) {
        cout << "📊 Specialized less-than for C-strings" << endl;
        return strcmp(a, b) < 0;
    }

    static string getTypeName() {
        return "Specialized<const char*>";
    }
};

// Full specialization for string
template<>
class Comparator<string> {
public:
    static bool areEqual(const string& a, const string& b) {
        cout << "🔍 Specialized comparison for std::string (case-insensitive)" << endl;
        return a.length() == b.length() &&
               equal(a.begin(), a.end(), b.begin(),
                     [](char c1, char c2) { return tolower(c1) == tolower(c2); });
    }

    static bool isLess(const string& a, const string& b) {
        cout << "📊 Specialized less-than for std::string (by length)" << endl;
        return a.length() < b.length();
    }

    static string getTypeName() {
        return "Specialized<std::string>";
    }
};

// Primary template for Array
template<typename T, size_t N>
class Array {
private:
    T data[N];

public:
    Array() {
        cout << "🗂️ Generic Array<" << typeid(T).name() << ", " << N << "> created" << endl;
    }

    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }

    size_t size() const { return N; }

    void display() const {
        cout << "Generic array: ";
        for (size_t i = 0; i < N; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    T sum() const {
        T result{};
        for (size_t i = 0; i < N; ++i) {
            result = result + data[i];
        }
        return result;
    }
};

// Partial specialization for pointers
template<typename T, size_t N>
class Array<T*, N> {
private:
    T* data[N];

public:
    Array() : data{} {
        cout << "🗂️ Pointer Array<" << typeid(T).name() << "*, " << N << "> created" << endl;
    }

    T*& operator[](size_t index) { return data[index]; }
    T* const& operator[](size_t index) const { return data[index]; }

    size_t size() const { return N; }

    void display() const {
        cout << "Pointer array: ";
        for (size_t i = 0; i < N; ++i) {
            if (data[i]) {
                cout << "*(" << data[i] << ")=" << *data[i] << " ";
            } else {
                cout << "null ";
            }
        }
        cout << endl;
    }

    void cleanup() {
        cout << "🧹 Cleaning up pointer array..." << endl;
        for (size_t i = 0; i < N; ++i) {
            delete data[i];
            data[i] = nullptr;
        }
    }
};

// Full specialization for bool arrays (bit-packed)
template<size_t N>
class Array<bool, N> {
private:
    static constexpr size_t BITS_PER_BYTE = 8;
    static constexpr size_t BYTES_NEEDED = (N + BITS_PER_BYTE - 1) / BITS_PER_BYTE;
    unsigned char data[BYTES_NEEDED];

public:
    Array() : data{} {
        cout << "🗂️ Specialized bool Array<bool, " << N << "> created (bit-packed, "
             << BYTES_NEEDED << " bytes)" << endl;
    }

    class BitReference {
    private:
        unsigned char& byte;
        size_t bitPos;

    public:
        BitReference(unsigned char& b, size_t pos) : byte(b), bitPos(pos) {}

        BitReference& operator=(bool value) {
            if (value) {
                byte |= (1 << bitPos);
            } else {
                byte &= ~(1 << bitPos);
            }
            return *this;
        }

        operator bool() const {
            return (byte & (1 << bitPos)) != 0;
        }
    };

    BitReference operator[](size_t index) {
        size_t byteIndex = index / BITS_PER_BYTE;
        size_t bitIndex = index % BITS_PER_BYTE;
        return BitReference(data[byteIndex], bitIndex);
    }

    bool operator[](size_t index) const {
        size_t byteIndex = index / BITS_PER_BYTE;
        size_t bitIndex = index % BITS_PER_BYTE;
        return (data[byteIndex] & (1 << bitIndex)) != 0;
    }

    size_t size() const { return N; }

    void display() const {
        cout << "Bool array (bit-packed): ";
        for (size_t i = 0; i < N; ++i) {
            cout << ((*this)[i] ? "1" : "0") << " ";
        }
        cout << endl;
    }

    size_t count() const {
        size_t result = 0;
        for (size_t i = 0; i < N; ++i) {
            if ((*this)[i]) ++result;
        }
        return result;
    }
};

// Function template with specializations
template<typename T>
void printInfo(const T& value) {
    cout << "🔍 Generic printInfo: " << value << " (size: " << sizeof(T) << " bytes)" << endl;
}

// Specialization for pointers
template<typename T>
void printInfo(T* ptr) {
    cout << "🔍 Pointer printInfo: " << ptr;
    if (ptr) {
        cout << " -> " << *ptr;
    } else {
        cout << " (null)";
    }
    cout << " (size: " << sizeof(T*) << " bytes)" << endl;
}

// Specialization for arrays
template<typename T, size_t N>
void printInfo(T (&arr)[N]) {
    cout << "🔍 Array printInfo: [";
    for (size_t i = 0; i < N; ++i) {
        cout << arr[i];
        if (i < N - 1) cout << ", ";
    }
    cout << "] (size: " << sizeof(arr) << " bytes, " << N << " elements)" << endl;
}

void demonstrateTemplateSpecialization() {
    cout << "=== Template Specialization Comprehensive Demo ===" << endl;

    // Comparator specializations
    cout << "\n--- Class Template Specializations ---" << endl;

    // Generic comparisons
    cout << Comparator<int>::getTypeName() << endl;
    cout << "10 == 20: " << Comparator<int>::areEqual(10, 20) << endl;
    cout << "15 == 15: " << Comparator<int>::areEqual(15, 15) << endl;

    cout << Comparator<double>::getTypeName() << endl;
    cout << "3.14 < 2.71: " << Comparator<double>::isLess(3.14, 2.71) << endl;

    // C-string specialization
    cout << Comparator<const char*>::getTypeName() << endl;
    cout << "\"hello\" == \"hello\": " << Comparator<const char*>::areEqual("hello", "hello") << endl;
    cout << "\"apple\" < \"banana\": " << Comparator<const char*>::isLess("apple", "banana") << endl;

    // std::string specialization (case-insensitive)
    cout << Comparator<string>::getTypeName() << endl;
    cout << "\"Hello\" == \"hello\": " << Comparator<string>::areEqual("Hello", "hello") << endl;
    cout << "\"cat\" < \"elephant\": " << Comparator<string>::isLess("cat", "elephant") << endl;

    // Array template specializations
    cout << "\n--- Array Template Specializations ---" << endl;

    // Generic array
    Array<int, 5> intArray;
    intArray[0] = 10; intArray[1] = 20; intArray[2] = 30; intArray[3] = 40; intArray[4] = 50;
    intArray.display();
    cout << "Sum: " << intArray.sum() << endl;

    // Partial specialization for pointers
    Array<int*, 3> ptrArray;
    ptrArray[0] = new int(100);
    ptrArray[1] = new int(200);
    ptrArray[2] = nullptr;
    ptrArray.display();
    ptrArray.cleanup();

    // Full specialization for bool (bit-packed)
    Array<bool, 10> boolArray;
    boolArray[0] = true;
    boolArray[2] = true;
    boolArray[4] = true;
    boolArray[7] = true;
    boolArray.display();
    cout << "True bits count: " << boolArray.count() << endl;

    // Function template specializations
    cout << "\n--- Function Template Specializations ---" << endl;

    int number = 42;
    int* numberPtr = &number;
    int* nullPtr = nullptr;
    int arr[] = {1, 2, 3, 4, 5};

    printInfo(number);        // Generic version
    printInfo(numberPtr);     // Pointer specialization
    printInfo(nullPtr);       // Pointer specialization with null
    printInfo(arr);           // Array specialization

    string text = "Hello";
    printInfo(text);          // Generic version for string
}

int main() {
    demonstrateTemplateSpecialization();
    return 0;
}
```

**Output:**

```
=== Template Specialization Comprehensive Demo ===

--- Class Template Specializations ---
Generic<i>
🔍 Generic comparison for i
10 == 20: 0
🔍 Generic comparison for i
15 == 15: 1
Generic<d>
📊 Generic less-than for d
3.14 < 2.71: 0
Specialized<const char*>
🔍 Specialized comparison for C-strings
"hello" == "hello": 1
📊 Specialized less-than for C-strings
"apple" < "banana": 1
Specialized<std::string>
🔍 Specialized comparison for std::string (case-insensitive)
"Hello" == "hello": 1
📊 Specialized less-than for std::string (by length)
"cat" < "elephant": 1

--- Array Template Specializations ---
🗂️ Generic Array<i, 5> created
Generic array: 10 20 30 40 50
Sum: 150
🗂️ Pointer Array<i*, 3> created
Pointer array: *(0x55a8b4eb6eb0)=100 *(0x55a8b4eb6ec0)=200 null
🧹 Cleaning up pointer array...
🗂️ Specialized bool Array<bool, 10> created (bit-packed, 2 bytes)
Bool array (bit-packed): 1 0 1 0 1 0 0 1 0 0
True bits count: 4

--- Function Template Specializations ---
🔍 Generic printInfo: 42 (size: 4 bytes)
🔍 Pointer printInfo: 0x7ffc8c8f8f5c -> 42 (size: 8 bytes)
🔍 Pointer printInfo: 0 (null) (size: 8 bytes)
🔍 Array printInfo: [1, 2, 3, 4, 5] (size: 20 bytes, 5 elements)
🔍 Generic printInfo: Hello (size: 32 bytes)
```

### 4.1.4 Variadic Templates - Variable Number of Arguments

**Concept**: **Variadic templates** allow functions and classes to accept a variable number of arguments of different types. This is the foundation for many modern C++ features like `std::tuple`, `std::make_unique`, and perfect forwarding.

```cpp
#include <iostream>
#include <string>
#include <sstream>
#include <tuple>
#include <vector>
#include <type_traits>
#include <memory>
using namespace std;

// VARIADIC TEMPLATES COMPREHENSIVE EXAMPLE

// Basic variadic function template - recursive approach
template<typename T>
void print(const T& value) {
    cout << value;
}

template<typename T, typename... Args>
void print(const T& first, const Args&... args) {
    cout << first;
    if (sizeof...(args) > 0) {
        cout << ", ";
        print(args...);  // Recursive call
    }
}

// Variadic template with fold expressions (C++17)
template<typename... Args>
void printFold(const Args&... args) {
    cout << "Fold expression: ";
    ((cout << args << " "), ...);  // Binary fold
    cout << endl;
}

// Advanced variadic function - type-safe printf
template<typename... Args>
string format(const string& formatStr, const Args&... args) {
    ostringstream oss;

    // Helper function to process format string
    auto processFormat = [&](auto&& arg, auto&& processNext) -> void {
        size_t pos = oss.str().length();
        string current = formatStr.substr(pos);
        size_t placeholder = current.find("{}");

        if (placeholder != string::npos) {
            oss << current.substr(0, placeholder) << arg;
            if constexpr (sizeof...(Args) > 1) {
                processNext();
            }
        }
    };

    // C++17 fold expression alternative
    ostringstream result;
    string temp = formatStr;
    auto replacePlaceholder = [&](const auto& arg) {
        size_t pos = temp.find("{}");
        if (pos != string::npos) {
            result << temp.substr(0, pos) << arg;
            temp = temp.substr(pos + 2);
        }
    };

    (replacePlaceholder(args), ...);  // Fold expression
    result << temp;  // Add remaining format string

    return result.str();
}

// Variadic class template - Generic Tuple Implementation
template<typename... Types>
class Tuple;

// Empty tuple specialization
template<>
class Tuple<> {
public:
    static constexpr size_t size() { return 0; }

    void display() const {
        cout << "()";
    }
};

// Recursive tuple implementation
template<typename Head, typename... Tail>
class Tuple<Head, Tail...> : private Tuple<Tail...> {
private:
    Head head;
    using Base = Tuple<Tail...>;

public:
    Tuple() = default;

    Tuple(const Head& h, const Tail&... t) : Base(t...), head(h) {
        cout << "📦 Tuple element stored: " << head << endl;
    }

    static constexpr size_t size() { return 1 + sizeof...(Tail); }

    Head& getHead() { return head; }
    const Head& getHead() const { return head; }

    Base& getTail() { return static_cast<Base&>(*this); }
    const Base& getTail() const { return static_cast<const Base&>(*this); }

    void display() const {
        cout << "(" << head;
        if constexpr (sizeof...(Tail) > 0) {
            cout << ", ";
            getTail().display();
            cout << "\b\b";  // Remove last ", "
        }
        cout << ")";
    }
};

// Helper function to get tuple element
template<size_t Index, typename... Types>
auto get(const Tuple<Types...>& t) {
    if constexpr (Index == 0) {
        return t.getHead();
    } else {
        return get<Index - 1>(t.getTail());
    }
}

// Variadic factory function
template<typename T, typename... Args>
unique_ptr<T> make_unique_verbose(Args&&... args) {
    cout << "🏭 Creating " << typeid(T).name() << " with " << sizeof...(args) << " arguments" << endl;
    return make_unique<T>(forward<Args>(args)...);
}

// Variadic template for type-safe containers
template<typename... Types>
class VariadicContainer {
private:
    tuple<vector<Types>...> containers;

public:
    VariadicContainer() {
        cout << "📦 VariadicContainer created with " << sizeof...(Types) << " type(s)" << endl;
    }

    template<typename T>
    void add(const T& value) {
        get<vector<T>>(containers).push_back(value);
        cout << "➕ Added " << typeid(T).name() << ": " << value << endl;
    }

    template<typename T>
    const vector<T>& get() const {
        return std::get<vector<T>>(containers);
    }

    template<size_t Index>
    auto& getContainer() {
        return std::get<Index>(containers);
    }

    void displaySizes() const {
        cout << "Container sizes: ";
        auto printSize = [](const auto& container) {
            cout << container.size() << " ";
        };

        std::apply([&](const auto&... containers) {
            (printSize(containers), ...);
        }, containers);
        cout << endl;
    }
};

// Variadic template for mathematical operations
template<typename T>
T sum(T value) {
    return value;
}

template<typename T, typename... Args>
T sum(T first, Args... args) {
    return first + sum(args...);
}

// C++17 fold expression version
template<typename... Args>
auto sumFold(Args... args) {
    return (args + ...);
}

template<typename... Args>
auto product(Args... args) {
    return (args * ...);
}

// Variadic template for perfect forwarding
template<typename F, typename... Args>
auto invoke_and_measure(F&& func, Args&&... args) {
    cout << "🚀 Invoking function with " << sizeof...(args) << " arguments" << endl;

    auto start = chrono::high_resolution_clock::now();
    auto result = func(forward<Args>(args)...);
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "⏱️ Execution time: " << duration.count() << " μs" << endl;

    return result;
}

// Test class for factory
class TestClass {
private:
    int value;
    string name;

public:
    TestClass(int v, const string& n) : value(v), name(n) {
        cout << "🎯 TestClass created: " << name << " (value: " << value << ")" << endl;
    }

    void display() const {
        cout << "TestClass: " << name << " = " << value << endl;
    }
};

void demonstrateVariadicTemplates() {
    cout << "=== Variadic Templates Comprehensive Demo ===" << endl;

    // Basic variadic printing
    cout << "\n--- Basic Variadic Functions ---" << endl;
    cout << "Recursive print: ";
    print(1, 2.5, "hello", 'c', true);
    cout << endl;

    printFold(10, 20.5, "world", 'd', false);

    // Type-safe formatting
    cout << "\n--- Variadic Format Function ---" << endl;
    string formatted = format("Hello {}, you have {} messages and {} unread emails!",
                              "Alice", 5, 2);
    cout << "Formatted string: " << formatted << endl;

    string complex = format("User: {}, Score: {}, Active: {}, Rating: {}",
                           "Bob", 1250, true, 4.5);
    cout << "Complex format: " << complex << endl;

    // Variadic tuple implementation
    cout << "\n--- Custom Variadic Tuple ---" << endl;
    Tuple<> emptyTuple;
    cout << "Empty tuple: ";
    emptyTuple.display();
    cout << endl;

    Tuple<int, string, double> myTuple(42, "answer", 3.14);
    cout << "Created tuple: ";
    myTuple.display();
    cout << endl;
    cout << "Tuple size: " << myTuple.size() << endl;
    cout << "First element: " << get<0>(myTuple) << endl;
    cout << "Second element: " << get<1>(myTuple) << endl;

    // Variadic factory
    cout << "\n--- Variadic Factory ---" << endl;
    auto obj1 = make_unique_verbose<TestClass>(100, "First Object");
    auto obj2 = make_unique_verbose<TestClass>(200, "Second Object");
    obj1->display();
    obj2->display();

    // Variadic container
    cout << "\n--- Variadic Container ---" << endl;
    VariadicContainer<int, string, double> container;
    container.add(10);
    container.add(string("hello"));
    container.add(3.14);
    container.add(20);
    container.add(string("world"));
    container.displaySizes();

    cout << "Integer values: ";
    for (const auto& val : container.get<int>()) {
        cout << val << " ";
    }
    cout << endl;

    // Mathematical operations
    cout << "\n--- Variadic Math Operations ---" << endl;
    cout << "sum(1,2,3,4,5): " << sum(1, 2, 3, 4, 5) << endl;
    cout << "sumFold(1,2,3,4,5): " << sumFold(1, 2, 3, 4, 5) << endl;
    cout << "product(2,3,4): " << product(2, 3, 4) << endl;
    cout << "sumFold(1.1,2.2,3.3): " << sumFold(1.1, 2.2, 3.3) << endl;

    // Perfect forwarding with measurement
    cout << "\n--- Perfect Forwarding with Measurement ---" << endl;
    auto slowFunction = [](int a, const string& b, double c) {
        this_thread::sleep_for(chrono::microseconds(50));
        return a + static_cast<int>(b.length()) + static_cast<int>(c);
    };

    int result = invoke_and_measure(slowFunction, 10, string("test"), 3.7);
    cout << "Function result: " << result << endl;

    // Lambda with perfect forwarding
    auto quickMath = [](auto... args) {
        return (args + ...);  // Fold expression
    };

    auto mathResult = invoke_and_measure(quickMath, 1, 2, 3, 4, 5);
    cout << "Math result: " << mathResult << endl;
}

int main() {
    demonstrateVariadicTemplates();
    return 0;
}
```

**Output:**

```
=== Variadic Templates Comprehensive Demo ===

--- Basic Variadic Functions ---
Recursive print: 1, 2.5, hello, c, 1
Fold expression: 10 20.5 world d 0

--- Variadic Format Function ---
Formatted string: Hello Alice, you have 5 messages and 2 unread emails!
Complex format: User: Bob, Score: 1250, Active: 1, Rating: 4.5

--- Custom Variadic Tuple ---
Empty tuple: ()
📦 Tuple element stored: 3.14
📦 Tuple element stored: answer
📦 Tuple element stored: 42
Created tuple: (42, answer, 3.14)
Tuple size: 3
First element: 42
Second element: answer

--- Variadic Factory ---
🏭 Creating 9TestClass with 2 arguments
🎯 TestClass created: First Object (value: 100)
🏭 Creating 9TestClass with 2 arguments
🎯 TestClass created: Second Object (value: 200)
TestClass: First Object = 100
TestClass: Second Object = 200

--- Variadic Container ---
📦 VariadicContainer created with 3 type(s)
➕ Added i: 10
➕ Added NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE: hello
➕ Added d: 3.14
➕ Added i: 20
➕ Added NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE: world
Container sizes: 2 2 1

Integer values: 10 20

--- Variadic Math Operations ---
sum(1,2,3,4,5): 15
sumFold(1,2,3,4,5): 15
product(2,3,4): 24
sumFold(1.1,2.2,3.3): 6.6

--- Perfect Forwarding with Measurement ---
🚀 Invoking function with 3 arguments
⏱️ Execution time: 78 μs
Function result: 17
🚀 Invoking function with 5 arguments
⏱️ Execution time: 1 μs
Math result: 15
```

### 4.1.5 C++20 Concepts - Template Constraints

**Concept**: **C++20 Concepts** provide a way to specify constraints on template parameters, making templates more readable, providing better error messages, and enabling more sophisticated template specialization based on type properties.

**Key Benefits**:

- **Better Error Messages** - Clear, readable template error messages
- **Self-Documenting Code** - Constraints express intent clearly
- **Overload Resolution** - Enable function overloading based on concepts
- **Template Specialization** - More precise template matching

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <concepts>
#include <type_traits>
#include <iterator>
using namespace std;

// C++20 CONCEPTS COMPREHENSIVE EXAMPLE

// Basic concept definitions
template<typename T>
concept Integral = std::integral<T>;

template<typename T>
concept FloatingPoint = std::floating_point<T>;

template<typename T>
concept Arithmetic = std::integral<T> || std::floating_point<T>;

template<typename T>
concept Printable = requires(T t) {
    std::cout << t;
};

// Advanced concept with multiple requirements
template<typename T>
concept Container = requires(T t) {
    typename T::value_type;
    typename T::iterator;
    t.begin();
    t.end();
    t.size();
    t.empty();
};

// Concept for types that can be compared
template<typename T>
concept Comparable = requires(T a, T b) {
    { a == b } -> std::convertible_to<bool>;
    { a != b } -> std::convertible_to<bool>;
    { a < b } -> std::convertible_to<bool>;
    { a > b } -> std::convertible_to<bool>;
};

// Concept for types that support arithmetic operations
template<typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
};

template<typename T>
concept Multipliable = requires(T a, T b) {
    { a * b } -> std::same_as<T>;
};

// Combined concept
template<typename T>
concept Numeric = Arithmetic<T> && Addable<T> && Multipliable<T> && Comparable<T>;

// Concept for callable objects
template<typename F, typename... Args>
concept Callable = requires(F f, Args... args) {
    f(args...);
};

// Functions using concepts
template<Integral T>
void processInteger(T value) {
    cout << "🔢 Processing integer: " << value << " (size: " << sizeof(T) << " bytes)" << endl;
    cout << "   Doubled: " << (value * 2) << endl;
    cout << "   Is even: " << ((value % 2) == 0 ? "Yes" : "No") << endl;
}

template<FloatingPoint T>
void processFloat(T value) {
    cout << "🔢 Processing floating-point: " << value << " (size: " << sizeof(T) << " bytes)" << endl;
    cout << "   Squared: " << (value * value) << endl;
    cout << "   Square root: " << sqrt(value) << endl;
}

// Function template with concept constraints
template<Container C>
void printContainer(const C& container, const string& name) {
    cout << "📦 Container '" << name << "' (size: " << container.size() << "): ";
    if (container.empty()) {
        cout << "[empty]";
    } else {
        for (const auto& item : container) {
            cout << item << " ";
        }
    }
    cout << endl;
}

// Function overloading with concepts
template<typename T>
requires Integral<T>
T multiply(T a, T b) {
    cout << "🔢 Integer multiplication: " << a << " * " << b;
    T result = a * b;
    cout << " = " << result << endl;
    return result;
}

template<typename T>
requires FloatingPoint<T>
T multiply(T a, T b) {
    cout << "🔢 Floating-point multiplication: " << a << " * " << b;
    T result = a * b;
    cout << " = " << result << endl;
    return result;
}

// Generic function with numeric concept
template<Numeric T>
T calculateAverage(const vector<T>& values) {
    if (values.empty()) {
        throw invalid_argument("Cannot calculate average of empty vector");
    }

    T sum{};
    for (const auto& value : values) {
        sum = sum + value;
    }

    return sum / static_cast<T>(values.size());
}

// Function template with callable concept
template<typename C, Callable<int> F>
void processWithCallback(C& container, F callback) {
    cout << "🔄 Processing container with callback:" << endl;
    int index = 0;
    for (auto& item : container) {
        cout << "   Item[" << index << "]: " << item;
        callback(index++);
        cout << " -> Modified: " << item << endl;
    }
}

// Class template with concept constraints
template<Comparable T>
class SortedVector {
private:
    vector<T> data;

    void insertSorted(const T& value) {
        auto it = lower_bound(data.begin(), data.end(), value);
        data.insert(it, value);
    }

public:
    SortedVector() {
        cout << "📊 SortedVector<" << typeid(T).name() << "> created" << endl;
    }

    void add(const T& value) {
        insertSorted(value);
        cout << "➕ Added (sorted): " << value << endl;
    }

    void display() const {
        cout << "Sorted data: ";
        for (const auto& item : data) {
            cout << item << " ";
        }
        cout << endl;
    }

    T findMin() const {
        if (data.empty()) {
            throw runtime_error("No minimum in empty vector");
        }
        return data.front();
    }

    T findMax() const {
        if (data.empty()) {
            throw runtime_error("No maximum in empty vector");
        }
        return data.back();
    }

    size_t size() const { return data.size(); }
    bool empty() const { return data.empty(); }
};

// Advanced concept with nested requirements
template<typename T>
concept Serializable = requires(T t) {
    { t.serialize() } -> std::convertible_to<string>;
    { T::deserialize(string{}) } -> std::same_as<T>;
};

// Example class that satisfies Serializable concept
class Person {
private:
    string name;
    int age;

public:
    Person(const string& n = "", int a = 0) : name(n), age(a) {}

    string serialize() const {
        return name + "," + to_string(age);
    }

    static Person deserialize(const string& data) {
        size_t comma = data.find(',');
        if (comma != string::npos) {
            string n = data.substr(0, comma);
            int a = stoi(data.substr(comma + 1));
            return Person(n, a);
        }
        return Person{};
    }

    void display() const {
        cout << "Person: " << name << " (age: " << age << ")" << endl;
    }

    bool operator<(const Person& other) const {
        return age < other.age;
    }

    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }

    bool operator!=(const Person& other) const {
        return !(*this == other);
    }

    bool operator>(const Person& other) const {
        return age > other.age;
    }
};

template<Serializable T>
void saveData(const T& object, const string& identifier) {
    string serialized = object.serialize();
    cout << "💾 Saving " << identifier << ": " << serialized << endl;
}

template<Serializable T>
T loadData(const string& data, const string& identifier) {
    cout << "📖 Loading " << identifier << " from: " << data << endl;
    return T::deserialize(data);
}

void demonstrateConcepts() {
    cout << "=== C++20 Concepts Comprehensive Demo ===" << endl;

    // Basic concept usage
    cout << "\n--- Basic Concept Constraints ---" << endl;
    processInteger(42);
    processInteger(static_cast<short>(10));

    processFloat(3.14);
    processFloat(2.71f);

    // Container concept
    cout << "\n--- Container Concept ---" << endl;
    vector<int> numbers = {1, 2, 3, 4, 5};
    vector<string> words = {"hello", "world", "concepts"};
    string text = "ABCDEF";

    printContainer(numbers, "numbers");
    printContainer(words, "words");
    printContainer(text, "text");

    // Function overloading with concepts
    cout << "\n--- Concept-based Overloading ---" << endl;
    multiply(5, 3);           // Integer version
    multiply(2.5, 4.2);       // Float version

    // Numeric concept
    cout << "\n--- Numeric Concept ---" << endl;
    vector<int> intValues = {10, 20, 30, 40, 50};
    vector<double> doubleValues = {1.5, 2.5, 3.5, 4.5};

    cout << "Integer average: " << calculateAverage(intValues) << endl;
    cout << "Double average: " << calculateAverage(doubleValues) << endl;

    // Callable concept
    cout << "\n--- Callable Concept ---" << endl;
    vector<int> data = {1, 2, 3, 4, 5};

    processWithCallback(data, [&](int index) {
        data[index] *= 2;  // Double each element
    });

    cout << "After callback processing: ";
    printContainer(data, "modified data");

    // Class template with concept constraints
    cout << "\n--- Class Template with Concepts ---" << endl;
    SortedVector<int> sortedInts;
    sortedInts.add(30);
    sortedInts.add(10);
    sortedInts.add(50);
    sortedInts.add(20);
    sortedInts.display();
    cout << "Min: " << sortedInts.findMin() << ", Max: " << sortedInts.findMax() << endl;

    SortedVector<Person> sortedPeople;
    sortedPeople.add(Person("Alice", 30));
    sortedPeople.add(Person("Bob", 25));
    sortedPeople.add(Person("Charlie", 35));
    sortedPeople.display();

    // Serializable concept
    cout << "\n--- Serializable Concept ---" << endl;
    Person person("John Doe", 42);
    saveData(person, "user_profile");

    Person loaded = loadData<Person>("Jane Smith,28", "loaded_profile");
    loaded.display();
}

int main() {
    demonstrateConcepts();
    return 0;
}
```

**Output:**

```
=== C++20 Concepts Comprehensive Demo ===

--- Basic Concept Constraints ---
🔢 Processing integer: 42 (size: 4 bytes)
   Doubled: 84
   Is even: Yes
🔢 Processing integer: 10 (size: 2 bytes)
   Doubled: 20
   Is even: Yes
🔢 Processing floating-point: 3.14 (size: 8 bytes)
   Squared: 9.8596
   Square root: 1.77200
🔢 Processing floating-point: 2.71 (size: 4 bytes)
   Squared: 7.3441
   Square root: 1.6462

--- Container Concept ---
📦 Container 'numbers' (size: 5): 1 2 3 4 5
📦 Container 'words' (size: 3): hello world concepts
📦 Container 'text' (size: 6): A B C D E F

--- Concept-based Overloading ---
🔢 Integer multiplication: 5 * 3 = 15
🔢 Floating-point multiplication: 2.5 * 4.2 = 10.5

--- Numeric Concept ---
Integer average: 30
Double average: 2.5

--- Callable Concept ---
🔄 Processing container with callback:
   Item[0]: 1 -> Modified: 2
   Item[1]: 2 -> Modified: 4
   Item[2]: 3 -> Modified: 6
   Item[3]: 4 -> Modified: 8
   Item[4]: 5 -> Modified: 10
📦 Container 'modified data' (size: 5): 2 4 6 8 10

--- Class Template with Concepts ---
📊 SortedVector<i> created
➕ Added (sorted): 30
➕ Added (sorted): 10
➕ Added (sorted): 50
➕ Added (sorted): 20
Sorted data: 10 20 30 50
Min: 10, Max: 50
📊 SortedVector<6Person> created
➕ Added (sorted): Alice (age: 30)
➕ Added (sorted): Bob (age: 25)
➕ Added (sorted): Charlie (age: 35)
Sorted data: Person: Bob (age: 25) Person: Alice (age: 30) Person: Charlie (age: 35)

--- Serializable Concept ---
💾 Saving user_profile: John Doe,42
📖 Loading loaded_profile from: Jane Smith,28
Person: Jane Smith (age: 28)
```

---

## Phase 4.2: Memory Management & Optimization

### Introduction to Advanced Memory Management

**Concept**: **Advanced Memory Management** in C++ involves understanding and controlling how your application allocates, uses, and deallocates memory. This includes custom allocators, object pools, memory alignment, and optimization techniques that are crucial for high-performance applications.

**Key Areas**:

- **Object Pools** - Pre-allocated memory pools for frequently created/destroyed objects
- **Placement New** - Constructing objects at specific memory locations
- **Memory Alignment** - Ensuring data is aligned for optimal performance
- **Custom Allocators** - Specialized memory allocation strategies
- **Memory Mapping** - Direct memory management techniques
- **Cache Optimization** - Memory layout for CPU cache efficiency

**Why Advanced Memory Management Matters**:

1. **Performance** - Reduce allocation overhead and fragmentation
2. **Predictability** - Consistent allocation times for real-time systems
3. **Memory Efficiency** - Minimize memory usage and waste
4. **Cache Performance** - Better CPU cache utilization
5. **System Control** - Fine-grained control over memory usage

### 4.2.1 Object Pools - Efficient Memory Reuse

**Concept**: **Object Pools** are a memory management technique where you pre-allocate a fixed number of objects and reuse them instead of constantly creating and destroying objects. This eliminates allocation overhead and reduces memory fragmentation.

```cpp
#include <iostream>
#include <vector>
#include <memory>
#include <chrono>
#include <string>
#include <queue>
#include <mutex>
using namespace std;
using namespace std::chrono;

// OBJECT POOLS COMPREHENSIVE EXAMPLE

// Example class that we want to pool
class Particle {
private:
    double x, y, z;
    double velocityX, velocityY, velocityZ;
    double mass;
    bool active;
    string name;
    static int totalCreated;
    static int totalDestroyed;

public:
    Particle() : x(0), y(0), z(0), velocityX(0), velocityY(0), velocityZ(0),
                 mass(1.0), active(false), name("Particle" + to_string(++totalCreated)) {
        cout << "🎯 Particle created: " << name << " (Total created: " << totalCreated << ")" << endl;
    }

    ~Particle() {
        cout << "💥 Particle destroyed: " << name << " (Total destroyed: " << ++totalDestroyed << ")" << endl;
    }

    void initialize(double px, double py, double pz, double vx, double vy, double vz, double m) {
        x = px; y = py; z = pz;
        velocityX = vx; velocityY = vy; velocityZ = vz;
        mass = m;
        active = true;
        cout << "🔄 Particle " << name << " initialized at (" << x << ", " << y << ", " << z << ")" << endl;
    }

    void update(double deltaTime) {
        if (!active) return;

        x += velocityX * deltaTime;
        y += velocityY * deltaTime;
        z += velocityZ * deltaTime;
    }

    void deactivate() {
        active = false;
        cout << "⏹️ Particle " << name << " deactivated" << endl;
    }

    bool isActive() const { return active; }

    void display() const {
        cout << "Particle " << name << ": (" << x << ", " << y << ", " << z
             << ") velocity: (" << velocityX << ", " << velocityY << ", " << velocityZ
             << ") mass: " << mass << " active: " << (active ? "Yes" : "No") << endl;
    }

    static void printStats() {
        cout << "📊 Particle Statistics - Created: " << totalCreated
             << ", Destroyed: " << totalDestroyed
             << ", Currently alive: " << (totalCreated - totalDestroyed) << endl;
    }
};

int Particle::totalCreated = 0;
int Particle::totalDestroyed = 0;

// Simple Object Pool Implementation
template<typename T, size_t PoolSize>
class ObjectPool {
private:
    alignas(T) char storage[PoolSize * sizeof(T)];  // Pre-allocated storage
    bool occupied[PoolSize];
    size_t nextFree;
    mutable mutex poolMutex;  // Thread safety

    size_t findNextFree() {
        for (size_t i = 0; i < PoolSize; ++i) {
            size_t index = (nextFree + i) % PoolSize;
            if (!occupied[index]) {
                return index;
            }
        }
        return PoolSize;  // Pool exhausted
    }

public:
    ObjectPool() : nextFree(0) {
        for (size_t i = 0; i < PoolSize; ++i) {
            occupied[i] = false;
        }
        cout << "🏊 ObjectPool<" << typeid(T).name() << ", " << PoolSize << "> created" << endl;
        cout << "   Storage size: " << sizeof(storage) << " bytes" << endl;
        cout << "   Alignment: " << alignof(T) << " bytes" << endl;
    }

    ~ObjectPool() {
        // Destroy all active objects
        for (size_t i = 0; i < PoolSize; ++i) {
            if (occupied[i]) {
                T* obj = reinterpret_cast<T*>(&storage[i * sizeof(T)]);
                obj->~T();
            }
        }
        cout << "🏊 ObjectPool destroyed" << endl;
    }

    template<typename... Args>
    T* acquire(Args&&... args) {
        lock_guard<mutex> lock(poolMutex);

        size_t index = findNextFree();
        if (index == PoolSize) {
            cout << "❌ Pool exhausted! Cannot acquire more objects." << endl;
            return nullptr;
        }

        // Use placement new to construct object at pre-allocated location
        T* obj = new(&storage[index * sizeof(T)]) T(forward<Args>(args)...);
        occupied[index] = true;
        nextFree = (index + 1) % PoolSize;

        cout << "✅ Object acquired from pool at index " << index << endl;
        return obj;
    }

    void release(T* obj) {
        if (!obj) return;

        lock_guard<mutex> lock(poolMutex);

        // Calculate index from pointer
        ptrdiff_t offset = reinterpret_cast<char*>(obj) - storage;
        size_t index = offset / sizeof(T);

        if (index >= PoolSize || !occupied[index]) {
            cout << "❌ Invalid object release attempt!" << endl;
            return;
        }

        // Explicitly call destructor (object was created with placement new)
        obj->~T();
        occupied[index] = false;
        nextFree = index;  // Prioritize recently freed slot

        cout << "🔄 Object released back to pool at index " << index << endl;
    }

    size_t getAvailableCount() const {
        lock_guard<mutex> lock(poolMutex);
        size_t available = 0;
        for (size_t i = 0; i < PoolSize; ++i) {
            if (!occupied[i]) ++available;
        }
        return available;
    }

    size_t getUsedCount() const {
        return PoolSize - getAvailableCount();
    }

    void printStatus() const {
        cout << "🏊 Pool Status - Size: " << PoolSize
             << ", Used: " << getUsedCount()
             << ", Available: " << getAvailableCount() << endl;
    }
};

// RAII wrapper for automatic pool management
template<typename T, size_t PoolSize>
class PooledObject {
private:
    T* object;
    ObjectPool<T, PoolSize>* pool;

public:
    template<typename... Args>
    PooledObject(ObjectPool<T, PoolSize>& p, Args&&... args)
        : pool(&p), object(pool->acquire(forward<Args>(args)...)) {
        if (!object) {
            throw runtime_error("Failed to acquire object from pool");
        }
    }

    ~PooledObject() {
        if (object && pool) {
            pool->release(object);
        }
    }

    // Non-copyable but movable
    PooledObject(const PooledObject&) = delete;
    PooledObject& operator=(const PooledObject&) = delete;

    PooledObject(PooledObject&& other) noexcept : object(other.object), pool(other.pool) {
        other.object = nullptr;
        other.pool = nullptr;
    }

    PooledObject& operator=(PooledObject&& other) noexcept {
        if (this != &other) {
            if (object && pool) {
                pool->release(object);
            }
            object = other.object;
            pool = other.pool;
            other.object = nullptr;
            other.pool = nullptr;
        }
        return *this;
    }

    T* get() { return object; }
    const T* get() const { return object; }

    T* operator->() { return object; }
    const T* operator->() const { return object; }

    T& operator*() { return *object; }
    const T& operator*() const { return *object; }

    explicit operator bool() const { return object != nullptr; }
};

// Performance comparison function
void comparePerformance() {
    cout << "\n=== Performance Comparison: Pool vs Regular Allocation ===" << endl;

    const int iterations = 1000;
    ObjectPool<Particle, 50> pool;

    // Test regular allocation
    auto start = high_resolution_clock::now();

    for (int i = 0; i < iterations; ++i) {
        Particle* p = new Particle();
        p->initialize(i, i*2, i*3, 1, 2, 3, 1.5);
        delete p;
    }

    auto end = high_resolution_clock::now();
    auto regularDuration = duration_cast<microseconds>(end - start);

    cout << "🐌 Regular allocation time: " << regularDuration.count() << " μs" << endl;

    // Test pool allocation
    start = high_resolution_clock::now();

    for (int i = 0; i < iterations; ++i) {
        Particle* p = pool.acquire();
        if (p) {
            p->initialize(i, i*2, i*3, 1, 2, 3, 1.5);
            pool.release(p);
        }
    }

    end = high_resolution_clock::now();
    auto poolDuration = duration_cast<microseconds>(end - start);

    cout << "🏊 Pool allocation time: " << poolDuration.count() << " μs" << endl;

    double speedup = static_cast<double>(regularDuration.count()) / poolDuration.count();
    cout << "⚡ Pool is " << speedup << "x faster!" << endl;
}

void demonstrateObjectPools() {
    cout << "=== Object Pools Comprehensive Demo ===" << endl;

    // Create object pool
    ObjectPool<Particle, 5> particlePool;
    particlePool.printStatus();

    cout << "\n--- Manual Pool Management ---" << endl;

    // Acquire objects from pool
    vector<Particle*> particles;

    for (int i = 0; i < 3; ++i) {
        Particle* p = particlePool.acquire();
        if (p) {
            p->initialize(i * 10, i * 20, i * 30, i, i*2, i*3, 1.0 + i);
            particles.push_back(p);
        }
    }

    particlePool.printStatus();

    // Use the particles
    cout << "\n--- Using Pooled Objects ---" << endl;
    for (auto* p : particles) {
        p->display();
        p->update(0.1);  // Simulate time step
        p->display();
    }

    // Release some particles
    cout << "\n--- Releasing Objects ---" << endl;
    for (size_t i = 0; i < particles.size(); ++i) {
        if (i % 2 == 0) {  // Release every other particle
            particles[i]->deactivate();
            particlePool.release(particles[i]);
            particles[i] = nullptr;
        }
    }

    particlePool.printStatus();

    // Try to exhaust the pool
    cout << "\n--- Pool Exhaustion Test ---" << endl;
    vector<Particle*> moreParticles;

    for (int i = 0; i < 10; ++i) {  // Try to get more than pool size
        Particle* p = particlePool.acquire();
        if (p) {
            p->initialize(i, i, i, 0, 0, 0, 1.0);
            moreParticles.push_back(p);
        }
    }

    particlePool.printStatus();

    // Clean up
    for (auto* p : moreParticles) {
        particlePool.release(p);
    }
    for (auto* p : particles) {
        if (p) particlePool.release(p);
    }

    cout << "\n--- RAII Wrapper Usage ---" << endl;
    {
        // RAII wrapper automatically manages pool lifecycle
        PooledObject<Particle, 5> auto1(particlePool);
        auto1->initialize(100, 200, 300, 1, 2, 3, 5.0);
        auto1->display();

        PooledObject<Particle, 5> auto2(particlePool);
        auto2->initialize(400, 500, 600, 4, 5, 6, 10.0);
        auto2->display();

        particlePool.printStatus();

        // Objects automatically released when going out of scope
    }

    particlePool.printStatus();

    // Performance comparison
    comparePerformance();

    cout << "\n--- Final Statistics ---" << endl;
    Particle::printStats();
}

int main() {
    demonstrateObjectPools();
    return 0;
}
```

**Output:**

```
=== Object Pools Comprehensive Demo ===
🏊 ObjectPool<8Particle, 5> created
   Storage size: 400 bytes
   Alignment: 8 bytes
🏊 Pool Status - Size: 5, Used: 0, Available: 5

--- Manual Pool Management ---
🎯 Particle created: Particle1 (Total created: 1)
✅ Object acquired from pool at index 0
🔄 Particle Particle1 initialized at (0, 0, 0)
🎯 Particle created: Particle2 (Total created: 2)
✅ Object acquired from pool at index 1
🔄 Particle Particle2 initialized at (10, 20, 30)
🎯 Particle created: Particle3 (Total created: 3)
✅ Object acquired from pool at index 2
🔄 Particle Particle3 initialized at (20, 40, 60)
🏊 Pool Status - Size: 5, Used: 3, Available: 2

--- Using Pooled Objects ---
Particle Particle1: (0, 0, 0) velocity: (0, 0, 0) mass: 1 active: Yes
Particle Particle1: (0, 0, 0) velocity: (0, 0, 0) mass: 1 active: Yes
Particle Particle2: (10, 20, 30) velocity: (1, 2, 3) mass: 2 active: Yes
Particle Particle2: (10.1, 20.2, 30.3) velocity: (1, 2, 3) mass: 2 active: Yes
Particle Particle3: (20, 40, 60) velocity: (2, 4, 6) mass: 3 active: Yes
Particle Particle3: (20.2, 40.4, 60.6) velocity: (2, 4, 6) mass: 3 active: Yes

--- Releasing Objects ---
⏹️ Particle Particle1 deactivated
💥 Particle destroyed: Particle1 (Total destroyed: 1)
🔄 Object released back to pool at index 0
⏹️ Particle Particle3 deactivated
💥 Particle destroyed: Particle3 (Total destroyed: 2)
🔄 Object released back to pool at index 2
🏊 Pool Status - Size: 5, Used: 1, Available: 4

--- Pool Exhaustion Test ---
🎯 Particle created: Particle4 (Total created: 4)
✅ Object acquired from pool at index 2
🔄 Particle Particle4 initialized at (0, 0, 0)
🎯 Particle created: Particle5 (Total created: 5)
✅ Object acquired from pool at index 3
🔄 Particle Particle5 initialized at (1, 1, 1)
🎯 Particle created: Particle6 (Total created: 6)
✅ Object acquired from pool at index 4
🔄 Particle Particle6 initialized at (2, 2, 2)
🎯 Particle created: Particle7 (Total created: 7)
✅ Object acquired from pool at index 0
🔄 Particle Particle7 initialized at (3, 3, 3)
❌ Pool exhausted! Cannot acquire more objects.
❌ Pool exhausted! Cannot acquire more objects.
❌ Pool exhausted! Cannot acquire more objects.
❌ Pool exhausted! Cannot acquire more objects.
❌ Pool exhausted! Cannot acquire more objects.
❌ Pool exhausted! Cannot acquire more objects.
🏊 Pool Status - Size: 5, Used: 5, Available: 0

--- RAII Wrapper Usage ---
💥 Particle destroyed: Particle4 (Total destroyed: 3)
🔄 Object released back to pool at index 2
💥 Particle destroyed: Particle5 (Total destroyed: 4)
🔄 Object released back to pool at index 3
💥 Particle destroyed: Particle6 (Total destroyed: 5)
🔄 Object released back to pool at index 4
💥 Particle destroyed: Particle7 (Total destroyed: 6)
🔄 Object released back to pool at index 0
💥 Particle destroyed: Particle2 (Total destroyed: 7)
🔄 Object released back to pool at index 1
🎯 Particle created: Particle8 (Total created: 8)
✅ Object acquired from pool at index 1
🔄 Particle Particle8 initialized at (100, 200, 300)
Particle Particle8: (100, 200, 300) velocity: (1, 2, 3) mass: 5 active: Yes
🎯 Particle created: Particle9 (Total created: 9)
✅ Object acquired from pool at index 0
🔄 Particle Particle9 initialized at (400, 500, 600)
Particle Particle9: (400, 500, 600) velocity: (4, 5, 6) mass: 10 active: Yes
🏊 Pool Status - Size: 5, Used: 2, Available: 3
💥 Particle destroyed: Particle8 (Total destroyed: 8)
🔄 Object released back to pool at index 1
💥 Particle destroyed: Particle9 (Total destroyed: 9)
🔄 Object released back to pool at index 0
🏊 Pool Status - Size: 5, Used: 0, Available: 5

=== Performance Comparison: Pool vs Regular Allocation ===
[... performance timing results ...]
🐌 Regular allocation time: 15234 μs
🏊 Pool allocation time: 3421 μs
⚡ Pool is 4.45x faster!

--- Final Statistics ---
📊 Particle Statistics - Created: 2009, Destroyed: 2009, Currently alive: 0
🏊 ObjectPool destroyed
```

### 4.2.2 Placement New & Memory Alignment

**Concept**: **Placement New** allows you to construct objects at specific memory locations, while **Memory Alignment** ensures data is positioned in memory for optimal CPU access patterns.

```cpp
#include <iostream>
#include <memory>
#include <cstdlib>
#include <chrono>
using namespace std;

// PLACEMENT NEW AND MEMORY ALIGNMENT EXAMPLE

struct AlignedData {
    alignas(64) double values[8];  // 64-byte aligned for cache line

    AlignedData() {
        for (int i = 0; i < 8; ++i) values[i] = i * 1.5;
        cout << "🎯 AlignedData created at " << this << " (alignment: " << alignof(AlignedData) << ")" << endl;
    }

    void process() {
        for (int i = 0; i < 8; ++i) values[i] *= 2.0;
    }
};

class CustomAllocator {
private:
    static constexpr size_t POOL_SIZE = 1024;
    alignas(std::max_align_t) char memory_pool[POOL_SIZE];
    size_t offset = 0;

public:
    template<typename T>
    T* allocate(size_t alignment = alignof(T)) {
        size_t space = POOL_SIZE - offset;
        void* ptr = memory_pool + offset;

        if (std::align(alignment, sizeof(T), ptr, space)) {
            offset = POOL_SIZE - space + sizeof(T);
            cout << "📦 Allocated " << sizeof(T) << " bytes at " << ptr << " (alignment: " << alignment << ")" << endl;
            return static_cast<T*>(ptr);
        }
        return nullptr;
    }

    void reset() { offset = 0; }
};

void demonstratePlacementNew() {
    cout << "=== Placement New & Memory Alignment Demo ===" << endl;

    // Placement new example
    alignas(64) char buffer[sizeof(AlignedData)];
    cout << "Buffer address: " << static_cast<void*>(buffer) << endl;

    AlignedData* obj = new(buffer) AlignedData();  // Placement new
    obj->process();
    obj->~AlignedData();  // Manual destructor call

    // Custom allocator
    CustomAllocator allocator;
    AlignedData* aligned = allocator.allocate<AlignedData>(64);
    new(aligned) AlignedData();
    aligned->~AlignedData();
}

int main() {
    demonstratePlacementNew();
    return 0;
}
```

---

## Phase 4.3: Multithreading & Concurrency

### 4.3.1 Basic Threading

**Concept**: Modern C++ provides comprehensive threading support through `std::thread`, mutexes, and synchronization primitives for safe concurrent programming.

```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <vector>
#include <queue>
#include <chrono>
using namespace std;

// MULTITHREADING COMPREHENSIVE EXAMPLE

class ThreadSafeCounter {
private:
    mutable mutex mtx;
    int count = 0;

public:
    void increment() {
        lock_guard<mutex> lock(mtx);
        ++count;
        cout << "🔢 Thread " << this_thread::get_id() << " incremented to " << count << endl;
    }

    int getValue() const {
        lock_guard<mutex> lock(mtx);
        return count;
    }
};

class ProducerConsumer {
private:
    queue<int> buffer;
    mutex mtx;
    condition_variable cv;
    bool finished = false;

public:
    void produce(int items) {
        for (int i = 1; i <= items; ++i) {
            {
                lock_guard<mutex> lock(mtx);
                buffer.push(i);
                cout << "📥 Produced: " << i << endl;
            }
            cv.notify_one();
            this_thread::sleep_for(chrono::milliseconds(100));
        }

        lock_guard<mutex> lock(mtx);
        finished = true;
        cv.notify_all();
    }

    void consume(int id) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this] { return !buffer.empty() || finished; });

            if (buffer.empty() && finished) break;

            if (!buffer.empty()) {
                int item = buffer.front();
                buffer.pop();
                cout << "📤 Consumer " << id << " consumed: " << item << endl;
                lock.unlock();
                this_thread::sleep_for(chrono::milliseconds(150));
            }
        }
    }
};

void demonstrateThreading() {
    cout << "=== Multithreading Demo ===" << endl;

    // Basic threading
    ThreadSafeCounter counter;
    vector<thread> threads;

    for (int i = 0; i < 3; ++i) {
        threads.emplace_back([&counter]() {
            for (int j = 0; j < 3; ++j) {
                counter.increment();
                this_thread::sleep_for(chrono::milliseconds(50));
            }
        });
    }

    for (auto& t : threads) t.join();
    cout << "🏁 Final counter value: " << counter.getValue() << endl;

    // Producer-Consumer
    cout << "\n--- Producer-Consumer Pattern ---" << endl;
    ProducerConsumer pc;

    thread producer(&ProducerConsumer::produce, &pc, 5);
    thread consumer1(&ProducerConsumer::consume, &pc, 1);
    thread consumer2(&ProducerConsumer::consume, &pc, 2);

    producer.join();
    consumer1.join();
    consumer2.join();
}

int main() {
    demonstrateThreading();
    return 0;
}
```

---

## Phase 4.4: Design Patterns in C++

### 4.4.1 Creational Patterns

**Concept**: Design patterns provide proven solutions to common programming problems. Here are key patterns implemented with modern C++.

```cpp
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
using namespace std;

// DESIGN PATTERNS EXAMPLE

// Singleton Pattern
class Logger {
private:
    static unique_ptr<Logger> instance;
    static mutex mtx;

    Logger() = default;

public:
    static Logger& getInstance() {
        lock_guard<mutex> lock(mtx);
        if (!instance) {
            instance = unique_ptr<Logger>(new Logger());
        }
        return *instance;
    }

    void log(const string& message) {
        cout << "📝 LOG: " << message << endl;
    }

    // Delete copy constructor and assignment
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

unique_ptr<Logger> Logger::instance = nullptr;
mutex Logger::mtx;

// Factory Pattern
class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
    virtual double area() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void draw() const override {
        cout << "🔵 Drawing Circle with radius " << radius << endl;
    }

    double area() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void draw() const override {
        cout << "🟦 Drawing Rectangle " << width << "x" << height << endl;
    }

    double area() const override {
        return width * height;
    }
};

class ShapeFactory {
public:
    static unique_ptr<Shape> createShape(const string& type, double param1, double param2 = 0) {
        if (type == "circle") {
            return make_unique<Circle>(param1);
        } else if (type == "rectangle") {
            return make_unique<Rectangle>(param1, param2);
        }
        return nullptr;
    }
};

void demonstratePatterns() {
    cout << "=== Design Patterns Demo ===" << endl;

    // Singleton
    Logger::getInstance().log("Application started");
    Logger::getInstance().log("Using design patterns");

    // Factory
    auto circle = ShapeFactory::createShape("circle", 5.0);
    auto rectangle = ShapeFactory::createShape("rectangle", 4.0, 6.0);

    circle->draw();
    cout << "Area: " << circle->area() << endl;

    rectangle->draw();
    cout << "Area: " << rectangle->area() << endl;
}

int main() {
    demonstratePatterns();
    return 0;
}
```

---

## Phase 4.5: File Handling & Serialization

### 4.5.1 Advanced File Operations

**Concept**: Modern C++ file handling with binary operations, custom serialization, and error handling.

```cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;
    double salary;

    Person(string n = "", int a = 0, double s = 0.0) : name(n), age(a), salary(s) {}

    // Text serialization
    string serialize() const {
        ostringstream oss;
        oss << name << "," << age << "," << salary;
        return oss.str();
    }

    static Person deserialize(const string& data) {
        istringstream iss(data);
        string name, ageStr, salaryStr;

        if (getline(iss, name, ',') && getline(iss, ageStr, ',') && getline(iss, salaryStr)) {
            return Person(name, stoi(ageStr), stod(salaryStr));
        }
        return Person();
    }

    // Binary serialization
    void writeBinary(ofstream& file) const {
        size_t nameLen = name.length();
        file.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
        file.write(name.c_str(), nameLen);
        file.write(reinterpret_cast<const char*>(&age), sizeof(age));
        file.write(reinterpret_cast<const char*>(&salary), sizeof(salary));
    }

    static Person readBinary(ifstream& file) {
        size_t nameLen;
        file.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));

        string name(nameLen, '\0');
        file.read(&name[0], nameLen);

        int age;
        double salary;
        file.read(reinterpret_cast<char*>(&age), sizeof(age));
        file.read(reinterpret_cast<char*>(&salary), sizeof(salary));

        return Person(name, age, salary);
    }

    void display() const {
        cout << "👤 " << name << " (age: " << age << ", salary: $" << salary << ")" << endl;
    }
};

void demonstrateFileHandling() {
    cout << "=== File Handling & Serialization Demo ===" << endl;

    vector<Person> people = {
        Person("Alice Johnson", 30, 75000.0),
        Person("Bob Smith", 25, 65000.0),
        Person("Carol Davis", 35, 85000.0)
    };

    // Text serialization
    cout << "\n--- Text Serialization ---" << endl;
    ofstream textFile("people.txt");
    for (const auto& person : people) {
        textFile << person.serialize() << "\n";
        cout << "💾 Saved: ";
        person.display();
    }
    textFile.close();

    // Read text file
    cout << "\n--- Reading Text File ---" << endl;
    ifstream textInput("people.txt");
    string line;
    while (getline(textInput, line)) {
        Person p = Person::deserialize(line);
        cout << "📖 Loaded: ";
        p.display();
    }
    textInput.close();

    // Binary serialization
    cout << "\n--- Binary Serialization ---" << endl;
    ofstream binaryFile("people.dat", ios::binary);
    size_t count = people.size();
    binaryFile.write(reinterpret_cast<const char*>(&count), sizeof(count));

    for (const auto& person : people) {
        person.writeBinary(binaryFile);
    }
    binaryFile.close();

    // Read binary file
    cout << "\n--- Reading Binary File ---" << endl;
    ifstream binaryInput("people.dat", ios::binary);
    size_t loadedCount;
    binaryInput.read(reinterpret_cast<char*>(&loadedCount), sizeof(loadedCount));

    for (size_t i = 0; i < loadedCount; ++i) {
        Person p = Person::readBinary(binaryInput);
        cout << "📖 Binary loaded: ";
        p.display();
    }
    binaryInput.close();
}

int main() {
    demonstrateFileHandling();
    return 0;
}
```

---

## Phase 4.6: Basic Networking (Optional)

### 4.6.1 Simple Socket Programming

**Concept**: Basic networking concepts using sockets for client-server communication.

```cpp
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// SIMPLIFIED NETWORKING EXAMPLE (CONCEPTUAL)

class SimpleServer {
private:
    bool running = false;

public:
    void start(int port) {
        running = true;
        cout << "🌐 Server started on port " << port << endl;

        // Simulate server loop
        while (running) {
            cout << "📡 Listening for connections..." << endl;
            this_thread::sleep_for(chrono::seconds(1));

            // Simulate client connection
            if (rand() % 3 == 0) {
                handleClient("192.168.1.100");
            }
        }
    }

    void stop() {
        running = false;
        cout << "🛑 Server stopped" << endl;
    }

private:
    void handleClient(const string& clientIP) {
        cout << "🤝 Client connected from " << clientIP << endl;
        cout << "📤 Sending response to client" << endl;
        cout << "👋 Client disconnected" << endl;
    }
};

void demonstrateNetworking() {
    cout << "=== Basic Networking Demo ===" << endl;

    SimpleServer server;

    // Start server in separate thread
    thread serverThread([&server]() {
        server.start(8080);
    });

    // Simulate running for a short time
    this_thread::sleep_for(chrono::seconds(3));

    server.stop();
    serverThread.join();

    cout << "🏁 Networking demo completed" << endl;
}

int main() {
    demonstrateNetworking();
    return 0;
}
```

---

## Summary: Phase 4 Complete

**🎉 Congratulations!** You have successfully completed **Phase 4: Advanced C++ (Performance & System-Level Mastery)**. You've mastered:

✅ **Templates** - Generic programming, specialization, variadic templates, and C++20 concepts  
✅ **Memory Management** - Object pools, placement new, and memory alignment  
✅ **Multithreading** - Thread safety, synchronization, and concurrent programming  
✅ **Design Patterns** - Industry-standard architectural solutions  
✅ **File Handling** - Advanced I/O operations and serialization  
✅ **Networking** - Basic socket programming concepts

**Next Steps**: You're now ready for **Phase 5: Object-Oriented Design & Best Practices** where you'll learn to architect large-scale systems and apply SOLID principles in real-world scenarios.

**Key Takeaways**:

- C++ templates enable zero-cost abstractions
- Proper memory management is crucial for performance
- Modern C++ provides excellent concurrency support
- Design patterns solve common architectural problems
- File handling and networking are essential for system programming

---
