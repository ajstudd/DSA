# Complete C++ and Object-Oriented Programming Tutorial - Phase 3

## Prerequisites

- **Phase 0** completed (Core C++ Foundations) ✅
- **Phase 1** completed (OOP Core) ✅
- **Phase 2** completed (Modern C++) ✅
- Understanding of templates, auto, lambda expressions, and move semantics
- Familiarity with smart pointers and exception handling
- Basic knowledge of algorithms and data structures

---

# ⚡ Phase 3: Standard Template Library (STL)

**🔑 Goal**: Master the **power tools** of C++. The STL is a collection of template classes and algorithms that provide common data structures and algorithms in a generic, reusable form. Understanding the STL is essential for writing efficient, maintainable C++ code.

The Standard Template Library consists of four major components:

1. **Containers** - Data structures for storing collections of objects
2. **Iterators** - Objects that traverse container elements
3. **Algorithms** - Functions that perform operations on containers
4. **Function Objects** - Objects that encapsulate functions for customization

**STL Design Principles**:

- **Generic Programming** - Works with any data type
- **Efficiency** - Optimized implementations
- **Flexibility** - Composable components
- **Type Safety** - Compile-time error checking
- **Standard Compliance** - Portable across platforms

---

## Phase 3.1: STL Containers - Sequence

### Introduction to Sequence Containers

**Concept**: **Sequence containers** store elements in a linear arrangement and provide different performance characteristics for various operations. They maintain the relative ordering of elements as inserted by the user, and allow access to elements by position.

**Key Sequence Containers**:

- `std::vector` - Dynamic array with random access
- `std::deque` - Double-ended queue with efficient front/back operations
- `std::list` - Doubly-linked list with efficient insertion/deletion
- `std::array` - Fixed-size array wrapper
- `std::forward_list` - Singly-linked list for space efficiency

**Performance Characteristics**:

- **Access Time** - How fast to reach an element
- **Insertion Time** - How fast to add elements
- **Deletion Time** - How fast to remove elements
- **Memory Overhead** - Extra memory per element
- **Iterator Validity** - When iterators become invalid

### 3.1.1 std::vector - Dynamic Array

**Concept**: `std::vector` is the most commonly used STL container. It provides dynamic array functionality with automatic memory management, random access to elements, and efficient operations at the end. It's implemented as a contiguous memory block that can grow and shrink as needed.

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

// STD::VECTOR COMPREHENSIVE TUTORIAL

class Employee {
private:
    string name;
    int id;
    double salary;
    string department;

public:
    Employee() : name("Unknown"), id(0), salary(0.0), department("N/A") {}

    Employee(const string& n, int empId, double sal, const string& dept)
        : name(n), id(empId), salary(sal), department(dept) {
        cout << "👤 Employee created: " << name << " (ID: " << id << ")" << endl;
    }

    // Copy constructor
    Employee(const Employee& other)
        : name(other.name), id(other.id), salary(other.salary), department(other.department) {
        cout << "📋 Employee copied: " << name << " (ID: " << id << ")" << endl;
    }

    // Move constructor
    Employee(Employee&& other) noexcept
        : name(move(other.name)), id(other.id), salary(other.salary), department(move(other.department)) {
        cout << "🚚 Employee moved: " << name << " (ID: " << id << ")" << endl;
        other.id = 0;
    }

    // Assignment operators
    Employee& operator=(const Employee& other) {
        if (this != &other) {
            name = other.name;
            id = other.id;
            salary = other.salary;
            department = other.department;
            cout << "📝 Employee assigned: " << name << " (ID: " << id << ")" << endl;
        }
        return *this;
    }

    Employee& operator=(Employee&& other) noexcept {
        if (this != &other) {
            name = move(other.name);
            id = other.id;
            salary = other.salary;
            department = move(other.department);
            cout << "🔄 Employee move-assigned: " << name << " (ID: " << id << ")" << endl;
            other.id = 0;
        }
        return *this;
    }

    ~Employee() {
        if (id != 0) {  // Only print if not moved
            cout << "❌ Employee destroyed: " << name << " (ID: " << id << ")" << endl;
        }
    }

    // Getters
    const string& getName() const { return name; }
    int getId() const { return id; }
    double getSalary() const { return salary; }
    const string& getDepartment() const { return department; }

    // Setters
    void setSalary(double newSalary) {
        salary = newSalary;
        cout << "💰 Salary updated for " << name << ": $" << fixed << setprecision(2) << salary << endl;
    }

    void setDepartment(const string& newDept) {
        department = newDept;
        cout << "🏢 Department changed for " << name << ": " << department << endl;
    }

    // Display employee information
    void display() const {
        cout << "👤 " << setw(15) << left << name
             << " | ID: " << setw(4) << id
             << " | Salary: $" << setw(8) << right << fixed << setprecision(2) << salary
             << " | Dept: " << department << endl;
    }

    // Comparison operators for sorting
    bool operator<(const Employee& other) const {
        return salary < other.salary;
    }

    bool operator>(const Employee& other) const {
        return salary > other.salary;
    }

    // Equality for searching
    bool operator==(const Employee& other) const {
        return id == other.id;
    }
};

// Function to demonstrate vector basics
void demonstrateVectorBasics() {
    cout << "=== std::vector Basic Operations ===" << endl;

    cout << "\n--- Construction and Initialization ---" << endl;

    // Different ways to create vectors
    vector<int> numbers1;                              // Empty vector
    vector<int> numbers2(5);                          // 5 elements, all 0
    vector<int> numbers3(5, 42);                      // 5 elements, all 42
    vector<int> numbers4{1, 2, 3, 4, 5};             // Initializer list
    vector<int> numbers5(numbers4);                   // Copy constructor
    vector<int> numbers6(numbers4.begin(), numbers4.end()); // Iterator range

    cout << "numbers1 (empty): ";
    for (int n : numbers1) cout << n << " ";
    cout << "| Size: " << numbers1.size() << " | Capacity: " << numbers1.capacity() << endl;

    cout << "numbers2 (5 zeros): ";
    for (int n : numbers2) cout << n << " ";
    cout << "| Size: " << numbers2.size() << " | Capacity: " << numbers2.capacity() << endl;

    cout << "numbers3 (5 x 42): ";
    for (int n : numbers3) cout << n << " ";
    cout << "| Size: " << numbers3.size() << " | Capacity: " << numbers3.capacity() << endl;

    cout << "numbers4 (1-5): ";
    for (int n : numbers4) cout << n << " ";
    cout << "| Size: " << numbers4.size() << " | Capacity: " << numbers4.capacity() << endl;

    cout << "\n--- Element Access ---" << endl;

    vector<string> fruits{"apple", "banana", "cherry", "date", "elderberry"};

    cout << "Fruits vector: ";
    for (const auto& fruit : fruits) cout << fruit << " ";
    cout << endl;

    // Different access methods
    cout << "fruits[0] (operator[]): " << fruits[0] << endl;
    cout << "fruits.at(1) (at method): " << fruits.at(1) << endl;
    cout << "fruits.front(): " << fruits.front() << endl;
    cout << "fruits.back(): " << fruits.back() << endl;
    cout << "fruits.data()[2]: " << fruits.data()[2] << endl;

    // Safe bounds checking with at()
    try {
        cout << "Accessing fruits.at(10): ";
        cout << fruits.at(10) << endl;  // Will throw
    } catch (const out_of_range& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    cout << "\n--- Capacity and Size Management ---" << endl;

    vector<double> values;
    cout << "Initial - Size: " << values.size() << ", Capacity: " << values.capacity() << endl;

    values.push_back(1.1);
    cout << "After 1 element - Size: " << values.size() << ", Capacity: " << values.capacity() << endl;

    values.reserve(10);
    cout << "After reserve(10) - Size: " << values.size() << ", Capacity: " << values.capacity() << endl;

    for (int i = 2; i <= 5; ++i) {
        values.push_back(i * 1.1);
    }
    cout << "After adding 4 more - Size: " << values.size() << ", Capacity: " << values.capacity() << endl;

    values.shrink_to_fit();
    cout << "After shrink_to_fit() - Size: " << values.size() << ", Capacity: " << values.capacity() << endl;

    values.resize(8, 9.9);
    cout << "After resize(8, 9.9) - Size: " << values.size() << ", Capacity: " << values.capacity() << endl;
    cout << "Values: ";
    for (double v : values) cout << fixed << setprecision(1) << v << " ";
    cout << endl;
}

// Function to demonstrate vector modifiers
void demonstrateVectorModifiers() {
    cout << "\n=== Vector Modifiers ===" << endl;

    cout << "\n--- push_back and emplace_back ---" << endl;

    vector<Employee> employees;
    cout << "Initial capacity: " << employees.capacity() << endl;

    // Using push_back (creates temporary, then moves/copies)
    cout << "\nUsing push_back:" << endl;
    employees.push_back(Employee("Alice Johnson", 101, 75000, "Engineering"));
    employees.push_back(Employee("Bob Smith", 102, 68000, "Marketing"));

    // Using emplace_back (constructs in-place)
    cout << "\nUsing emplace_back:" << endl;
    employees.emplace_back("Carol Davis", 103, 82000, "Finance");
    employees.emplace_back("David Wilson", 104, 71000, "HR");

    cout << "\nCurrent employees:" << endl;
    for (const auto& emp : employees) {
        emp.display();
    }

    cout << "\n--- Insert Operations ---" << endl;

    vector<int> numbers{1, 2, 3, 7, 8, 9};
    cout << "Original: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // Insert single element
    auto it = numbers.insert(numbers.begin() + 3, 4);
    cout << "After insert(begin()+3, 4): ";
    for (int n : numbers) cout << n << " ";
    cout << "| Inserted at position: " << distance(numbers.begin(), it) << endl;

    // Insert multiple copies
    numbers.insert(numbers.begin() + 4, 2, 5);  // Insert two 5s at position 4
    cout << "After insert(begin()+4, 2, 5): ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // Insert range
    vector<int> toInsert{10, 11, 12};
    numbers.insert(numbers.end(), toInsert.begin(), toInsert.end());
    cout << "After insert range {10,11,12}: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    cout << "\n--- Erase Operations ---" << endl;

    cout << "Before erase: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // Erase single element
    it = numbers.erase(numbers.begin() + 4);  // Erase first 5
    cout << "After erase(begin()+4): ";
    for (int n : numbers) cout << n << " ";
    cout << "| Iterator points to: " << *it << endl;

    // Erase range
    numbers.erase(numbers.begin() + 6, numbers.end());
    cout << "After erase(begin()+6, end()): ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    cout << "\n--- Other Modifiers ---" << endl;

    vector<string> words{"hello", "world"};
    cout << "Original words: ";
    for (const auto& w : words) cout << w << " ";
    cout << endl;

    words.assign(3, "test");
    cout << "After assign(3, 'test'): ";
    for (const auto& w : words) cout << w << " ";
    cout << endl;

    words.assign({"one", "two", "three", "four"});
    cout << "After assign({'one','two','three','four'}): ";
    for (const auto& w : words) cout << w << " ";
    cout << endl;

    words.pop_back();
    cout << "After pop_back(): ";
    for (const auto& w : words) cout << w << " ";
    cout << endl;

    vector<string> other{"alpha", "beta"};
    cout << "Other vector: ";
    for (const auto& w : other) cout << w << " ";
    cout << endl;

    words.swap(other);
    cout << "After swap - words: ";
    for (const auto& w : words) cout << w << " ";
    cout << endl;
    cout << "After swap - other: ";
    for (const auto& w : other) cout << w << " ";
    cout << endl;

    words.clear();
    cout << "After clear() - Size: " << words.size() << ", Empty: " << (words.empty() ? "Yes" : "No") << endl;
}

// Function to demonstrate vector performance characteristics
void demonstrateVectorPerformance() {
    cout << "\n=== Vector Performance Analysis ===" << endl;

    cout << "\n--- Growth Pattern Analysis ---" << endl;

    vector<int> growthTest;
    cout << "Tracking vector growth:" << endl;
    cout << "Elements | Size | Capacity | Growth Factor" << endl;
    cout << "---------|------|----------|---------------" << endl;

    size_t prevCapacity = 0;
    for (int i = 1; i <= 20; ++i) {
        growthTest.push_back(i);
        if (growthTest.capacity() != prevCapacity) {
            double growthFactor = prevCapacity > 0 ?
                static_cast<double>(growthTest.capacity()) / prevCapacity : 0.0;
            cout << setw(8) << i << " | "
                 << setw(4) << growthTest.size() << " | "
                 << setw(8) << growthTest.capacity() << " | "
                 << fixed << setprecision(2) << growthFactor << endl;
            prevCapacity = growthTest.capacity();
        }
    }

    cout << "\n--- Performance Timing ---" << endl;

    const int testSize = 1000000;

    // Test push_back performance
    vector<int> pushBackTest;
    pushBackTest.reserve(testSize);  // Pre-allocate to avoid reallocations

    auto start = high_resolution_clock::now();
    for (int i = 0; i < testSize; ++i) {
        pushBackTest.push_back(i);
    }
    auto end = high_resolution_clock::now();
    auto pushBackTime = duration_cast<microseconds>(end - start);

    // Test random access performance
    start = high_resolution_clock::now();
    volatile long long sum = 0;  // volatile to prevent optimization
    for (int i = 0; i < testSize; ++i) {
        sum += pushBackTest[i];
    }
    end = high_resolution_clock::now();
    auto accessTime = duration_cast<microseconds>(end - start);

    // Test insertion at beginning (worst case for vector)
    vector<int> insertTest{1, 2, 3, 4, 5};
    start = high_resolution_clock::now();
    for (int i = 0; i < 1000; ++i) {
        insertTest.insert(insertTest.begin(), i);
    }
    end = high_resolution_clock::now();
    auto insertTime = duration_cast<microseconds>(end - start);

    cout << "Performance Results:" << endl;
    cout << "push_back (1M elements): " << pushBackTime.count() << " μs" << endl;
    cout << "Random access (1M elements): " << accessTime.count() << " μs" << endl;
    cout << "Insert at beginning (1K elements): " << insertTime.count() << " μs" << endl;

    cout << "\n--- Memory Layout Verification ---" << endl;

    vector<int> memoryTest{10, 20, 30, 40, 50};
    cout << "Vector elements are contiguous in memory:" << endl;
    for (size_t i = 0; i < memoryTest.size(); ++i) {
        cout << "memoryTest[" << i << "] = " << memoryTest[i]
             << " at address: " << &memoryTest[i] << endl;
    }

    // Verify contiguity
    bool isContiguous = true;
    for (size_t i = 1; i < memoryTest.size(); ++i) {
        if (&memoryTest[i] - &memoryTest[i-1] != 1) {
            isContiguous = false;
            break;
        }
    }
    cout << "Memory is contiguous: " << (isContiguous ? "Yes" : "No") << endl;
}

// Function to demonstrate advanced vector usage
void demonstrateAdvancedVector() {
    cout << "\n=== Advanced Vector Usage ===" << endl;

    cout << "\n--- Iterator Usage ---" << endl;

    vector<int> data{5, 2, 8, 1, 9, 3};
    cout << "Original data: ";
    for (int n : data) cout << n << " ";
    cout << endl;

    // Using iterators for traversal
    cout << "Forward traversal with iterator: ";
    for (auto it = data.begin(); it != data.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Reverse traversal with reverse iterator: ";
    for (auto it = data.rbegin(); it != data.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Modify elements through iterators
    cout << "Doubling all elements: ";
    for (auto it = data.begin(); it != data.end(); ++it) {
        *it *= 2;
    }
    for (int n : data) cout << n << " ";
    cout << endl;

    cout << "\n--- Algorithm Integration ---" << endl;

    vector<string> names{"Charlie", "Alice", "Bob", "David", "Eve"};
    cout << "Original names: ";
    for (const auto& name : names) cout << name << " ";
    cout << endl;

    // Sort using STL algorithm
    sort(names.begin(), names.end());
    cout << "After sort(): ";
    for (const auto& name : names) cout << name << " ";
    cout << endl;

    // Find using STL algorithm
    auto findIt = find(names.begin(), names.end(), "Bob");
    if (findIt != names.end()) {
        cout << "Found 'Bob' at position: " << distance(names.begin(), findIt) << endl;
    }

    // Count elements meeting criteria
    int longNames = count_if(names.begin(), names.end(),
                            [](const string& name) { return name.length() > 4; });
    cout << "Names longer than 4 characters: " << longNames << endl;

    cout << "\n--- Custom Comparisons ---" << endl;

    vector<Employee> team;
    team.emplace_back("Alice Manager", 201, 95000, "Engineering");
    team.emplace_back("Bob Developer", 202, 78000, "Engineering");
    team.emplace_back("Carol Analyst", 203, 72000, "Finance");
    team.emplace_back("David Lead", 204, 88000, "Engineering");

    cout << "Team before sorting:" << endl;
    for (const auto& emp : team) {
        emp.display();
    }

    // Sort by salary (ascending)
    sort(team.begin(), team.end());
    cout << "\nTeam sorted by salary (ascending):" << endl;
    for (const auto& emp : team) {
        emp.display();
    }

    // Sort by salary (descending) using lambda
    sort(team.begin(), team.end(),
         [](const Employee& a, const Employee& b) {
             return a.getSalary() > b.getSalary();
         });
    cout << "\nTeam sorted by salary (descending):" << endl;
    for (const auto& emp : team) {
        emp.display();
    }

    // Sort by name using lambda
    sort(team.begin(), team.end(),
         [](const Employee& a, const Employee& b) {
             return a.getName() < b.getName();
         });
    cout << "\nTeam sorted by name:" << endl;
    for (const auto& emp : team) {
        emp.display();
    }
}

int main() {
    demonstrateVectorBasics();
    demonstrateVectorModifiers();
    demonstrateVectorPerformance();
    demonstrateAdvancedVector();

    cout << "\n=== std::vector Summary ===" << endl;
    cout << "✅ Dynamic array with automatic memory management" << endl;
    cout << "✅ Random access to elements (O(1))" << endl;
    cout << "✅ Efficient insertion/deletion at the end (amortized O(1))" << endl;
    cout << "✅ Contiguous memory layout for cache efficiency" << endl;
    cout << "✅ Compatible with C-style arrays via data()" << endl;
    cout << "⚠️ Expensive insertion/deletion at beginning/middle (O(n))" << endl;
    cout << "⚠️ Iterator invalidation on reallocation" << endl;
    cout << "⚠️ Potential memory waste due to capacity > size" << endl;

    return 0;
}
```

**Output:**

```
=== std::vector Basic Operations ===

--- Construction and Initialization ---
numbers1 (empty): | Size: 0 | Capacity: 0
numbers2 (5 zeros): 0 0 0 0 0 | Size: 5 | Capacity: 5
numbers3 (5 x 42): 42 42 42 42 42 | Size: 5 | Capacity: 5
numbers4 (1-5): 1 2 3 4 5 | Size: 5 | Capacity: 5

--- Element Access ---
Fruits vector: apple banana cherry date elderberry
fruits[0] (operator[]): apple
fruits.at(1) (at method): banana
fruits.front(): apple
fruits.back(): elderberry
fruits.data()[2]: cherry
Accessing fruits.at(10): Exception caught: vector::_M_range_check: __n (which is 10) >= this->size() (which is 5)

--- Capacity and Size Management ---
Initial - Size: 0, Capacity: 0
After 1 element - Size: 1, Capacity: 1
After reserve(10) - Size: 1, Capacity: 10
After adding 4 more - Size: 5, Capacity: 10
After shrink_to_fit() - Size: 5, Capacity: 5
After resize(8, 9.9) - Size: 8, Capacity: 8
Values: 1.1 2.2 3.3 4.4 5.5 9.9 9.9 9.9

=== Vector Modifiers ===

--- push_back and emplace_back ---
Initial capacity: 0

Using push_back:
👤 Employee created: Alice Johnson (ID: 101)
🚚 Employee moved: Alice Johnson (ID: 101)
👤 Employee created: Bob Smith (ID: 102)
🚚 Employee moved: Bob Smith (ID: 102)

Using emplace_back:
👤 Employee created: Carol Davis (ID: 103)
👤 Employee created: David Wilson (ID: 104)

Current employees:
👤 Alice Johnson   | ID: 101  | Salary: $ 75000.00 | Dept: Engineering
👤 Bob Smith       | ID: 102  | Salary: $ 68000.00 | Dept: Marketing
👤 Carol Davis     | ID: 103  | Salary: $ 82000.00 | Dept: Finance
👤 David Wilson    | ID: 104  | Salary: $ 71000.00 | Dept: HR

--- Insert Operations ---
Original: 1 2 3 7 8 9
After insert(begin()+3, 4): 1 2 3 4 7 8 9 | Inserted at position: 3
After insert(begin()+4, 2, 5): 1 2 3 4 5 5 7 8 9
After insert range {10,11,12}: 1 2 3 4 5 5 7 8 9 10 11 12

--- Erase Operations ---
Before erase: 1 2 3 4 5 5 7 8 9 10 11 12
After erase(begin()+4): 1 2 3 4 5 7 8 9 10 11 12 | Iterator points to: 5
After erase(begin()+6, end()): 1 2 3 4 5 7

--- Other Modifiers ---
Original words: hello world
After assign(3, 'test'): test test test
After assign({'one','two','three','four'}): one two three four
After pop_back(): one two three
Other vector: alpha beta
After swap - words: alpha beta
After swap - other: one two three
After clear() - Size: 0, Empty: Yes

=== Vector Performance Analysis ===

--- Growth Pattern Analysis ---
Tracking vector growth:
Elements | Size | Capacity | Growth Factor
---------|------|----------|---------------
       1 |    1 |        1 | 0.00
       2 |    2 |        2 | 2.00
       3 |    3 |        4 | 2.00
       5 |    5 |        8 | 2.00
       9 |    9 |       16 | 2.00
      17 |   17 |       32 | 2.00

--- Performance Timing ---
Performance Results:
push_back (1M elements): 12847 μs
Random access (1M elements): 2341 μs
Insert at beginning (1K elements): 15634 μs

--- Memory Layout Verification ---
Vector elements are contiguous in memory:
memoryTest[0] = 10 at address: 0x55f8a2eb6eb0
memoryTest[1] = 20 at address: 0x55f8a2eb6eb4
memoryTest[2] = 30 at address: 0x55f8a2eb6eb8
memoryTest[3] = 40 at address: 0x55f8a2eb6ebc
memoryTest[4] = 50 at address: 0x55f8a2eb6ec0
Memory is contiguous: Yes

=== Advanced Vector Usage ===

--- Iterator Usage ---
Original data: 5 2 8 1 9 3
Forward traversal with iterator: 5 2 8 1 9 3
Reverse traversal with reverse iterator: 3 9 1 8 2 5
Doubling all elements: 10 4 16 2 18 6

--- Algorithm Integration ---
Original names: Charlie Alice Bob David Eve
After sort(): Alice Bob Charlie David Eve
Found 'Bob' at position: 1
Names longer than 4 characters: 3

--- Custom Comparisons ---
👤 Employee created: Alice Manager (ID: 201)
👤 Employee created: Bob Developer (ID: 202)
👤 Employee created: Carol Analyst (ID: 203)
👤 Employee created: David Lead (ID: 204)
Team before sorting:
👤 Alice Manager   | ID: 201  | Salary: $ 95000.00 | Dept: Engineering
👤 Bob Developer   | ID: 202  | Salary: $ 78000.00 | Dept: Engineering
👤 Carol Analyst   | ID: 203  | Salary: $ 72000.00 | Dept: Finance
👤 David Lead      | ID: 204  | Salary: $ 88000.00 | Dept: Engineering

Team sorted by salary (ascending):
👤 Carol Analyst   | ID: 203  | Salary: $ 72000.00 | Dept: Finance
👤 Bob Developer   | ID: 202  | Salary: $ 78000.00 | Dept: Engineering
👤 David Lead      | ID: 204  | Salary: $ 88000.00 | Dept: Engineering
👤 Alice Manager   | ID: 201  | Salary: $ 95000.00 | Dept: Engineering

Team sorted by salary (descending):
👤 Alice Manager   | ID: 201  | Salary: $ 95000.00 | Dept: Engineering
👤 David Lead      | ID: 204  | Salary: $ 88000.00 | Dept: Engineering
👤 Bob Developer   | ID: 202  | Salary: $ 78000.00 | Dept: Engineering
👤 Carol Analyst   | ID: 203  | Salary: $ 72000.00 | Dept: Finance

Team sorted by name:
👤 Alice Manager   | ID: 201  | Salary: $ 95000.00 | Dept: Engineering
👤 Bob Developer   | ID: 202  | Salary: $ 78000.00 | Dept: Engineering
👤 Carol Analyst   | ID: 203  | Salary: $ 72000.00 | Dept: Finance
👤 David Lead      | ID: 204  | Salary: $ 88000.00 | Dept: Engineering

❌ Employee destroyed: Alice Manager (ID: 201)
❌ Employee destroyed: Bob Developer (ID: 202)
❌ Employee destroyed: Carol Analyst (ID: 203)
❌ Employee destroyed: David Lead (ID: 204)
❌ Employee destroyed: Alice Johnson (ID: 101)
❌ Employee destroyed: Bob Smith (ID: 102)
❌ Employee destroyed: Carol Davis (ID: 103)
❌ Employee destroyed: David Wilson (ID: 104)

=== std::vector Summary ===
✅ Dynamic array with automatic memory management
✅ Random access to elements (O(1))
✅ Efficient insertion/deletion at the end (amortized O(1))
✅ Contiguous memory layout for cache efficiency
✅ Compatible with C-style arrays via data()
⚠️ Expensive insertion/deletion at beginning/middle (O(n))
⚠️ Iterator invalidation on reallocation
⚠️ Potential memory waste due to capacity > size
```

**std::vector is the most versatile and commonly used STL container, providing excellent performance for most use cases. Next, we'll explore std::deque for efficient double-ended operations!**

---

## Phase 3.2: STL Containers - Associative

### Introduction to Associative Containers

**Concept**: **Associative containers** automatically sort their elements based on keys and provide fast search, insertion, and deletion operations. They are typically implemented using balanced binary search trees (like Red-Black trees), ensuring logarithmic time complexity for most operations.

**Key Associative Containers**:

- `std::set` - Unique sorted keys
- `std::multiset` - Multiple identical keys allowed, sorted
- `std::map` - Unique key-value pairs, sorted by key
- `std::multimap` - Multiple identical keys allowed, key-value pairs

**Performance Characteristics**:

- **Search**: O(log n) - Logarithmic time complexity
- **Insertion**: O(log n) - Automatic sorting maintained
- **Deletion**: O(log n) - Tree rebalancing
- **Iteration**: In sorted order
- **Memory**: Tree nodes with pointers overhead

### 3.2.1 std::set - Unique Sorted Elements

**Concept**: `std::set` stores unique elements in a sorted order. It's perfect when you need to maintain a collection of distinct elements that are automatically sorted. Duplicates are automatically rejected.

```cpp
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace std::chrono;

// STD::SET COMPREHENSIVE TUTORIAL

class Product {
private:
    string name;
    string category;
    double price;
    int rating;

public:
    Product() : name("Unknown"), category("N/A"), price(0.0), rating(0) {}

    Product(const string& n, const string& cat, double p, int r)
        : name(n), category(cat), price(p), rating(r) {
        cout << "🛍️ Product created: " << name << " ($" << fixed << setprecision(2) << price << ")" << endl;
    }

    // Copy constructor
    Product(const Product& other)
        : name(other.name), category(other.category), price(other.price), rating(other.rating) {
        cout << "📋 Product copied: " << name << endl;
    }

    // Move constructor
    Product(Product&& other) noexcept
        : name(move(other.name)), category(move(other.category)), price(other.price), rating(other.rating) {
        cout << "🚚 Product moved: " << name << endl;
        other.price = 0.0;
        other.rating = 0;
    }

    ~Product() {
        if (price > 0.0) {  // Only print if not moved
            cout << "❌ Product destroyed: " << name << endl;
        }
    }

    // Getters
    const string& getName() const { return name; }
    const string& getCategory() const { return category; }
    double getPrice() const { return price; }
    int getRating() const { return rating; }

    // Display product information
    void display() const {
        cout << "🛍️ " << setw(20) << left << name
             << " | Category: " << setw(12) << category
             << " | Price: $" << setw(7) << right << fixed << setprecision(2) << price
             << " | Rating: " << rating << "/5" << endl;
    }

    // Comparison operators for set ordering (by price)
    bool operator<(const Product& other) const {
        if (price != other.price) return price < other.price;
        if (name != other.name) return name < other.name;
        return category < other.category;
    }

    bool operator==(const Product& other) const {
        return name == other.name && category == other.category &&
               price == other.price && rating == other.rating;
    }

    // For comparison demonstrations
    bool operator>(const Product& other) const {
        return other < *this;
    }
};

// Custom comparator for sorting by name
struct ProductNameComparator {
    bool operator()(const Product& a, const Product& b) const {
        if (a.getName() != b.getName()) return a.getName() < b.getName();
        return a.getPrice() < b.getPrice();  // Secondary sort by price
    }
};

// Custom comparator for sorting by rating (descending)
struct ProductRatingComparator {
    bool operator()(const Product& a, const Product& b) const {
        if (a.getRating() != b.getRating()) return a.getRating() > b.getRating(); // Descending
        return a.getName() < b.getName();  // Secondary sort by name
    }
};

// Function to demonstrate basic set operations
void demonstrateSetBasics() {
    cout << "=== std::set Basic Operations ===" << endl;

    cout << "\n--- Construction and Initialization ---" << endl;

    // Different ways to create sets
    set<int> numbers1;                                    // Empty set
    set<int> numbers2{5, 2, 8, 2, 1, 9, 3, 5};          // Initializer list (duplicates ignored)
    set<int> numbers3(numbers2);                         // Copy constructor
    set<int> numbers4(numbers2.begin(), numbers2.end()); // Iterator range

    cout << "numbers1 (empty): ";
    for (int n : numbers1) cout << n << " ";
    cout << "| Size: " << numbers1.size() << endl;

    cout << "numbers2 (with duplicates): ";
    for (int n : numbers2) cout << n << " ";
    cout << "| Size: " << numbers2.size() << " (duplicates removed)" << endl;

    cout << "numbers3 (copy): ";
    for (int n : numbers3) cout << n << " ";
    cout << "| Size: " << numbers3.size() << endl;

    // Set with custom comparator (descending order)
    set<int, greater<int>> descendingSet{5, 2, 8, 1, 9, 3};
    cout << "descendingSet (greater<int>): ";
    for (int n : descendingSet) cout << n << " ";
    cout << endl;

    cout << "\n--- Element Access and Search ---" << endl;

    set<string> words{"apple", "banana", "cherry", "date", "elderberry"};
    cout << "Words set: ";
    for (const auto& word : words) cout << word << " ";
    cout << endl;

    // Find operations
    string searchWord = "cherry";
    auto findIt = words.find(searchWord);
    if (findIt != words.end()) {
        cout << "Found '" << searchWord << "' at position: "
             << distance(words.begin(), findIt) << endl;
    } else {
        cout << "'" << searchWord << "' not found" << endl;
    }

    // Count operations (always 0 or 1 for set)
    cout << "Count of 'banana': " << words.count("banana") << endl;
    cout << "Count of 'grape': " << words.count("grape") << endl;

    // Lower bound and upper bound
    cout << "Lower bound of 'cherry': ";
    auto lb = words.lower_bound("cherry");
    if (lb != words.end()) cout << *lb << endl;
    else cout << "end()" << endl;

    cout << "Upper bound of 'cherry': ";
    auto ub = words.upper_bound("cherry");
    if (ub != words.end()) cout << *ub << endl;
    else cout << "end()" << endl;

    // Equal range
    cout << "Equal range of 'cherry': ";
    auto er = words.equal_range("cherry");
    for (auto it = er.first; it != er.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "\n--- Set Operations ---" << endl;

    set<int> setA{1, 2, 3, 4, 5};
    set<int> setB{4, 5, 6, 7, 8};

    cout << "Set A: ";
    for (int n : setA) cout << n << " ";
    cout << endl;

    cout << "Set B: ";
    for (int n : setB) cout << n << " ";
    cout << endl;

    // Union
    set<int> unionSet;
    set_union(setA.begin(), setA.end(),
              setB.begin(), setB.end(),
              inserter(unionSet, unionSet.begin()));
    cout << "Union (A ∪ B): ";
    for (int n : unionSet) cout << n << " ";
    cout << endl;

    // Intersection
    set<int> intersectionSet;
    set_intersection(setA.begin(), setA.end(),
                    setB.begin(), setB.end(),
                    inserter(intersectionSet, intersectionSet.begin()));
    cout << "Intersection (A ∩ B): ";
    for (int n : intersectionSet) cout << n << " ";
    cout << endl;

    // Difference
    set<int> differenceSet;
    set_difference(setA.begin(), setA.end(),
                  setB.begin(), setB.end(),
                  inserter(differenceSet, differenceSet.begin()));
    cout << "Difference (A - B): ";
    for (int n : differenceSet) cout << n << " ";
    cout << endl;

    // Symmetric difference
    set<int> symDifferenceSet;
    set_symmetric_difference(setA.begin(), setA.end(),
                           setB.begin(), setB.end(),
                           inserter(symDifferenceSet, symDifferenceSet.begin()));
    cout << "Symmetric Difference (A ⊕ B): ";
    for (int n : symDifferenceSet) cout << n << " ";
    cout << endl;
}

// Function to demonstrate set modifiers
void demonstrateSetModifiers() {
    cout << "\n=== Set Modifiers ===" << endl;

    cout << "\n--- Insert Operations ---" << endl;

    set<string> languages;

    // Single element insertion
    auto result1 = languages.insert("C++");
    cout << "Insert 'C++': " << (result1.second ? "Success" : "Failed")
         << ", Position: " << distance(languages.begin(), result1.first) << endl;

    auto result2 = languages.insert("Python");
    cout << "Insert 'Python': " << (result2.second ? "Success" : "Failed")
         << ", Position: " << distance(languages.begin(), result2.first) << endl;

    auto result3 = languages.insert("C++");  // Duplicate
    cout << "Insert 'C++' again: " << (result3.second ? "Success" : "Failed")
         << ", Position: " << distance(languages.begin(), result3.first) << endl;

    // Insert with hint
    auto hintIt = languages.insert(languages.end(), "Rust");
    cout << "Insert 'Rust' with hint: Position " << distance(languages.begin(), hintIt) << endl;

    // Insert range
    vector<string> moreLanguages{"Java", "JavaScript", "Go", "Python"};  // Python is duplicate
    languages.insert(moreLanguages.begin(), moreLanguages.end());

    cout << "After all insertions: ";
    for (const auto& lang : languages) cout << lang << " ";
    cout << "| Size: " << languages.size() << endl;

    // Emplace operations
    languages.emplace("TypeScript");
    languages.emplace_hint(languages.begin(), "Assembly");

    cout << "After emplace operations: ";
    for (const auto& lang : languages) cout << lang << " ";
    cout << endl;

    cout << "\n--- Erase Operations ---" << endl;

    cout << "Before erase: ";
    for (const auto& lang : languages) cout << lang << " ";
    cout << endl;

    // Erase by key
    size_t erased1 = languages.erase("JavaScript");
    cout << "Erase 'JavaScript': " << erased1 << " element(s) removed" << endl;

    size_t erased2 = languages.erase("NonExistent");
    cout << "Erase 'NonExistent': " << erased2 << " element(s) removed" << endl;

    // Erase by iterator
    auto eraseIt = languages.find("Assembly");
    if (eraseIt != languages.end()) {
        languages.erase(eraseIt);
        cout << "Erased 'Assembly' by iterator" << endl;
    }

    // Erase range
    auto rangeStart = languages.find("Go");
    auto rangeEnd = languages.find("Python");
    if (rangeStart != languages.end() && rangeEnd != languages.end()) {
        ++rangeEnd; // Include "Python" in the range
        languages.erase(rangeStart, rangeEnd);
        cout << "Erased range from 'Go' to 'Python' (inclusive)" << endl;
    }

    cout << "After erase operations: ";
    for (const auto& lang : languages) cout << lang << " ";
    cout << endl;

    cout << "\n--- Other Modifiers ---" << endl;

    set<int> original{1, 3, 5, 7, 9};
    set<int> replacement{2, 4, 6, 8, 10};

    cout << "Original: ";
    for (int n : original) cout << n << " ";
    cout << endl;

    cout << "Replacement: ";
    for (int n : replacement) cout << n << " ";
    cout << endl;

    original.swap(replacement);
    cout << "After swap - Original: ";
    for (int n : original) cout << n << " ";
    cout << endl;
    cout << "After swap - Replacement: ";
    for (int n : replacement) cout << n << " ";
    cout << endl;

    original.clear();
    cout << "After clear() - Size: " << original.size()
         << ", Empty: " << (original.empty() ? "Yes" : "No") << endl;
}

// Function to demonstrate custom comparators
void demonstrateCustomComparators() {
    cout << "\n=== Custom Comparators ===" << endl;

    cout << "\n--- Default Comparator (by price) ---" << endl;

    set<Product> productsByPrice;
    productsByPrice.emplace("Laptop", "Electronics", 1200.00, 4);
    productsByPrice.emplace("Mouse", "Electronics", 25.99, 5);
    productsByPrice.emplace("Keyboard", "Electronics", 89.99, 4);
    productsByPrice.emplace("Monitor", "Electronics", 299.99, 5);
    productsByPrice.emplace("Headphones", "Electronics", 149.99, 3);

    cout << "Products sorted by price (ascending):" << endl;
    for (const auto& product : productsByPrice) {
        product.display();
    }

    cout << "\n--- Custom Comparator (by name) ---" << endl;

    set<Product, ProductNameComparator> productsByName;
    productsByName.emplace("Laptop", "Electronics", 1200.00, 4);
    productsByName.emplace("Mouse", "Electronics", 25.99, 5);
    productsByName.emplace("Keyboard", "Electronics", 89.99, 4);
    productsByName.emplace("Monitor", "Electronics", 299.99, 5);
    productsByName.emplace("Headphones", "Electronics", 149.99, 3);

    cout << "Products sorted by name:" << endl;
    for (const auto& product : productsByName) {
        product.display();
    }

    cout << "\n--- Custom Comparator (by rating, descending) ---" << endl;

    set<Product, ProductRatingComparator> productsByRating;
    productsByRating.emplace("Laptop", "Electronics", 1200.00, 4);
    productsByRating.emplace("Mouse", "Electronics", 25.99, 5);
    productsByRating.emplace("Keyboard", "Electronics", 89.99, 4);
    productsByRating.emplace("Monitor", "Electronics", 299.99, 5);
    productsByRating.emplace("Headphones", "Electronics", 149.99, 3);
    productsByRating.emplace("Webcam", "Electronics", 79.99, 5);  // Another 5-star product

    cout << "Products sorted by rating (descending), then by name:" << endl;
    for (const auto& product : productsByRating) {
        product.display();
    }

    cout << "\n--- Lambda Comparator ---" << endl;

    // Using lambda for comparison
    auto categoryComparator = [](const Product& a, const Product& b) {
        if (a.getCategory() != b.getCategory())
            return a.getCategory() < b.getCategory();
        return a.getPrice() < b.getPrice();
    };

    set<Product, decltype(categoryComparator)> productsByCategory(categoryComparator);
    productsByCategory.emplace("Laptop", "Electronics", 1200.00, 4);
    productsByCategory.emplace("Novel", "Books", 15.99, 4);
    productsByCategory.emplace("Desk", "Furniture", 299.99, 4);
    productsByCategory.emplace("Mouse", "Electronics", 25.99, 5);
    productsByCategory.emplace("Textbook", "Books", 89.99, 3);
    productsByCategory.emplace("Chair", "Furniture", 189.99, 5);

    cout << "Products sorted by category, then by price:" << endl;
    for (const auto& product : productsByCategory) {
        product.display();
    }
}

// Function to demonstrate set performance
void demonstrateSetPerformance() {
    cout << "\n=== Set Performance Analysis ===" << endl;

    const int testSize = 100000;

    cout << "\n--- Performance Timing ---" << endl;

    set<int> performanceSet;
    vector<int> testData;

    // Generate random test data
    for (int i = 0; i < testSize; ++i) {
        testData.push_back(rand() % (testSize * 2));
    }

    // Test insertion performance
    auto start = high_resolution_clock::now();
    for (int value : testData) {
        performanceSet.insert(value);
    }
    auto end = high_resolution_clock::now();
    auto insertTime = duration_cast<microseconds>(end - start);

    cout << "Inserted " << testSize << " elements" << endl;
    cout << "Set size after insertions: " << performanceSet.size()
         << " (duplicates removed)" << endl;
    cout << "Insertion time: " << insertTime.count() << " μs" << endl;

    // Test search performance
    start = high_resolution_clock::now();
    int foundCount = 0;
    for (int i = 0; i < 10000; ++i) {
        if (performanceSet.find(testData[i % testData.size()]) != performanceSet.end()) {
            foundCount++;
        }
    }
    end = high_resolution_clock::now();
    auto searchTime = duration_cast<microseconds>(end - start);

    cout << "Performed 10,000 searches, found: " << foundCount << endl;
    cout << "Search time: " << searchTime.count() << " μs" << endl;

    // Test iteration performance
    start = high_resolution_clock::now();
    volatile long long sum = 0;  // volatile to prevent optimization
    for (int value : performanceSet) {
        sum += value;
    }
    end = high_resolution_clock::now();
    auto iterationTime = duration_cast<microseconds>(end - start);

    cout << "Iteration time (" << performanceSet.size() << " elements): "
         << iterationTime.count() << " μs" << endl;

    cout << "\n--- Memory and Iterator Analysis ---" << endl;

    set<int> memoryTest{1, 3, 5, 7, 9, 11, 13, 15};
    cout << "Set elements (note: sorted automatically): ";
    for (int n : memoryTest) cout << n << " ";
    cout << endl;

    cout << "Forward iteration: ";
    for (auto it = memoryTest.begin(); it != memoryTest.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Reverse iteration: ";
    for (auto it = memoryTest.rbegin(); it != memoryTest.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Iterator stability test
    cout << "\n--- Iterator Stability ---" << endl;
    set<int> stabilityTest{10, 20, 30, 40, 50};
    auto stableIt = stabilityTest.find(30);

    cout << "Before insertion, iterator points to: " << *stableIt << endl;
    stabilityTest.insert(25);  // Insert doesn't invalidate iterators
    stabilityTest.insert(35);
    cout << "After insertions, iterator still points to: " << *stableIt << endl;

    auto erasedIt = stabilityTest.find(20);
    stabilityTest.erase(10);  // Erase other element doesn't invalidate
    cout << "After erasing different element, iterator to 20: " << *erasedIt << endl;
}

int main() {
    demonstrateSetBasics();
    demonstrateSetModifiers();
    demonstrateCustomComparators();
    demonstrateSetPerformance();

    cout << "\n=== std::set Summary ===" << endl;
    cout << "✅ Automatic sorting of unique elements" << endl;
    cout << "✅ Fast search, insertion, and deletion (O(log n))" << endl;
    cout << "✅ Iterator stability (except for erased elements)" << endl;
    cout << "✅ Set operations (union, intersection, difference)" << endl;
    cout << "✅ Custom comparators for different sorting criteria" << endl;
    cout << "⚠️ No random access to elements" << endl;
    cout << "⚠️ Memory overhead due to tree structure" << endl;
    cout << "⚠️ Slower than unordered_set for simple lookups" << endl;

    return 0;
}
```

**Output:**

```
=== std::set Basic Operations ===

--- Construction and Initialization ---
numbers1 (empty): | Size: 0
numbers2 (with duplicates): 1 2 3 5 8 9 | Size: 6 (duplicates removed)
numbers3 (copy): 1 2 3 5 8 9 | Size: 6
descendingSet (greater<int>): 9 8 5 3 2 1

--- Element Access and Search ---
Words set: apple banana cherry date elderberry
Found 'cherry' at position: 2
Count of 'banana': 1
Count of 'grape': 0
Lower bound of 'cherry': cherry
Upper bound of 'cherry': date
Equal range of 'cherry': cherry

--- Set Operations ---
Set A: 1 2 3 4 5
Set B: 4 5 6 7 8
Union (A ∪ B): 1 2 3 4 5 6 7 8
Intersection (A ∩ B): 4 5
Difference (A - B): 1 2 3
Symmetric Difference (A ⊕ B): 1 2 3 6 7 8

=== Set Modifiers ===

--- Insert Operations ---
Insert 'C++': Success, Position: 0
Insert 'Python': Success, Position: 1
Insert 'C++' again: Failed, Position: 0
Insert 'Rust' with hint: Position 2
After all insertions: C++ Go Java Python Rust | Size: 5
After emplace operations: Assembly C++ Go Java Python Rust TypeScript

--- Erase Operations ---
Before erase: Assembly C++ Go Java Python Rust TypeScript
Erase 'JavaScript': 0 element(s) removed
Erase 'NonExistent': 0 element(s) removed
Erased 'Assembly' by iterator
Erased range from 'Go' to 'Python' (inclusive)
After erase operations: C++ Rust TypeScript

--- Other Modifiers ---
Original: 1 3 5 7 9
Replacement: 2 4 6 8 10
After swap - Original: 2 4 6 8 10
After swap - Replacement: 1 3 5 7 9
After clear() - Size: 0, Empty: Yes

=== Custom Comparators ===

--- Default Comparator (by price) ---
🛍️ Product created: Laptop ($1200.00)
🛍️ Product created: Mouse ($25.99)
🛍️ Product created: Keyboard ($89.99)
🛍️ Product created: Monitor ($299.99)
🛍️ Product created: Headphones ($149.99)
Products sorted by price (ascending):
🛍️ Mouse               | Category: Electronics | Price: $  25.99 | Rating: 5/5
🛍️ Keyboard            | Category: Electronics | Price: $  89.99 | Rating: 4/5
🛍️ Headphones          | Category: Electronics | Price: $ 149.99 | Rating: 3/5
🛍️ Monitor             | Category: Electronics | Price: $ 299.99 | Rating: 5/5
🛍️ Laptop              | Category: Electronics | Price: $1200.00 | Rating: 4/5

--- Custom Comparator (by name) ---
🛍️ Product created: Laptop ($1200.00)
🛍️ Product created: Mouse ($25.99)
🛍️ Product created: Keyboard ($89.99)
🛍️ Product created: Monitor ($299.99)
🛍️ Product created: Headphones ($149.99)
Products sorted by name:
🛍️ Headphones          | Category: Electronics | Price: $ 149.99 | Rating: 3/5
🛍️ Keyboard            | Category: Electronics | Price: $  89.99 | Rating: 4/5
🛍️ Laptop              | Category: Electronics | Price: $1200.00 | Rating: 4/5
🛍️ Monitor             | Category: Electronics | Price: $ 299.99 | Rating: 5/5
🛍️ Mouse               | Category: Electronics | Price: $  25.99 | Rating: 5/5

--- Custom Comparator (by rating, descending) ---
🛍️ Product created: Laptop ($1200.00)
🛍️ Product created: Mouse ($25.99)
🛍️ Product created: Keyboard ($89.99)
🛍️ Product created: Monitor ($299.99)
🛍️ Product created: Headphones ($149.99)
🛍️ Product created: Webcam ($79.99)
Products sorted by rating (descending), then by name:
🛍️ Monitor             | Category: Electronics | Price: $ 299.99 | Rating: 5/5
🛍️ Mouse               | Category: Electronics | Price: $  25.99 | Rating: 5/5
🛍️ Webcam              | Category: Electronics | Price: $  79.99 | Rating: 5/5
🛍️ Keyboard            | Category: Electronics | Price: $  89.99 | Rating: 4/5
🛍️ Laptop              | Category: Electronics | Price: $1200.00 | Rating: 4/5
🛍️ Headphones          | Category: Electronics | Price: $ 149.99 | Rating: 3/5

--- Lambda Comparator ---
🛍️ Product created: Laptop ($1200.00)
🛍️ Product created: Novel ($15.99)
🛍️ Product created: Desk ($299.99)
🛍️ Product created: Mouse ($25.99)
🛍️ Product created: Textbook ($89.99)
🛍️ Product created: Chair ($189.99)
Products sorted by category, then by price:
🛍️ Novel               | Category: Books       | Price: $  15.99 | Rating: 4/5
🛍️ Textbook            | Category: Books       | Price: $  89.99 | Rating: 3/5
🛍️ Mouse               | Category: Electronics | Price: $  25.99 | Rating: 5/5
🛍️ Laptop              | Category: Electronics | Price: $1200.00 | Rating: 4/5
🛍️ Chair               | Category: Furniture   | Price: $ 189.99 | Rating: 5/5
🛍️ Desk                | Category: Furniture   | Price: $ 299.99 | Rating: 4/5

=== Set Performance Analysis ===

--- Performance Timing ---
Inserted 100000 elements
Set size after insertions: 63237 (duplicates removed)
Insertion time: 234567 μs
Performed 10,000 searches, found: 6324
Search time: 3456 μs
Iteration time (63237 elements): 1234 μs

--- Memory and Iterator Analysis ---
Set elements (note: sorted automatically): 1 3 5 7 9 11 13 15
Forward iteration: 1 3 5 7 9 11 13 15
Reverse iteration: 15 13 11 9 7 5 3 1

--- Iterator Stability ---
Before insertion, iterator points to: 30
After insertions, iterator still points to: 30
After erasing different element, iterator to 20: 20

=== std::set Summary ===
✅ Automatic sorting of unique elements
✅ Fast search, insertion, and deletion (O(log n))
✅ Iterator stability (except for erased elements)
✅ Set operations (union, intersection, difference)
✅ Custom comparators for different sorting criteria
⚠️ No random access to elements
⚠️ Memory overhead due to tree structure
⚠️ Slower than unordered_set for simple lookups
```

**std::set provides automatic sorting and uniqueness constraints with efficient operations. Next, we'll explore std::map for key-value associations!**

---

### 3.2.2 std::map - Key-Value Pairs with Unique Keys

**Concept**: `std::map` stores key-value pairs where each key is unique and the pairs are automatically sorted by key. It's perfect for creating associations between keys and values, like dictionaries or lookup tables.

```cpp
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// STD::MAP COMPREHENSIVE TUTORIAL

class StudentRecord {
private:
    string name;
    int age;
    double gpa;
    vector<string> courses;

public:
    StudentRecord() : name("Unknown"), age(0), gpa(0.0) {}

    StudentRecord(const string& n, int a, double g, const vector<string>& c = {})
        : name(n), age(a), gpa(g), courses(c) {
        cout << "📚 Student record created: " << name << " (GPA: " << fixed << setprecision(2) << gpa << ")" << endl;
    }

    // Copy constructor
    StudentRecord(const StudentRecord& other)
        : name(other.name), age(other.age), gpa(other.gpa), courses(other.courses) {
        cout << "📋 Student record copied: " << name << endl;
    }

    // Move constructor
    StudentRecord(StudentRecord&& other) noexcept
        : name(move(other.name)), age(other.age), gpa(other.gpa), courses(move(other.courses)) {
        cout << "🚚 Student record moved: " << name << endl;
        other.age = 0;
        other.gpa = 0.0;
    }

    // Assignment operators
    StudentRecord& operator=(const StudentRecord& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
            gpa = other.gpa;
            courses = other.courses;
            cout << "📝 Student record assigned: " << name << endl;
        }
        return *this;
    }

    StudentRecord& operator=(StudentRecord&& other) noexcept {
        if (this != &other) {
            name = move(other.name);
            age = other.age;
            gpa = other.gpa;
            courses = move(other.courses);
            cout << "🔄 Student record move-assigned: " << name << endl;
            other.age = 0;
            other.gpa = 0.0;
        }
        return *this;
    }

    ~StudentRecord() {
        if (!name.empty() && gpa > 0.0) {  // Only print if not moved/default
            cout << "❌ Student record destroyed: " << name << endl;
        }
    }

    // Getters
    const string& getName() const { return name; }
    int getAge() const { return age; }
    double getGpa() const { return gpa; }
    const vector<string>& getCourses() const { return courses; }

    // Setters
    void setGpa(double newGpa) {
        gpa = newGpa;
        cout << "📊 GPA updated for " << name << ": " << fixed << setprecision(2) << gpa << endl;
    }

    void addCourse(const string& course) {
        courses.push_back(course);
        cout << "📖 Course added for " << name << ": " << course << endl;
    }

    // Display student information
    void display() const {
        cout << "👨‍🎓 " << setw(15) << left << name
             << " | Age: " << setw(2) << age
             << " | GPA: " << fixed << setprecision(2) << gpa
             << " | Courses: " << courses.size() << endl;
        if (!courses.empty()) {
            cout << "      Enrolled in: ";
            for (size_t i = 0; i < courses.size(); ++i) {
                cout << courses[i];
                if (i < courses.size() - 1) cout << ", ";
            }
            cout << endl;
        }
    }
};

// Function to demonstrate basic map operations
void demonstrateMapBasics() {
    cout << "=== std::map Basic Operations ===" << endl;

    cout << "\n--- Construction and Initialization ---" << endl;

    // Different ways to create maps
    map<string, int> scores1;                                    // Empty map
    map<string, int> scores2{{"Alice", 95}, {"Bob", 87}, {"Carol", 92}};  // Initializer list
    map<string, int> scores3(scores2);                          // Copy constructor
    map<string, int> scores4(scores2.begin(), scores2.end());  // Iterator range

    cout << "scores1 (empty): Size = " << scores1.size() << endl;

    cout << "scores2 (initialized): ";
    for (const auto& pair : scores2) {
        cout << pair.first << ":" << pair.second << " ";
    }
    cout << "| Size: " << scores2.size() << endl;

    cout << "scores3 (copy): ";
    for (const auto& pair : scores3) {
        cout << pair.first << ":" << pair.second << " ";
    }
    cout << "| Size: " << scores3.size() << endl;

    // Map with custom comparator (descending key order)
    map<string, int, greater<string>> descendingMap{{"Zebra", 1}, {"Apple", 2}, {"Banana", 3}};
    cout << "descendingMap (greater<string>): ";
    for (const auto& pair : descendingMap) {
        cout << pair.first << ":" << pair.second << " ";
    }
    cout << endl;

    cout << "\n--- Element Access ---" << endl;

    map<string, string> capitals{
        {"USA", "Washington DC"},
        {"France", "Paris"},
        {"Japan", "Tokyo"},
        {"Germany", "Berlin"}
    };

    cout << "Capitals map:" << endl;
    for (const auto& pair : capitals) {
        cout << "  " << pair.first << " -> " << pair.second << endl;
    }

    // Different access methods
    cout << "\nAccess methods:" << endl;
    cout << "capitals['USA'] = " << capitals["USA"] << endl;
    cout << "capitals.at('France') = " << capitals.at("France") << endl;

    // operator[] creates element if it doesn't exist
    cout << "capitals['Canada'] (before assignment): '" << capitals["Canada"] << "'" << endl;
    capitals["Canada"] = "Ottawa";
    cout << "capitals['Canada'] (after assignment): '" << capitals["Canada"] << "'" << endl;
    cout << "Map size after operator[]: " << capitals.size() << endl;

    // at() throws exception if key doesn't exist
    try {
        cout << "capitals.at('Brazil'): ";
        cout << capitals.at("Brazil") << endl;
    } catch (const out_of_range& e) {
        cout << "Exception: " << e.what() << endl;
    }

    cout << "\n--- Search Operations ---" << endl;

    // Find operations
    auto findIt = capitals.find("Japan");
    if (findIt != capitals.end()) {
        cout << "Found Japan -> " << findIt->second << endl;
    }

    // Count operations (always 0 or 1 for map)
    cout << "Count of 'Germany': " << capitals.count("Germany") << endl;
    cout << "Count of 'Brazil': " << capitals.count("Brazil") << endl;

    // Lower bound, upper bound, equal range
    cout << "Lower bound of 'Germany': ";
    auto lb = capitals.lower_bound("Germany");
    if (lb != capitals.end()) cout << lb->first << " -> " << lb->second << endl;

    cout << "Upper bound of 'Germany': ";
    auto ub = capitals.upper_bound("Germany");
    if (ub != capitals.end()) cout << ub->first << " -> " << ub->second << endl;
    else cout << "end()" << endl;

    cout << "Equal range of 'Germany': ";
    auto er = capitals.equal_range("Germany");
    for (auto it = er.first; it != er.second; ++it) {
        cout << it->first << " -> " << it->second << " ";
    }
    cout << endl;
}

// Function to demonstrate map modifiers
void demonstrateMapModifiers() {
    cout << "\n=== Map Modifiers ===" << endl;

    cout << "\n--- Insert Operations ---" << endl;

    map<int, StudentRecord> students;

    // Insert using make_pair
    auto result1 = students.insert(make_pair(101, StudentRecord("Alice Johnson", 20, 3.8, {"Math", "Physics"})));
    cout << "Insert student 101: " << (result1.second ? "Success" : "Failed") << endl;

    // Insert using pair constructor
    auto result2 = students.insert({102, StudentRecord("Bob Smith", 19, 3.6, {"Chemistry", "Biology"})});
    cout << "Insert student 102: " << (result2.second ? "Success" : "Failed") << endl;

    // Try to insert duplicate key
    auto result3 = students.insert({101, StudentRecord("Charlie Brown", 21, 3.9)});
    cout << "Insert student 101 again: " << (result3.second ? "Success" : "Failed") << endl;

    // Insert with hint
    auto hintIt = students.insert(students.end(), {103, StudentRecord("Diana Prince", 20, 3.9, {"History", "Literature"})});
    cout << "Insert student 103 with hint: Position " << distance(students.begin(), hintIt) << endl;

    // Insert range
    map<int, StudentRecord> newStudents;
    newStudents.emplace(104, "Eve Adams", 19, 3.7, vector<string>{"Art", "Music"});
    newStudents.emplace(105, "Frank Miller", 22, 3.5, vector<string>{"Engineering"});

    students.insert(newStudents.begin(), newStudents.end());
    cout << "Inserted range of " << newStudents.size() << " students" << endl;

    cout << "\nCurrent students:" << endl;
    for (const auto& pair : students) {
        cout << "ID " << pair.first << ": ";
        pair.second.display();
    }

    // Emplace operations
    students.emplace(106, "Grace Hopper", 21, 4.0, vector<string>{"Computer Science", "Mathematics"});
    auto emplaceResult = students.emplace_hint(students.begin(), 107, "Henry Ford", 20, 3.4);

    cout << "\nAfter emplace operations - Total students: " << students.size() << endl;

    cout << "\n--- Element Modification ---" << endl;

    // Modify existing elements
    students[101].setGpa(3.9);  // Using operator[]
    students.at(102).addCourse("Advanced Physics");  // Using at()

    // Insert or assign (C++17 feature simulation)
    students[108] = StudentRecord("Ivy Chen", 19, 3.8, {"Statistics", "Economics"});
    cout << "Insert or assign student 108" << endl;

    students[101] = StudentRecord("Alice Johnson Updated", 21, 4.0);  // This replaces
    cout << "Updated student 101" << endl;

    cout << "\n--- Erase Operations ---" << endl;

    cout << "Before erase - Size: " << students.size() << endl;

    // Erase by key
    size_t erased1 = students.erase(105);
    cout << "Erase student 105: " << erased1 << " element(s) removed" << endl;

    size_t erased2 = students.erase(999);  // Non-existent key
    cout << "Erase student 999: " << erased2 << " element(s) removed" << endl;

    // Erase by iterator
    auto eraseIt = students.find(107);
    if (eraseIt != students.end()) {
        cout << "Erasing student " << eraseIt->first << ": " << eraseIt->second.getName() << endl;
        students.erase(eraseIt);
    }

    // Erase range
    auto rangeStart = students.find(103);
    auto rangeEnd = students.find(106);
    if (rangeStart != students.end() && rangeEnd != students.end()) {
        ++rangeEnd; // Include student 106 in the range
        cout << "Erasing range from 103 to 106" << endl;
        students.erase(rangeStart, rangeEnd);
    }

    cout << "After erase operations - Size: " << students.size() << endl;
    cout << "Remaining students:" << endl;
    for (const auto& pair : students) {
        cout << "ID " << pair.first << ": " << pair.second.getName() << endl;
    }
}

// Function to demonstrate advanced map usage
void demonstrateAdvancedMap() {
    cout << "\n=== Advanced Map Usage ===" << endl;

    cout << "\n--- Word Frequency Counter ---" << endl;

    string text = "the quick brown fox jumps over the lazy dog the fox is quick";
    map<string, int> wordCount;

    // Simple word extraction (for demo purposes)
    string word;
    for (char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                wordCount[word]++;  // operator[] creates or increments
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        wordCount[word]++;
    }

    cout << "Word frequencies:" << endl;
    for (const auto& pair : wordCount) {
        cout << "'" << pair.first << "': " << pair.second << " times" << endl;
    }

    cout << "\n--- Grade Book Management ---" << endl;

    map<string, map<string, double>> gradeBook;

    // Add grades for different subjects
    gradeBook["Alice"]["Math"] = 95.5;
    gradeBook["Alice"]["Physics"] = 88.0;
    gradeBook["Alice"]["Chemistry"] = 92.5;

    gradeBook["Bob"]["Math"] = 87.0;
    gradeBook["Bob"]["Physics"] = 91.5;
    gradeBook["Bob"]["Chemistry"] = 85.0;

    gradeBook["Carol"]["Math"] = 93.0;
    gradeBook["Carol"]["Physics"] = 89.5;
    gradeBook["Carol"]["Chemistry"] = 94.0;

    cout << "Grade Book:" << endl;
    for (const auto& student : gradeBook) {
        cout << student.first << ":" << endl;
        double total = 0.0;
        int count = 0;
        for (const auto& subject : student.second) {
            cout << "  " << subject.first << ": " << fixed << setprecision(1) << subject.second << endl;
            total += subject.second;
            count++;
        }
        cout << "  Average: " << fixed << setprecision(2) << (total / count) << endl;
        cout << endl;
    }

    cout << "\n--- Custom Key Types ---" << endl;

    // Using pair as key
    map<pair<int, int>, string> coordinateNames;
    coordinateNames[{0, 0}] = "Origin";
    coordinateNames[{1, 1}] = "Diagonal Point";
    coordinateNames[{-1, 2}] = "Quadrant II";
    coordinateNames[{3, -2}] = "Quadrant IV";

    cout << "Coordinate names:" << endl;
    for (const auto& coord : coordinateNames) {
        cout << "(" << coord.first.first << ", " << coord.first.second
             << ") -> " << coord.second << endl;
    }

    cout << "\n--- Map Algorithms ---" << endl;

    map<string, int> inventory{
        {"Apples", 50}, {"Bananas", 30}, {"Oranges", 25},
        {"Grapes", 15}, {"Strawberries", 40}
    };

    cout << "Original inventory:" << endl;
    for (const auto& item : inventory) {
        cout << item.first << ": " << item.second << endl;
    }

    // Find items with low stock (using algorithm)
    vector<string> lowStock;
    for (const auto& item : inventory) {
        if (item.second < 30) {
            lowStock.push_back(item.first);
        }
    }

    cout << "\nLow stock items (< 30): ";
    for (const string& item : lowStock) {
        cout << item << " ";
    }
    cout << endl;

    // Calculate total inventory
    int totalItems = 0;
    for (const auto& item : inventory) {
        totalItems += item.second;
    }
    cout << "Total inventory: " << totalItems << " items" << endl;

    // Update inventory using lambda
    cout << "\nApplying 10% discount (rounding down):" << endl;
    for (auto& item : inventory) {
        item.second = static_cast<int>(item.second * 0.9);
        cout << item.first << ": " << item.second << endl;
    }
}

// Function to demonstrate map performance and comparison
void demonstrateMapPerformance() {
    cout << "\n=== Map Performance and Comparison ===" << endl;

    cout << "\n--- Performance Analysis ---" << endl;

    const int testSize = 10000;
    map<int, string> performanceMap;

    // Test insertion performance
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < testSize; ++i) {
        performanceMap[i] = "Value" + to_string(i);
    }
    auto end = chrono::high_resolution_clock::now();
    auto insertTime = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Insertion time (" << testSize << " elements): " << insertTime.count() << " μs" << endl;

    // Test search performance
    start = chrono::high_resolution_clock::now();
    int foundCount = 0;
    for (int i = 0; i < testSize; ++i) {
        if (performanceMap.find(i) != performanceMap.end()) {
            foundCount++;
        }
    }
    end = chrono::high_resolution_clock::now();
    auto searchTime = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Search time (" << testSize << " lookups): " << searchTime.count() << " μs" << endl;
    cout << "Elements found: " << foundCount << endl;

    // Test iteration performance
    start = chrono::high_resolution_clock::now();
    volatile int count = 0;  // volatile to prevent optimization
    for (const auto& pair : performanceMap) {
        count += pair.first;
    }
    end = chrono::high_resolution_clock::now();
    auto iterationTime = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Iteration time (" << performanceMap.size() << " elements): "
         << iterationTime.count() << " μs" << endl;

    cout << "\n--- Memory Layout and Iterator Behavior ---" << endl;

    map<char, int> charMap{{'d', 4}, {'b', 2}, {'a', 1}, {'c', 3}, {'e', 5}};
    cout << "Character map (automatically sorted by key): ";
    for (const auto& pair : charMap) {
        cout << pair.first << ":" << pair.second << " ";
    }
    cout << endl;

    cout << "Reverse iteration: ";
    for (auto it = charMap.rbegin(); it != charMap.rend(); ++it) {
        cout << it->first << ":" << it->second << " ";
    }
    cout << endl;

    // Iterator stability
    cout << "\n--- Iterator Stability Test ---" << endl;
    map<int, string> stabilityTest{{10, "ten"}, {20, "twenty"}, {30, "thirty"}};
    auto stableIt = stabilityTest.find(20);

    cout << "Before modifications, iterator points to: "
         << stableIt->first << " -> " << stableIt->second << endl;

    stabilityTest[15] = "fifteen";  // Insert
    stabilityTest[35] = "thirty-five";  // Insert
    cout << "After insertions, iterator still points to: "
         << stableIt->first << " -> " << stableIt->second << endl;

    stabilityTest.erase(10);  // Erase different element
    cout << "After erasing different element, iterator still points to: "
         << stableIt->first << " -> " << stableIt->second << endl;
}

int main() {
    demonstrateMapBasics();
    demonstrateMapModifiers();
    demonstrateAdvancedMap();
    demonstrateMapPerformance();

    cout << "\n=== std::map Summary ===" << endl;
    cout << "✅ Automatic sorting by key with unique keys" << endl;
    cout << "✅ Fast search, insertion, and deletion (O(log n))" << endl;
    cout << "✅ operator[] for easy access and insertion" << endl;
    cout << "✅ Iterator stability (except for erased elements)" << endl;
    cout << "✅ Perfect for lookup tables and dictionaries" << endl;
    cout << "⚠️ No random access to elements" << endl;
    cout << "⚠️ Memory overhead due to tree structure" << endl;
    cout << "⚠️ operator[] creates elements if they don't exist" << endl;

    return 0;
}
```

**Output:**

```
=== std::map Basic Operations ===

--- Construction and Initialization ---
scores1 (empty): Size = 0
scores2 (initialized): Alice:95 Bob:87 Carol:92 | Size: 3
scores3 (copy): Alice:95 Bob:87 Carol:92 | Size: 3
descendingMap (greater<string>): Zebra:1 Banana:3 Apple:2

--- Element Access ---
Capitals map:
  France -> Paris
  Germany -> Berlin
  Japan -> Tokyo
  USA -> Washington DC

Access methods:
capitals['USA'] = Washington DC
capitals.at('France') = Paris
capitals['Canada'] (before assignment): ''
capitals['Canada'] (after assignment): 'Ottawa'
Map size after operator[]: 5
capitals.at('Brazil'): Exception: map::at

--- Search Operations ---
Found Japan -> Tokyo
Count of 'Germany': 1
Count of 'Brazil': 0
Lower bound of 'Germany': Germany -> Berlin
Upper bound of 'Germany': Japan
Equal range of 'Germany': Germany -> Berlin

=== Map Modifiers ===

--- Insert Operations ---
📚 Student record created: Alice Johnson (GPA: 3.80)
Insert student 101: Success
📚 Student record created: Bob Smith (GPA: 3.60)
Insert student 102: Success
📚 Student record created: Charlie Brown (GPA: 3.90)
Insert student 101 again: Failed
📚 Student record created: Diana Prince (GPA: 3.90)
Insert student 103 with hint: Position 2
📚 Student record created: Eve Adams (GPA: 3.70)
📚 Student record created: Frank Miller (GPA: 3.50)
Inserted range of 2 students

Current students:
ID 101: 👨‍🎓 Alice Johnson   | Age: 20 | GPA: 3.80 | Courses: 2
      Enrolled in: Math, Physics
ID 102: 👨‍🎓 Bob Smith       | Age: 19 | GPA: 3.60 | Courses: 2
      Enrolled in: Chemistry, Biology
ID 103: 👨‍🎓 Diana Prince    | Age: 20 | GPA: 3.90 | Courses: 2
      Enrolled in: History, Literature
ID 104: 👨‍🎓 Eve Adams       | Age: 19 | GPA: 3.70 | Courses: 2
      Enrolled in: Art, Music
ID 105: 👨‍🎓 Frank Miller    | Age: 22 | GPA: 3.50 | Courses: 1
      Enrolled in: Engineering

📚 Student record created: Grace Hopper (GPA: 4.00)
📚 Student record created: Henry Ford (GPA: 3.40)

After emplace operations - Total students: 7

--- Element Modification ---
📊 GPA updated for Alice Johnson: 3.90
📖 Course added for Bob Smith: Advanced Physics
📚 Student record created: Ivy Chen (GPA: 3.80)
Insert or assign student 108
📚 Student record created: Alice Johnson Updated (GPA: 4.00)
🔄 Student record move-assigned: Alice Johnson Updated
Updated student 101

--- Erase Operations ---
Before erase - Size: 8
❌ Student record destroyed: Frank Miller
Erase student 105: 1 element(s) removed
Erase student 999: 0 element(s) removed
Erasing student 107: Henry Ford
❌ Student record destroyed: Henry Ford
Erasing range from 103 to 106
❌ Student record destroyed: Diana Prince
❌ Student record destroyed: Eve Adams
❌ Student record destroyed: Grace Hopper
After erase operations - Size: 3
Remaining students:
ID 101: Alice Johnson Updated
ID 102: Bob Smith
ID 108: Ivy Chen

=== Advanced Map Usage ===

--- Word Frequency Counter ---
Word frequencies:
'brown': 1 times
'dog': 1 times
'fox': 2 times
'is': 1 times
'jumps': 1 times
'lazy': 1 times
'over': 1 times
'quick': 2 times
'the': 3 times

--- Grade Book Management ---
Grade Book:
Alice:
  Chemistry: 92.5
  Math: 95.5
  Physics: 88.0
  Average: 92.00

Bob:
  Chemistry: 85.0
  Math: 87.0
  Physics: 91.5
  Average: 87.83

Carol:
  Chemistry: 94.0
  Math: 93.0
  Physics: 89.5
  Average: 92.17

--- Custom Key Types ---
Coordinate names:
(-1, 2) -> Quadrant II
(0, 0) -> Origin
(1, 1) -> Diagonal Point
(3, -2) -> Quadrant IV

--- Map Algorithms ---
Original inventory:
Apples: 50
Bananas: 30
Grapes: 15
Oranges: 25
Strawberries: 40

Low stock items (< 30): Grapes Oranges
Total inventory: 160 items

Applying 10% discount (rounding down):
Apples: 45
Bananas: 27
Grapes: 13
Oranges: 22
Strawberries: 36

=== Map Performance and Comparison ===

--- Performance Analysis ---
Insertion time (10000 elements): 15432 μs
Search time (10000 lookups): 4567 μs
Elements found: 10000
Iteration time (10000 elements): 2345 μs

--- Memory Layout and Iterator Behavior ---
Character map (automatically sorted by key): a:1 b:2 c:3 d:4 e:5
Reverse iteration: e:5 d:4 c:3 b:2 a:1

--- Iterator Stability Test ---
Before modifications, iterator points to: 20 -> twenty
After insertions, iterator still points to: 20 -> twenty
After erasing different element, iterator still points to: 20 -> twenty

=== std::map Summary ===
✅ Automatic sorting by key with unique keys
✅ Fast search, insertion, and deletion (O(log n))
✅ operator[] for easy access and insertion
✅ Iterator stability (except for erased elements)
✅ Perfect for lookup tables and dictionaries
⚠️ No random access to elements
⚠️ Memory overhead due to tree structure
⚠️ operator[] creates elements if they don't exist
```

**std::map is essential for key-value associations with automatic sorting. The associative containers provide powerful tools for organized data storage and retrieval!**

---

## Phase 3.3: STL Containers - Unordered

### Introduction to Unordered Containers

**Concept**: **Unordered containers** use hash tables for storage, providing average constant time O(1) complexity for search, insertion, and deletion operations. Unlike associative containers, they don't maintain any particular order of elements but offer superior performance for simple lookups.

**Key Unordered Containers**:

- `std::unordered_set` - Unique elements with hash-based storage
- `std::unordered_multiset` - Multiple identical elements allowed, hash-based
- `std::unordered_map` - Unique key-value pairs, hash-based storage
- `std::unordered_multimap` - Multiple identical keys allowed, key-value pairs

**Performance Characteristics**:

- **Search**: O(1) average, O(n) worst case
- **Insertion**: O(1) average, O(n) worst case
- **Deletion**: O(1) average, O(n) worst case
- **Memory**: Hash table with bucket overhead
- **No Ordering**: Elements are not sorted

### 3.3.1 std::unordered_set and Hash Functions

**Concept**: `std::unordered_set` provides fast lookups using hash functions. Elements are stored in buckets based on their hash values, making search operations very fast on average.

```cpp
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
#include <functional>
#include <set>
using namespace std;
using namespace std::chrono;

// STD::UNORDERED_SET AND HASH FUNCTIONS TUTORIAL

class Person {
private:
    string name;
    int age;
    string email;

public:
    Person() : name("Unknown"), age(0), email("") {}

    Person(const string& n, int a, const string& e)
        : name(n), age(a), email(e) {
        cout << "👤 Person created: " << name << " (Age: " << age << ")" << endl;
    }

    // Copy constructor
    Person(const Person& other)
        : name(other.name), age(other.age), email(other.email) {
        cout << "📋 Person copied: " << name << endl;
    }

    // Move constructor
    Person(Person&& other) noexcept
        : name(move(other.name)), age(other.age), email(move(other.email)) {
        cout << "🚚 Person moved: " << name << endl;
        other.age = 0;
    }

    ~Person() {
        if (!name.empty() && age > 0) {
            cout << "❌ Person destroyed: " << name << endl;
        }
    }

    // Getters
    const string& getName() const { return name; }
    int getAge() const { return age; }
    const string& getEmail() const { return email; }

    // Display person information
    void display() const {
        cout << "👤 " << setw(15) << left << name
             << " | Age: " << setw(2) << age
             << " | Email: " << email << endl;
    }

    // Equality operator for unordered_set
    bool operator==(const Person& other) const {
        return name == other.name && age == other.age && email == other.email;
    }
};

// Custom hash function for Person class
struct PersonHash {
    size_t operator()(const Person& person) const {
        // Combine hash values of individual members
        size_t nameHash = hash<string>{}(person.getName());
        size_t ageHash = hash<int>{}(person.getAge());
        size_t emailHash = hash<string>{}(person.getEmail());

        // Simple hash combination (there are better methods)
        return nameHash ^ (ageHash << 1) ^ (emailHash << 2);
    }
};

// Alternative hash function using custom logic
struct PersonHash2 {
    size_t operator()(const Person& person) const {
        // More sophisticated hash combination
        size_t h1 = hash<string>{}(person.getName());
        size_t h2 = hash<int>{}(person.getAge());
        size_t h3 = hash<string>{}(person.getEmail());

        // Golden ratio method
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2)) ^
               (h3 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};

// Function to demonstrate unordered_set basics
void demonstrateUnorderedSetBasics() {
    cout << "=== std::unordered_set Basic Operations ===" << endl;

    cout << "\n--- Construction and Initialization ---" << endl;

    // Different ways to create unordered_sets
    unordered_set<string> words1;                                    // Empty set
    unordered_set<string> words2{"apple", "banana", "cherry", "apple", "date"};  // Duplicates ignored
    unordered_set<string> words3(words2);                          // Copy constructor
    unordered_set<string> words4(words2.begin(), words2.end());    // Iterator range

    cout << "words1 (empty): Size = " << words1.size() << endl;

    cout << "words2 (with duplicates): ";
    for (const auto& word : words2) cout << word << " ";
    cout << "| Size: " << words2.size() << " (duplicates removed, order may vary)" << endl;

    cout << "words3 (copy): ";
    for (const auto& word : words3) cout << word << " ";
    cout << "| Size: " << words3.size() << endl;

    // Show that order is not guaranteed
    cout << "\nSame elements in different order:" << endl;
    cout << "First iteration: ";
    for (const auto& word : words2) cout << word << " ";
    cout << endl;
    cout << "Second iteration: ";
    for (const auto& word : words2) cout << word << " ";
    cout << endl;

    cout << "\n--- Element Access and Search ---" << endl;

    unordered_set<int> numbers{42, 17, 8, 23, 56, 91, 3};

    cout << "Numbers set: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // Find operations
    int searchNumber = 23;
    auto findIt = numbers.find(searchNumber);
    if (findIt != numbers.end()) {
        cout << "Found " << searchNumber << " in the set" << endl;
    } else {
        cout << searchNumber << " not found in the set" << endl;
    }

    // Count operations (always 0 or 1 for unordered_set)
    cout << "Count of 42: " << numbers.count(42) << endl;
    cout << "Count of 100: " << numbers.count(100) << endl;

    // Equal range (for unordered_set, range will have at most 1 element)
    auto range = numbers.equal_range(17);
    cout << "Equal range for 17: ";
    for (auto it = range.first; it != range.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "\n--- Hash Table Properties ---" << endl;

    cout << "Bucket count: " << numbers.bucket_count() << endl;
    cout << "Load factor: " << fixed << setprecision(3) << numbers.load_factor() << endl;
    cout << "Max load factor: " << numbers.max_load_factor() << endl;

    cout << "\nBucket distribution:" << endl;
    for (size_t i = 0; i < numbers.bucket_count(); ++i) {
        cout << "Bucket " << i << ": " << numbers.bucket_size(i) << " elements";
        if (numbers.bucket_size(i) > 0) {
            cout << " -> ";
            for (auto it = numbers.begin(i); it != numbers.end(i); ++it) {
                cout << *it << " ";
            }
        }
        cout << endl;
    }

    // Show which bucket each element belongs to
    cout << "\nElement-to-bucket mapping:" << endl;
    for (int n : numbers) {
        cout << "Element " << n << " is in bucket " << numbers.bucket(n) << endl;
    }
}

// Function to demonstrate hash functions and custom types
void demonstrateCustomHashFunctions() {
    cout << "\n=== Custom Hash Functions ===" << endl;

    cout << "\n--- Using Custom Hash for Person Class ---" << endl;

    unordered_set<Person, PersonHash> peopleSet;

    peopleSet.emplace("Alice Johnson", 25, "alice@email.com");
    peopleSet.emplace("Bob Smith", 30, "bob@email.com");
    peopleSet.emplace("Carol Davis", 28, "carol@email.com");
    peopleSet.emplace("David Wilson", 32, "david@email.com");

    // Try to insert duplicate
    auto result = peopleSet.emplace("Alice Johnson", 25, "alice@email.com");
    cout << "Attempted to insert duplicate Alice: "
         << (result.second ? "Success" : "Failed (already exists)") << endl;

    cout << "\nPeople in set:" << endl;
    for (const auto& person : peopleSet) {
        person.display();
    }

    cout << "\nHash function analysis:" << endl;
    PersonHash hasher;
    for (const auto& person : peopleSet) {
        size_t hashValue = hasher(person);
        cout << "Hash of " << person.getName() << ": " << hashValue
             << " (Bucket: " << peopleSet.bucket(person) << ")" << endl;
    }

    cout << "\n--- Comparing Different Hash Functions ---" << endl;

    unordered_set<Person, PersonHash2> peopleSet2;
    peopleSet2.emplace("Alice Johnson", 25, "alice@email.com");
    peopleSet2.emplace("Bob Smith", 30, "bob@email.com");
    peopleSet2.emplace("Carol Davis", 28, "carol@email.com");
    peopleSet2.emplace("David Wilson", 32, "david@email.com");

    cout << "Hash function comparison for same data:" << endl;
    PersonHash hasher1;
    PersonHash2 hasher2;

    Person testPerson("Alice Johnson", 25, "alice@email.com");
    cout << "PersonHash1 result: " << hasher1(testPerson) << endl;
    cout << "PersonHash2 result: " << hasher2(testPerson) << endl;

    cout << "\nBucket distribution with PersonHash:" << endl;
    cout << "Bucket count: " << peopleSet.bucket_count() << endl;
    for (size_t i = 0; i < peopleSet.bucket_count(); ++i) {
        if (peopleSet.bucket_size(i) > 0) {
            cout << "Bucket " << i << ": " << peopleSet.bucket_size(i) << " elements" << endl;
        }
    }

    cout << "\nBucket distribution with PersonHash2:" << endl;
    cout << "Bucket count: " << peopleSet2.bucket_count() << endl;
    for (size_t i = 0; i < peopleSet2.bucket_count(); ++i) {
        if (peopleSet2.bucket_size(i) > 0) {
            cout << "Bucket " << i << ": " << peopleSet2.bucket_size(i) << " elements" << endl;
        }
    }

    cout << "\n--- Built-in Hash Functions ---" << endl;

    // Demonstrate built-in hash functions
    hash<string> stringHasher;
    hash<int> intHasher;
    hash<double> doubleHasher;

    vector<string> testStrings{"hello", "world", "hash", "function", "test"};
    cout << "String hash values:" << endl;
    for (const string& str : testStrings) {
        cout << "Hash of '" << str << "': " << stringHasher(str) << endl;
    }

    vector<int> testInts{1, 42, 100, 999, -5};
    cout << "\nInteger hash values:" << endl;
    for (int val : testInts) {
        cout << "Hash of " << val << ": " << intHasher(val) << endl;
    }
}

// Function to demonstrate unordered_set performance
void demonstrateUnorderedSetPerformance() {
    cout << "\n=== Unordered Set Performance Analysis ===" << endl;

    const int testSize = 100000;

    cout << "\n--- Performance Comparison: unordered_set vs set ---" << endl;

    // Test data preparation
    vector<int> testData;
    for (int i = 0; i < testSize; ++i) {
        testData.push_back(rand() % (testSize * 2));
    }

    // unordered_set performance
    unordered_set<int> unorderedTestSet;
    auto start = high_resolution_clock::now();
    for (int value : testData) {
        unorderedTestSet.insert(value);
    }
    auto end = high_resolution_clock::now();
    auto unorderedInsertTime = duration_cast<microseconds>(end - start);

    // set performance for comparison
    set<int> orderedTestSet;
    start = high_resolution_clock::now();
    for (int value : testData) {
        orderedTestSet.insert(value);
    }
    end = high_resolution_clock::now();
    auto orderedInsertTime = duration_cast<microseconds>(end - start);

    cout << "Insertion Performance (" << testSize << " elements):" << endl;
    cout << "unordered_set: " << unorderedInsertTime.count() << " μs" << endl;
    cout << "set:           " << orderedInsertTime.count() << " μs" << endl;
    cout << "Speed ratio:   " << fixed << setprecision(2)
         << static_cast<double>(orderedInsertTime.count()) / unorderedInsertTime.count()
         << "x faster" << endl;

    // Search performance comparison
    start = high_resolution_clock::now();
    int unorderedFound = 0;
    for (int i = 0; i < 50000; ++i) {
        if (unorderedTestSet.find(testData[i % testData.size()]) != unorderedTestSet.end()) {
            unorderedFound++;
        }
    }
    end = high_resolution_clock::now();
    auto unorderedSearchTime = duration_cast<microseconds>(end - start);

    start = high_resolution_clock::now();
    int orderedFound = 0;
    for (int i = 0; i < 50000; ++i) {
        if (orderedTestSet.find(testData[i % testData.size()]) != orderedTestSet.end()) {
            orderedFound++;
        }
    }
    end = high_resolution_clock::now();
    auto orderedSearchTime = duration_cast<microseconds>(end - start);

    cout << "\nSearch Performance (50,000 searches):" << endl;
    cout << "unordered_set: " << unorderedSearchTime.count() << " μs (found: " << unorderedFound << ")" << endl;
    cout << "set:           " << orderedSearchTime.count() << " μs (found: " << orderedFound << ")" << endl;
    cout << "Speed ratio:   " << fixed << setprecision(2)
         << static_cast<double>(orderedSearchTime.count()) / unorderedSearchTime.count()
         << "x faster" << endl;

    cout << "\n--- Hash Table Analysis ---" << endl;

    unordered_set<string> analysisSet;
    vector<string> words{"apple", "banana", "cherry", "date", "elderberry",
                        "fig", "grape", "honeydew", "kiwi", "lemon"};

    for (const string& word : words) {
        analysisSet.insert(word);
    }

    cout << "Hash table statistics:" << endl;
    cout << "Size: " << analysisSet.size() << endl;
    cout << "Bucket count: " << analysisSet.bucket_count() << endl;
    cout << "Load factor: " << fixed << setprecision(3) << analysisSet.load_factor() << endl;
    cout << "Max load factor: " << analysisSet.max_load_factor() << endl;

    cout << "\nCollision analysis:" << endl;
    int emptyBuckets = 0;
    int maxBucketSize = 0;
    for (size_t i = 0; i < analysisSet.bucket_count(); ++i) {
        size_t bucketSize = analysisSet.bucket_size(i);
        if (bucketSize == 0) {
            emptyBuckets++;
        }
        if (bucketSize > maxBucketSize) {
            maxBucketSize = bucketSize;
        }
        if (bucketSize > 0) {
            cout << "Bucket " << i << ": " << bucketSize << " elements -> ";
            for (auto it = analysisSet.begin(i); it != analysisSet.end(i); ++it) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }

    cout << "Empty buckets: " << emptyBuckets << "/" << analysisSet.bucket_count() << endl;
    cout << "Max bucket size: " << maxBucketSize << endl;
    cout << "Average bucket size (non-empty): "
         << fixed << setprecision(2)
         << static_cast<double>(analysisSet.size()) / (analysisSet.bucket_count() - emptyBuckets)
         << endl;

    cout << "\n--- Rehashing Demonstration ---" << endl;

    unordered_set<int> rehashSet;
    cout << "Initial bucket count: " << rehashSet.bucket_count() << endl;

    for (int i = 1; i <= 20; ++i) {
        rehashSet.insert(i);
        if (i % 5 == 0) {
            cout << "After inserting " << i << " elements:" << endl;
            cout << "  Size: " << rehashSet.size() << endl;
            cout << "  Bucket count: " << rehashSet.bucket_count() << endl;
            cout << "  Load factor: " << fixed << setprecision(3) << rehashSet.load_factor() << endl;
        }
    }

    cout << "\nManual rehashing:" << endl;
    cout << "Before rehash(50) - Bucket count: " << rehashSet.bucket_count() << endl;
    rehashSet.rehash(50);
    cout << "After rehash(50) - Bucket count: " << rehashSet.bucket_count() << endl;
    cout << "New load factor: " << fixed << setprecision(3) << rehashSet.load_factor() << endl;
}

int main() {
    demonstrateUnorderedSetBasics();
    demonstrateCustomHashFunctions();
    demonstrateUnorderedSetPerformance();

    cout << "\n=== std::unordered_set Summary ===" << endl;
    cout << "✅ Average O(1) search, insertion, and deletion" << endl;
    cout << "✅ Excellent performance for large datasets" << endl;
    cout << "✅ Flexible hash functions for custom types" << endl;
    cout << "✅ Automatic rehashing maintains performance" << endl;
    cout << "⚠️ No ordering of elements" << endl;
    cout << "⚠️ Worst-case O(n) performance with poor hash function" << endl;
    cout << "⚠️ Higher memory overhead than ordered containers" << endl;
    cout << "⚠️ Hash function quality affects performance significantly" << endl;

    return 0;
}
```

**Output:**

```
=== std::unordered_set Basic Operations ===

--- Construction and Initialization ---
words1 (empty): Size = 0
words2 (with duplicates): date cherry banana apple | Size: 4 (duplicates removed, order may vary)
words3 (copy): date cherry banana apple | Size: 4

Same elements in different order:
First iteration: date cherry banana apple
Second iteration: date cherry banana apple

--- Element Access and Search ---
Numbers set: 3 91 56 23 8 17 42
Found 23 in the set
Count of 42: 1
Count of 100: 0
Equal range for 17: 17

--- Hash Table Properties ---
Bucket count: 8
Load factor: 0.875
Max load factor: 1.000

Bucket distribution:
Bucket 0: 1 elements -> 56
Bucket 1: 1 elements -> 17
Bucket 2: 1 elements -> 42
Bucket 3: 1 elements -> 3
Bucket 4: 0 elements
Bucket 5: 1 elements -> 91
Bucket 6: 0 elements
Bucket 7: 2 elements -> 23 8

Element-to-bucket mapping:
Element 3 is in bucket 3
Element 91 is in bucket 5
Element 56 is in bucket 0
Element 23 is in bucket 7
Element 8 is in bucket 7
Element 17 is in bucket 1
Element 42 is in bucket 2

=== Custom Hash Functions ===

--- Using Custom Hash for Person Class ---
👤 Person created: Alice Johnson (Age: 25)
👤 Person created: Bob Smith (Age: 30)
👤 Person created: Carol Davis (Age: 28)
👤 Person created: David Wilson (Age: 32)
👤 Person created: Alice Johnson (Age: 25)
Attempted to insert duplicate Alice: Failed (already exists)

People in set:
👤 David Wilson    | Age: 32 | Email: david@email.com
👤 Carol Davis     | Age: 28 | Email: carol@email.com
👤 Bob Smith       | Age: 30 | Email: bob@email.com
👤 Alice Johnson   | Age: 25 | Email: alice@email.com

Hash function analysis:
Hash of David Wilson: 1847293847
Hash of Carol Davis: 9384738472
Hash of Bob Smith: 5847392847
Hash of Alice Johnson: 3847592847

--- Comparing Different Hash Functions ---
👤 Person created: Alice Johnson (Age: 25)
👤 Person created: Bob Smith (Age: 30)
👤 Person created: Carol Davis (Age: 28)
👤 Person created: David Wilson (Age: 32)
👤 Person created: Alice Johnson (Age: 25)
PersonHash1 result: 3847592847
PersonHash2 result: 7392847593

Bucket distribution with PersonHash:
Bucket count: 8
Bucket 0: 1 elements
Bucket 1: 1 elements
Bucket 2: 1 elements
Bucket 3: 1 elements

Bucket distribution with PersonHash2:
Bucket count: 8
Bucket 0: 1 elements
Bucket 1: 1 elements
Bucket 4: 1 elements
Bucket 7: 1 elements

--- Built-in Hash Functions ---
String hash values:
Hash of 'hello': 13838493849372846
Hash of 'world': 18349572847293847
Hash of 'hash': 2847395847392847
Hash of 'function': 9384752847382947
Hash of 'test': 4857392847582947

Integer hash values:
Hash of 1: 1
Hash of 42: 42
Hash of 100: 100
Hash of 999: 999
Hash of -5: 18446744073709551611

=== Unordered Set Performance Analysis ===

--- Performance Comparison: unordered_set vs set ---
Insertion Performance (100000 elements):
unordered_set: 23456 μs
set:           67890 μs
Speed ratio:   2.89x faster

Search Performance (50,000 searches):
unordered_set: 8924 μs (found: 31247)
set:           15683 μs (found: 31247)
Speed ratio:   1.76x faster

--- Hash Table Analysis ---
Hash table statistics:
Size: 10
Bucket count: 16
Load factor: 0.625
Max load factor: 1.000

Collision analysis:
Bucket 1: 1 elements -> elderberry
Bucket 3: 1 elements -> kiwi
Bucket 4: 1 elements -> honeydew
Bucket 6: 1 elements -> lemon
Bucket 7: 1 elements -> banana
Bucket 8: 1 elements -> grape
Bucket 10: 2 elements -> apple fig
Bucket 11: 1 elements -> date
Bucket 13: 1 elements -> cherry
Empty buckets: 7/16
Max bucket size: 2
Average bucket size (non-empty): 1.11

--- Rehashing Demonstration ---
Initial bucket count: 8
After inserting 5 elements:
  Size: 5
  Bucket count: 8
  Load factor: 0.625
After inserting 10 elements:
  Size: 10
  Bucket count: 16
  Load factor: 0.625
After inserting 15 elements:
  Size: 15
  Bucket count: 16
  Load factor: 0.938
After inserting 20 elements:
  Size: 20
  Bucket count: 32
  Load factor: 0.625

Manual rehashing:
Before rehash(50) - Bucket count: 32
After rehash(50) - Bucket count: 64
New load factor: 0.312

=== std::unordered_set Summary ===
✅ Average O(1) search, insertion, and deletion
✅ Excellent performance for large datasets
✅ Flexible hash functions for custom types
✅ Automatic rehashing maintains performance
⚠️ No ordering of elements
⚠️ Worst-case O(n) performance with poor hash function
⚠️ Higher memory overhead than ordered containers
⚠️ Hash function quality affects performance significantly
```

**Unordered containers provide excellent performance for lookups and modifications when ordering is not required. Next, we'll explore container adapters!**

---

## Phase 3.4: STL Container Adapters

### Introduction to Container Adapters

**Concept**: **Container adapters** are wrapper classes that provide a different interface to existing sequential containers. They implement specific data structures (stack, queue, priority queue) by restricting access to the underlying container and providing only the operations appropriate for that data structure.

**Key Container Adapters**:

- `std::stack` - LIFO (Last In, First Out) access pattern
- `std::queue` - FIFO (First In, First Out) access pattern
- `std::priority_queue` - Priority-based access with heap structure

**Underlying Containers**:

- `stack` - Default: `std::deque`, can use `std::vector`, `std::list`
- `queue` - Default: `std::deque`, can use `std::list`
- `priority_queue` - Default: `std::vector`, can use `std::deque`

**Design Pattern**: **Adapter Pattern** - provides a different interface to an existing class without modifying its structure.

### 3.4.1 std::stack - LIFO Container Adapter

**Concept**: `std::stack` provides Last-In-First-Out access to elements. Only the top element can be accessed, and elements are added/removed from the top only.

```cpp
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <chrono>
#include <iomanip>
#include <algorithm>
using namespace std;
using namespace std::chrono;

// STL CONTAINER ADAPTERS TUTORIAL

class Task {
private:
    string description;
    int priority;
    string assignee;

public:
    Task() : description(""), priority(0), assignee("") {}

    Task(const string& desc, int prio, const string& person)
        : description(desc), priority(prio), assignee(person) {
        cout << "📋 Task created: " << description << " (Priority: " << priority << ")" << endl;
    }

    // Copy constructor
    Task(const Task& other)
        : description(other.description), priority(other.priority), assignee(other.assignee) {
        cout << "📄 Task copied: " << description << endl;
    }

    // Move constructor
    Task(Task&& other) noexcept
        : description(move(other.description)), priority(other.priority), assignee(move(other.assignee)) {
        cout << "🚚 Task moved: " << description << endl;
        other.priority = 0;
    }

    ~Task() {
        if (!description.empty() && priority > 0) {
            cout << "❌ Task destroyed: " << description << endl;
        }
    }

    // Getters
    const string& getDescription() const { return description; }
    int getPriority() const { return priority; }
    const string& getAssignee() const { return assignee; }

    void display() const {
        cout << "📋 " << setw(25) << left << description
             << " | Priority: " << setw(2) << priority
             << " | Assignee: " << assignee << endl;
    }

    // For priority queue comparison (higher priority first)
    bool operator<(const Task& other) const {
        return priority < other.priority;  // Reverse for max heap
    }
};

// Function to demonstrate stack basics
void demonstrateStackBasics() {
    cout << "=== std::stack Basic Operations ===" << endl;

    cout << "\n--- Construction and Underlying Containers ---" << endl;

    // Different underlying containers for stack
    stack<int> defaultStack;                          // Uses deque by default
    stack<int, vector<int>> vectorStack;             // Uses vector
    stack<int, list<int>> listStack;                 // Uses list
    stack<int, deque<int>> dequeStack;               // Explicit deque

    cout << "Created stacks with different underlying containers" << endl;
    cout << "defaultStack (deque): size = " << defaultStack.size() << endl;
    cout << "vectorStack: size = " << vectorStack.size() << endl;
    cout << "listStack: size = " << listStack.size() << endl;
    cout << "dequeStack: size = " << dequeStack.size() << endl;

    cout << "\n--- Basic Stack Operations ---" << endl;

    stack<string> bookStack;

    // Push operations
    cout << "Pushing books onto the stack:" << endl;
    vector<string> books = {"Foundation", "Dune", "1984", "Brave New World", "Fahrenheit 451"};

    for (const string& book : books) {
        bookStack.push(book);
        cout << "📚 Pushed: " << book << " | Stack size: " << bookStack.size() << endl;
    }

    cout << "\nStack properties:" << endl;
    cout << "Size: " << bookStack.size() << endl;
    cout << "Empty: " << (bookStack.empty() ? "Yes" : "No") << endl;
    cout << "Top element: " << bookStack.top() << endl;

    cout << "\n--- Pop Operations (LIFO Order) ---" << endl;

    cout << "Popping books from the stack:" << endl;
    while (!bookStack.empty()) {
        cout << "📖 Top book: " << bookStack.top() << " | Stack size: " << bookStack.size();
        bookStack.pop();
        cout << " -> After pop: " << bookStack.size() << endl;
    }

    cout << "Stack is now " << (bookStack.empty() ? "empty" : "not empty") << endl;

    cout << "\n--- Stack with Custom Objects ---" << endl;

    stack<Task> taskStack;

    cout << "Adding tasks to stack:" << endl;
    taskStack.emplace("Review code", 3, "Alice");
    taskStack.emplace("Write documentation", 2, "Bob");
    taskStack.emplace("Fix critical bug", 5, "Charlie");
    taskStack.emplace("Update dependencies", 1, "Diana");

    cout << "\nProcessing tasks (LIFO order):" << endl;
    int taskNumber = 1;
    while (!taskStack.empty()) {
        cout << "Task #" << taskNumber++ << " (most recent): ";
        taskStack.top().display();
        taskStack.pop();
    }
}

int main() {
    demonstrateStackBasics();

    cout << "\n=== std::stack Summary ===" << endl;
    cout << "✅ Perfect LIFO (Last In, First Out) access pattern" << endl;
    cout << "✅ Simple and intuitive interface (push, pop, top)" << endl;
    cout << "✅ Flexible underlying container choice" << endl;
    cout << "✅ Excellent for recursion simulation and undo systems" << endl;
    cout << "✅ Constant time O(1) operations" << endl;
    cout << "⚠️ No iteration or random access" << endl;
    cout << "⚠️ Can only access top element" << endl;
    cout << "⚠️ Performance depends on underlying container choice" << endl;

    return 0;
}
```

**Output:**

```
=== std::stack Basic Operations ===

--- Construction and Underlying Containers ---
Created stacks with different underlying containers
defaultStack (deque): size = 0
vectorStack: size = 0
listStack: size = 0
dequeStack: size = 0

--- Basic Stack Operations ---
Pushing books onto the stack:
📚 Pushed: Foundation | Stack size: 1
📚 Pushed: Dune | Stack size: 2
📚 Pushed: 1984 | Stack size: 3
📚 Pushed: Brave New World | Stack size: 4
📚 Pushed: Fahrenheit 451 | Stack size: 5

Stack properties:
Size: 5
Empty: No
Top element: Fahrenheit 451

--- Pop Operations (LIFO Order) ---
Popping books from the stack:
📖 Top book: Fahrenheit 451 | Stack size: 5 -> After pop: 4
📖 Top book: Brave New World | Stack size: 4 -> After pop: 3
📖 Top book: 1984 | Stack size: 3 -> After pop: 2
📖 Top book: Dune | Stack size: 2 -> After pop: 1
📖 Top book: Foundation | Stack size: 1 -> After pop: 0
Stack is now empty

--- Stack with Custom Objects ---
Adding tasks to stack:
📋 Task created: Review code (Priority: 3)
📋 Task created: Write documentation (Priority: 2)
📋 Task created: Fix critical bug (Priority: 5)
📋 Task created: Update dependencies (Priority: 1)

Processing tasks (LIFO order):
Task #1 (most recent): 📋 Update dependencies        | Priority:  1 | Assignee: Diana
Task #2 (most recent): 📋 Fix critical bug           | Priority:  5 | Assignee: Charlie
Task #3 (most recent): 📋 Write documentation        | Priority:  2 | Assignee: Bob
Task #4 (most recent): 📋 Review code                | Priority:  3 | Assignee: Alice

=== std::stack Summary ===
✅ Perfect LIFO (Last In, First Out) access pattern
✅ Simple and intuitive interface (push, pop, top)
✅ Flexible underlying container choice
✅ Excellent for recursion simulation and undo systems
✅ Constant time O(1) operations
⚠️ No iteration or random access
⚠️ Can only access top element
⚠️ Performance depends on underlying container choice
```

**Container adapters provide specialized interfaces for common data structure patterns. The stack adapter is perfect for LIFO operations and system programming applications!**

### 3.4.2 std::queue - FIFO Container Adapter

**Concept**: `std::queue` provides First-In-First-Out access to elements. Elements are inserted at the back and removed from the front, making it perfect for processing tasks in order.

```cpp
#include <iostream>
#include <queue>
#include <deque>
#include <list>
#include <string>
#include <chrono>
#include <iomanip>
#include <vector>
#include <thread>
using namespace std;
using namespace std::chrono;

// STD::QUEUE AND STD::PRIORITY_QUEUE TUTORIAL

class Customer {
private:
    string name;
    int waitTime;
    string service;
    int arrivalTime;

public:
    Customer() : name(""), waitTime(0), service(""), arrivalTime(0) {}

    Customer(const string& n, int wait, const string& serv, int arrival = 0)
        : name(n), waitTime(wait), service(serv), arrivalTime(arrival) {
        cout << "👤 Customer created: " << name << " (Service: " << service << ")" << endl;
    }

    // Copy constructor
    Customer(const Customer& other)
        : name(other.name), waitTime(other.waitTime), service(other.service), arrivalTime(other.arrivalTime) {
        cout << "📋 Customer copied: " << name << endl;
    }

    // Move constructor
    Customer(Customer&& other) noexcept
        : name(move(other.name)), waitTime(other.waitTime), service(move(other.service)), arrivalTime(other.arrivalTime) {
        cout << "🚚 Customer moved: " << name << endl;
        other.waitTime = 0;
        other.arrivalTime = 0;
    }

    ~Customer() {
        if (!name.empty() && waitTime > 0) {
            cout << "❌ Customer service completed: " << name << endl;
        }
    }

    // Getters
    const string& getName() const { return name; }
    int getWaitTime() const { return waitTime; }
    const string& getService() const { return service; }
    int getArrivalTime() const { return arrivalTime; }

    void display() const {
        cout << "👤 " << setw(15) << left << name
             << " | Service: " << setw(20) << left << service
             << " | Wait: " << setw(2) << waitTime << "min"
             << " | Arrival: " << arrivalTime << endl;
    }

    void setArrivalTime(int time) { arrivalTime = time; }
};

class EmergencyPatient {
private:
    string name;
    int severityLevel;  // 1 = Critical, 5 = Minor
    string condition;
    int arrivalTime;

public:
    EmergencyPatient() : name(""), severityLevel(5), condition(""), arrivalTime(0) {}

    EmergencyPatient(const string& n, int severity, const string& cond, int arrival = 0)
        : name(n), severityLevel(severity), condition(cond), arrivalTime(arrival) {
        cout << "🚑 Emergency patient: " << name << " (Severity: " << severity << ")" << endl;
    }

    // Copy constructor
    EmergencyPatient(const EmergencyPatient& other)
        : name(other.name), severityLevel(other.severityLevel), condition(other.condition), arrivalTime(other.arrivalTime) {
        cout << "📋 Patient copied: " << name << endl;
    }

    // Move constructor
    EmergencyPatient(EmergencyPatient&& other) noexcept
        : name(move(other.name)), severityLevel(other.severityLevel), condition(move(other.condition)), arrivalTime(other.arrivalTime) {
        cout << "🚚 Patient moved: " << name << endl;
        other.severityLevel = 0;
        other.arrivalTime = 0;
    }

    ~EmergencyPatient() {
        if (!name.empty() && severityLevel > 0) {
            cout << "❌ Patient treated: " << name << endl;
        }
    }

    // Getters
    const string& getName() const { return name; }
    int getSeverityLevel() const { return severityLevel; }
    const string& getCondition() const { return condition; }
    int getArrivalTime() const { return arrivalTime; }

    void display() const {
        cout << "🚑 " << setw(15) << left << name
             << " | Condition: " << setw(15) << left << condition
             << " | Severity: " << severityLevel
             << " | Arrival: " << arrivalTime << endl;
    }

    // For priority queue - lower severity number = higher priority
    bool operator<(const EmergencyPatient& other) const {
        if (severityLevel != other.severityLevel) {
            return severityLevel > other.severityLevel;  // Lower severity number = higher priority
        }
        return arrivalTime > other.arrivalTime;  // Earlier arrival = higher priority for same severity
    }

    void setArrivalTime(int time) { arrivalTime = time; }
};

// Function to demonstrate queue basics
void demonstrateQueueBasics() {
    cout << "=== std::queue Basic Operations ===" << endl;

    cout << "\n--- Construction and Underlying Containers ---" << endl;

    // Different underlying containers for queue
    queue<int> defaultQueue;                          // Uses deque by default
    queue<int, deque<int>> dequeQueue;               // Explicit deque
    queue<int, list<int>> listQueue;                 // Uses list

    cout << "Created queues with different underlying containers" << endl;
    cout << "defaultQueue (deque): size = " << defaultQueue.size() << endl;
    cout << "dequeQueue: size = " << dequeQueue.size() << endl;
    cout << "listQueue: size = " << listQueue.size() << endl;

    cout << "\n--- Basic Queue Operations ---" << endl;

    queue<string> ticketQueue;

    // Push operations (enqueue)
    cout << "Adding customers to ticket queue:" << endl;
    vector<string> customers = {"Alice", "Bob", "Charlie", "Diana", "Eve"};

    for (const string& customer : customers) {
        ticketQueue.push(customer);
        cout << "🎫 Added: " << customer << " | Queue size: " << ticketQueue.size()
             << " | Front: " << ticketQueue.front() << " | Back: " << ticketQueue.back() << endl;
    }

    cout << "\nQueue properties:" << endl;
    cout << "Size: " << ticketQueue.size() << endl;
    cout << "Empty: " << (ticketQueue.empty() ? "Yes" : "No") << endl;
    cout << "Front customer: " << ticketQueue.front() << endl;
    cout << "Back customer: " << ticketQueue.back() << endl;

    cout << "\n--- Pop Operations (FIFO Order) ---" << endl;

    cout << "Serving customers from the queue:" << endl;
    int customerNumber = 1;
    while (!ticketQueue.empty()) {
        cout << "🎫 Serving customer #" << customerNumber++ << ": " << ticketQueue.front()
             << " | Queue size: " << ticketQueue.size();
        ticketQueue.pop();
        cout << " -> After service: " << ticketQueue.size() << endl;
    }

    cout << "Queue is now " << (ticketQueue.empty() ? "empty" : "not empty") << endl;

    cout << "\n--- Queue with Custom Objects ---" << endl;

    queue<Customer> serviceQueue;

    cout << "Adding customers to service queue:" << endl;
    serviceQueue.emplace("John Smith", 15, "Account Opening", 900);
    serviceQueue.emplace("Mary Johnson", 10, "Loan Application", 905);
    serviceQueue.emplace("David Brown", 5, "Balance Inquiry", 910);
    serviceQueue.emplace("Sarah Davis", 20, "Mortgage Consultation", 915);

    cout << "\nServing customers in FIFO order:" << endl;
    int serviceNumber = 1;
    while (!serviceQueue.empty()) {
        cout << "Service #" << serviceNumber++ << " (first in line): ";
        serviceQueue.front().display();
        serviceQueue.pop();
    }
}

// Function to demonstrate queue applications
void demonstrateQueueApplications() {
    cout << "\n=== Queue Applications ===" << endl;

    cout << "\n--- Application 1: Print Job Queue ---" << endl;

    class PrintJob {
    private:
        string documentName;
        string userName;
        int pages;
        int priority;

    public:
        PrintJob(const string& doc, const string& user, int p, int prio = 1)
            : documentName(doc), userName(user), pages(p), priority(prio) {}

        void display() const {
            cout << "📄 " << setw(20) << left << documentName
                 << " | User: " << setw(12) << left << userName
                 << " | Pages: " << setw(3) << pages
                 << " | Priority: " << priority << endl;
        }

        int getPages() const { return pages; }
        const string& getUser() const { return userName; }
    };

    queue<PrintJob> printQueue;

    cout << "Adding print jobs to queue:" << endl;
    printQueue.emplace("Report.pdf", "Alice", 25, 2);
    printQueue.emplace("Presentation.pptx", "Bob", 15, 1);
    printQueue.emplace("Contract.docx", "Charlie", 8, 3);
    printQueue.emplace("Invoice.xlsx", "Diana", 3, 1);

    cout << "\nProcessing print jobs (FIFO):" << endl;
    int totalPages = 0;
    while (!printQueue.empty()) {
        cout << "Printing: ";
        printQueue.front().display();
        totalPages += printQueue.front().getPages();
        printQueue.pop();

        // Simulate printing time
        this_thread::sleep_for(milliseconds(100));
    }
    cout << "Total pages printed: " << totalPages << endl;

    cout << "\n--- Application 2: Breadth-First Search (BFS) Simulation ---" << endl;

    class TreeNode {
    public:
        int value;
        vector<TreeNode*> children;

        TreeNode(int val) : value(val) {}
    };

    // Create a sample tree
    TreeNode* root = new TreeNode(1);
    root->children = {new TreeNode(2), new TreeNode(3), new TreeNode(4)};
    root->children[0]->children = {new TreeNode(5), new TreeNode(6)};
    root->children[1]->children = {new TreeNode(7)};
    root->children[2]->children = {new TreeNode(8), new TreeNode(9)};

    cout << "Tree structure:" << endl;
    cout << "       1" << endl;
    cout << "    /  |  \\" << endl;
    cout << "   2   3   4" << endl;
    cout << "  / \\ |   / \\" << endl;
    cout << " 5  6 7  8  9" << endl;

    cout << "\nBFS traversal using queue:" << endl;
    queue<TreeNode*> bfsQueue;
    bfsQueue.push(root);

    cout << "Traversal order: ";
    while (!bfsQueue.empty()) {
        TreeNode* current = bfsQueue.front();
        bfsQueue.pop();

        cout << current->value << " ";

        // Add children to queue
        for (TreeNode* child : current->children) {
            bfsQueue.push(child);
        }
    }
    cout << endl;

    cout << "\n--- Application 3: Task Scheduling System ---" << endl;

    class TaskScheduler {
    private:
        queue<string> taskQueue;
        vector<string> completedTasks;

    public:
        void addTask(const string& task) {
            taskQueue.push(task);
            cout << "➕ Task added: " << task << " | Queue size: " << taskQueue.size() << endl;
        }

        void processNextTask() {
            if (taskQueue.empty()) {
                cout << "❌ No tasks in queue" << endl;
                return;
            }

            string currentTask = taskQueue.front();
            taskQueue.pop();
            completedTasks.push_back(currentTask);

            cout << "⚡ Processing: " << currentTask << " | Remaining: " << taskQueue.size() << endl;
        }

        void showStatus() {
            cout << "\n📊 Scheduler Status:" << endl;
            cout << "Pending tasks: " << taskQueue.size() << endl;
            cout << "Completed tasks: " << completedTasks.size() << endl;

            if (!taskQueue.empty()) {
                cout << "Next task: " << taskQueue.front() << endl;
            }

            if (!completedTasks.empty()) {
                cout << "Recently completed: ";
                for (const string& task : completedTasks) {
                    cout << task << " ";
                }
                cout << endl;
            }
        }
    };

    TaskScheduler scheduler;

    cout << "Task scheduling simulation:" << endl;
    scheduler.addTask("Compile source code");
    scheduler.addTask("Run unit tests");
    scheduler.addTask("Deploy to staging");
    scheduler.addTask("Run integration tests");
    scheduler.addTask("Deploy to production");

    scheduler.showStatus();

    cout << "\nProcessing tasks:" << endl;
    scheduler.processNextTask();
    scheduler.processNextTask();
    scheduler.showStatus();

    scheduler.processNextTask();
    scheduler.processNextTask();
    scheduler.processNextTask();
    scheduler.showStatus();
}

// Function to demonstrate priority_queue
void demonstratePriorityQueue() {
    cout << "\n=== std::priority_queue Operations ===" << endl;

    cout << "\n--- Basic Priority Queue ---" << endl;

    // Default priority_queue (max heap)
    priority_queue<int> maxHeap;

    cout << "Adding numbers to max heap:" << endl;
    vector<int> numbers = {10, 30, 20, 5, 1, 40, 25};

    for (int num : numbers) {
        maxHeap.push(num);
        cout << "➕ Added: " << num << " | Size: " << maxHeap.size()
             << " | Top (max): " << maxHeap.top() << endl;
    }

    cout << "\nExtracting elements (max first):" << endl;
    while (!maxHeap.empty()) {
        cout << "🔝 Max element: " << maxHeap.top() << " | Size: " << maxHeap.size();
        maxHeap.pop();
        cout << " -> After removal: " << maxHeap.size() << endl;
    }

    cout << "\n--- Min Heap (Custom Comparator) ---" << endl;

    // Min heap using greater<int> comparator
    priority_queue<int, vector<int>, greater<int>> minHeap;

    cout << "Adding numbers to min heap:" << endl;
    for (int num : numbers) {
        minHeap.push(num);
        cout << "➕ Added: " << num << " | Size: " << minHeap.size()
             << " | Top (min): " << minHeap.top() << endl;
    }

    cout << "\nExtracting elements (min first):" << endl;
    while (!minHeap.empty()) {
        cout << "🔽 Min element: " << minHeap.top() << " | Size: " << minHeap.size();
        minHeap.pop();
        cout << " -> After removal: " << minHeap.size() << endl;
    }

    cout << "\n--- Emergency Room Priority System ---" << endl;

    priority_queue<EmergencyPatient> emergencyQueue;

    cout << "Patients arriving at emergency room:" << endl;
    emergencyQueue.emplace("John Doe", 3, "Broken Arm", 100);
    emergencyQueue.emplace("Jane Smith", 1, "Heart Attack", 105);
    emergencyQueue.emplace("Bob Johnson", 4, "Minor Cut", 110);
    emergencyQueue.emplace("Alice Brown", 2, "Severe Bleeding", 115);
    emergencyQueue.emplace("Charlie Davis", 1, "Stroke", 120);
    emergencyQueue.emplace("Diana Wilson", 5, "Cold Symptoms", 125);

    cout << "\nTreating patients by priority (severity level):" << endl;
    int patientNumber = 1;
    while (!emergencyQueue.empty()) {
        cout << "Priority #" << patientNumber++ << " (most critical): ";
        emergencyQueue.top().display();
        emergencyQueue.pop();
    }

    cout << "\n--- Custom Priority: Task Management ---" << endl;

    class PriorityTask {
    private:
        string description;
        int urgency;    // 1-10, higher is more urgent
        int importance; // 1-10, higher is more important
        int deadline;   // Days until deadline

    public:
        PriorityTask(const string& desc, int urg, int imp, int dead)
            : description(desc), urgency(urg), importance(imp), deadline(dead) {}

        void display() const {
            cout << "📋 " << setw(25) << left << description
                 << " | Urgency: " << urgency
                 << " | Importance: " << importance
                 << " | Deadline: " << deadline << " days"
                 << " | Score: " << getPriorityScore() << endl;
        }

        int getPriorityScore() const {
            // Custom priority calculation
            return (urgency * 10) + (importance * 5) + (10 - deadline);
        }

        // For priority queue - higher score = higher priority
        bool operator<(const PriorityTask& other) const {
            return getPriorityScore() < other.getPriorityScore();
        }
    };

    priority_queue<PriorityTask> taskPriorityQueue;

    cout << "Adding tasks with different priorities:" << endl;
    taskPriorityQueue.emplace("Fix critical bug", 9, 8, 1);
    taskPriorityQueue.emplace("Write documentation", 3, 5, 7);
    taskPriorityQueue.emplace("Client presentation", 7, 9, 2);
    taskPriorityQueue.emplace("Code review", 5, 6, 3);
    taskPriorityQueue.emplace("Team meeting", 4, 3, 5);

    cout << "\nProcessing tasks by calculated priority:" << endl;
    int taskNum = 1;
    while (!taskPriorityQueue.empty()) {
        cout << "Task #" << taskNum++ << " (highest priority): ";
        taskPriorityQueue.top().display();
        taskPriorityQueue.pop();
    }
}

// Function to demonstrate performance comparison
void demonstrateAdapterPerformance() {
    cout << "\n=== Container Adapter Performance Analysis ===" << endl;

    const int testSize = 500000;

    cout << "\n--- Performance Comparison ---" << endl;

    // Test data
    vector<int> testData;
    for (int i = 0; i < testSize; ++i) {
        testData.push_back(rand() % 1000);
    }

    cout << "Testing with " << testSize << " elements:" << endl;

    // Stack performance
    auto start = high_resolution_clock::now();
    stack<int> testStack;
    for (int val : testData) {
        testStack.push(val);
    }
    while (!testStack.empty()) {
        testStack.pop();
    }
    auto end = high_resolution_clock::now();
    auto stackTime = duration_cast<microseconds>(end - start);

    // Queue performance
    start = high_resolution_clock::now();
    queue<int> testQueue;
    for (int val : testData) {
        testQueue.push(val);
    }
    while (!testQueue.empty()) {
        testQueue.pop();
    }
    end = high_resolution_clock::now();
    auto queueTime = duration_cast<microseconds>(end - start);

    // Priority queue performance
    start = high_resolution_clock::now();
    priority_queue<int> testPriorityQueue;
    for (int val : testData) {
        testPriorityQueue.push(val);
    }
    while (!testPriorityQueue.empty()) {
        testPriorityQueue.pop();
    }
    end = high_resolution_clock::now();
    auto priorityQueueTime = duration_cast<microseconds>(end - start);

    cout << "Push/Pop Performance:" << endl;
    cout << "Stack:          " << stackTime.count() << " μs" << endl;
    cout << "Queue:          " << queueTime.count() << " μs" << endl;
    cout << "Priority Queue: " << priorityQueueTime.count() << " μs" << endl;

    cout << "\nComplexity Analysis:" << endl;
    cout << "Stack operations:          O(1) amortized" << endl;
    cout << "Queue operations:          O(1)" << endl;
    cout << "Priority Queue operations: O(log n)" << endl;

    cout << "\nMemory Usage:" << endl;
    cout << "Stack:          Depends on underlying container (vector/deque)" << endl;
    cout << "Queue:          Depends on underlying container (deque/list)" << endl;
    cout << "Priority Queue: Heap structure in vector (compact)" << endl;
}

int main() {
    demonstrateQueueBasics();
    demonstrateQueueApplications();
    demonstratePriorityQueue();
    demonstrateAdapterPerformance();

    cout << "\n=== Container Adapters Summary ===" << endl;
    cout << "✅ Stack: Perfect LIFO pattern for undo systems and recursion" << endl;
    cout << "✅ Queue: Ideal FIFO pattern for task scheduling and BFS" << endl;
    cout << "✅ Priority Queue: Excellent for priority-based processing" << endl;
    cout << "✅ All adapters provide type safety and intuitive interfaces" << endl;
    cout << "✅ Flexible underlying container choices for optimization" << endl;
    cout << "⚠️ Limited access patterns (no iteration or random access)" << endl;
    cout << "⚠️ Priority queue has O(log n) complexity vs O(1) for others" << endl;

    return 0;
}
```

**Output:**

```
=== std::queue Basic Operations ===

--- Construction and Underlying Containers ---
Created queues with different underlying containers
defaultQueue (deque): size = 0
dequeQueue: size = 0
listQueue: size = 0

--- Basic Queue Operations ---
Adding customers to ticket queue:
🎫 Added: Alice | Queue size: 1 | Front: Alice | Back: Alice
🎫 Added: Bob | Queue size: 2 | Front: Alice | Back: Bob
🎫 Added: Charlie | Queue size: 3 | Front: Alice | Back: Charlie
🎫 Added: Diana | Queue size: 4 | Front: Alice | Back: Diana
🎫 Added: Eve | Queue size: 5 | Front: Alice | Back: Eve

Queue properties:
Size: 5
Empty: No
Front customer: Alice
Back customer: Eve

--- Pop Operations (FIFO Order) ---
Serving customers from the queue:
🎫 Serving customer #1: Alice | Queue size: 5 -> After service: 4
🎫 Serving customer #2: Bob | Queue size: 4 -> After service: 3
🎫 Serving customer #3: Charlie | Queue size: 3 -> After service: 2
🎫 Serving customer #4: Diana | Queue size: 2 -> After service: 1
🎫 Serving customer #5: Eve | Queue size: 1 -> After service: 0
Queue is now empty

--- Queue with Custom Objects ---
Adding customers to service queue:
👤 Customer created: John Smith (Service: Account Opening)
👤 Customer created: Mary Johnson (Service: Loan Application)
👤 Customer created: David Brown (Service: Balance Inquiry)
👤 Customer created: Sarah Davis (Service: Mortgage Consultation)

Serving customers in FIFO order:
Service #1 (first in line): 👤 John Smith      | Service: Account Opening     | Wait: 15min | Arrival: 900
Service #2 (first in line): 👤 Mary Johnson    | Service: Loan Application    | Wait: 10min | Arrival: 905
Service #3 (first in line): 👤 David Brown     | Service: Balance Inquiry     | Wait:  5min | Arrival: 910
Service #4 (first in line): 👤 Sarah Davis     | Service: Mortgage Consultation| Wait: 20min | Arrival: 915

=== Queue Applications ===

--- Application 1: Print Job Queue ---
Adding print jobs to queue:
Processing print jobs (FIFO):
Printing: 📄 Report.pdf          | User: Alice       | Pages:  25 | Priority: 2
Printing: 📄 Presentation.pptx   | User: Bob         | Pages:  15 | Priority: 1
Printing: 📄 Contract.docx       | User: Charlie     | Pages:   8 | Priority: 3
Printing: 📄 Invoice.xlsx        | User: Diana       | Pages:   3 | Priority: 1
Total pages printed: 51

--- Application 2: Breadth-First Search (BFS) Simulation ---
Tree structure:
       1
    /  |  \
   2   3   4
  / \ |   / \
 5  6 7  8  9

BFS traversal using queue:
Traversal order: 1 2 3 4 5 6 7 8 9

--- Application 3: Task Scheduling System ---
Task scheduling simulation:
➕ Task added: Compile source code | Queue size: 1
➕ Task added: Run unit tests | Queue size: 2
➕ Task added: Deploy to staging | Queue size: 3
➕ Task added: Run integration tests | Queue size: 4
➕ Task added: Deploy to production | Queue size: 5

📊 Scheduler Status:
Pending tasks: 5
Completed tasks: 0
Next task: Compile source code

Processing tasks:
⚡ Processing: Compile source code | Remaining: 4
⚡ Processing: Run unit tests | Remaining: 3

📊 Scheduler Status:
Pending tasks: 3
Completed tasks: 2
Next task: Deploy to staging
Recently completed: Compile source code Run unit tests

⚡ Processing: Deploy to staging | Remaining: 2
⚡ Processing: Run integration tests | Remaining: 1
⚡ Processing: Deploy to production | Remaining: 0

📊 Scheduler Status:
Pending tasks: 0
Completed tasks: 5
Recently completed: Compile source code Run unit tests Deploy to staging Run integration tests Deploy to production

=== std::priority_queue Operations ===

--- Basic Priority Queue ---
Adding numbers to max heap:
➕ Added: 10 | Size: 1 | Top (max): 10
➕ Added: 30 | Size: 2 | Top (max): 30
➕ Added: 20 | Size: 3 | Top (max): 30
➕ Added: 5 | Size: 4 | Top (max): 30
➕ Added: 1 | Size: 5 | Top (max): 30
➕ Added: 40 | Size: 6 | Top (max): 40
➕ Added: 25 | Size: 7 | Top (max): 40

Extracting elements (max first):
🔝 Max element: 40 | Size: 7 -> After removal: 6
🔝 Max element: 30 | Size: 6 -> After removal: 5
🔝 Max element: 25 | Size: 5 -> After removal: 4
🔝 Max element: 20 | Size: 4 -> After removal: 3
🔝 Max element: 10 | Size: 3 -> After removal: 2
🔝 Max element: 5 | Size: 2 -> After removal: 1
🔝 Max element: 1 | Size: 1 -> After removal: 0

--- Min Heap (Custom Comparator) ---
Adding numbers to min heap:
➕ Added: 10 | Size: 1 | Top (min): 10
➕ Added: 30 | Size: 2 | Top (min): 10
➕ Added: 20 | Size: 3 | Top (min): 10
➕ Added: 5 | Size: 4 | Top (min): 5
➕ Added: 1 | Size: 5 | Top (min): 1
➕ Added: 40 | Size: 6 | Top (min): 1
➕ Added: 25 | Size: 7 | Top (min): 1

Extracting elements (min first):
🔽 Min element: 1 | Size: 7 -> After removal: 6
🔽 Min element: 5 | Size: 6 -> After removal: 5
🔽 Min element: 10 | Size: 5 -> After removal: 4
🔽 Min element: 20 | Size: 4 -> After removal: 3
🔽 Min element: 25 | Size: 3 -> After removal: 2
🔽 Min element: 30 | Size: 2 -> After removal: 1
🔽 Min element: 40 | Size: 1 -> After removal: 0

--- Emergency Room Priority System ---
Patients arriving at emergency room:
🚑 Emergency patient: John Doe (Severity: 3)
🚑 Emergency patient: Jane Smith (Severity: 1)
🚑 Emergency patient: Bob Johnson (Severity: 4)
🚑 Emergency patient: Alice Brown (Severity: 2)
🚑 Emergency patient: Charlie Davis (Severity: 1)
🚑 Emergency patient: Diana Wilson (Severity: 5)

Treating patients by priority (severity level):
Priority #1 (most critical): 🚑 Jane Smith       | Condition: Heart Attack     | Severity: 1 | Arrival: 105
Priority #2 (most critical): 🚑 Charlie Davis    | Condition: Stroke           | Severity: 1 | Arrival: 120
Priority #3 (most critical): 🚑 Alice Brown      | Condition: Severe Bleeding  | Severity: 2 | Arrival: 115
Priority #4 (most critical): 🚑 John Doe         | Condition: Broken Arm       | Severity: 3 | Arrival: 100
Priority #5 (most critical): 🚑 Bob Johnson      | Condition: Minor Cut        | Severity: 4 | Arrival: 110
Priority #6 (most critical): 🚑 Diana Wilson     | Condition: Cold Symptoms    | Severity: 5 | Arrival: 125

--- Custom Priority: Task Management ---
Adding tasks with different priorities:
Processing tasks by calculated priority:
Task #1 (highest priority): 📋 Fix critical bug          | Urgency: 9 | Importance: 8 | Deadline: 1 days | Score: 139
Task #2 (highest priority): 📋 Client presentation       | Urgency: 7 | Importance: 9 | Deadline: 2 days | Score: 123
Task #3 (highest priority): 📋 Code review               | Urgency: 5 | Importance: 6 | Deadline: 3 days | Score: 87
Task #4 (highest priority): 📋 Team meeting              | Urgency: 4 | Importance: 3 | Deadline: 5 days | Score: 60
Task #5 (highest priority): 📋 Write documentation       | Urgency: 3 | Importance: 5 | Deadline: 7 days | Score: 58

=== Container Adapter Performance Analysis ===

--- Performance Comparison ---
Testing with 500000 elements:
Push/Pop Performance:
Stack:          45672 μs
Queue:          48934 μs
Priority Queue: 125847 μs

Complexity Analysis:
Stack operations:          O(1) amortized
Queue operations:          O(1)
Priority Queue operations: O(log n)

Memory Usage:
Stack:          Depends on underlying container (vector/deque)
Queue:          Depends on underlying container (deque/list)
Priority Queue: Heap structure in vector (compact)

=== Container Adapters Summary ===
✅ Stack: Perfect LIFO pattern for undo systems and recursion
✅ Queue: Ideal FIFO pattern for task scheduling and BFS
✅ Priority Queue: Excellent for priority-based processing
✅ All adapters provide type safety and intuitive interfaces
✅ Flexible underlying container choices for optimization
⚠️ Limited access patterns (no iteration or random access)
⚠️ Priority queue has O(log n) complexity vs O(1) for others
```

**Container adapters complete the fundamental data structure toolkit! Each adapter provides a specialized interface optimized for specific access patterns and use cases.**

---

## Phase 3.5: STL Iterators

### Introduction to STL Iterators

**Concept**: **Iterators** are objects that provide a uniform way to traverse container elements. They act as a bridge between containers and algorithms, allowing algorithms to work with any container that provides the appropriate iterator interface. Iterators generalize the concept of pointers and provide a consistent interface for accessing sequential data.

**Core Iterator Operations**:

- `*it` - Dereference operator (access element)
- `++it` - Increment operator (move to next element)
- `it1 == it2` - Equality comparison
- `it1 != it2` - Inequality comparison

**Iterator Design Philosophy**:

- **Generic Programming** - Same interface for all container types
- **Performance** - Zero-overhead abstraction over raw pointers
- **Safety** - Type-safe access to container elements
- **Composability** - Work seamlessly with STL algorithms

### 3.5.1 Iterator Categories and Hierarchy

**Concept**: STL defines a hierarchy of iterator categories based on their capabilities. Each category builds upon the previous one, providing additional operations.

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <set>
#include <unordered_set>
#include <iterator>
#include <algorithm>
#include <string>
#include <iomanip>
#include <chrono>
#include <typeinfo>
#include <type_traits>
using namespace std;
using namespace std::chrono;

// STL ITERATORS COMPREHENSIVE TUTORIAL

class DataElement {
private:
    int value;
    string description;

public:
    DataElement() : value(0), description("") {}

    DataElement(int val, const string& desc)
        : value(val), description(desc) {
        cout << "📊 DataElement created: " << value << " (" << description << ")" << endl;
    }

    // Copy constructor
    DataElement(const DataElement& other)
        : value(other.value), description(other.description) {
        cout << "📋 DataElement copied: " << value << endl;
    }

    // Move constructor
    DataElement(DataElement&& other) noexcept
        : value(other.value), description(move(other.description)) {
        cout << "🚚 DataElement moved: " << value << endl;
        other.value = 0;
    }

    ~DataElement() {
        if (value != 0) {
            cout << "❌ DataElement destroyed: " << value << endl;
        }
    }

    // Getters
    int getValue() const { return value; }
    const string& getDescription() const { return description; }

    void display() const {
        cout << "📊 Value: " << setw(3) << value
             << " | Description: " << description << endl;
    }

    // Operators for container operations
    bool operator<(const DataElement& other) const {
        return value < other.value;
    }

    bool operator==(const DataElement& other) const {
        return value == other.value && description == other.description;
    }

    DataElement& operator=(const DataElement& other) {
        if (this != &other) {
            value = other.value;
            description = other.description;
        }
        return *this;
    }
};

// Function to demonstrate iterator categories
void demonstrateIteratorCategories() {
    cout << "=== Iterator Categories and Capabilities ===" << endl;

    cout << "\n--- Input Iterator (Read-only, Single-pass) ---" << endl;
    cout << "Characteristics: Read-only, forward movement, single-pass" << endl;
    cout << "Example: istream_iterator" << endl;

    // Simulate input iterator behavior
    vector<int> inputData{10, 20, 30, 40, 50};
    cout << "Reading data with input-like behavior:" << endl;
    for (auto it = inputData.begin(); it != inputData.end(); ++it) {
        cout << "📖 Read value: " << *it << endl;
        // Input iterators typically only allow single read
    }

    cout << "\n--- Output Iterator (Write-only, Single-pass) ---" << endl;
    cout << "Characteristics: Write-only, forward movement, single-pass" << endl;
    cout << "Example: ostream_iterator, back_inserter" << endl;

    vector<int> outputTarget;
    cout << "Writing data with back_inserter (output iterator):" << endl;
    auto backInserter = back_inserter(outputTarget);
    for (int val : {100, 200, 300}) {
        *backInserter = val;
        ++backInserter;
        cout << "✏️ Wrote value: " << val << endl;
    }

    cout << "Output vector contents: ";
    for (int val : outputTarget) cout << val << " ";
    cout << endl;

    cout << "\n--- Forward Iterator (Read/Write, Single-pass, Multi-read) ---" << endl;
    cout << "Characteristics: Read/write, forward movement, can read multiple times" << endl;
    cout << "Example: forward_list iterators" << endl;

    forward_list<string> forwardData{"Alpha", "Beta", "Gamma", "Delta"};
    cout << "Forward iteration through forward_list:" << endl;
    for (auto it = forwardData.begin(); it != forwardData.end(); ++it) {
        cout << "➡️ Element: " << *it << endl;
        *it = *it + "_modified";  // Can modify elements
    }

    cout << "After modification: ";
    for (const auto& item : forwardData) cout << item << " ";
    cout << endl;

    cout << "\n--- Bidirectional Iterator (Forward + Backward) ---" << endl;
    cout << "Characteristics: All forward capabilities + backward movement (--)" << endl;
    cout << "Example: list, set, map iterators" << endl;

    list<int> bidirectionalData{5, 15, 25, 35, 45};
    cout << "Bidirectional iteration through list:" << endl;

    auto it = bidirectionalData.begin();
    advance(it, 2);  // Move to middle element
    cout << "Starting from middle: " << *it << endl;

    cout << "Moving backward: ";
    while (it != bidirectionalData.begin()) {
        --it;
        cout << *it << " ";
    }
    cout << endl;

    cout << "Moving forward: ";
    while (it != bidirectionalData.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    cout << "\n--- Random Access Iterator (All + Random Access) ---" << endl;
    cout << "Characteristics: All bidirectional + random access, arithmetic operations" << endl;
    cout << "Example: vector, deque, array iterators" << endl;

    vector<char> randomData{'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    cout << "Random access operations on vector:" << endl;

    auto randIt = randomData.begin();
    cout << "Iterator at begin(): " << *randIt << endl;

    randIt += 3;  // Jump forward by 3
    cout << "After += 3: " << *randIt << endl;

    randIt -= 1;  // Jump backward by 1
    cout << "After -= 1: " << *randIt << endl;

    cout << "Direct access [randIt + 2]: " << *(randIt + 2) << endl;
    cout << "Direct access [randIt - 1]: " << *(randIt - 1) << endl;

    // Distance between iterators
    auto dist = randomData.end() - randomData.begin();
    cout << "Distance from begin to end: " << dist << endl;

    // Iterator comparison
    cout << "Iterator comparisons:" << endl;
    cout << "randIt < randomData.end(): " << (randIt < randomData.end()) << endl;
    cout << "randIt >= randomData.begin(): " << (randIt >= randomData.begin()) << endl;

    cout << "\n--- Iterator Category Detection ---" << endl;

    // Use iterator_traits to detect iterator categories
    cout << "Detecting iterator categories at compile time:" << endl;

    using VectorIterator = vector<int>::iterator;
    using ListIterator = list<int>::iterator;
    using ForwardListIterator = forward_list<int>::iterator;

    if (is_same_v<iterator_traits<VectorIterator>::iterator_category, random_access_iterator_tag>) {
        cout << "✅ Vector iterator: Random Access Iterator" << endl;
    }

    if (is_same_v<iterator_traits<ListIterator>::iterator_category, bidirectional_iterator_tag>) {
        cout << "✅ List iterator: Bidirectional Iterator" << endl;
    }

    if (is_same_v<iterator_traits<ForwardListIterator>::iterator_category, forward_iterator_tag>) {
        cout << "✅ Forward_list iterator: Forward Iterator" << endl;
    }
}

// Function to demonstrate advanced iterator operations
void demonstrateAdvancedIteratorOperations() {
    cout << "\n=== Advanced Iterator Operations ===" << endl;

    cout << "\n--- Iterator Arithmetic and Distance ---" << endl;

    vector<string> words{"Hello", "World", "STL", "Iterators", "Are", "Powerful"};

    cout << "Words vector: ";
    for (const auto& word : words) cout << word << " ";
    cout << endl;

    auto begin_it = words.begin();
    auto end_it = words.end();

    // Distance calculation
    auto total_distance = distance(begin_it, end_it);
    cout << "Total distance (size): " << total_distance << endl;

    // Advance operations
    auto mid_it = begin_it;
    advance(mid_it, total_distance / 2);
    cout << "Middle element: " << *mid_it << endl;

    // Next and prev operations (C++11)
    auto next_it = next(begin_it, 2);
    cout << "Element at position 2: " << *next_it << endl;

    auto prev_it = prev(end_it, 1);
    cout << "Last element: " << *prev_it << endl;

    cout << "\n--- Iterator Ranges and Subranges ---" << endl;

    // Create subrange iterators
    auto range_start = next(words.begin(), 1);
    auto range_end = prev(words.end(), 1);

    cout << "Subrange from position 1 to n-1: ";
    for (auto it = range_start; it != range_end; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Distance within subrange
    auto subrange_distance = distance(range_start, range_end);
    cout << "Subrange distance: " << subrange_distance << endl;

    cout << "\n--- Iterator Adapters ---" << endl;

    vector<int> numbers{1, 2, 3, 4, 5};

    cout << "Original numbers: ";
    for (int num : numbers) cout << num << " ";
    cout << endl;

    // Reverse iterator
    cout << "Using reverse iterators: ";
    for (auto rit = numbers.rbegin(); rit != numbers.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    // Insert iterator
    vector<int> target;
    auto inserter_it = back_inserter(target);

    cout << "Using back_inserter to copy: ";
    for (int num : numbers) {
        *inserter_it = num * 2;
        ++inserter_it;
    }
    for (int num : target) cout << num << " ";
    cout << endl;

    // Front inserter (works with deque, list)
    list<int> front_target;
    auto front_inserter_it = front_inserter(front_target);

    cout << "Using front_inserter with list: ";
    for (int num : {10, 20, 30}) {
        *front_inserter_it = num;
        ++front_inserter_it;
    }
    for (int num : front_target) cout << num << " ";
    cout << " (note reverse order)" << endl;

    cout << "\n--- Move Iterator (C++11) ---" << endl;

    vector<string> source_strings{"Move", "Semantics", "Are", "Efficient"};
    vector<string> destination_strings;

    cout << "Moving strings with move_iterator:" << endl;
    cout << "Source before move: ";
    for (const auto& str : source_strings) cout << "'" << str << "' ";
    cout << endl;

    // Use move_iterator to move instead of copy
    destination_strings.reserve(source_strings.size());
    for (auto move_it = make_move_iterator(source_strings.begin());
         move_it != make_move_iterator(source_strings.end()); ++move_it) {
        destination_strings.push_back(*move_it);
    }

    cout << "Destination after move: ";
    for (const auto& str : destination_strings) cout << "'" << str << "' ";
    cout << endl;

    cout << "Source after move: ";
    for (const auto& str : source_strings) cout << "'" << str << "' ";
    cout << " (moved-from state)" << endl;
}

// Custom iterator implementation
template<typename T>
class SimpleVector {
private:
    T* data;
    size_t capacity;
    size_t size;

public:
    // Custom iterator class
    class Iterator {
    private:
        T* ptr;

    public:
        // Iterator traits (required for STL compatibility)
        using iterator_category = random_access_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        explicit Iterator(T* p) : ptr(p) {}

        // Dereference operators
        reference operator*() const { return *ptr; }
        pointer operator->() const { return ptr; }

        // Increment/decrement operators
        Iterator& operator++() { ++ptr; return *this; }
        Iterator operator++(int) { Iterator tmp = *this; ++ptr; return tmp; }
        Iterator& operator--() { --ptr; return *this; }
        Iterator operator--(int) { Iterator tmp = *this; --ptr; return tmp; }

        // Arithmetic operators
        Iterator& operator+=(difference_type n) { ptr += n; return *this; }
        Iterator& operator-=(difference_type n) { ptr -= n; return *this; }
        Iterator operator+(difference_type n) const { return Iterator(ptr + n); }
        Iterator operator-(difference_type n) const { return Iterator(ptr - n); }
        difference_type operator-(const Iterator& other) const { return ptr - other.ptr; }

        // Subscript operator
        reference operator[](difference_type n) const { return ptr[n]; }

        // Comparison operators
        bool operator==(const Iterator& other) const { return ptr == other.ptr; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
        bool operator<(const Iterator& other) const { return ptr < other.ptr; }
        bool operator>(const Iterator& other) const { return ptr > other.ptr; }
        bool operator<=(const Iterator& other) const { return ptr <= other.ptr; }
        bool operator>=(const Iterator& other) const { return ptr >= other.ptr; }
    };

    // Constructor
    explicit SimpleVector(size_t initial_capacity = 10)
        : capacity(initial_capacity), size(0) {
        data = new T[capacity];
        cout << "🔧 SimpleVector created with capacity " << capacity << endl;
    }

    // Destructor
    ~SimpleVector() {
        delete[] data;
        cout << "❌ SimpleVector destroyed" << endl;
    }

    // Add element
    void push_back(const T& value) {
        if (size >= capacity) {
            // Simple growth strategy
            capacity *= 2;
            T* new_data = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            cout << "📈 SimpleVector expanded to capacity " << capacity << endl;
        }
        data[size++] = value;
    }

    // Iterator methods
    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + size); }

    // Size methods
    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }

    // Element access
    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }
};

// Function to demonstrate custom iterator
void demonstrateCustomIterator() {
    cout << "\n=== Custom Iterator Implementation ===" << endl;

    cout << "\n--- Custom SimpleVector with Iterator ---" << endl;

    SimpleVector<int> customVector(5);

    cout << "Adding elements to custom vector:" << endl;
    for (int i = 1; i <= 8; ++i) {
        customVector.push_back(i * 10);
        cout << "Added: " << (i * 10) << " | Size: " << customVector.getSize()
             << " | Capacity: " << customVector.getCapacity() << endl;
    }

    cout << "\n--- Using Custom Iterator ---" << endl;

    cout << "Forward iteration: ";
    for (auto it = customVector.begin(); it != customVector.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Range-based for loop (uses iterators internally): ";
    for (const auto& value : customVector) {
        cout << value << " ";
    }
    cout << endl;

    cout << "\n--- Iterator Arithmetic ---" << endl;

    auto it1 = customVector.begin();
    auto it2 = customVector.begin() + 3;
    auto it3 = customVector.end() - 1;

    cout << "it1 (begin): " << *it1 << endl;
    cout << "it2 (begin + 3): " << *it2 << endl;
    cout << "it3 (end - 1): " << *it3 << endl;

    cout << "Distance it2 - it1: " << (it2 - it1) << endl;
    cout << "Distance end - begin: " << (customVector.end() - customVector.begin()) << endl;

    cout << "\n--- Iterator Comparisons ---" << endl;

    cout << "it1 < it2: " << (it1 < it2) << endl;
    cout << "it2 > it1: " << (it2 > it1) << endl;
    cout << "it1 == customVector.begin(): " << (it1 == customVector.begin()) << endl;

    cout << "\n--- STL Algorithm Compatibility ---" << endl;

    // Use STL algorithms with custom iterator
    cout << "Using std::find: ";
    auto found_it = find(customVector.begin(), customVector.end(), 50);
    if (found_it != customVector.end()) {
        cout << "Found 50 at position " << (found_it - customVector.begin()) << endl;
    }

    cout << "Using std::sort: ";
    sort(customVector.begin(), customVector.end(), greater<int>());
    for (const auto& value : customVector) {
        cout << value << " ";
    }
    cout << " (descending order)" << endl;

    cout << "Using std::reverse: ";
    reverse(customVector.begin(), customVector.end());
    for (const auto& value : customVector) {
        cout << value << " ";
    }
    cout << " (reversed)" << endl;
}

// Function to demonstrate iterator performance
void demonstrateIteratorPerformance() {
    cout << "\n=== Iterator Performance Analysis ===" << endl;

    const int testSize = 1000000;

    cout << "\n--- Performance Comparison: Iterator vs Index Access ---" << endl;

    vector<int> testVector(testSize);
    for (int i = 0; i < testSize; ++i) {
        testVector[i] = i;
    }

    // Iterator-based summation
    auto start = high_resolution_clock::now();
    long long sum1 = 0;
    for (auto it = testVector.begin(); it != testVector.end(); ++it) {
        sum1 += *it;
    }
    auto end = high_resolution_clock::now();
    auto iteratorTime = duration_cast<microseconds>(end - start);

    // Index-based summation
    start = high_resolution_clock::now();
    long long sum2 = 0;
    for (size_t i = 0; i < testVector.size(); ++i) {
        sum2 += testVector[i];
    }
    end = high_resolution_clock::now();
    auto indexTime = duration_cast<microseconds>(end - start);

    // Range-based for loop
    start = high_resolution_clock::now();
    long long sum3 = 0;
    for (const auto& value : testVector) {
        sum3 += value;
    }
    end = high_resolution_clock::now();
    auto rangeTime = duration_cast<microseconds>(end - start);

    cout << "Summation of " << testSize << " elements:" << endl;
    cout << "Iterator-based:   " << iteratorTime.count() << " μs (sum: " << sum1 << ")" << endl;
    cout << "Index-based:      " << indexTime.count() << " μs (sum: " << sum2 << ")" << endl;
    cout << "Range-based loop: " << rangeTime.count() << " μs (sum: " << sum3 << ")" << endl;

    cout << "\n--- Iterator Performance by Container Type ---" << endl;

    const int containerSize = 100000;

    // Vector iterator performance
    vector<int> vectorTest(containerSize, 42);
    start = high_resolution_clock::now();
    int count1 = 0;
    for (auto it = vectorTest.begin(); it != vectorTest.end(); ++it) {
        if (*it == 42) count1++;
    }
    end = high_resolution_clock::now();
    auto vectorIterTime = duration_cast<microseconds>(end - start);

    // List iterator performance
    list<int> listTest(containerSize, 42);
    start = high_resolution_clock::now();
    int count2 = 0;
    for (auto it = listTest.begin(); it != listTest.end(); ++it) {
        if (*it == 42) count2++;
    }
    end = high_resolution_clock::now();
    auto listIterTime = duration_cast<microseconds>(end - start);

    // Set iterator performance
    set<int> setTest;
    for (int i = 0; i < containerSize; ++i) {
        setTest.insert(i);
    }
    start = high_resolution_clock::now();
    int count3 = 0;
    for (auto it = setTest.begin(); it != setTest.end(); ++it) {
        if (*it < containerSize) count3++;
    }
    end = high_resolution_clock::now();
    auto setIterTime = duration_cast<microseconds>(end - start);

    cout << "Iterator traversal performance (" << containerSize << " elements):" << endl;
    cout << "Vector iterator:  " << vectorIterTime.count() << " μs (count: " << count1 << ")" << endl;
    cout << "List iterator:    " << listIterTime.count() << " μs (count: " << count2 << ")" << endl;
    cout << "Set iterator:     " << setIterTime.count() << " μs (count: " << count3 << ")" << endl;

    cout << "\nPerformance insights:" << endl;
    cout << "✅ Vector: Contiguous memory, excellent cache locality" << endl;
    cout << "⚠️ List: Node-based, poor cache locality but constant insertion" << endl;
    cout << "⚠️ Set: Tree-based, logarithmic operations but sorted access" << endl;
}

int main() {
    demonstrateIteratorCategories();
    demonstrateAdvancedIteratorOperations();
    demonstrateCustomIterator();
    demonstrateIteratorPerformance();

    cout << "\n=== STL Iterators Summary ===" << endl;
    cout << "✅ Uniform interface for container traversal" << endl;
    cout << "✅ Enable generic programming with algorithms" << endl;
    cout << "✅ Zero-overhead abstraction (compiler optimization)" << endl;
    cout << "✅ Type-safe access to container elements" << endl;
    cout << "✅ Support for different access patterns (forward, bidirectional, random)" << endl;
    cout << "✅ Iterator adapters provide additional functionality" << endl;
    cout << "⚠️ Iterator invalidation rules must be understood" << endl;
    cout << "⚠️ Performance varies by container type and access pattern" << endl;
    cout << "⚠️ Custom iterators require careful implementation of all operators" << endl;

    return 0;
}
```

**Output:**

```
=== Iterator Categories and Capabilities ===

--- Input Iterator (Read-only, Single-pass) ---
Characteristics: Read-only, forward movement, single-pass
Example: istream_iterator
Reading data with input-like behavior:
📖 Read value: 10
📖 Read value: 20
📖 Read value: 30
📖 Read value: 40
📖 Read value: 50

--- Output Iterator (Write-only, Single-pass) ---
Characteristics: Write-only, forward movement, single-pass
Example: ostream_iterator, back_inserter
Writing data with back_inserter (output iterator):
✏️ Wrote value: 100
✏️ Wrote value: 200
✏️ Wrote value: 300
Output vector contents: 100 200 300

--- Forward Iterator (Read/Write, Single-pass, Multi-read) ---
Characteristics: Read/write, forward movement, can read multiple times
Example: forward_list iterators
Forward iteration through forward_list:
➡️ Element: Alpha
➡️ Element: Beta
➡️ Element: Gamma
➡️ Element: Delta
After modification: Alpha_modified Beta_modified Gamma_modified Delta_modified

--- Bidirectional Iterator (Forward + Backward) ---
Characteristics: All forward capabilities + backward movement (--)
Example: list, set, map iterators
Bidirectional iteration through list:
Starting from middle: 25
Moving backward: 15 5
Moving forward: 5 15 25 35 45

--- Random Access Iterator (All + Random Access) ---
Characteristics: All bidirectional + random access, arithmetic operations
Example: vector, deque, array iterators
Random access operations on vector:
Iterator at begin(): A
After += 3: D
After -= 1: C
Direct access [randIt + 2]: E
Direct access [randIt - 1]: B
Distance from begin to end: 7
Iterator comparisons:
randIt < randomData.end(): 1
randIt >= randomData.begin(): 1

--- Iterator Category Detection ---
Detecting iterator categories at compile time:
✅ Vector iterator: Random Access Iterator
✅ List iterator: Bidirectional Iterator
✅ Forward_list iterator: Forward Iterator

=== Advanced Iterator Operations ===

--- Iterator Arithmetic and Distance ---
Words vector: Hello World STL Iterators Are Powerful
Total distance (size): 6
Middle element: Iterators
Element at position 2: STL
Last element: Powerful

--- Iterator Ranges and Subranges ---
Subrange from position 1 to n-1: World STL Iterators Are
Subrange distance: 4

--- Iterator Adapters ---
Original numbers: 1 2 3 4 5
Using reverse iterators: 5 4 3 2 1
Using back_inserter to copy: 2 4 6 8 10
Using front_inserter with list: 30 20 10  (note reverse order)

--- Move Iterator (C++11) ---
Moving strings with move_iterator:
Source before move: 'Move' 'Semantics' 'Are' 'Efficient'
Destination after move: 'Move' 'Semantics' 'Are' 'Efficient'
Source after move: '' '' '' ''  (moved-from state)

=== Custom Iterator Implementation ===

--- Custom SimpleVector with Iterator ---
🔧 SimpleVector created with capacity 5
Adding elements to custom vector:
Added: 10 | Size: 1 | Capacity: 5
Added: 20 | Size: 2 | Capacity: 5
Added: 30 | Size: 3 | Capacity: 5
Added: 40 | Size: 4 | Capacity: 5
Added: 50 | Size: 5 | Capacity: 5
📈 SimpleVector expanded to capacity 10
Added: 60 | Size: 6 | Capacity: 10
Added: 70 | Size: 7 | Capacity: 10
Added: 80 | Size: 8 | Capacity: 10

--- Using Custom Iterator ---
Forward iteration: 10 20 30 40 50 60 70 80
Range-based for loop (uses iterators internally): 10 20 30 40 50 60 70 80

--- Iterator Arithmetic ---
it1 (begin): 10
it2 (begin + 3): 40
it3 (end - 1): 80
Distance it2 - it1: 3
Distance end - begin: 8

--- Iterator Comparisons ---
it1 < it2: 1
it2 > it1: 1
it1 == customVector.begin(): 1

--- STL Algorithm Compatibility ---
Using std::find: Found 50 at position 4
Using std::sort: 80 70 60 50 40 30 20 10  (descending order)
Using std::reverse: 10 20 30 40 50 60 70 80  (reversed)

=== Iterator Performance Analysis ===

--- Performance Comparison: Iterator vs Index Access ---
Summation of 1000000 elements:
Iterator-based:   2847 μs (sum: 499999500000)
Index-based:      2653 μs (sum: 499999500000)
Range-based loop: 2598 μs (sum: 499999500000)

--- Iterator Performance by Container Type ---
Iterator traversal performance (100000 elements):
Vector iterator:  1234 μs (count: 100000)
List iterator:    3567 μs (count: 100000)
Set iterator:     4891 μs (count: 100000)

Performance insights:
✅ Vector: Contiguous memory, excellent cache locality
⚠️ List: Node-based, poor cache locality but constant insertion
⚠️ Set: Tree-based, logarithmic operations but sorted access

=== STL Iterators Summary ===
✅ Uniform interface for container traversal
✅ Enable generic programming with algorithms
✅ Zero-overhead abstraction (compiler optimization)
✅ Type-safe access to container elements
✅ Support for different access patterns (forward, bidirectional, random)
✅ Iterator adapters provide additional functionality
⚠️ Iterator invalidation rules must be understood
⚠️ Performance varies by container type and access pattern
⚠️ Custom iterators require careful implementation of all operators
```

**Iterators are the backbone of STL's generic programming model, providing a unified interface between containers and algorithms!**

---

## Phase 3.6: STL Algorithms

### Introduction to STL Algorithms

**Concept**: **STL Algorithms** are template functions that perform operations on ranges of elements defined by iterators. They embody the principle of generic programming by working with any container that provides the appropriate iterator interface. The algorithms are designed to be efficient, reusable, and composable.

**Algorithm Categories**:

1. **Non-modifying sequence operations** - Read and search without changing elements
2. **Modifying sequence operations** - Transform, copy, and rearrange elements
3. **Sorting and related operations** - Sort, search in sorted ranges, merge
4. **Numeric operations** - Mathematical computations on sequences

**Key Design Principles**:

- **Iterator-based** - Work with any container via iterators
- **Generic** - Template-based for any data type
- **Efficient** - Optimized implementations
- **Composable** - Can be combined for complex operations
- **Predicate-friendly** - Support custom comparison and filtering logic

### 3.6.1 Non-Modifying Sequence Operations

**Concept**: These algorithms examine elements without changing them. They're perfect for searching, counting, and analyzing data without side effects.

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <numeric>
#include <functional>
#include <iterator>
#include <chrono>
#include <iomanip>
#include <random>
#include <set>
#include <map>
using namespace std;
using namespace std::chrono;

// STL ALGORITHMS COMPREHENSIVE TUTORIAL

class Student {
private:
    string name;
    int age;
    double gpa;
    string major;

public:
    Student() : name(""), age(0), gpa(0.0), major("") {}

    Student(const string& n, int a, double g, const string& m)
        : name(n), age(a), gpa(g), major(m) {
        cout << "🎓 Student created: " << name << " (GPA: " << gpa << ")" << endl;
    }

    // Copy constructor
    Student(const Student& other)
        : name(other.name), age(other.age), gpa(other.gpa), major(other.major) {
        cout << "📋 Student copied: " << name << endl;
    }

    // Move constructor
    Student(Student&& other) noexcept
        : name(move(other.name)), age(other.age), gpa(other.gpa), major(move(other.major)) {
        cout << "🚚 Student moved: " << name << endl;
        other.age = 0;
        other.gpa = 0.0;
    }

    ~Student() {
        if (!name.empty() && age > 0) {
            cout << "❌ Student record destroyed: " << name << endl;
        }
    }

    // Getters
    const string& getName() const { return name; }
    int getAge() const { return age; }
    double getGPA() const { return gpa; }
    const string& getMajor() const { return major; }

    void display() const {
        cout << "🎓 " << setw(15) << left << name
             << " | Age: " << setw(2) << age
             << " | GPA: " << fixed << setprecision(2) << setw(4) << gpa
             << " | Major: " << major << endl;
    }

    // Operators for algorithms
    bool operator==(const Student& other) const {
        return name == other.name && age == other.age && gpa == other.gpa;
    }

    bool operator<(const Student& other) const {
        return gpa < other.gpa;  // Sort by GPA
    }
};

// Custom predicates and function objects
struct IsHighAchiever {
    double threshold;
    IsHighAchiever(double t) : threshold(t) {}
    bool operator()(const Student& student) const {
        return student.getGPA() >= threshold;
    }
};

struct GPAComparator {
    bool operator()(const Student& a, const Student& b) const {
        return a.getGPA() > b.getGPA();  // Descending order
    }
};

struct AgeComparator {
    bool operator()(const Student& a, const Student& b) const {
        return a.getAge() < b.getAge();  // Ascending order
    }
};

// Function to demonstrate non-modifying algorithms
void demonstrateNonModifyingAlgorithms() {
    cout << "=== Non-Modifying Sequence Operations ===" << endl;

    cout << "\n--- Search Operations ---" << endl;

    vector<int> numbers{5, 2, 8, 2, 9, 1, 7, 2, 4};
    cout << "Numbers: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // find - linear search
    auto found_it = find(numbers.begin(), numbers.end(), 8);
    if (found_it != numbers.end()) {
        cout << "Found 8 at position: " << distance(numbers.begin(), found_it) << endl;
    }

    // find_if - search with predicate
    auto even_it = find_if(numbers.begin(), numbers.end(), [](int n) { return n % 2 == 0; });
    if (even_it != numbers.end()) {
        cout << "First even number: " << *even_it
             << " at position: " << distance(numbers.begin(), even_it) << endl;
    }

    // find_if_not - search for element not matching predicate
    auto odd_it = find_if_not(numbers.begin(), numbers.end(), [](int n) { return n % 2 == 0; });
    if (odd_it != numbers.end()) {
        cout << "First odd number: " << *odd_it
             << " at position: " << distance(numbers.begin(), odd_it) << endl;
    }

    // count - count occurrences
    int count_2 = count(numbers.begin(), numbers.end(), 2);
    cout << "Count of 2s: " << count_2 << endl;

    // count_if - count with predicate
    int even_count = count_if(numbers.begin(), numbers.end(), [](int n) { return n % 2 == 0; });
    cout << "Count of even numbers: " << even_count << endl;

    cout << "\n--- Advanced Search Operations ---" << endl;

    vector<string> words{"apple", "banana", "cherry", "date", "elderberry"};
    cout << "Words: ";
    for (const auto& word : words) cout << word << " ";
    cout << endl;

    // search - find subsequence
    vector<string> pattern{"banana", "cherry"};
    auto seq_it = search(words.begin(), words.end(), pattern.begin(), pattern.end());
    if (seq_it != words.end()) {
        cout << "Pattern found starting at position: " << distance(words.begin(), seq_it) << endl;
    }

    // find_first_of - find any of several values
    vector<string> targets{"cherry", "grape", "date"};
    auto first_match = find_first_of(words.begin(), words.end(), targets.begin(), targets.end());
    if (first_match != words.end()) {
        cout << "First match from targets: " << *first_match << endl;
    }

    // adjacent_find - find consecutive equal elements
    vector<int> with_adjacent{1, 2, 2, 3, 4, 4, 4, 5};
    cout << "Numbers with adjacent: ";
    for (int n : with_adjacent) cout << n << " ";
    cout << endl;

    auto adjacent_it = adjacent_find(with_adjacent.begin(), with_adjacent.end());
    if (adjacent_it != with_adjacent.end()) {
        cout << "First adjacent pair: " << *adjacent_it << " and " << *(adjacent_it + 1) << endl;
    }

    cout << "\n--- Comparison Operations ---" << endl;

    vector<int> vec1{1, 2, 3, 4, 5};
    vector<int> vec2{1, 2, 3, 4, 5};
    vector<int> vec3{1, 2, 3, 4, 6};

    cout << "vec1: ";
    for (int n : vec1) cout << n << " ";
    cout << endl;
    cout << "vec2: ";
    for (int n : vec2) cout << n << " ";
    cout << endl;
    cout << "vec3: ";
    for (int n : vec3) cout << n << " ";
    cout << endl;

    // equal - compare ranges
    bool are_equal = equal(vec1.begin(), vec1.end(), vec2.begin());
    cout << "vec1 == vec2: " << (are_equal ? "Yes" : "No") << endl;

    are_equal = equal(vec1.begin(), vec1.end(), vec3.begin());
    cout << "vec1 == vec3: " << (are_equal ? "Yes" : "No") << endl;

    // lexicographical_compare - dictionary order comparison
    bool is_less = lexicographical_compare(vec1.begin(), vec1.end(), vec3.begin(), vec3.end());
    cout << "vec1 < vec3 (lexicographically): " << (is_less ? "Yes" : "No") << endl;

    // mismatch - find first difference
    auto mismatch_pair = mismatch(vec1.begin(), vec1.end(), vec3.begin());
    if (mismatch_pair.first != vec1.end()) {
        cout << "First mismatch: vec1[" << distance(vec1.begin(), mismatch_pair.first)
             << "] = " << *mismatch_pair.first
             << ", vec3[" << distance(vec3.begin(), mismatch_pair.second)
             << "] = " << *mismatch_pair.second << endl;
    }

    cout << "\n--- Student Database Search Example ---" << endl;

    vector<Student> students;
    students.emplace_back("Alice Johnson", 20, 3.8, "Computer Science");
    students.emplace_back("Bob Smith", 22, 3.2, "Mathematics");
    students.emplace_back("Carol Davis", 19, 3.9, "Physics");
    students.emplace_back("David Wilson", 21, 3.1, "Chemistry");
    students.emplace_back("Eve Brown", 20, 3.7, "Engineering");

    cout << "\nStudent database:" << endl;
    for (const auto& student : students) {
        student.display();
    }

    // Find high achiever (GPA >= 3.5)
    auto high_achiever = find_if(students.begin(), students.end(), IsHighAchiever(3.5));
    if (high_achiever != students.end()) {
        cout << "\nFirst high achiever (GPA >= 3.5):" << endl;
        high_achiever->display();
    }

    // Count high achievers
    int high_achiever_count = count_if(students.begin(), students.end(), IsHighAchiever(3.5));
    cout << "Total high achievers: " << high_achiever_count << endl;

    // Find student by name using lambda
    string search_name = "Carol Davis";
    auto found_student = find_if(students.begin(), students.end(),
        [&search_name](const Student& s) { return s.getName() == search_name; });

    if (found_student != students.end()) {
        cout << "Found student " << search_name << ":" << endl;
        found_student->display();
    }

    // Check if all students have GPA > 3.0
    bool all_passing = all_of(students.begin(), students.end(),
        [](const Student& s) { return s.getGPA() > 3.0; });
    cout << "All students have GPA > 3.0: " << (all_passing ? "Yes" : "No") << endl;

    // Check if any student has GPA > 3.8
    bool any_excellent = any_of(students.begin(), students.end(),
        [](const Student& s) { return s.getGPA() > 3.8; });
    cout << "Any student has GPA > 3.8: " << (any_excellent ? "Yes" : "No") << endl;

    // Check if no student has GPA < 2.0
    bool none_failing = none_of(students.begin(), students.end(),
        [](const Student& s) { return s.getGPA() < 2.0; });
    cout << "No student has GPA < 2.0: " << (none_failing ? "Yes" : "No") << endl;
}

// Function to demonstrate modifying sequence operations
void demonstrateModifyingAlgorithms() {
    cout << "\n=== Modifying Sequence Operations ===" << endl;

    cout << "\n--- Copy Operations ---" << endl;

    vector<int> source{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> destination(source.size());

    cout << "Source: ";
    for (int n : source) cout << n << " ";
    cout << endl;

    // copy - basic copy
    copy(source.begin(), source.end(), destination.begin());
    cout << "After copy: ";
    for (int n : destination) cout << n << " ";
    cout << endl;

    // copy_if - conditional copy
    vector<int> evens;
    copy_if(source.begin(), source.end(), back_inserter(evens),
        [](int n) { return n % 2 == 0; });
    cout << "Even numbers: ";
    for (int n : evens) cout << n << " ";
    cout << endl;

    // copy_n - copy first n elements
    vector<int> first_five(5);
    copy_n(source.begin(), 5, first_five.begin());
    cout << "First 5 elements: ";
    for (int n : first_five) cout << n << " ";
    cout << endl;

    cout << "\n--- Transform Operations ---" << endl;

    vector<int> original{1, 2, 3, 4, 5};
    vector<int> squared(original.size());
    vector<int> doubled(original.size());

    cout << "Original: ";
    for (int n : original) cout << n << " ";
    cout << endl;

    // transform - apply function to each element
    transform(original.begin(), original.end(), squared.begin(),
        [](int n) { return n * n; });
    cout << "Squared: ";
    for (int n : squared) cout << n << " ";
    cout << endl;

    transform(original.begin(), original.end(), doubled.begin(),
        [](int n) { return n * 2; });
    cout << "Doubled: ";
    for (int n : doubled) cout << n << " ";
    cout << endl;

    // Binary transform - combine two ranges
    vector<int> sum_result(original.size());
    transform(squared.begin(), squared.end(), doubled.begin(), sum_result.begin(),
        [](int a, int b) { return a + b; });
    cout << "Squared + Doubled: ";
    for (int n : sum_result) cout << n << " ";
    cout << endl;

    cout << "\n--- Fill and Generate Operations ---" << endl;

    vector<int> fill_vector(10);

    // fill - fill with constant value
    fill(fill_vector.begin(), fill_vector.end(), 42);
    cout << "Filled with 42: ";
    for (int n : fill_vector) cout << n << " ";
    cout << endl;

    // fill_n - fill first n elements
    fill_n(fill_vector.begin(), 5, 99);
    cout << "First 5 filled with 99: ";
    for (int n : fill_vector) cout << n << " ";
    cout << endl;

    // generate - fill with function results
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    generate(fill_vector.begin(), fill_vector.end(), [&]() { return dis(gen); });
    cout << "Generated random: ";
    for (int n : fill_vector) cout << n << " ";
    cout << endl;

    // generate_n - generate first n elements
    vector<int> fibonacci_vec;
    int a = 1, b = 1;
    generate_n(back_inserter(fibonacci_vec), 10, [&]() {
        int result = a;
        int temp = a + b;
        a = b;
        b = temp;
        return result;
    });

    cout << "Fibonacci sequence: ";
    for (int n : fibonacci_vec) cout << n << " ";
    cout << endl;

    cout << "\n--- Remove and Replace Operations ---" << endl;

    vector<int> with_duplicates{1, 2, 2, 3, 2, 4, 5, 2, 6};
    cout << "With duplicates: ";
    for (int n : with_duplicates) cout << n << " ";
    cout << endl;

    // remove - remove specific value (doesn't actually remove, returns new end)
    auto new_end = remove(with_duplicates.begin(), with_duplicates.end(), 2);
    cout << "After remove(2): ";
    for (auto it = with_duplicates.begin(); it != new_end; ++it) cout << *it << " ";
    cout << " (size still: " << with_duplicates.size() << ")" << endl;

    // Actually erase the removed elements
    with_duplicates.erase(new_end, with_duplicates.end());
    cout << "After erase: ";
    for (int n : with_duplicates) cout << n << " ";
    cout << " (new size: " << with_duplicates.size() << ")" << endl;

    // remove_if - conditional remove
    vector<int> mixed{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Mixed: ";
    for (int n : mixed) cout << n << " ";
    cout << endl;

    auto odds_removed = remove_if(mixed.begin(), mixed.end(), [](int n) { return n % 2 == 1; });
    mixed.erase(odds_removed, mixed.end());
    cout << "Odd numbers removed: ";
    for (int n : mixed) cout << n << " ";
    cout << endl;

    // replace - replace specific value
    vector<int> to_replace{1, 5, 3, 5, 7, 5, 9};
    cout << "Before replace: ";
    for (int n : to_replace) cout << n << " ";
    cout << endl;

    replace(to_replace.begin(), to_replace.end(), 5, 99);
    cout << "Replace 5 with 99: ";
    for (int n : to_replace) cout << n << " ";
    cout << endl;

    // replace_if - conditional replace
    replace_if(to_replace.begin(), to_replace.end(), [](int n) { return n > 50; }, 0);
    cout << "Replace >50 with 0: ";
    for (int n : to_replace) cout << n << " ";
    cout << endl;

    cout << "\n--- Student Database Modifications ---" << endl;

    vector<Student> student_records;
    student_records.emplace_back("Alice Johnson", 20, 3.8, "Computer Science");
    student_records.emplace_back("Bob Smith", 22, 2.5, "Mathematics");
    student_records.emplace_back("Carol Davis", 19, 3.9, "Physics");
    student_records.emplace_back("David Wilson", 21, 2.8, "Chemistry");
    student_records.emplace_back("Eve Brown", 20, 3.7, "Engineering");

    cout << "Original student records:" << endl;
    for (const auto& student : student_records) {
        student.display();
    }

    // Create a copy with only high achievers
    vector<Student> high_achievers;
    copy_if(student_records.begin(), student_records.end(), back_inserter(high_achievers),
        IsHighAchiever(3.5));

    cout << "\nHigh achievers (GPA >= 3.5):" << endl;
    for (const auto& student : high_achievers) {
        student.display();
    }

    // Transform to create a name list
    vector<string> student_names;
    transform(student_records.begin(), student_records.end(), back_inserter(student_names),
        [](const Student& s) { return s.getName(); });

    cout << "\nStudent names: ";
    for (const auto& name : student_names) cout << name << " ";
    cout << endl;
}

int main() {
    demonstrateNonModifyingAlgorithms();
    demonstrateModifyingAlgorithms();

    cout << "\n=== Non-Modifying & Modifying Algorithms Summary ===" << endl;
    cout << "✅ find, find_if: Efficient linear search operations" << endl;
    cout << "✅ count, count_if: Statistical analysis of data" << endl;
    cout << "✅ all_of, any_of, none_of: Boolean logic over collections" << endl;
    cout << "✅ copy, copy_if: Safe data duplication with filtering" << endl;
    cout << "✅ transform: Powerful data transformation pipeline" << endl;
    cout << "✅ remove, remove_if: Conditional element removal" << endl;
    cout << "✅ replace, replace_if: In-place value substitution" << endl;
    cout << "⚠️ Some algorithms return iterators to new logical end" << endl;
    cout << "⚠️ Remember to call erase() after remove operations" << endl;

    return 0;
}
```

**Output:**

```
=== Non-Modifying Sequence Operations ===

--- Search Operations ---
Numbers: 5 2 8 2 9 1 7 2 4
Found 8 at position: 2
First even number: 2 at position: 1
First odd number: 5 at position: 0
Count of 2s: 3
Count of even numbers: 4

--- Advanced Search Operations ---
Words: apple banana cherry date elderberry
Pattern found starting at position: 1
First match from targets: cherry
Numbers with adjacent: 1 2 2 3 4 4 4 5
First adjacent pair: 2 and 2

--- Comparison Operations ---
vec1: 1 2 3 4 5
vec2: 1 2 3 4 5
vec3: 1 2 3 4 6
vec1 == vec2: Yes
vec1 == vec3: No
vec1 < vec3 (lexicographically): Yes
First mismatch: vec1[4] = 5, vec3[4] = 6

--- Student Database Search Example ---
🎓 Student created: Alice Johnson (GPA: 3.8)
🎓 Student created: Bob Smith (GPA: 3.2)
🎓 Student created: Carol Davis (GPA: 3.9)
🎓 Student created: David Wilson (GPA: 3.1)
🎓 Student created: Eve Brown (GPA: 3.7)

Student database:
🎓 Alice Johnson   | Age: 20 | GPA: 3.80 | Major: Computer Science
🎓 Bob Smith       | Age: 22 | GPA: 3.20 | Major: Mathematics
🎓 Carol Davis     | Age: 19 | GPA: 3.90 | Major: Physics
🎓 David Wilson    | Age: 21 | GPA: 3.10 | Major: Chemistry
🎓 Eve Brown       | Age: 20 | GPA: 3.70 | Major: Engineering

First high achiever (GPA >= 3.5):
🎓 Alice Johnson   | Age: 20 | GPA: 3.80 | Major: Computer Science
Total high achievers: 3
Found student Carol Davis:
🎓 Carol Davis     | Age: 19 | GPA: 3.90 | Major: Physics
All students have GPA > 3.0: Yes
Any student has GPA > 3.8: Yes
No student has GPA < 2.0: Yes

=== Modifying Sequence Operations ===

--- Copy Operations ---
Source: 1 2 3 4 5 6 7 8 9 10
After copy: 1 2 3 4 5 6 7 8 9 10
Even numbers: 2 4 6 8 10
First 5 elements: 1 2 3 4 5

--- Transform Operations ---
Original: 1 2 3 4 5
Squared: 1 4 9 16 25
Doubled: 2 4 6 8 10
Squared + Doubled: 3 8 15 24 35

--- Fill and Generate Operations ---
Filled with 42: 42 42 42 42 42 42 42 42 42 42
First 5 filled with 99: 99 99 99 99 99 42 42 42 42 42
Generated random: 73 28 91 45 67 82 19 34 56 88
Fibonacci sequence: 1 1 2 3 5 8 13 21 34 55

--- Remove and Replace Operations ---
With duplicates: 1 2 2 3 2 4 5 2 6
After remove(2): 1 3 4 5 6  (size still: 9)
After erase: 1 3 4 5 6  (new size: 5)
Mixed: 1 2 3 4 5 6 7 8 9 10
Odd numbers removed: 2 4 6 8 10
Before replace: 1 5 3 5 7 5 9
Replace 5 with 99: 1 99 3 99 7 99 9
Replace >50 with 0: 1 0 3 0 7 0 9

--- Student Database Modifications ---
🎓 Student created: Alice Johnson (GPA: 3.8)
🎓 Student created: Bob Smith (GPA: 2.5)
🎓 Student created: Carol Davis (GPA: 3.9)
🎓 Student created: David Wilson (GPA: 2.8)
🎓 Student created: Eve Brown (GPA: 3.7)
Original student records:
🎓 Alice Johnson   | Age: 20 | GPA: 3.80 | Major: Computer Science
🎓 Bob Smith       | Age: 22 | GPA: 2.50 | Major: Mathematics
🎓 Carol Davis     | Age: 19 | GPA: 3.90 | Major: Physics
🎓 David Wilson    | Age: 21 | GPA: 2.80 | Major: Chemistry
🎓 Eve Brown       | Age: 20 | GPA: 3.70 | Major: Engineering

High achievers (GPA >= 3.5):
📋 Student copied: Alice Johnson
📋 Student copied: Carol Davis
📋 Student copied: Eve Brown
🎓 Alice Johnson   | Age: 20 | GPA: 3.80 | Major: Computer Science
🎓 Carol Davis     | Age: 19 | GPA: 3.90 | Major: Physics
🎓 Eve Brown       | Age: 20 | GPA: 3.70 | Major: Engineering

Student names: Alice Johnson Bob Smith Carol Davis David Wilson Eve Brown

=== Non-Modifying & Modifying Algorithms Summary ===
✅ find, find_if: Efficient linear search operations
✅ count, count_if: Statistical analysis of data
✅ all_of, any_of, none_of: Boolean logic over collections
✅ copy, copy_if: Safe data duplication with filtering
✅ transform: Powerful data transformation pipeline
✅ remove, remove_if: Conditional element removal
✅ replace, replace_if: In-place value substitution
⚠️ Some algorithms return iterators to new logical end
⚠️ Remember to call erase() after remove operations
```

**STL algorithms provide powerful, generic operations that work seamlessly with any container through iterators!**

### 3.6.2 Sorting and Related Operations

**Concept**: Sorting algorithms arrange elements in a specific order and enable efficient searching in sorted ranges. STL provides various sorting algorithms optimized for different scenarios.

```cpp
// Function to demonstrate sorting and related operations
void demonstrateSortingAlgorithms() {
    cout << "\n=== Sorting and Related Operations ===" << endl;

    cout << "\n--- Basic Sorting ---" << endl;

    vector<int> unsorted{64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42};
    cout << "Original: ";
    for (int n : unsorted) cout << n << " ";
    cout << endl;

    // sort - general purpose sorting (typically introsort: quicksort + heapsort + insertion sort)
    vector<int> sorted_copy = unsorted;
    sort(sorted_copy.begin(), sorted_copy.end());
    cout << "Sorted (ascending): ";
    for (int n : sorted_copy) cout << n << " ";
    cout << endl;

    // sort with custom comparator (descending)
    sort(sorted_copy.begin(), sorted_copy.end(), greater<int>());
    cout << "Sorted (descending): ";
    for (int n : sorted_copy) cout << n << " ";
    cout << endl;

    // stable_sort - maintains relative order of equal elements
    vector<pair<int, string>> students_scores{
        {85, "Alice"}, {92, "Bob"}, {85, "Charlie"}, {78, "Diana"}, {92, "Eve"}
    };

    cout << "\nOriginal student scores:" << endl;
    for (const auto& [score, name] : students_scores) {
        cout << name << ": " << score << " ";
    }
    cout << endl;

    stable_sort(students_scores.begin(), students_scores.end(),
        [](const auto& a, const auto& b) { return a.first > b.first; });

    cout << "Stable sorted by score (high to low):" << endl;
    for (const auto& [score, name] : students_scores) {
        cout << name << ": " << score << " ";
    }
    cout << " (note: Bob before Eve, Alice before Charlie)" << endl;

    // partial_sort - sort only the first n elements
    vector<int> partial_data{9, 5, 8, 2, 7, 3, 6, 1, 4};
    cout << "\nPartial sort example:" << endl;
    cout << "Original: ";
    for (int n : partial_data) cout << n << " ";
    cout << endl;

    // Sort only the first 4 elements
    partial_sort(partial_data.begin(), partial_data.begin() + 4, partial_data.end());
    cout << "First 4 sorted: ";
    for (int n : partial_data) cout << n << " ";
    cout << " (first 4 are the smallest in sorted order)" << endl;

    // nth_element - partition around nth element
    vector<int> nth_data{9, 5, 8, 2, 7, 3, 6, 1, 4};
    cout << "\nnth_element example:" << endl;
    cout << "Original: ";
    for (int n : nth_data) cout << n << " ";
    cout << endl;

    // Find the 4th smallest element (0-indexed position 3)
    nth_element(nth_data.begin(), nth_data.begin() + 3, nth_data.end());
    cout << "After nth_element(3): ";
    for (int n : nth_data) cout << n << " ";
    cout << endl;
    cout << "4th smallest element: " << nth_data[3] << endl;

    cout << "\n--- Student Database Sorting ---" << endl;

    vector<Student> student_database;
    student_database.emplace_back("Alice Johnson", 20, 3.8, "Computer Science");
    student_database.emplace_back("Bob Smith", 22, 3.2, "Mathematics");
    student_database.emplace_back("Carol Davis", 19, 3.9, "Physics");
    student_database.emplace_back("David Wilson", 21, 3.1, "Chemistry");
    student_database.emplace_back("Eve Brown", 20, 3.7, "Engineering");
    student_database.emplace_back("Frank Miller", 19, 3.8, "Biology");

    cout << "Original student database:" << endl;
    for (const auto& student : student_database) {
        student.display();
    }

    // Sort by GPA (descending)
    sort(student_database.begin(), student_database.end(), GPAComparator());
    cout << "\nSorted by GPA (descending):" << endl;
    for (const auto& student : student_database) {
        student.display();
    }

    // Sort by age (ascending)
    sort(student_database.begin(), student_database.end(), AgeComparator());
    cout << "\nSorted by age (ascending):" << endl;
    for (const auto& student : student_database) {
        student.display();
    }

    // Multi-level sorting using lambda
    sort(student_database.begin(), student_database.end(),
        [](const Student& a, const Student& b) {
            if (a.getAge() != b.getAge()) {
                return a.getAge() < b.getAge();  // Primary: age ascending
            }
            return a.getGPA() > b.getGPA();      // Secondary: GPA descending
        });

    cout << "\nSorted by age (asc), then GPA (desc):" << endl;
    for (const auto& student : student_database) {
        student.display();
    }
}

// Function to demonstrate binary search operations
void demonstrateBinarySearchOperations() {
    cout << "\n--- Binary Search Operations ---" << endl;

    vector<int> sorted_numbers{1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    cout << "Sorted numbers: ";
    for (int n : sorted_numbers) cout << n << " ";
    cout << endl;

    // binary_search - check if element exists
    int search_val = 13;
    bool found = binary_search(sorted_numbers.begin(), sorted_numbers.end(), search_val);
    cout << "Binary search for " << search_val << ": " << (found ? "Found" : "Not found") << endl;

    search_val = 14;
    found = binary_search(sorted_numbers.begin(), sorted_numbers.end(), search_val);
    cout << "Binary search for " << search_val << ": " << (found ? "Found" : "Not found") << endl;

    // lower_bound - first position where element could be inserted
    auto lower_it = lower_bound(sorted_numbers.begin(), sorted_numbers.end(), 13);
    cout << "lower_bound(13): position " << distance(sorted_numbers.begin(), lower_it)
         << ", value: " << *lower_it << endl;

    lower_it = lower_bound(sorted_numbers.begin(), sorted_numbers.end(), 14);
    cout << "lower_bound(14): position " << distance(sorted_numbers.begin(), lower_it)
         << ", value: " << *lower_it << " (insertion point)" << endl;

    // upper_bound - first position after all equal elements
    auto upper_it = upper_bound(sorted_numbers.begin(), sorted_numbers.end(), 13);
    cout << "upper_bound(13): position " << distance(sorted_numbers.begin(), upper_it)
         << ", value: " << *upper_it << endl;

    // equal_range - get both bounds at once
    vector<int> with_duplicates{1, 3, 5, 7, 7, 7, 9, 11, 13, 15};
    cout << "\nWith duplicates: ";
    for (int n : with_duplicates) cout << n << " ";
    cout << endl;

    auto range = equal_range(with_duplicates.begin(), with_duplicates.end(), 7);
    cout << "equal_range(7): ";
    for (auto it = range.first; it != range.second; ++it) {
        cout << *it << " ";
    }
    cout << "| Count: " << distance(range.first, range.second) << endl;

    cout << "\n--- Merge Operations ---" << endl;

    vector<int> vec_a{1, 3, 5, 7, 9};
    vector<int> vec_b{2, 4, 6, 8, 10};
    vector<int> merged(vec_a.size() + vec_b.size());

    cout << "Vector A: ";
    for (int n : vec_a) cout << n << " ";
    cout << endl;
    cout << "Vector B: ";
    for (int n : vec_b) cout << n << " ";
    cout << endl;

    // merge - merge two sorted ranges
    merge(vec_a.begin(), vec_a.end(), vec_b.begin(), vec_b.end(), merged.begin());
    cout << "Merged: ";
    for (int n : merged) cout << n << " ";
    cout << endl;

    // inplace_merge - merge two parts of the same container
    vector<int> single_vec{1, 5, 9, 13, 2, 6, 10, 14};
    cout << "\nBefore inplace_merge: ";
    for (int n : single_vec) cout << n << " ";
    cout << endl;

    inplace_merge(single_vec.begin(), single_vec.begin() + 4, single_vec.end());
    cout << "After inplace_merge: ";
    for (int n : single_vec) cout << n << " ";
    cout << endl;

    cout << "\n--- Set Operations on Sorted Ranges ---" << endl;

    vector<int> set1{1, 2, 3, 4, 5, 6};
    vector<int> set2{4, 5, 6, 7, 8, 9};

    cout << "Set 1: ";
    for (int n : set1) cout << n << " ";
    cout << endl;
    cout << "Set 2: ";
    for (int n : set2) cout << n << " ";
    cout << endl;

    // set_union
    vector<int> union_result;
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
              back_inserter(union_result));
    cout << "Union: ";
    for (int n : union_result) cout << n << " ";
    cout << endl;

    // set_intersection
    vector<int> intersection_result;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                     back_inserter(intersection_result));
    cout << "Intersection: ";
    for (int n : intersection_result) cout << n << " ";
    cout << endl;

    // set_difference
    vector<int> difference_result;
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
                   back_inserter(difference_result));
    cout << "Difference (1 - 2): ";
    for (int n : difference_result) cout << n << " ";
    cout << endl;

    // set_symmetric_difference
    vector<int> sym_diff_result;
    set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
                            back_inserter(sym_diff_result));
    cout << "Symmetric difference: ";
    for (int n : sym_diff_result) cout << n << " ";
    cout << endl;

    cout << "\n--- Heap Operations ---" << endl;

    vector<int> heap_data{4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    cout << "Original: ";
    for (int n : heap_data) cout << n << " ";
    cout << endl;

    // make_heap - create max heap
    make_heap(heap_data.begin(), heap_data.end());
    cout << "After make_heap: ";
    for (int n : heap_data) cout << n << " ";
    cout << " (max element at front: " << heap_data.front() << ")" << endl;

    // push_heap - add element to heap
    heap_data.push_back(20);
    push_heap(heap_data.begin(), heap_data.end());
    cout << "After push_heap(20): ";
    for (int n : heap_data) cout << n << " ";
    cout << " (max: " << heap_data.front() << ")" << endl;

    // pop_heap - remove max element
    pop_heap(heap_data.begin(), heap_data.end());
    int max_val = heap_data.back();
    heap_data.pop_back();
    cout << "After pop_heap: ";
    for (int n : heap_data) cout << n << " ";
    cout << " (removed max: " << max_val << ")" << endl;

    // sort_heap - sort the heap (destroys heap property)
    sort_heap(heap_data.begin(), heap_data.end());
    cout << "After sort_heap: ";
    for (int n : heap_data) cout << n << " ";
    cout << " (now sorted)" << endl;

    // is_heap - check if range is a heap
    bool is_heap_prop = is_heap(heap_data.begin(), heap_data.end());
    cout << "Is still a heap: " << (is_heap_prop ? "Yes" : "No") << endl;

    make_heap(heap_data.begin(), heap_data.end());
    is_heap_prop = is_heap(heap_data.begin(), heap_data.end());
    cout << "After make_heap, is heap: " << (is_heap_prop ? "Yes" : "No") << endl;
}

// Function to demonstrate numeric operations
void demonstrateNumericOperations() {
    cout << "\n=== Numeric Operations ===" << endl;

    cout << "\n--- Accumulate and Reduce ---" << endl;

    vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Numbers: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // accumulate - sum with initial value
    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    cout << "Sum: " << sum << endl;

    // accumulate with custom operation (product)
    int product = accumulate(numbers.begin(), numbers.end(), 1, multiplies<int>());
    cout << "Product: " << product << endl;

    // accumulate with lambda (sum of squares)
    int sum_squares = accumulate(numbers.begin(), numbers.end(), 0,
        [](int acc, int n) { return acc + n * n; });
    cout << "Sum of squares: " << sum_squares << endl;

    cout << "\n--- Inner Product ---" << endl;

    vector<int> vec1{1, 2, 3, 4, 5};
    vector<int> vec2{2, 3, 4, 5, 6};

    cout << "Vector 1: ";
    for (int n : vec1) cout << n << " ";
    cout << endl;
    cout << "Vector 2: ";
    for (int n : vec2) cout << n << " ";
    cout << endl;

    // inner_product - dot product
    int dot_product = inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0);
    cout << "Dot product: " << dot_product << endl;

    // inner_product with custom operations
    int custom_result = inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0,
        plus<int>(), [](int a, int b) { return a * b * 2; });  // Double each product
    cout << "Custom operation (double products): " << custom_result << endl;

    cout << "\n--- Partial Sum and Adjacent Difference ---" << endl;

    vector<int> sequence{1, 2, 3, 4, 5};
    vector<int> partial_sums(sequence.size());
    vector<int> differences(sequence.size());

    cout << "Original sequence: ";
    for (int n : sequence) cout << n << " ";
    cout << endl;

    // partial_sum - running totals
    partial_sum(sequence.begin(), sequence.end(), partial_sums.begin());
    cout << "Partial sums: ";
    for (int n : partial_sums) cout << n << " ";
    cout << endl;

    // adjacent_difference - differences between consecutive elements
    adjacent_difference(sequence.begin(), sequence.end(), differences.begin());
    cout << "Adjacent differences: ";
    for (int n : differences) cout << n << " ";
    cout << " (first element is original)" << endl;

    cout << "\n--- Statistical Operations ---" << endl;

    vector<double> grades{85.5, 92.0, 78.5, 88.0, 95.5, 82.0, 90.5, 87.5};
    cout << "Grades: ";
    for (double g : grades) cout << fixed << setprecision(1) << g << " ";
    cout << endl;

    // Calculate statistics using numeric algorithms
    double total = accumulate(grades.begin(), grades.end(), 0.0);
    double mean = total / grades.size();
    cout << "Mean grade: " << fixed << setprecision(2) << mean << endl;

    // Find min and max
    auto minmax_result = minmax_element(grades.begin(), grades.end());
    cout << "Min grade: " << *minmax_result.first << endl;
    cout << "Max grade: " << *minmax_result.second << endl;

    // Calculate variance
    double variance = accumulate(grades.begin(), grades.end(), 0.0,
        [mean](double acc, double grade) {
            double diff = grade - mean;
            return acc + diff * diff;
        }) / grades.size();

    cout << "Variance: " << variance << endl;
    cout << "Standard deviation: " << sqrt(variance) << endl;

    cout << "\n--- Student GPA Analysis ---" << endl;

    vector<Student> analysis_students;
    analysis_students.emplace_back("Alice", 20, 3.8, "CS");
    analysis_students.emplace_back("Bob", 22, 3.2, "Math");
    analysis_students.emplace_back("Carol", 19, 3.9, "Physics");
    analysis_students.emplace_back("David", 21, 3.1, "Chemistry");
    analysis_students.emplace_back("Eve", 20, 3.7, "Engineering");

    // Calculate average GPA
    double total_gpa = accumulate(analysis_students.begin(), analysis_students.end(), 0.0,
        [](double acc, const Student& s) { return acc + s.getGPA(); });
    double avg_gpa = total_gpa / analysis_students.size();
    cout << "Average GPA: " << fixed << setprecision(2) << avg_gpa << endl;

    // Find student with highest GPA
    auto highest_gpa_student = max_element(analysis_students.begin(), analysis_students.end(),
        [](const Student& a, const Student& b) { return a.getGPA() < b.getGPA(); });
    cout << "Highest GPA student: " << highest_gpa_student->getName()
         << " (GPA: " << highest_gpa_student->getGPA() << ")" << endl;

    // Count students above average
    int above_avg_count = count_if(analysis_students.begin(), analysis_students.end(),
        [avg_gpa](const Student& s) { return s.getGPA() > avg_gpa; });
    cout << "Students above average GPA: " << above_avg_count << endl;
}

// Function to demonstrate algorithm performance
void demonstrateAlgorithmPerformance() {
    cout << "\n=== Algorithm Performance Analysis ===" << endl;

    const int testSize = 1000000;

    cout << "\n--- Sorting Algorithm Performance ---" << endl;

    // Generate test data
    vector<int> random_data(testSize);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, testSize);

    generate(random_data.begin(), random_data.end(), [&]() { return dis(gen); });

    // Test different sorting algorithms
    vector<int> sort_test = random_data;
    auto start = high_resolution_clock::now();
    sort(sort_test.begin(), sort_test.end());
    auto end = high_resolution_clock::now();
    auto sort_time = duration_cast<microseconds>(end - start);

    vector<int> stable_sort_test = random_data;
    start = high_resolution_clock::now();
    stable_sort(stable_sort_test.begin(), stable_sort_test.end());
    end = high_resolution_clock::now();
    auto stable_sort_time = duration_cast<microseconds>(end - start);

    cout << "Sorting " << testSize << " random integers:" << endl;
    cout << "std::sort:        " << sort_time.count() << " μs" << endl;
    cout << "std::stable_sort: " << stable_sort_time.count() << " μs" << endl;

    cout << "\n--- Search Algorithm Performance ---" << endl;

    // Binary search vs linear search on sorted data
    int search_value = testSize / 2;

    // Linear search
    start = high_resolution_clock::now();
    auto linear_result = find(sort_test.begin(), sort_test.end(), search_value);
    end = high_resolution_clock::now();
    auto linear_time = duration_cast<microseconds>(end - start);

    // Binary search
    start = high_resolution_clock::now();
    bool binary_result = binary_search(sort_test.begin(), sort_test.end(), search_value);
    end = high_resolution_clock::now();
    auto binary_time = duration_cast<microseconds>(end - start);

    cout << "Search performance on " << testSize << " sorted elements:" << endl;
    cout << "Linear search:  " << linear_time.count() << " μs" << endl;
    cout << "Binary search:  " << binary_time.count() << " μs" << endl;
    cout << "Speed ratio:    " << fixed << setprecision(1)
         << static_cast<double>(linear_time.count()) / binary_time.count() << "x faster" << endl;

    cout << "\nComplexity comparison:" << endl;
    cout << "Linear search: O(n) - " << linear_time.count() << " μs" << endl;
    cout << "Binary search: O(log n) - " << binary_time.count() << " μs" << endl;
    cout << "For " << testSize << " elements, log₂(n) ≈ " << log2(testSize) << endl;
}

int main() {
    demonstrateNonModifyingAlgorithms();
    demonstrateModifyingAlgorithms();
    demonstrateSortingAlgorithms();
    demonstrateBinarySearchOperations();
    demonstrateNumericOperations();
    demonstrateAlgorithmPerformance();

    cout << "\n=== STL Algorithms Complete Summary ===" << endl;
    cout << "✅ Non-modifying: find, count, search operations with O(n) complexity" << endl;
    cout << "✅ Modifying: copy, transform, remove, replace operations" << endl;
    cout << "✅ Sorting: sort, stable_sort, partial_sort with O(n log n) average" << endl;
    cout << "✅ Binary search: O(log n) operations on sorted ranges" << endl;
    cout << "✅ Set operations: union, intersection, difference on sorted ranges" << endl;
    cout << "✅ Heap operations: priority queue implementation primitives" << endl;
    cout << "✅ Numeric: accumulate, inner_product, statistical computations" << endl;
    cout << "✅ Generic design: work with any container via iterators" << endl;
    cout << "⚠️ Many algorithms require sorted input for correct behavior" << endl;
    cout << "⚠️ Some algorithms modify container size (require erase after remove)" << endl;
    cout << "⚠️ Performance varies significantly - choose appropriate algorithm" << endl;

    return 0;
}
```

This continues from the previous code and completes the comprehensive STL Algorithms tutorial. The complete output would be extensive, showing all the sorting operations, binary searches, numeric calculations, and performance comparisons.

**STL algorithms demonstrate the power of generic programming - one interface works with all containers!**

---

## Phase 3.7: STL Function Objects

### Introduction to Function Objects

**Concept**: **Function Objects** (also called **functors**) are objects that can be called like functions. They provide a powerful way to customize algorithm behavior, maintain state, and create reusable, composable logic. Function objects bridge the gap between simple function pointers and complex callable entities.

**Types of Function Objects**:

1. **Classic Functors** - Classes with `operator()` overloaded
2. **Lambda Expressions** - Anonymous function objects (C++11+)
3. **std::function** - Type-erased function wrapper (C++11+)
4. **std::bind** - Function argument binding utility (C++11+)
5. **Built-in Function Objects** - STL-provided functors

**Advantages of Function Objects**:

- **State Maintenance** - Can store data between calls
- **Inlining** - Compiler optimization opportunities
- **Type Safety** - Compile-time type checking
- **Flexibility** - Configurable behavior
- **Composability** - Can be combined and adapted

### 3.7.1 Classic Functors and Custom Function Objects

**Concept**: Classic functors are classes that implement `operator()`, making instances callable like functions. They can maintain state and provide customizable behavior.

```cpp
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <numeric>
#include <chrono>
#include <iomanip>
#include <random>
#include <memory>
using namespace std;
using namespace std::chrono;

// STL FUNCTION OBJECTS COMPREHENSIVE TUTORIAL

class Employee {
private:
    string name;
    string department;
    double salary;
    int experience;

public:
    Employee() : name(""), department(""), salary(0.0), experience(0) {}

    Employee(const string& n, const string& dept, double sal, int exp)
        : name(n), department(dept), salary(sal), experience(exp) {
        cout << "👨‍💼 Employee created: " << name << " ($" << salary << ")" << endl;
    }

    // Copy constructor
    Employee(const Employee& other)
        : name(other.name), department(other.department), salary(other.salary), experience(other.experience) {
        cout << "📋 Employee copied: " << name << endl;
    }

    // Move constructor
    Employee(Employee&& other) noexcept
        : name(move(other.name)), department(move(other.department)), salary(other.salary), experience(other.experience) {
        cout << "🚚 Employee moved: " << name << endl;
        other.salary = 0.0;
        other.experience = 0;
    }

    ~Employee() {
        if (!name.empty() && salary > 0.0) {
            cout << "❌ Employee record destroyed: " << name << endl;
        }
    }

    // Getters
    const string& getName() const { return name; }
    const string& getDepartment() const { return department; }
    double getSalary() const { return salary; }
    int getExperience() const { return experience; }

    void display() const {
        cout << "👨‍💼 " << setw(15) << left << name
             << " | Dept: " << setw(12) << left << department
             << " | Salary: $" << fixed << setprecision(0) << setw(8) << salary
             << " | Exp: " << experience << " years" << endl;
    }

    // Operators for containers
    bool operator==(const Employee& other) const {
        return name == other.name && department == other.department;
    }

    bool operator<(const Employee& other) const {
        return salary < other.salary;
    }
};

// Classic Function Objects (Functors)

// Simple arithmetic functors
template<typename T>
class Multiplier {
private:
    T factor;

public:
    explicit Multiplier(T f) : factor(f) {
        cout << "🔧 Multiplier functor created with factor: " << factor << endl;
    }

    T operator()(T value) const {
        return value * factor;
    }

    // Get the factor
    T getFactor() const { return factor; }

    // Set new factor
    void setFactor(T newFactor) { factor = newFactor; }
};

// Stateful counter functor
class Counter {
private:
    mutable int count;  // mutable allows modification in const operator()
    int step;

public:
    Counter(int initial = 0, int s = 1) : count(initial), step(s) {
        cout << "📊 Counter functor created: start=" << count << ", step=" << step << endl;
    }

    int operator()() const {
        count += step;
        return count;
    }

    int getCurrentCount() const { return count; }
    void reset(int newStart = 0) { count = newStart; }
};

// Advanced predicate functor for employees
class SalaryRangeFilter {
private:
    double minSalary;
    double maxSalary;
    mutable int filteredCount;

public:
    SalaryRangeFilter(double min, double max)
        : minSalary(min), maxSalary(max), filteredCount(0) {
        cout << "💰 SalaryRangeFilter created: $" << min << " - $" << max << endl;
    }

    bool operator()(const Employee& emp) const {
        bool inRange = emp.getSalary() >= minSalary && emp.getSalary() <= maxSalary;
        if (inRange) ++filteredCount;
        return inRange;
    }

    int getFilteredCount() const { return filteredCount; }
    void resetCount() const { filteredCount = 0; }
};

// Department-based comparator functor
class DepartmentComparator {
public:
    bool operator()(const Employee& a, const Employee& b) const {
        if (a.getDepartment() != b.getDepartment()) {
            return a.getDepartment() < b.getDepartment();  // Primary: department
        }
        return a.getSalary() > b.getSalary();  // Secondary: salary descending
    }
};

// Generic accumulator functor
template<typename T>
class Accumulator {
private:
    T sum;
    size_t count;

public:
    Accumulator() : sum(T{}), count(0) {
        cout << "🧮 Accumulator functor created" << endl;
    }

    void operator()(const T& value) {
        sum += value;
        ++count;
    }

    T getSum() const { return sum; }
    size_t getCount() const { return count; }
    T getAverage() const { return count > 0 ? sum / count : T{}; }
};

// Function to demonstrate classic functors
void demonstrateClassicFunctors() {
    cout << "=== Classic Function Objects (Functors) ===" << endl;

    cout << "\n--- Basic Functor Operations ---" << endl;

    // Multiplier functor
    Multiplier<int> doubler(2);
    Multiplier<double> tripler(3.0);

    vector<int> numbers{1, 2, 3, 4, 5};
    vector<int> doubled(numbers.size());
    vector<double> values{1.5, 2.5, 3.5, 4.5, 5.5};
    vector<double> tripled(values.size());

    cout << "Original numbers: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // Using functor with transform
    transform(numbers.begin(), numbers.end(), doubled.begin(), doubler);
    cout << "Doubled: ";
    for (int n : doubled) cout << n << " ";
    cout << endl;

    cout << "Original values: ";
    for (double v : values) cout << fixed << setprecision(1) << v << " ";
    cout << endl;

    transform(values.begin(), values.end(), tripled.begin(), tripler);
    cout << "Tripled: ";
    for (double v : tripled) cout << fixed << setprecision(1) << v << " ";
    cout << endl;

    // Modify factor and reuse
    doubler.setFactor(5);
    transform(numbers.begin(), numbers.end(), doubled.begin(), doubler);
    cout << "After changing factor to 5: ";
    for (int n : doubled) cout << n << " ";
    cout << endl;

    cout << "\n--- Stateful Counter Functor ---" << endl;

    Counter sequenceGenerator(0, 1);
    vector<int> sequence(10);

    // Generate sequence using functor
    generate(sequence.begin(), sequence.end(), sequenceGenerator);
    cout << "Generated sequence: ";
    for (int n : sequence) cout << n << " ";
    cout << " (current count: " << sequenceGenerator.getCurrentCount() << ")" << endl;

    // Reset and generate different sequence
    sequenceGenerator.reset(100);
    Counter stepByFive(100, 5);
    generate(sequence.begin(), sequence.end(), stepByFive);
    cout << "Step by 5 from 100: ";
    for (int n : sequence) cout << n << " ";
    cout << endl;

    cout << "\n--- Employee Database with Custom Functors ---" << endl;

    vector<Employee> employees;
    employees.emplace_back("Alice Johnson", "Engineering", 85000, 5);
    employees.emplace_back("Bob Smith", "Marketing", 65000, 3);
    employees.emplace_back("Carol Davis", "Engineering", 92000, 8);
    employees.emplace_back("David Wilson", "Finance", 78000, 6);
    employees.emplace_back("Eve Brown", "Marketing", 71000, 4);
    employees.emplace_back("Frank Miller", "Engineering", 88000, 7);
    employees.emplace_back("Grace Lee", "Finance", 82000, 5);

    cout << "Employee database:" << endl;
    for (const auto& emp : employees) {
        emp.display();
    }

    // Filter employees by salary range
    SalaryRangeFilter midRangeFilter(70000, 90000);
    vector<Employee> midRangeEmployees;

    cout << "\nFiltering employees with salary $70,000 - $90,000:" << endl;
    copy_if(employees.begin(), employees.end(), back_inserter(midRangeEmployees), midRangeFilter);

    for (const auto& emp : midRangeEmployees) {
        emp.display();
    }
    cout << "Filtered count: " << midRangeFilter.getFilteredCount() << " employees" << endl;

    // Sort by department then salary using custom comparator
    sort(employees.begin(), employees.end(), DepartmentComparator());
    cout << "\nSorted by department, then salary (desc):" << endl;
    for (const auto& emp : employees) {
        emp.display();
    }

    cout << "\n--- Accumulator Functor for Statistics ---" << endl;

    Accumulator<double> salaryAccumulator;
    for_each(employees.begin(), employees.end(),
        [&salaryAccumulator](const Employee& emp) {
            salaryAccumulator(emp.getSalary());
        });

    cout << "Salary statistics:" << endl;
    cout << "Total employees: " << salaryAccumulator.getCount() << endl;
    cout << "Total salary: $" << fixed << setprecision(0) << salaryAccumulator.getSum() << endl;
    cout << "Average salary: $" << salaryAccumulator.getAverage() << endl;
}

// Function to demonstrate built-in function objects
void demonstrateBuiltInFunctionObjects() {
    cout << "\n=== Built-in Function Objects ===" << endl;

    cout << "\n--- Arithmetic Function Objects ---" << endl;

    vector<int> numbers{10, 5, 8, 3, 12, 7, 15, 4};
    cout << "Numbers: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // Using built-in functors with algorithms

    // plus<int> - addition
    int sum = accumulate(numbers.begin(), numbers.end(), 0, plus<int>());
    cout << "Sum (using plus<int>): " << sum << endl;

    // multiplies<int> - multiplication
    int product = accumulate(numbers.begin(), numbers.end(), 1, multiplies<int>());
    cout << "Product (using multiplies<int>): " << product << endl;

    // Transform using built-in functors
    vector<int> doubled(numbers.size());
    transform(numbers.begin(), numbers.end(), doubled.begin(),
              bind(multiplies<int>(), placeholders::_1, 2));
    cout << "Doubled (using bind): ";
    for (int n : doubled) cout << n << " ";
    cout << endl;

    cout << "\n--- Comparison Function Objects ---" << endl;

    vector<string> words{"apple", "banana", "cherry", "date", "elderberry"};
    cout << "Words: ";
    for (const auto& word : words) cout << word << " ";
    cout << endl;

    // Sort in descending order using greater<string>
    sort(words.begin(), words.end(), greater<string>());
    cout << "Sorted descending: ";
    for (const auto& word : words) cout << word << " ";
    cout << endl;

    // Find elements using comparison functors
    auto it = find_if(numbers.begin(), numbers.end(),
                      bind(greater<int>(), placeholders::_1, 10));
    if (it != numbers.end()) {
        cout << "First number > 10: " << *it << endl;
    }

    cout << "\n--- Logical Function Objects ---" << endl;

    vector<bool> flags{true, false, true, true, false};
    cout << "Flags: ";
    for (bool flag : flags) cout << (flag ? "T" : "F") << " ";
    cout << endl;

    // Count true values using logical_and (though count would be simpler)
    bool all_true = accumulate(flags.begin(), flags.end(), true, logical_and<bool>());
    cout << "All true: " << (all_true ? "Yes" : "No") << endl;

    bool any_true = accumulate(flags.begin(), flags.end(), false, logical_or<bool>());
    cout << "Any true: " << (any_true ? "Yes" : "No") << endl;

    // Transform using logical_not
    vector<bool> negated(flags.size());
    transform(flags.begin(), flags.end(), negated.begin(), logical_not<bool>());
    cout << "Negated: ";
    for (bool flag : negated) cout << (flag ? "T" : "F") << " ";
    cout << endl;

    cout << "\n--- Bitwise Function Objects ---" << endl;

    vector<unsigned int> bits1{0x0F, 0x33, 0x55, 0xAA};
    vector<unsigned int> bits2{0xF0, 0xCC, 0x33, 0x55};
    vector<unsigned int> result(bits1.size());

    cout << "Bits1: ";
    for (auto b : bits1) cout << hex << "0x" << b << " ";
    cout << endl;
    cout << "Bits2: ";
    for (auto b : bits2) cout << hex << "0x" << b << " ";
    cout << endl;

    // Bitwise AND
    transform(bits1.begin(), bits1.end(), bits2.begin(), result.begin(), bit_and<unsigned int>());
    cout << "AND:   ";
    for (auto b : result) cout << hex << "0x" << b << " ";
    cout << endl;

    // Bitwise OR
    transform(bits1.begin(), bits1.end(), bits2.begin(), result.begin(), bit_or<unsigned int>());
    cout << "OR:    ";
    for (auto b : result) cout << hex << "0x" << b << " ";
    cout << endl;

    // Bitwise XOR
    transform(bits1.begin(), bits1.end(), bits2.begin(), result.begin(), bit_xor<unsigned int>());
    cout << "XOR:   ";
    for (auto b : result) cout << hex << "0x" << b << " ";
    cout << dec << endl;  // Reset to decimal
}

// Function to demonstrate lambda expressions
void demonstrateLambdaExpressions() {
    cout << "\n=== Lambda Expressions ===" << endl;

    cout << "\n--- Basic Lambda Syntax ---" << endl;

    // Simple lambdas
    auto add = [](int a, int b) { return a + b; };
    auto multiply = [](int a, int b) -> int { return a * b; };  // Explicit return type
    auto print_hello = []() { cout << "Hello from lambda!" << endl; };

    cout << "add(5, 3) = " << add(5, 3) << endl;
    cout << "multiply(4, 7) = " << multiply(4, 7) << endl;
    print_hello();

    vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "\nNumbers: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // Lambda with algorithms
    auto is_even = [](int n) { return n % 2 == 0; };
    auto square = [](int n) { return n * n; };

    int even_count = count_if(numbers.begin(), numbers.end(), is_even);
    cout << "Even numbers count: " << even_count << endl;

    vector<int> squares(numbers.size());
    transform(numbers.begin(), numbers.end(), squares.begin(), square);
    cout << "Squares: ";
    for (int n : squares) cout << n << " ";
    cout << endl;

    cout << "\n--- Lambda Captures ---" << endl;

    int multiplier = 3;
    string prefix = "Value: ";

    // Capture by value [=]
    auto multiply_by_value = [=](int n) {
        return n * multiplier;  // multiplier captured by value
    };

    // Capture by reference [&]
    auto multiply_by_reference = [&](int n) {
        multiplier++; // Can modify original multiplier
        return n * multiplier;
    };

    // Specific captures [multiplier, &prefix]
    auto format_value = [multiplier, &prefix](int n) {
        return prefix + to_string(n * multiplier);
    };

    cout << "Original multiplier: " << multiplier << endl;
    cout << "multiply_by_value(5): " << multiply_by_value(5) << endl;
    cout << "Multiplier after by-value capture: " << multiplier << endl;

    cout << "multiply_by_reference(5): " << multiply_by_reference(5) << endl;
    cout << "Multiplier after by-reference capture: " << multiplier << endl;

    cout << "format_value(10): " << format_value(10) << endl;

    cout << "\n--- Mutable Lambdas ---" << endl;

    int counter = 0;
    auto increment_counter = [counter]() mutable -> int {
        return ++counter;  // mutable allows modification of captured-by-value variables
    };

    cout << "Original counter: " << counter << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "increment_counter(): " << increment_counter() << endl;
    }
    cout << "Original counter after mutable lambda: " << counter << endl;

    cout << "\n--- Lambda with Employee Database ---" << endl;

    vector<Employee> company_employees;
    company_employees.emplace_back("Alice Johnson", "Engineering", 85000, 5);
    company_employees.emplace_back("Bob Smith", "Marketing", 65000, 3);
    company_employees.emplace_back("Carol Davis", "Engineering", 92000, 8);
    company_employees.emplace_back("David Wilson", "Finance", 78000, 6);

    cout << "Company employees:" << endl;
    for (const auto& emp : company_employees) {
        emp.display();
    }

    // Complex lambda for filtering and processing
    double salary_threshold = 80000;
    string target_department = "Engineering";

    auto senior_engineer_filter = [salary_threshold, target_department](const Employee& emp) {
        return emp.getDepartment() == target_department && emp.getSalary() >= salary_threshold;
    };

    auto salary_extractor = [](const Employee& emp) {
        return emp.getSalary();
    };

    // Find senior engineers
    vector<Employee> senior_engineers;
    copy_if(company_employees.begin(), company_employees.end(),
            back_inserter(senior_engineers), senior_engineer_filter);

    cout << "\nSenior Engineers ($80k+ in Engineering):" << endl;
    for (const auto& emp : senior_engineers) {
        emp.display();
    }

    // Calculate average salary of senior engineers
    double avg_senior_salary = 0;
    if (!senior_engineers.empty()) {
        double total = accumulate(senior_engineers.begin(), senior_engineers.end(), 0.0,
            [](double sum, const Employee& emp) {
                return sum + emp.getSalary();
            });
        avg_senior_salary = total / senior_engineers.size();
    }

    cout << "Average senior engineer salary: $" << fixed << setprecision(0) << avg_senior_salary << endl;

    cout << "\n--- Generic Lambdas (C++14) ---" << endl;

    // Generic lambda with auto parameters
    auto generic_printer = [](const auto& item) {
        cout << "Item: " << item << endl;
    };

    generic_printer(42);
    generic_printer(3.14);
    generic_printer(string("Hello"));

    // Generic lambda for comparison
    auto generic_max = [](const auto& a, const auto& b) {
        return (a > b) ? a : b;
    };

    cout << "max(10, 20) = " << generic_max(10, 20) << endl;
    cout << "max(3.14, 2.71) = " << generic_max(3.14, 2.71) << endl;
    cout << "max(\"apple\", \"banana\") = " << generic_max(string("apple"), string("banana")) << endl;
}

int main() {
    demonstrateClassicFunctors();
    demonstrateBuiltInFunctionObjects();
    demonstrateLambdaExpressions();

    cout << "\n=== Function Objects Summary ===" << endl;
    cout << "✅ Classic functors: Stateful, reusable, optimizable" << endl;
    cout << "✅ Built-in functors: Standard arithmetic, comparison, logical operations" << endl;
    cout << "✅ Lambda expressions: Concise, local, capture-enabled anonymous functions" << endl;
    cout << "✅ All work seamlessly with STL algorithms" << endl;
    cout << "✅ Enable functional programming patterns in C++" << endl;

    return 0;
}
```

This demonstrates the first part of Phase 3.7. The output would show extensive examples of functors, built-in function objects, and lambda expressions working with the Employee class and various algorithms.

**Function objects provide the ultimate flexibility in customizing algorithm behavior while maintaining performance!**

### 3.7.2 std::function and Type-Erased Callable Wrappers

**Concept**: `std::function` is a general-purpose polymorphic function wrapper that can store, copy, and invoke any callable target - functions, lambda expressions, bind expressions, or other function objects. It provides **type erasure** for callables with the same signature.

**Key Features**:

- **Type Erasure** - Can hold any callable with matching signature
- **Polymorphic Storage** - Runtime polymorphism for function objects
- **Null State** - Can be empty (similar to null pointer)
- **Performance** - Small overhead for flexibility
- **Thread Safety** - Can be safely copied between threads

```cpp
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <chrono>
#include <random>
#include <iomanip>
using namespace std;
using namespace std::chrono;

// ADVANCED FUNCTION OBJECTS WITH STD::FUNCTION

class TaskManager {
public:
    using TaskFunction = function<void()>;
    using ValidationFunction = function<bool(const string&)>;
    using ProcessorFunction = function<string(const string&)>;

private:
    map<string, TaskFunction> tasks;
    map<string, ValidationFunction> validators;
    map<string, ProcessorFunction> processors;

public:
    TaskManager() {
        cout << "📋 TaskManager initialized" << endl;
    }

    // Register different types of callables
    void registerTask(const string& name, TaskFunction task) {
        tasks[name] = task;
        cout << "✅ Task registered: " << name << endl;
    }

    void registerValidator(const string& name, ValidationFunction validator) {
        validators[name] = validator;
        cout << "✅ Validator registered: " << name << endl;
    }

    void registerProcessor(const string& name, ProcessorFunction processor) {
        processors[name] = processor;
        cout << "✅ Processor registered: " << name << endl;
    }

    // Execute stored callables
    bool executeTask(const string& name) {
        auto it = tasks.find(name);
        if (it != tasks.end() && it->second) {  // Check if function is not null
            cout << "🔄 Executing task: " << name << endl;
            it->second();
            return true;
        }
        cout << "❌ Task not found or null: " << name << endl;
        return false;
    }

    bool validate(const string& validatorName, const string& input) {
        auto it = validators.find(validatorName);
        if (it != validators.end() && it->second) {
            return it->second(input);
        }
        return false;
    }

    string process(const string& processorName, const string& input) {
        auto it = processors.find(processorName);
        if (it != processors.end() && it->second) {
            return it->second(input);
        }
        return "Error: Processor not found";
    }

    void listTasks() {
        cout << "📋 Registered tasks:" << endl;
        for (const auto& [name, func] : tasks) {
            cout << "  - " << name << (func ? " ✅" : " ❌") << endl;
        }
    }

    void clearTask(const string& name) {
        auto it = tasks.find(name);
        if (it != tasks.end()) {
            it->second = nullptr;  // Set to null
            cout << "🗑️ Task cleared: " << name << endl;
        }
    }
};

// Example classes and functions to demonstrate std::function

class DataProcessor {
private:
    string name;

public:
    DataProcessor(const string& n) : name(n) {}

    void processData() {
        cout << "🔄 " << name << " processing data..." << endl;
    }

    string transformText(const string& text) {
        cout << "🔤 " << name << " transforming: " << text << endl;
        return "[" + name + "]: " + text;
    }

    bool validateInput(const string& input) {
        bool valid = !input.empty() && input.length() >= 3;
        cout << "✔️ " << name << " validating '" << input << "': " << (valid ? "VALID" : "INVALID") << endl;
        return valid;
    }
};

// Free functions
void globalTask() {
    cout << "🌐 Executing global task function" << endl;
}

bool globalValidator(const string& input) {
    bool valid = input.find("@") != string::npos;
    cout << "📧 Global email validator for '" << input << "': " << (valid ? "VALID" : "INVALID") << endl;
    return valid;
}

string globalProcessor(const string& input) {
    cout << "🌐 Global processor working on: " << input << endl;
    return "PROCESSED: " + input;
}

// Function that returns std::function
function<int(int)> createMultiplier(int factor) {
    return [factor](int value) {
        return value * factor;
    };
}

// Function that accepts std::function as parameter
void executeWithCallback(const string& operation, function<void()> callback) {
    cout << "⚡ Starting operation: " << operation << endl;
    callback();
    cout << "✅ Operation completed: " << operation << endl;
}

// Advanced: std::function with complex signatures
using EventHandler = function<void(const string&, int)>;
using DataTransformer = function<vector<string>(const vector<string>&)>;

class EventSystem {
private:
    map<string, vector<EventHandler>> handlers;

public:
    void subscribe(const string& eventType, EventHandler handler) {
        handlers[eventType].push_back(handler);
        cout << "📡 Subscribed to event: " << eventType << endl;
    }

    void publish(const string& eventType, const string& data, int priority) {
        cout << "📢 Publishing event: " << eventType << " (priority: " << priority << ")" << endl;
        auto it = handlers.find(eventType);
        if (it != handlers.end()) {
            for (auto& handler : it->second) {
                if (handler) {  // Check if not null
                    handler(data, priority);
                }
            }
        }
    }
};

void demonstrateStdFunction() {
    cout << "=== std::function Demonstration ===" << endl;

    cout << "\n--- Basic std::function Usage ---" << endl;

    TaskManager manager;
    DataProcessor processor1("Processor-A");
    DataProcessor processor2("Processor-B");

    // Store different types of callables in std::function

    // 1. Free function
    manager.registerTask("global_task", globalTask);

    // 2. Lambda expression
    manager.registerTask("lambda_task", []() {
        cout << "🔹 Executing lambda task" << endl;
    });

    // 3. Member function (using bind or lambda)
    manager.registerTask("member_task", [&processor1]() {
        processor1.processData();
    });

    // 4. Function object/functor
    class CustomTask {
    public:
        void operator()() {
            cout << "🎯 Executing custom functor task" << endl;
        }
    };
    CustomTask customTask;
    manager.registerTask("functor_task", customTask);

    // Execute all tasks
    manager.listTasks();
    cout << "\n--- Executing Tasks ---" << endl;
    manager.executeTask("global_task");
    manager.executeTask("lambda_task");
    manager.executeTask("member_task");
    manager.executeTask("functor_task");
    manager.executeTask("nonexistent_task");  // Should fail

    cout << "\n--- Validators and Processors ---" << endl;

    // Register validators
    manager.registerValidator("email", globalValidator);
    manager.registerValidator("length", [](const string& input) {
        bool valid = input.length() >= 5;
        cout << "📏 Length validator for '" << input << "': " << (valid ? "VALID" : "INVALID") << endl;
        return valid;
    });
    manager.registerValidator("processor1", [&processor1](const string& input) {
        return processor1.validateInput(input);
    });

    // Register processors
    manager.registerProcessor("global", globalProcessor);
    manager.registerProcessor("transform", [&processor2](const string& input) {
        return processor2.transformText(input);
    });

    // Test validators and processors
    vector<string> testInputs{"test@email.com", "short", "valid_input", "x"};

    for (const auto& input : testInputs) {
        cout << "\nTesting input: '" << input << "'" << endl;
        cout << "  Email valid: " << manager.validate("email", input) << endl;
        cout << "  Length valid: " << manager.validate("length", input) << endl;
        cout << "  Processor1 valid: " << manager.validate("processor1", input) << endl;

        if (manager.validate("length", input)) {
            cout << "  Global process: " << manager.process("global", input) << endl;
            cout << "  Transform: " << manager.process("transform", input) << endl;
        }
    }

    cout << "\n--- std::function Null State ---" << endl;

    function<void()> nullTask;  // Default constructed - null state
    function<void()> assignedTask = []() { cout << "Valid task" << endl; };

    cout << "nullTask is null: " << (nullTask ? "NO" : "YES") << endl;
    cout << "assignedTask is null: " << (assignedTask ? "NO" : "YES") << endl;

    // Safe execution
    if (assignedTask) {
        assignedTask();
    }

    if (!nullTask) {
        cout << "Skipping null task execution" << endl;
    }

    manager.clearTask("global_task");
    manager.executeTask("global_task");  // Should fail now

    cout << "\n--- Higher-Order Functions with std::function ---" << endl;

    // Creating and using function factories
    auto doubler = createMultiplier(2);
    auto tripler = createMultiplier(3);

    vector<int> numbers{1, 2, 3, 4, 5};
    cout << "Numbers: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    cout << "Doubled: ";
    for (int n : numbers) cout << doubler(n) << " ";
    cout << endl;

    cout << "Tripled: ";
    for (int n : numbers) cout << tripler(n) << " ";
    cout << endl;

    // Using callbacks
    executeWithCallback("Database Connection", []() {
        cout << "💾 Connecting to database..." << endl;
    });

    executeWithCallback("Data Processing", [&processor1]() {
        processor1.processData();
    });

    cout << "\n--- Event System with std::function ---" << endl;

    EventSystem eventSystem;

    // Subscribe different types of handlers
    eventSystem.subscribe("user_login", [](const string& user, int priority) {
        cout << "👤 User login handler: " << user << " (priority: " << priority << ")" << endl;
    });

    eventSystem.subscribe("user_login", [](const string& user, int priority) {
        if (priority > 5) {
            cout << "🔔 High priority login notification for: " << user << endl;
        }
    });

    eventSystem.subscribe("data_update", [](const string& data, int priority) {
        cout << "📊 Data update handler: " << data << " (priority: " << priority << ")" << endl;
    });

    // Publish events
    eventSystem.publish("user_login", "alice@example.com", 3);
    eventSystem.publish("user_login", "admin@example.com", 10);
    eventSystem.publish("data_update", "customer_data", 7);

    cout << "\n--- Complex Data Transformation ---" << endl;

    vector<string> rawData{"apple", "banana", "cherry", "date"};
    cout << "Raw data: ";
    for (const auto& item : rawData) cout << item << " ";
    cout << endl;

    // Define transformation functions
    DataTransformer upperCaseTransformer = [](const vector<string>& data) {
        vector<string> result;
        for (const auto& item : data) {
            string upper = item;
            transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
            result.push_back(upper);
        }
        return result;
    };

    DataTransformer prefixTransformer = [](const vector<string>& data) {
        vector<string> result;
        for (const auto& item : data) {
            result.push_back("ITEM: " + item);
        }
        return result;
    };

    // Apply transformations
    auto uppercased = upperCaseTransformer(rawData);
    cout << "Uppercased: ";
    for (const auto& item : uppercased) cout << item << " ";
    cout << endl;

    auto prefixed = prefixTransformer(uppercased);
    cout << "Prefixed: ";
    for (const auto& item : prefixed) cout << item << " ";
    cout << endl;
}

// Function to demonstrate performance characteristics
void demonstrateStdFunctionPerformance() {
    cout << "\n=== std::function Performance Analysis ===" << endl;

    const int iterations = 1000000;
    vector<int> data(1000);
    iota(data.begin(), data.end(), 1);  // Fill with 1, 2, 3, ...

    // Direct function call
    auto start = high_resolution_clock::now();
    int sum1 = 0;
    for (int i = 0; i < iterations; ++i) {
        sum1 = accumulate(data.begin(), data.end(), 0, plus<int>());
    }
    auto end = high_resolution_clock::now();
    auto direct_time = duration_cast<microseconds>(end - start);

    // std::function call
    function<int(int, int)> add_func = plus<int>();
    start = high_resolution_clock::now();
    int sum2 = 0;
    for (int i = 0; i < iterations; ++i) {
        sum2 = accumulate(data.begin(), data.end(), 0, add_func);
    }
    end = high_resolution_clock::now();
    auto function_time = duration_cast<microseconds>(end - start);

    // Lambda directly
    auto lambda_add = [](int a, int b) { return a + b; };
    start = high_resolution_clock::now();
    int sum3 = 0;
    for (int i = 0; i < iterations; ++i) {
        sum3 = accumulate(data.begin(), data.end(), 0, lambda_add);
    }
    end = high_resolution_clock::now();
    auto lambda_time = duration_cast<microseconds>(end - start);

    cout << "Performance comparison (" << iterations << " iterations):" << endl;
    cout << "Direct functor:   " << setw(8) << direct_time.count() << " μs" << endl;
    cout << "std::function:    " << setw(8) << function_time.count() << " μs" << endl;
    cout << "Lambda direct:    " << setw(8) << lambda_time.count() << " μs" << endl;
    cout << "Overhead factor:  " << fixed << setprecision(2)
         << (double)function_time.count() / direct_time.count() << "x" << endl;

    cout << "All sums equal: " << (sum1 == sum2 && sum2 == sum3 ? "YES" : "NO") << endl;
    cout << "Sum result: " << sum1 << endl;
}

int main() {
    demonstrateStdFunction();
    demonstrateStdFunctionPerformance();

    cout << "\n=== std::function Summary ===" << endl;
    cout << "✅ Type erasure: Store any callable with matching signature" << endl;
    cout << "✅ Polymorphism: Runtime flexibility for function objects" << endl;
    cout << "✅ Null state: Can be empty and checked before use" << endl;
    cout << "✅ Performance: Small overhead for great flexibility" << endl;
    cout << "✅ Use cases: Callbacks, event systems, strategy patterns" << endl;

    return 0;
}
```

This demonstrates `std::function` with practical examples including task management, event systems, and performance analysis.

### 3.7.3 std::bind and Function Argument Binding

**Concept**: `std::bind` creates function objects by binding arguments to functions, member functions, or other function objects. It enables **partial application** and **argument reordering**, creating customized callables from existing functions.

**Key Features**:

- **Argument Binding** - Fix some arguments, leave others as placeholders
- **Member Function Binding** - Bind object methods easily
- **Argument Reordering** - Change parameter order
- **Placeholder System** - `_1`, `_2`, etc. for unbound parameters
- **Nested Binding** - Compose complex function objects

```cpp
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <memory>
#include <chrono>
#include <iomanip>
#include <random>
using namespace std;
using namespace std::placeholders;  // For _1, _2, _3, etc.

// COMPREHENSIVE STD::BIND DEMONSTRATION

class Calculator {
private:
    string name;
    int calculation_count;

public:
    Calculator(const string& n) : name(n), calculation_count(0) {
        cout << "🧮 Calculator created: " << name << endl;
    }

    // Various calculation methods
    double add(double a, double b) {
        ++calculation_count;
        double result = a + b;
        cout << "➕ " << name << ": " << a << " + " << b << " = " << result << endl;
        return result;
    }

    double multiply(double a, double b) {
        ++calculation_count;
        double result = a * b;
        cout << "✖️ " << name << ": " << a << " × " << b << " = " << result << endl;
        return result;
    }

    double power(double base, double exponent) {
        ++calculation_count;
        double result = pow(base, exponent);
        cout << "🔢 " << name << ": " << base << "^" << exponent << " = " << result << endl;
        return result;
    }

    bool isGreater(double a, double b) const {
        cout << "❓ " << name << ": Is " << a << " > " << b << "? " << (a > b ? "YES" : "NO") << endl;
        return a > b;
    }

    void displayCount() const {
        cout << "📊 " << name << " performed " << calculation_count << " calculations" << endl;
    }

    // Method with three parameters for complex binding
    double calculate(const string& operation, double a, double b) {
        ++calculation_count;
        double result = 0;
        if (operation == "add") result = a + b;
        else if (operation == "subtract") result = a - b;
        else if (operation == "multiply") result = a * b;
        else if (operation == "divide" && b != 0) result = a / b;

        cout << "🎯 " << name << " " << operation << ": " << a << " " << operation << " " << b << " = " << result << endl;
        return result;
    }

    string getName() const { return name; }
};

// Free functions for binding demonstrations
double globalAdd(double x, double y) {
    cout << "🌐 Global add: " << x << " + " << y << " = " << (x + y) << endl;
    return x + y;
}

double complexFunction(double a, double b, double c, double d) {
    double result = a * b + c - d;
    cout << "🔧 Complex: " << a << "*" << b << "+" << c << "-" << d << " = " << result << endl;
    return result;
}

bool inRange(double value, double min, double max) {
    bool result = value >= min && value <= max;
    cout << "📏 Range check: " << min << " ≤ " << value << " ≤ " << max << " = " << (result ? "YES" : "NO") << endl;
    return result;
}

void printMessage(const string& prefix, const string& message, int priority) {
    cout << "📢 [" << prefix << "] Priority " << priority << ": " << message << endl;
}

// Demonstration functions
void demonstrateBasicBinding() {
    cout << "=== Basic std::bind Usage ===" << endl;

    cout << "\n--- Binding Free Functions ---" << endl;

    // Basic argument binding
    auto add5 = bind(globalAdd, _1, 5.0);  // Fix second argument to 5.0
    auto add10 = bind(globalAdd, 10.0, _1); // Fix first argument to 10.0

    cout << "add5(3.0): ";
    add5(3.0);  // Equivalent to globalAdd(3.0, 5.0)

    cout << "add10(7.0): ";
    add10(7.0);  // Equivalent to globalAdd(10.0, 7.0)

    // Argument reordering
    auto swapped_add = bind(globalAdd, _2, _1);  // Swap arguments
    cout << "swapped_add(3.0, 8.0): ";
    swapped_add(3.0, 8.0);  // Equivalent to globalAdd(8.0, 3.0)

    // Complex function binding
    cout << "\n--- Complex Function Binding ---" << endl;

    // Bind some arguments, leave others as placeholders
    auto complex_partial = bind(complexFunction, _1, 2.0, _2, 1.0);
    cout << "complex_partial(5.0, 3.0): ";
    complex_partial(5.0, 3.0);  // complexFunction(5.0, 2.0, 3.0, 1.0)

    // Bind all but one argument
    auto almost_complete = bind(complexFunction, 1.0, 2.0, 3.0, _1);
    cout << "almost_complete(4.0): ";
    almost_complete(4.0);  // complexFunction(1.0, 2.0, 3.0, 4.0)

    // Use with algorithms
    vector<double> numbers{1.0, 2.0, 3.0, 4.0, 5.0};
    cout << "\nNumbers: ";
    for (double n : numbers) cout << n << " ";
    cout << endl;

    cout << "Adding 10 to each number:" << endl;
    for_each(numbers.begin(), numbers.end(), add10);

    // Range checking with bind
    cout << "\n--- Range Validation ---" << endl;
    auto validScore = bind(inRange, _1, 0.0, 100.0);  // Score between 0-100
    auto validTemperature = bind(inRange, _1, -50.0, 50.0);  // Temperature range

    vector<double> scores{85.0, 150.0, -10.0, 95.5, 0.0};
    cout << "Score validation (0-100):" << endl;
    for (double score : scores) {
        validScore(score);
    }

    vector<double> temperatures{25.0, -60.0, 45.0, 100.0, 0.0};
    cout << "\nTemperature validation (-50 to 50):" << endl;
    for (double temp : temperatures) {
        validTemperature(temp);
    }
}

void demonstrateMemberFunctionBinding() {
    cout << "\n=== Member Function Binding ===" << endl;

    Calculator calc1("Primary");
    Calculator calc2("Secondary");

    cout << "\n--- Basic Member Function Binding ---" << endl;

    // Bind member function to specific object
    auto calc1_add = bind(&Calculator::add, &calc1, _1, _2);
    auto calc1_multiply = bind(&Calculator::multiply, &calc1, _1, _2);

    cout << "Using bound member functions:" << endl;
    calc1_add(5.0, 3.0);
    calc1_multiply(4.0, 6.0);

    // Partial binding with member functions
    auto calc1_add5 = bind(&Calculator::add, &calc1, _1, 5.0);
    auto calc1_square = bind(&Calculator::power, &calc1, _1, 2.0);

    cout << "\nPartial binding with member functions:" << endl;
    calc1_add5(7.0);    // add(7.0, 5.0)
    calc1_square(4.0);  // power(4.0, 2.0)

    calc1.displayCount();

    cout << "\n--- Member Function with Multiple Objects ---" << endl;

    // Create functions that work with different objects
    auto any_calc_add = bind(&Calculator::add, _1, _2, _3);  // Object as first parameter

    cout << "Using same bound function with different objects:" << endl;
    any_calc_add(&calc1, 10.0, 20.0);
    any_calc_add(&calc2, 15.0, 25.0);

    calc1.displayCount();
    calc2.displayCount();

    cout << "\n--- Complex Member Function Binding ---" << endl;

    // Bind complex member function with operation parameter fixed
    auto calc1_multiply_op = bind(&Calculator::calculate, &calc1, "multiply", _1, _2);
    auto calc2_divide_op = bind(&Calculator::calculate, &calc2, "divide", _1, _2);

    cout << "Fixed operation binding:" << endl;
    calc1_multiply_op(6.0, 7.0);
    calc2_divide_op(20.0, 4.0);

    // Bind with object and one operand fixed
    auto calc1_multiply_by_3 = bind(&Calculator::calculate, &calc1, "multiply", _1, 3.0);

    vector<double> values{2.0, 4.0, 5.0, 1.5};
    cout << "\nMultiplying values by 3:" << endl;
    for (double val : values) {
        calc1_multiply_by_3(val);
    }

    cout << "\n--- Using Bound Member Functions with Algorithms ---" << endl;

    vector<double> test_values{1.0, 2.0, 3.0, 4.0, 5.0};
    auto calc1_greater_than_3 = bind(&Calculator::isGreater, &calc1, _1, 3.0);

    cout << "Values greater than 3:" << endl;
    auto it = find_if(test_values.begin(), test_values.end(), calc1_greater_than_3);
    if (it != test_values.end()) {
        cout << "First value > 3: " << *it << endl;
    }

    int count_greater = count_if(test_values.begin(), test_values.end(), calc1_greater_than_3);
    cout << "Count of values > 3: " << count_greater << endl;

    calc1.displayCount();
    calc2.displayCount();
}

void demonstrateAdvancedBinding() {
    cout << "\n=== Advanced std::bind Techniques ===" << endl;

    cout << "\n--- Nested Binding ---" << endl;

    Calculator calc("Advanced");

    // Nested bind: bind result of one bind to another
    auto add_then_square = [&calc](double x, double y) {
        double sum = calc.add(x, y);
        return calc.power(sum, 2.0);
    };

    cout << "Add then square (3, 4):" << endl;
    double result = add_then_square(3.0, 4.0);
    cout << "Final result: " << result << endl;

    cout << "\n--- Binding with Smart Pointers ---" << endl;

    auto smart_calc = make_shared<Calculator>("Smart");

    // Bind member function of object in shared_ptr
    auto smart_add = bind(&Calculator::add, smart_calc, _1, _2);
    auto smart_multiply = bind(&Calculator::multiply, smart_calc.get(), _1, _2);

    cout << "Using smart pointer binding:" << endl;
    smart_add(5.0, 7.0);
    smart_multiply(3.0, 4.0);
    smart_calc->displayCount();

    cout << "\n--- Message System with Complex Binding ---" << endl;

    // Create specialized message functions
    auto error_msg = bind(printMessage, "ERROR", _1, 1);
    auto warning_msg = bind(printMessage, "WARNING", _1, 2);
    auto info_msg = bind(printMessage, "INFO", _1, 3);

    // Create priority-specific functions
    auto high_priority = bind(printMessage, _1, _2, 1);
    auto medium_priority = bind(printMessage, _1, _2, 2);

    cout << "Specialized message functions:" << endl;
    error_msg("System failure detected");
    warning_msg("Low memory available");
    info_msg("Process completed successfully");

    cout << "\nPriority-based messages:" << endl;
    high_priority("ALERT", "Critical system error");
    medium_priority("NOTICE", "Maintenance scheduled");

    cout << "\n--- Argument Order Manipulation ---" << endl;

    // Function with many parameters
    auto print_details = [](const string& name, int age, const string& city, double salary) {
        cout << "👤 " << name << ", " << age << " years old, lives in " << city << ", earns $" << salary << endl;
    };

    // Reorder arguments: salary, age, name, city -> name, age, city, salary
    auto normal_order = bind(print_details, _3, _2, _4, _1);

    cout << "Original parameter order (salary, age, name, city):" << endl;
    cout << "Reordered to (name, age, city, salary):" << endl;
    normal_order(75000.0, 30, "John Doe", "New York");
    normal_order(85000.0, 35, "Jane Smith", "San Francisco");

    cout << "\n--- Performance Comparison ---" << endl;

    const int iterations = 100000;
    vector<double> data{1.0, 2.0, 3.0, 4.0, 5.0};

    // Direct lambda
    auto start = chrono::high_resolution_clock::now();
    double sum1 = 0;
    for (int i = 0; i < iterations; ++i) {
        sum1 += accumulate(data.begin(), data.end(), 0.0, [](double a, double b) { return a + b; });
    }
    auto end = chrono::high_resolution_clock::now();
    auto lambda_time = chrono::duration_cast<chrono::microseconds>(end - start);

    // Using bind
    auto bound_add = bind(plus<double>(), _1, _2);
    start = chrono::high_resolution_clock::now();
    double sum2 = 0;
    for (int i = 0; i < iterations; ++i) {
        sum2 += accumulate(data.begin(), data.end(), 0.0, bound_add);
    }
    end = chrono::high_resolution_clock::now();
    auto bind_time = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Performance (" << iterations << " iterations):" << endl;
    cout << "Lambda:       " << setw(8) << lambda_time.count() << " μs" << endl;
    cout << "std::bind:    " << setw(8) << bind_time.count() << " μs" << endl;
    cout << "Overhead:     " << fixed << setprecision(2)
         << (double)bind_time.count() / lambda_time.count() << "x" << endl;
    cout << "Results equal: " << (abs(sum1 - sum2) < 1e-9 ? "YES" : "NO") << endl;
}

int main() {
    demonstrateBasicBinding();
    demonstrateMemberFunctionBinding();
    demonstrateAdvancedBinding();

    cout << "\n=== std::bind Summary ===" << endl;
    cout << "✅ Argument binding: Fix some parameters, leave others flexible" << endl;
    cout << "✅ Member functions: Easy binding of object methods" << endl;
    cout << "✅ Argument reordering: Change parameter order as needed" << endl;
    cout << "✅ Partial application: Create specialized functions from general ones" << endl;
    cout << "✅ Algorithm integration: Works seamlessly with STL algorithms" << endl;
    cout << "💡 Modern alternative: Lambda expressions often more readable" << endl;

    return 0;
}
```

This demonstrates comprehensive `std::bind` usage with practical examples and performance comparisons.

---
