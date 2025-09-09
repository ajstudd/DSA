/*
=================================================================================
                    COMPREHENSIVE GUIDE TO POINTERS IN C++
=================================================================================
Author: Complete Educational Resource
Purpose: Master pointers from basic to advanced concepts
Language: C++

This file covers:
1. Basic Pointer Concepts
2. Pointer Arithmetic
3. Pointers and Arrays
4. Pointers and Functions
5. Dynamic Memory Allocation
6. Pointer to Pointers
7. Function Pointers
8. Smart Pointers (C++11+)
9. Advanced Pointer Concepts
10. Common Pitfalls and Best Practices

=================================================================================
*/

#include <iostream>
#include <memory> // For smart pointers
#include <string>
#include <vector>
#include <functional> // For std::function
#include <cassert>

using namespace std;

// =================================================================================
// 1. BASIC POINTER CONCEPTS
// =================================================================================

void basicPointerConcepts()
{
    cout << "\n=== BASIC POINTER CONCEPTS ===\n";

    // What is a pointer?
    // A pointer is a variable that stores the memory address of another variable

    int x = 42;    // Regular variable storing value 42
    int *ptr = &x; // Pointer variable storing address of x

    cout << "Value of x: " << x << endl;                 // Prints: 42
    cout << "Address of x: " << &x << endl;              // Address in memory
    cout << "Value stored in ptr: " << ptr << endl;      // Same address as &x
    cout << "Value pointed to by ptr: " << *ptr << endl; // Dereferencing: prints 42

    // Key Concepts:
    // & - Address-of operator (gets address of variable)
    // * - Dereference operator (gets value at address)
    // * in declaration - Declares pointer type

    // Modifying value through pointer
    *ptr = 100;                                    // Changes the value of x through pointer
    cout << "After *ptr = 100, x = " << x << endl; // x is now 100

    // Pointer size vs pointed data size
    cout << "Size of int: " << sizeof(int) << " bytes\n";
    cout << "Size of pointer: " << sizeof(ptr) << " bytes\n"; // Usually 8 bytes on 64-bit systems
}

// =================================================================================
// 2. POINTER DECLARATION AND INITIALIZATION
// =================================================================================

void pointerDeclarationAndInit()
{
    cout << "\n=== POINTER DECLARATION AND INITIALIZATION ===\n";

    // CRITICAL UNDERSTANDING: Three different uses of * with pointers
    cout << "\n--- Three Uses of * with Pointers ---\n";

    int value = 42;

    // 1. * in DECLARATION - declares variable as pointer type
    int *ptr1;          // * declares ptr1 as "pointer to int"
    int *ptr2 = &value; // * declares ptr2 as "pointer to int" AND initializes it

    // 2. * in ASSIGNMENT to pointed value (DEREFERENCE)
    *ptr2 = 100;                                            // * dereferences ptr2, assigns 100 to the value it points to
    cout << "After *ptr2 = 100, value = " << value << endl; // value is now 100

    // 3. NO * when assigning ADDRESS to pointer
    ptr1 = ptr2;   // NO * - assigns address stored in ptr2 to ptr1
    ptr1 = &value; // NO * - assigns address of value to ptr1

    cout << "\nDemonstration:\n";
    cout << "value = " << value << endl;
    cout << "ptr1 points to: " << *ptr1 << endl; // Dereference to get value
    cout << "ptr2 points to: " << *ptr2 << endl; // Dereference to get value
    cout << "ptr1 and ptr2 point to same location: " << (ptr1 == ptr2 ? "Yes" : "No") << endl;

    // Different ways to declare pointers
    int *ptr3;        // Uninitialized pointer (dangerous!)
    int *ptr4;        // Same as above, different style
    int *ptr5, ptr6;  // ptr5 is pointer, ptr6 is int (not pointer!)
    int *ptr7, *ptr8; // Both are pointers

    // Proper initialization
    int another_value = 25;
    int *initialized_ptr = &another_value; // Initialize with address
    int *null_ptr = nullptr;               // C++11 way to initialize null pointer
    int *old_null = NULL;                  // Old C-style (avoid in modern C++)

    // Checking for null pointers (ALWAYS check before dereferencing!)
    if (initialized_ptr != nullptr)
    {
        cout << "Safe to dereference: " << *initialized_ptr << endl;
    }

    if (null_ptr == nullptr)
    {
        cout << "null_ptr is null, cannot dereference\n";
    }

    // Common mistake: Using uninitialized pointers
    // int* bad_ptr;         // Don't do this!
    // *bad_ptr = 10;        // CRASH! Undefined behavior
}

// =================================================================================
// 3. POINTER ARITHMETIC
// =================================================================================

void pointerArithmetic()
{
    cout << "\n=== POINTER ARITHMETIC ===\n";

    // IMPORTANT: Understanding * in declaration vs assignment
    // int *ptr = arr;  <-- * is part of TYPE DECLARATION (declares ptr as pointer to int)
    // ptr = arr;       <-- NO * because we're assigning ADDRESS to existing pointer
    // *ptr = value;    <-- * is DEREFERENCE operator (assigns value to what ptr points to)

    // Pointer arithmetic is based on the size of the data type
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // DECLARATION: * declares ptr as pointer, = assigns address of arr[0]

    cout << "Array elements using pointer arithmetic:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "*(ptr + " << i << ") = " << *(ptr + i) << endl;
        // ptr + i moves pointer by i * sizeof(int) bytes
    }

    // Pre and post increment/decrement
    ptr = arr; // ASSIGNMENT: NO * because we're changing WHERE ptr points (assigning new address)
    cout << "\nPointer increment operations:\n";
    cout << "Current value: " << *ptr << endl;   // DEREFERENCE: * gets VALUE at address
    cout << "After ++ptr: " << *(++ptr) << endl; // 20 (pre-increment)
    cout << "After ptr++: " << *(ptr++) << endl; // 20, then moves to 30
    cout << "Current value: " << *ptr << endl;   // 30

    // Pointer subtraction
    int *start = arr;
    int *end = arr + 4;               // Points to last element
    ptrdiff_t distance = end - start; // Number of elements between pointers
    cout << "Distance between pointers: " << distance << " elements\n";

    // Comparison of pointers
    if (start < end)
    {
        cout << "start pointer comes before end pointer in memory\n";
    }
}

// =================================================================================
// 4. POINTERS AND ARRAYS - DEEP RELATIONSHIP
// =================================================================================

void pointersAndArrays()
{
    cout << "\n=== POINTERS AND ARRAYS ===\n";

    // Arrays and pointers are closely related
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr; // Array name is like a pointer to first element

    // These are equivalent ways to access array elements:
    cout << "Different ways to access array elements:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Index " << i << ": ";
        cout << "arr[" << i << "]=" << arr[i] << ", ";       // Array notation
        cout << "*(arr+" << i << ")=" << *(arr + i) << ", "; // Pointer arithmetic
        cout << "ptr[" << i << "]=" << ptr[i] << ", ";       // Pointer as array
        cout << "*(ptr+" << i << ")=" << *(ptr + i) << endl; // Pointer arithmetic
    }

    // Key difference: Array name is constant pointer
    // ptr++;        // This is allowed
    // arr++;        // This would be ERROR! Array name is not modifiable

    // Multi-dimensional arrays and pointers
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    // matrix[i][j] is equivalent to *(*(matrix + i) + j)
    cout << "\nAccessing 2D array element matrix[1][2]:\n";
    cout << "matrix[1][2] = " << matrix[1][2] << endl;
    cout << "*(*(matrix + 1) + 2) = " << *(*(matrix + 1) + 2) << endl;

    // Array of pointers vs Pointer to array
    int a = 10, b = 20, c = 30;
    int *arr_of_ptrs[3] = {&a, &b, &c}; // Array of 3 pointers
    int (*ptr_to_arr)[5] = &arr;        // Pointer to array of 5 integers

    cout << "\nArray of pointers:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "*arr_of_ptrs[" << i << "] = " << *arr_of_ptrs[i] << endl;
    }
}

// =================================================================================
// 5. POINTERS AND FUNCTIONS
// =================================================================================

// Pass by value - function gets copy of value
void passByValue(int x)
{
    x = 100; // This won't affect the original variable
    cout << "Inside passByValue: x = " << x << endl;
}

// Pass by pointer - function gets copy of address
void passByPointer(int *x)
{
    if (x != nullptr)
    {             // Always check for null!
        *x = 200; // This WILL affect the original variable
        cout << "Inside passByPointer: *x = " << *x << endl;
    }
}

// Pass by reference (C++ feature) - function gets alias to original
void passByReference(int &x)
{
    x = 300; // This WILL affect the original variable
    cout << "Inside passByReference: x = " << x << endl;
}

// Function returning pointer
int *createAndReturnPointer(int value)
{
    // DANGER: Don't return pointer to local variable!
    // int local = value;
    // return &local;  // BAD! local gets destroyed when function ends

    // Safe: Return pointer to dynamically allocated memory
    int *ptr = new int(value); // Allocate on heap
    return ptr;                // Caller must delete this!
}

// Function that modifies pointer itself
void modifyPointer(int **ptr)
{
    // Double pointer allows us to modify the pointer itself
    static int new_value = 999;
    *ptr = &new_value; // Changes where the original pointer points
}

void pointersAndFunctions()
{
    cout << "\n=== POINTERS AND FUNCTIONS ===\n";

    int original = 50;

    // Pass by value - original unchanged
    cout << "Before passByValue: original = " << original << endl;
    passByValue(original);
    cout << "After passByValue: original = " << original << endl; // Still 50

    // Pass by pointer - original changed
    cout << "\nBefore passByPointer: original = " << original << endl;
    passByPointer(&original);
    cout << "After passByPointer: original = " << original << endl; // Now 200

    // Pass by reference - original changed
    cout << "\nBefore passByReference: original = " << original << endl;
    passByReference(original);
    cout << "After passByReference: original = " << original << endl; // Now 300

    // Function returning pointer
    int *dynamic_ptr = createAndReturnPointer(777);
    cout << "\nValue from returned pointer: " << *dynamic_ptr << endl;
    delete dynamic_ptr;    // Don't forget to free memory!
    dynamic_ptr = nullptr; // Good practice to nullify after delete

    // Modifying pointer through double pointer
    int value = 123;
    int *ptr = &value;
    cout << "\nBefore modifyPointer: *ptr = " << *ptr << endl;
    modifyPointer(&ptr); // Pass address of pointer
    cout << "After modifyPointer: *ptr = " << *ptr << endl;
}

// =================================================================================
// 6. DYNAMIC MEMORY ALLOCATION
// =================================================================================

void dynamicMemoryAllocation()
{
    cout << "\n=== DYNAMIC MEMORY ALLOCATION ===\n";

    // Stack vs Heap memory
    // Stack: Automatic variables, limited size, automatically managed
    // Heap: Dynamic allocation, larger space, manually managed

    // Single variable allocation
    int *single_int = new int(42); // Allocate and initialize
    cout << "Dynamically allocated int: " << *single_int << endl;
    delete single_int;    // Free memory
    single_int = nullptr; // Prevent dangling pointer

    // Array allocation
    int size = 5;
    int *dynamic_array = new int[size]; // Allocate array

    // Initialize array
    for (int i = 0; i < size; i++)
    {
        dynamic_array[i] = i * i;
    }

    cout << "Dynamic array contents: ";
    for (int i = 0; i < size; i++)
    {
        cout << dynamic_array[i] << " ";
    }
    cout << endl;

    delete[] dynamic_array; // Note: delete[] for arrays!
    dynamic_array = nullptr;

    // 2D dynamic array allocation
    int rows = 3, cols = 4;
    int **matrix = new int *[rows]; // Array of pointers
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols]; // Each pointer points to an array
    }

    // Initialize 2D array
    int value = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = value++;
        }
    }

    cout << "\nDynamic 2D array:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Free 2D array (reverse order of allocation)
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i]; // Free each row
    }
    delete[] matrix; // Free array of pointers
    matrix = nullptr;

    // Memory allocation with error checking
    try
    {
        int *huge_array = new (std::nothrow) int[100000000]; // Might fail
        if (huge_array == nullptr)
        {
            cout << "Memory allocation failed!\n";
        }
        else
        {
            cout << "Large array allocated successfully\n";
            delete[] huge_array;
        }
    }
    catch (std::bad_alloc &e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }
}

// =================================================================================
// 7. POINTER TO POINTERS (DOUBLE POINTERS)
// =================================================================================

void pointerToPointers()
{
    cout << "\n=== POINTER TO POINTERS ===\n";

    // Single, double, and triple pointers
    int value = 100;
    int *ptr1 = &value;  // Pointer to int
    int **ptr2 = &ptr1;  // Pointer to pointer to int
    int ***ptr3 = &ptr2; // Pointer to pointer to pointer to int

    cout << "Original value: " << value << endl;
    cout << "Using single pointer: " << *ptr1 << endl;
    cout << "Using double pointer: " << **ptr2 << endl;
    cout << "Using triple pointer: " << ***ptr3 << endl;

    // Practical use: Dynamic 2D array with better memory layout
    int rows = 3, cols = 4;

    // Allocate as single block for better cache performance
    int *data = new int[rows * cols];
    int **matrix_ptrs = new int *[rows];

    // Set up row pointers
    for (int i = 0; i < rows; i++)
    {
        matrix_ptrs[i] = data + i * cols; // Point to start of each row
    }

    // Initialize
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix_ptrs[i][j] = i * cols + j;
        }
    }

    cout << "\nOptimized 2D array layout:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix_ptrs[i][j] << "\t";
        }
        cout << endl;
    }

    // Cleanup
    delete[] data;
    delete[] matrix_ptrs;

    // Use case: Modifying pointer in function
    int a = 10, b = 20;
    int *ptr = &a;
    cout << "\nBefore: ptr points to " << *ptr << endl;

    // Function to swap what pointer points to
    auto swapPointer = [&](int **p)
    {
        *p = &b; // Change where ptr points
    };

    swapPointer(&ptr);
    cout << "After: ptr points to " << *ptr << endl;
}

// =================================================================================
// 8. FUNCTION POINTERS
// =================================================================================

// Sample functions for function pointer examples
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }
void greet(const string &name) { cout << "Hello, " << name << "!" << endl; }

// Function that takes function pointer as parameter
int calculate(int a, int b, int (*operation)(int, int))
{
    return operation(a, b);
}

// Function returning function pointer
int (*getOperation(char op))(int, int)
{
    if (op == '+')
        return add;
    if (op == '*')
        return multiply;
    return nullptr;
}

void functionPointers()
{
    cout << "\n=== FUNCTION POINTERS ===\n";

    // Basic function pointer declaration and usage
    int (*func_ptr)(int, int) = add; // Point to add function

    cout << "Using function pointer: 5 + 3 = " << func_ptr(5, 3) << endl;

    // Change what function pointer points to
    func_ptr = multiply;
    cout << "After changing: 5 * 3 = " << func_ptr(5, 3) << endl;

    // Array of function pointers
    int (*operations[])(int, int) = {add, multiply};
    cout << "\nUsing array of function pointers:\n";
    cout << "Add: 4 + 6 = " << operations[0](4, 6) << endl;
    cout << "Multiply: 4 * 6 = " << operations[1](4, 6) << endl;

    // Function taking function pointer as parameter
    cout << "\nUsing function that takes function pointer:\n";
    cout << "Calculate with add: " << calculate(10, 5, add) << endl;
    cout << "Calculate with multiply: " << calculate(10, 5, multiply) << endl;

    // Function returning function pointer
    auto op = getOperation('+');
    if (op != nullptr)
    {
        cout << "Dynamic operation (+): 7 + 8 = " << op(7, 8) << endl;
    }

    // Void function pointer
    void (*greet_ptr)(const string &) = greet;
    greet_ptr("World");

    // Using typedef for cleaner syntax
    typedef int (*BinaryOp)(int, int);
    BinaryOp my_op = add;
    cout << "Using typedef: 15 + 25 = " << my_op(15, 25) << endl;

    // C++11 std::function (more flexible than function pointers)
    function<int(int, int)> modern_func = add;
    cout << "Using std::function: 20 + 30 = " << modern_func(20, 30) << endl;

    // Lambda with function pointer (C++11+)
    auto lambda = [](int a, int b) -> int
    { return a - b; };
    function<int(int, int)> lambda_func = lambda;
    cout << "Using lambda: 100 - 25 = " << lambda_func(100, 25) << endl;
}

// =================================================================================
// 9. SMART POINTERS (C++11 AND LATER)
// =================================================================================

class Resource
{
private:
    string name;

public:
    Resource(const string &n) : name(n)
    {
        cout << "Resource '" << name << "' created\n";
    }

    ~Resource()
    {
        cout << "Resource '" << name << "' destroyed\n";
    }

    void use() const
    {
        cout << "Using resource '" << name << "'\n";
    }

    const string &getName() const { return name; }
};

void smartPointers()
{
    cout << "\n=== SMART POINTERS (C++11+) ===\n";

    // 1. unique_ptr - Exclusive ownership, automatically deletes
    {
        cout << "\n--- unique_ptr Example ---\n";
        unique_ptr<Resource> ptr1 = make_unique<Resource>("Resource1");
        ptr1->use();

        // Transfer ownership
        unique_ptr<Resource> ptr2 = move(ptr1); // ptr1 is now null
        if (ptr1 == nullptr)
        {
            cout << "ptr1 is now null after move\n";
        }
        ptr2->use();

        // Custom deleter
        auto custom_deleter = [](Resource *r)
        {
            cout << "Custom deleter called for " << r->getName() << endl;
            delete r;
        };
        unique_ptr<Resource, decltype(custom_deleter)> ptr3(
            new Resource("Resource3"), custom_deleter);

    } // ptr2 and ptr3 automatically cleaned up here

    // 2. shared_ptr - Shared ownership, reference counting
    {
        cout << "\n--- shared_ptr Example ---\n";
        shared_ptr<Resource> ptr1 = make_shared<Resource>("SharedResource");
        cout << "Reference count: " << ptr1.use_count() << endl;

        {
            shared_ptr<Resource> ptr2 = ptr1; // Share ownership
            cout << "Reference count after sharing: " << ptr1.use_count() << endl;
            ptr2->use();
        } // ptr2 goes out of scope, but resource still alive

        cout << "Reference count after ptr2 destroyed: " << ptr1.use_count() << endl;
    } // ptr1 goes out of scope, resource finally destroyed

    // 3. weak_ptr - Non-owning observer, breaks circular references
    {
        cout << "\n--- weak_ptr Example ---\n";
        shared_ptr<Resource> shared = make_shared<Resource>("WeakResource");
        weak_ptr<Resource> weak = shared;

        cout << "Weak pointer expired? " << (weak.expired() ? "Yes" : "No") << endl;

        // Lock to get shared_ptr
        if (auto locked = weak.lock())
        {
            locked->use();
            cout << "Successfully accessed through weak_ptr\n";
        }

        shared.reset(); // Release shared ownership
        cout << "After reset, weak pointer expired? " << (weak.expired() ? "Yes" : "No") << endl;
    }

    // Comparing with raw pointers
    cout << "\n--- Smart Pointers vs Raw Pointers ---\n";

    // Raw pointer - manual management (error-prone)
    Resource *raw = new Resource("RawResource");
    raw->use();
    delete raw; // Must remember to delete!
    // raw = nullptr;  // Good practice but easy to forget

    // Smart pointer - automatic management (safe)
    auto smart = make_unique<Resource>("SmartResource");
    smart->use();
    // No need to call delete - automatic cleanup!
}

// =================================================================================
// 10. ADVANCED POINTER CONCEPTS
// =================================================================================

// Circular reference problem demonstration
class Parent;
class Child;

class Parent
{
public:
    shared_ptr<Child> child;
    string name;

    Parent(const string &n) : name(n)
    {
        cout << "Parent " << name << " created\n";
    }

    ~Parent()
    {
        cout << "Parent " << name << " destroyed\n";
    }
};

class Child
{
public:
    weak_ptr<Parent> parent; // Use weak_ptr to break cycle!
    string name;

    Child(const string &n) : name(n)
    {
        cout << "Child " << name << " created\n";
    }

    ~Child()
    {
        cout << "Child " << name << " destroyed\n";
    }
};

void advancedPointerConcepts()
{
    cout << "\n=== ADVANCED POINTER CONCEPTS ===\n";

    // 1. Circular Reference Problem and Solution
    cout << "\n--- Circular References ---\n";
    {
        auto parent = make_shared<Parent>("Dad");
        auto child = make_shared<Child>("Son");

        parent->child = child;
        child->parent = parent; // weak_ptr prevents cycle

        cout << "Parent reference count: " << parent.use_count() << endl;
        cout << "Child reference count: " << child.use_count() << endl;
    } // Both objects properly destroyed due to weak_ptr

    // 2. Pointer Alignment and Padding
    cout << "\n--- Pointer Alignment ---\n";
    struct AlignmentExample
    {
        char c;   // 1 byte
        int *ptr; // 8 bytes (on 64-bit)
        char c2;  // 1 byte
    }; // Total size might be more due to padding

    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of int*: " << sizeof(int *) << endl;
    cout << "Size of AlignmentExample: " << sizeof(AlignmentExample) << endl;

    // 3. Const Pointers and Pointer to Const
    cout << "\n--- Const with Pointers ---\n";
    int value1 = 10, value2 = 20;

    const int *ptr_to_const = &value1; // Pointer to const int
    // *ptr_to_const = 30;                  // ERROR: Cannot modify value
    ptr_to_const = &value2; // OK: Can change pointer

    int *const const_ptr = &value1; // Const pointer to int
    *const_ptr = 30;                // OK: Can modify value
    // const_ptr = &value2;                 // ERROR: Cannot change pointer

    const int *const const_ptr_to_const = &value1; // Const pointer to const int
    // *const_ptr_to_const = 40;           // ERROR: Cannot modify value
    // const_ptr_to_const = &value2;       // ERROR: Cannot change pointer

    cout << "Const pointer examples work as expected\n";

    // 4. Pointer Casting
    cout << "\n--- Pointer Casting ---\n";
    int int_val = 65;
    char *char_ptr = reinterpret_cast<char *>(&int_val);
    cout << "Int value: " << int_val << ", as char: " << *char_ptr << endl;

    // Safe casting with inheritance
    class Base
    {
    public:
        virtual ~Base() = default;
    };
    class Derived : public Base
    {
    public:
        Derived() = default; // Explicit default constructor
        void derivedMethod() { cout << "Derived method called\n"; }
    };

    Base *base_ptr = new Derived();
    Derived *derived_ptr = dynamic_cast<Derived *>(base_ptr);
    if (derived_ptr)
    {
        derived_ptr->derivedMethod();
    }
    delete base_ptr;

    // 5. Memory Pool and Custom Allocators (Advanced)
    cout << "\n--- Custom Memory Management ---\n";

    // Simple memory pool concept
    class SimplePool
    {
    private:
        char *pool;
        size_t size;
        size_t offset;

    public:
        SimplePool(size_t pool_size) : size(pool_size), offset(0)
        {
            pool = new char[size];
        }

        ~SimplePool()
        {
            delete[] pool;
        }

        void *allocate(size_t bytes)
        {
            if (offset + bytes > size)
                return nullptr;
            void *ptr = pool + offset;
            offset += bytes;
            return ptr;
        }

        void reset() { offset = 0; } // Simple reset (no individual free)
    };

    SimplePool pool(1024);
    int *pooled_int = static_cast<int *>(pool.allocate(sizeof(int)));
    if (pooled_int)
    {
        *pooled_int = 999;
        cout << "Pooled allocation: " << *pooled_int << endl;
    }
}

// =================================================================================
// 11. COMMON PITFALLS AND BEST PRACTICES
// =================================================================================

void commonPitfallsAndBestPractices()
{
    cout << "\n=== COMMON PITFALLS AND BEST PRACTICES ===\n";

    cout << "\n--- Common Pitfalls ---\n";

    // 1. Dangling Pointers
    cout << "1. Dangling Pointers:\n";
    int *dangling_ptr;
    {
        int local_var = 42;
        dangling_ptr = &local_var; // BAD: Points to local variable
    } // local_var destroyed here
    // cout << *dangling_ptr;  // UNDEFINED BEHAVIOR! Don't uncomment!
    cout << "   - Never return pointers to local variables\n";
    cout << "   - Set pointers to nullptr after delete\n";

    // 2. Memory Leaks
    cout << "\n2. Memory Leaks:\n";
    // int* leak = new int(100);  // BAD: Never deleted
    cout << "   - Always match new with delete, new[] with delete[]\n";
    cout << "   - Use smart pointers to avoid manual memory management\n";

    // 3. Double Delete
    cout << "\n3. Double Delete:\n";
    int *ptr = new int(50);
    delete ptr;
    ptr = nullptr; // GOOD: Prevents double delete
    // delete ptr;  // Would be safe now (deleting nullptr is safe)
    cout << "   - Set pointers to nullptr after delete\n";

    // 4. Buffer Overflows
    cout << "\n4. Buffer Overflows:\n";
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr_arr = arr;
    // ptr_arr[10] = 999;  // BAD: Writing beyond array bounds
    cout << "   - Always check array bounds\n";
    cout << "   - Use std::vector or std::array for safer alternatives\n";

    // 5. Incorrect Pointer Arithmetic
    cout << "\n5. Incorrect Pointer Arithmetic:\n";
    int *int_ptr = new int(100);
    // char* char_ptr = (char*)int_ptr;
    // char_ptr++;  // Moves by 1 byte, not sizeof(int)
    delete int_ptr;
    cout << "   - Be careful with pointer arithmetic on different types\n";

    cout << "\n--- Best Practices ---\n";

    // 1. Initialize pointers
    cout << "1. Always initialize pointers:\n";
    int *good_ptr = nullptr; // GOOD
    cout << "   int* ptr = nullptr;\n";

    // 2. Check for nullptr
    cout << "\n2. Always check for nullptr before dereferencing:\n";
    if (good_ptr != nullptr)
    {
        // Safe to use *good_ptr
    }
    cout << "   if (ptr != nullptr) { *ptr = value; }\n";

    // 3. Use smart pointers
    cout << "\n3. Prefer smart pointers over raw pointers:\n";
    auto smart = make_unique<int>(42);
    cout << "   auto ptr = make_unique<int>(42);\n";

    // 4. RAII (Resource Acquisition Is Initialization)
    cout << "\n4. Follow RAII principle:\n";
    cout << "   - Acquire resources in constructor\n";
    cout << "   - Release resources in destructor\n";
    cout << "   - Smart pointers follow RAII automatically\n";

    // 5. Const correctness
    cout << "\n5. Use const correctness:\n";
    const int *const_correct = &arr[0];
    cout << "   const int* ptr; // Pointer to const data\n";
    cout << "   int* const ptr; // Const pointer\n";

    // 6. Use modern C++ features
    cout << "\n6. Use modern C++ features:\n";
    cout << "   - prefer nullptr over NULL\n";
    cout << "   - Use auto for type deduction\n";
    cout << "   - Use range-based for loops\n";
    cout << "   - Use std::array or std::vector instead of C arrays\n";

    // 7. Memory debugging tools
    cout << "\n7. Use memory debugging tools:\n";
    cout << "   - Valgrind (Linux/Mac)\n";
    cout << "   - AddressSanitizer (GCC/Clang)\n";
    cout << "   - Visual Studio Diagnostics (Windows)\n";
    cout << "   - Static analysis tools\n";
}

// =================================================================================
// 12. PRACTICAL EXAMPLES AND EXERCISES
// =================================================================================

// Example 1: Simple Linked List implementation
struct ListNode
{
    int data;
    ListNode *next;

    ListNode(int val) : data(val), next(nullptr) {}
};

class SimpleLinkedList
{
private:
    ListNode *head;

public:
    SimpleLinkedList() : head(nullptr) {}

    ~SimpleLinkedList()
    {
        while (head)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_front(int value)
    {
        ListNode *new_node = new ListNode(value);
        new_node->next = head;
        head = new_node;
    }

    void print() const
    {
        ListNode *current = head;
        cout << "List: ";
        while (current)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr\n";
    }

    bool find(int value) const
    {
        ListNode *current = head;
        while (current)
        {
            if (current->data == value)
                return true;
            current = current->next;
        }
        return false;
    }
};

// Example 2: Generic swap function using pointers
template <typename T>
void generic_swap(T *a, T *b)
{
    if (a && b)
    { // Check for null pointers
        T temp = *a;
        *a = *b;
        *b = temp;
    }
}

// Example 3: Function that reverses array using pointers
void reverseArray(int *arr, int size)
{
    if (!arr || size <= 1)
        return;

    int *start = arr;
    int *end = arr + size - 1;

    while (start < end)
    {
        // Swap elements
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

void practicalExamples()
{
    cout << "\n=== PRACTICAL EXAMPLES ===\n";

    // Example 1: Linked List
    cout << "\n--- Linked List Example ---\n";
    SimpleLinkedList list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    list.print();

    cout << "Finding 2: " << (list.find(2) ? "Found" : "Not found") << endl;
    cout << "Finding 5: " << (list.find(5) ? "Found" : "Not found") << endl;

    // Example 2: Generic swap
    cout << "\n--- Generic Swap Example ---\n";
    int a = 10, b = 20;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    generic_swap(&a, &b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    string str1 = "Hello", str2 = "World";
    cout << "Before swap: str1 = " << str1 << ", str2 = " << str2 << endl;
    generic_swap(&str1, &str2);
    cout << "After swap: str1 = " << str1 << ", str2 = " << str2 << endl;

    // Example 3: Array reversal
    cout << "\n--- Array Reversal Example ---\n";
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    reverseArray(arr, size);

    cout << "Reversed array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// =================================================================================
// 13. PERFORMANCE CONSIDERATIONS
// =================================================================================

void performanceConsiderations()
{
    cout << "\n=== PERFORMANCE CONSIDERATIONS ===\n";

    cout << "1. Cache Locality:\n";
    cout << "   - Sequential memory access is faster than random access\n";
    cout << "   - Arrays provide better cache locality than linked lists\n";
    cout << "   - Consider data structure layout for performance\n";

    cout << "\n2. Pointer Indirection:\n";
    cout << "   - Each pointer dereference adds overhead\n";
    cout << "   - Multiple indirections (ptr->ptr->data) are expensive\n";
    cout << "   - Consider flattening data structures when possible\n";

    cout << "\n3. Memory Allocation:\n";
    cout << "   - Frequent new/delete calls are expensive\n";
    cout << "   - Consider memory pools for frequent allocations\n";
    cout << "   - Stack allocation is generally faster than heap\n";

    cout << "\n4. Smart Pointer Overhead:\n";
    cout << "   - shared_ptr has reference counting overhead\n";
    cout << "   - unique_ptr has minimal overhead\n";
    cout << "   - Consider the trade-off between safety and performance\n";

    // Demonstrate cache-friendly vs cache-unfriendly access
    const int SIZE = 1000000;
    vector<int> vec(SIZE);

    // Initialize
    for (int i = 0; i < SIZE; i++)
    {
        vec[i] = i;
    }

    cout << "\n5. Memory Access Patterns:\n";
    cout << "   - Sequential access is cache-friendly\n";
    cout << "   - Random access patterns can cause cache misses\n";
    cout << "   - Structure of Arrays (SoA) vs Array of Structures (AoS)\n";
}

// =================================================================================
// MAIN FUNCTION - DEMONSTRATES ALL CONCEPTS
// =================================================================================

int main()
{
    cout << "=================================================================\n";
    cout << "           COMPREHENSIVE C++ POINTERS TUTORIAL\n";
    cout << "=================================================================\n";

    try
    {
        // Execute all sections
        basicPointerConcepts();
        pointerDeclarationAndInit();
        pointerArithmetic();
        pointersAndArrays();
        pointersAndFunctions();
        dynamicMemoryAllocation();
        pointerToPointers();
        functionPointers();
        smartPointers();
        advancedPointerConcepts();
        commonPitfallsAndBestPractices();
        practicalExamples();
        performanceConsiderations();

        cout << "\n=================================================================\n";
        cout << "                     TUTORIAL COMPLETED!\n";
        cout << "=================================================================\n";
        cout << "\nKey Takeaways:\n";
        cout << "1. Always initialize pointers\n";
        cout << "2. Check for nullptr before dereferencing\n";
        cout << "3. Match every new with delete, new[] with delete[]\n";
        cout << "4. Prefer smart pointers over raw pointers\n";
        cout << "5. Understand the difference between pointer types\n";
        cout << "6. Be careful with pointer arithmetic\n";
        cout << "7. Use const correctness\n";
        cout << "8. Follow RAII principle\n";
        cout << "9. Consider performance implications\n";
        cout << "10. Use memory debugging tools\n";
    }
    catch (const exception &e)
    {
        cout << "Exception caught: " << e.what() << endl;
        return 1;
    }

    return 0;
}

/*
=================================================================================
                               SUMMARY OF CONCEPTS
=================================================================================

1. BASIC CONCEPTS:
   - Pointers store memory addresses
   - & operator gets address, * operator dereferences
   - Always initialize pointers

2. POINTER ARITHMETIC:
   - Arithmetic is based on pointed type size
   - ptr + 1 moves by sizeof(type) bytes
   - Useful for array traversal

3. POINTERS AND ARRAYS:
   - Array name is like pointer to first element
   - Multiple ways to access array elements
   - 2D arrays and pointer relationships

4. POINTERS AND FUNCTIONS:
   - Pass by value vs pass by pointer vs pass by reference
   - Functions can return pointers
   - Double pointers to modify pointer itself

5. DYNAMIC MEMORY:
   - new/delete for single objects
   - new[]/delete[] for arrays
   - Always free dynamically allocated memory

6. DOUBLE POINTERS:
   - Pointer to pointer
   - Useful for modifying pointer values
   - Efficient 2D array implementation

7. FUNCTION POINTERS:
   - Pointers to functions
   - Enable runtime function selection
   - Useful for callbacks and strategy pattern

8. SMART POINTERS (C++11+):
   - unique_ptr: Exclusive ownership
   - shared_ptr: Shared ownership with reference counting
   - weak_ptr: Non-owning observer, breaks cycles

9. ADVANCED CONCEPTS:
   - Circular references and solutions
   - Const correctness with pointers
   - Memory alignment and padding
   - Custom allocators and memory pools

10. BEST PRACTICES:
    - Initialize all pointers
    - Check for nullptr
    - Use smart pointers
    - Follow RAII principle
    - Consider performance implications

=================================================================================
Remember: With great power comes great responsibility!
Pointers are powerful but require careful handling.
=================================================================================
*/
