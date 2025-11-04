# Complete C++ and Object-Oriented Programming Tutorial

Welcome to the comprehensive C++ and OOP tutorial! This guide will take you from absolute fundamentals to advanced mastery with detailed explanations, concepts, and practical code examples.

## Prerequisites

- Phase 0.1 (Setup & Environment) - Already completed ✅
- Basic understanding of programming concepts
- C++ compiler installed (GCC/Clang/MSVC)
- Code editor or IDE set up

---

# 🚀 Phase 0: Core C++ Foundations

## Phase 0.2: C++ Basics

### 0.2.1 Structure of a C++ Program

Every C++ program follows a specific structure. Let's understand each component:

```cpp
#include <iostream>  // Preprocessor directive
#include <string>

using namespace std; // Namespace declaration

// Global variable (avoid in practice)
int globalVar = 100;

int main() {         // Entry point of program
    cout << "Hello, World!" << endl;
    return 0;        // Return status to OS
}
```

**Key Components Explained:**

- **Preprocessor Directives** (`#include`):
  - Processed before compilation begins
  - `#include <iostream>` brings in input/output stream functionality
  - Angle brackets `< >` are for standard library headers
  - Quotes `" "` are for user-defined headers
- **Namespaces**:
  - Organize code and prevent naming conflicts
  - `std` is the standard namespace containing standard library
  - `using namespace std;` allows using `cout` instead of `std::cout`
  - Best practice: Avoid `using namespace std;` in header files
- **main() function**:
  - Special function - entry point where program execution begins
  - Must return an integer value
  - OS receives this return value to determine program success
- **Return statement**:
  - `return 0;` indicates successful program completion
  - Non-zero values indicate errors (1, -1, etc.)
  - Return value can be checked by OS or calling program

**Example with detailed structure:**

```cpp
#include <iostream>
#include <iomanip>

// Custom namespace
namespace MyProject {
    void greetUser() {
        std::cout << "Welcome to C++ Tutorial!" << std::endl;
    }
}

int main() {
    MyProject::greetUser();
    std::cout << "Program executed successfully" << std::endl;
    return 0;
}
```

**Output:**

```
Welcome to C++ Tutorial!
Program executed successfully
```

### 0.2.2 Input/Output Operations

C++ provides multiple ways to handle I/O:

**Using iostream (Recommended):**

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Output using cout
    cout << "Enter your name: ";

    // Input using cin
    string name;
    cin >> name;  // Reads until whitespace

    cout << "Hello, " << name << "!" << endl;

    // Reading full line with spaces
    cin.ignore(); // Clear input buffer
    cout << "Enter your full address: ";
    string address;
    getline(cin, address);

    cout << "Address: " << address << endl;
    return 0;
}
```

**Sample Output:**

```
Enter your name: John
Hello, John!
Enter your full address: 123 Main Street, New York
Address: 123 Main Street, New York
```

**Key Concepts:**

- `cin >>` stops reading at whitespace (space, tab, newline)
- `getline()` reads entire line including spaces
- `cin.ignore()` clears the input buffer to prevent skipping getline
- Buffer issues occur when mixing `cin >>` and `getline()`

**Using printf/scanf (C-style):**

```cpp
#include <cstdio>

int main() {
    char name[50];
    int age;

    printf("Enter name and age: ");
    scanf("%s %d", name, &age);

    printf("Name: %s, Age: %d\n", name, age);
    return 0;
}
```

**Sample Output:**

```
Enter name and age: Alice 25
Name: Alice, Age: 25
```

**Important Notes:**

- **C-style I/O is legacy** - prefer C++ iostream for new code
- `scanf()` requires `&` (address-of) operator for variables
- Character arrays don't need `&` because array name is already an address
- Format specifiers: `%d` (int), `%f` (float), `%s` (string), `%c` (char)
- **Security risk**: `scanf("%s", name)` can cause buffer overflow
- No type safety compared to C++ streams

**Formatted Output Example:**

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double price = 29.99;
    int quantity = 5;

    cout << fixed << setprecision(2);
    cout << "Price: $" << price << endl;
    cout << "Quantity: " << setw(5) << quantity << endl;
    cout << "Total: $" << price * quantity << endl;

    return 0;
}
```

**Output:**

```
Price: $29.99
Quantity:     5
Total: $149.95
```

### 0.2.3 Variables & Constants

**Variable Declaration and Initialization:**

```cpp
#include <iostream>
using namespace std;

int main() {
    // Declaration and initialization
    int age = 25;
    double salary = 50000.50;
    char grade = 'A';
    bool isEmployed = true;
    string name = "John Doe";

    // Multiple declarations
    int x, y, z;
    int a = 1, b = 2, c = 3;

    // Auto keyword (C++11)
    auto autoInt = 42;        // Deduced as int
    auto autoDouble = 3.14;   // Deduced as double
    auto autoString = "Hello"; // Deduced as const char*

    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Salary: $" << salary << endl;
    cout << "Grade: " << grade << endl;
    cout << "Employed: " << (isEmployed ? "Yes" : "No") << endl;

    return 0;
}
```

**Output:**

```
Name: John Doe
Age: 25
Salary: $50000.5
Grade: A
Employed: Yes
```

**Important Concepts:**

**Variable Declaration Syntax:**

- `type variableName;` - Declaration without initialization (garbage value)
- `type variableName = value;` - Declaration with initialization
- Multiple variables: `int a, b, c;` or `int a = 1, b = 2, c = 3;`

**Auto Keyword (C++11 and later):**

- Compiler automatically deduces the type from initializer
- **Must be initialized** at declaration
- Makes code more concise with complex types (e.g., iterators)
- Example: `auto ptr = new int(10);` instead of `int* ptr = new int(10);`
- Be careful: `auto x = "Hello";` is `const char*`, not `string`

**Naming Conventions:**

- Variables must start with letter or underscore
- Cannot use keywords (int, class, return, etc.)
- Case-sensitive: `age` and `Age` are different
- Common styles: camelCase, snake_case, PascalCase

````

**Constants:**

```cpp
#include <iostream>
using namespace std;

int main() {
    // const keyword
    const int MAX_SIZE = 100;
    const double PI = 3.14159;

    // constexpr (compile-time constants)
    constexpr int BUFFER_SIZE = 256;
    constexpr double GRAVITY = 9.81;

    // const vs constexpr
    const int runtime_const = rand(); // OK - runtime initialization
    // constexpr int compile_const = rand(); // ERROR - must be compile-time

    cout << "Max size: " << MAX_SIZE << endl;
    cout << "PI value: " << PI << endl;
    cout << "Buffer size: " << BUFFER_SIZE << endl;

    return 0;
}
````

**Output:**

```
Max size: 100
PI value: 3.14159
Buffer size: 256
```

**Understanding const vs constexpr:**

**const:**

- Value cannot be modified after initialization
- Can be initialized at runtime
- Memory allocated at runtime
- Example: `const int x = getUserInput();` ✅ Valid

**constexpr (C++11):**

- Must be evaluated at compile-time
- More optimized - compiler can use value directly
- Cannot be initialized with runtime values
- Example: `constexpr int SIZE = 10 * 20;` ✅ Valid
- Example: `constexpr int x = rand();` ❌ Error - rand() is runtime

**When to use which:**

- Use `constexpr` for mathematical constants, array sizes, template arguments
- Use `const` when value is known only at runtime
- Use `constexpr` for performance-critical constant expressions

**Naming Convention:**

- Constants typically use UPPER_CASE with underscores
- Distinguishes them from variables at a glance

### 0.2.4 Data Types

C++ provides rich data type system:

```cpp
#include <iostream>
#include <climits>
using namespace std;

int main() {
    // Integer types
    short shortInt = 32767;
    int regularInt = 2147483647;
    long longInt = 2147483647L;
    long long longLongInt = 9223372036854775807LL;

    // Unsigned variants
    unsigned int unsignedInt = 4294967295U;

    // Floating point types
    float singlePrecision = 3.14159f;
    double doublePrecision = 3.141592653589793;
    long double extendedPrecision = 3.141592653589793238L;

    // Character types
    char character = 'A';
    wchar_t wideChar = L'A';

    // Boolean type
    bool flag = true;

    // Display sizes
    cout << "Size of different data types:" << endl;
    cout << "short: " << sizeof(short) << " bytes" << endl;
    cout << "int: " << sizeof(int) << " bytes" << endl;
    cout << "long: " << sizeof(long) << " bytes" << endl;
    cout << "long long: " << sizeof(long long) << " bytes" << endl;
    cout << "float: " << sizeof(float) << " bytes" << endl;
    cout << "double: " << sizeof(double) << " bytes" << endl;
    cout << "long double: " << sizeof(long double) << " bytes" << endl;
    cout << "char: " << sizeof(char) << " bytes" << endl;
    cout << "bool: " << sizeof(bool) << " bytes" << endl;

    // Display ranges
    cout << "\nInteger ranges:" << endl;
    cout << "int min: " << INT_MIN << endl;
    cout << "int max: " << INT_MAX << endl;

    return 0;
}
```

**Typical Output:**

```
Size of different data types:
short: 2 bytes
int: 4 bytes
long: 4 bytes
long long: 8 bytes
float: 4 bytes
double: 8 bytes
long double: 8 bytes
char: 1 bytes
bool: 1 bytes

Integer ranges:
int min: -2147483648
int max: 2147483647
```

### 0.2.5 Operators

**Arithmetic Operators:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 3;

    cout << "Arithmetic Operations:" << endl;
    cout << "a + b = " << (a + b) << endl;  // Addition
    cout << "a - b = " << (a - b) << endl;  // Subtraction
    cout << "a * b = " << (a * b) << endl;  // Multiplication
    cout << "a / b = " << (a / b) << endl;  // Division (integer)
    cout << "a % b = " << (a % b) << endl;  // Modulus

    double x = 10.0, y = 3.0;
    cout << "x / y = " << (x / y) << endl;  // Floating point division

    return 0;
}
```

**Output:**

```
Arithmetic Operations:
a + b = 13
a - b = 7
a * b = 30
a / b = 3
a % b = 1
x / y = 3.33333
```

**Relational and Logical Operators:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 10, c = 5;

    cout << "Relational Operations:" << endl;
    cout << "a == c: " << (a == c) << endl;  // Equal to
    cout << "a != b: " << (a != b) << endl;  // Not equal
    cout << "a < b: " << (a < b) << endl;    // Less than
    cout << "a > b: " << (a > b) << endl;    // Greater than
    cout << "a <= c: " << (a <= c) << endl;  // Less than or equal
    cout << "b >= a: " << (b >= a) << endl;  // Greater than or equal

    bool p = true, q = false;
    cout << "\nLogical Operations:" << endl;
    cout << "p && q: " << (p && q) << endl;  // Logical AND
    cout << "p || q: " << (p || q) << endl;  // Logical OR
    cout << "!p: " << (!p) << endl;          // Logical NOT

    return 0;
}
```

**Output:**

```
Relational Operations:
a == c: 1
a != b: 1
a < b: 1
a > b: 0
a <= c: 1
b >= a: 1

Logical Operations:
p && q: 0
p || q: 1
!p: 0
```

**Bitwise Operators:**

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int a = 12;  // Binary: 1100
    int b = 10;  // Binary: 1010

    cout << "Bitwise Operations:" << endl;
    cout << "a = " << bitset<8>(a) << " (" << a << ")" << endl;
    cout << "b = " << bitset<8>(b) << " (" << b << ")" << endl;

    cout << "a & b = " << bitset<8>(a & b) << " (" << (a & b) << ")" << endl;  // AND
    cout << "a | b = " << bitset<8>(a | b) << " (" << (a | b) << ")" << endl;  // OR
    cout << "a ^ b = " << bitset<8>(a ^ b) << " (" << (a ^ b) << ")" << endl;  // XOR
    cout << "~a = " << bitset<8>(~a) << " (" << (~a) << ")" << endl;           // NOT
    cout << "a << 1 = " << bitset<8>(a << 1) << " (" << (a << 1) << ")" << endl; // Left shift
    cout << "a >> 1 = " << bitset<8>(a >> 1) << " (" << (a >> 1) << ")" << endl; // Right shift

    return 0;
}
```

**Output:**

```
Bitwise Operations:
a = 00001100 (12)
b = 00001010 (10)
a & b = 00001000 (8)
a | b = 00001110 (14)
a ^ b = 00000110 (6)
~a = 11110011 (-13)
a << 1 = 00011000 (24)
a >> 1 = 00000110 (6)
```

**Bitwise Operators Explained:**

**Bitwise AND (&):**

- Compares each bit, result is 1 only if both bits are 1
- Use case: Masking bits, checking flags
- Example: `1100 & 1010 = 1000`

**Bitwise OR (|):**

- Result is 1 if at least one bit is 1
- Use case: Setting flags, combining bitmasks
- Example: `1100 | 1010 = 1110`

**Bitwise XOR (^):**

- Result is 1 if bits are different
- Use case: Toggling bits, simple encryption, swapping without temp variable
- Example: `1100 ^ 1010 = 0110`

**Bitwise NOT (~):**

- Flips all bits (1→0, 0→1)
- Result is two's complement (negative number)
- Example: `~00001100 = 11110011` (-13 in two's complement)

**Left Shift (<<):**

- Shifts bits left, fills right with zeros
- Equivalent to multiplying by 2^n
- Example: `12 << 1 = 24` (12 \* 2)

**Right Shift (>>):**

- Shifts bits right, discards rightmost bits
- Equivalent to dividing by 2^n (integer division)
- Example: `12 >> 1 = 6` (12 / 2)

**Practical Applications:**

- **Flag management**: Store multiple boolean values in one integer
- **Optimization**: Multiply/divide by powers of 2 using shifts
- **Bit manipulation**: Set, clear, toggle specific bits
- **Hashing**: Combine hash values
- **Graphics**: Color manipulation (RGB values)

**Increment/Decrement and Assignment Operators:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5;

    cout << "Pre/Post Increment/Decrement:" << endl;
    cout << "Original a = " << a << endl;

    cout << "++a = " << (++a) << endl;      // Pre-increment
    cout << "a after ++a = " << a << endl;

    cout << "a++ = " << (a++) << endl;      // Post-increment
    cout << "a after a++ = " << a << endl;

    cout << "--a = " << (--a) << endl;      // Pre-decrement
    cout << "a-- = " << (a--) << endl;      // Post-decrement
    cout << "Final a = " << a << endl;

    // Assignment operators
    a = 10;
    cout << "\nAssignment Operations:" << endl;
    cout << "a += 5: " << (a += 5) << endl;
    cout << "a -= 3: " << (a -= 3) << endl;
    cout << "a *= 2: " << (a *= 2) << endl;
    cout << "a /= 4: " << (a /= 4) << endl;
    cout << "a %= 3: " << (a %= 3) << endl;

    return 0;
}
```

**Output:**

```
Pre/Post Increment/Decrement:
Original a = 5
++a = 6
a after ++a = 6
a++ = 6
a after a++ = 7
--a = 6
a-- = 6
Final a = 5

Assignment Operations:
a += 5: 15
a -= 3: 12
a *= 2: 24
a /= 4: 6
a %= 3: 0
```

**Type Casting:**

```cpp
#include <iostream>
using namespace std;

int main() {
    // C-style casting (not recommended)
    double d = 3.14159;
    int i = (int)d;
    cout << "C-style cast: " << i << endl;

    // C++ style casting (recommended)
    // static_cast - for safe conversions
    double price = 29.99;
    int wholePart = static_cast<int>(price);
    cout << "static_cast: " << wholePart << endl;

    // const_cast - to remove const qualifier
    const int constValue = 100;
    int* ptr = const_cast<int*>(&constValue);
    cout << "const_cast value: " << *ptr << endl;

    // reinterpret_cast - for low-level casting
    int value = 65;
    char* charPtr = reinterpret_cast<char*>(&value);
    cout << "reinterpret_cast: " << *charPtr << endl;

    // Implicit conversion
    int intVal = 10;
    double doubleVal = intVal;  // Automatic conversion
    cout << "Implicit conversion: " << doubleVal << endl;

    return 0;
}
```

**Output:**

```
C-style cast: 3
static_cast: 29
const_cast value: 100
reinterpret_cast: A
Implicit conversion: 10
```

**Type Casting Explained:**

**1. C-Style Cast (Old Way - Avoid):**

```cpp
int x = (int)3.14;  // Dangerous, no compile-time checking
```

- Can perform any conversion (even unsafe ones)
- No compiler error checking
- Hard to search in code
- **Don't use in modern C++**

**2. static_cast (Most Common):**

```cpp
int x = static_cast<int>(3.14);  // Safe, compile-time checked
```

- For standard conversions (numeric types, related pointers)
- Compile-time type checking
- **Use this for most type conversions**
- Examples: int↔double, base→derived pointer

**3. const_cast (Remove const):**

```cpp
const int* cp = &value;
int* p = const_cast<int*>(cp);  // Removes const
```

- **Only** for adding/removing const or volatile
- Dangerous - modifying const data is undefined behavior
- Rarely needed in well-designed code
- Use case: Legacy APIs requiring non-const parameters

**4. reinterpret_cast (Low-Level):**

```cpp
int* ip = reinterpret_cast<int*>(rawMemory);
```

- Reinterprets bit pattern as different type
- Very dangerous, platform-dependent
- Use for: pointer↔integer, unrelated pointer types
- Common in systems programming, hardware access

**5. dynamic_cast (Runtime Polymorphism):**

```cpp
Derived* d = dynamic_cast<Derived*>(basePtr);  // Covered in OOP phase
```

- For safe downcasting in inheritance hierarchies
- Requires polymorphic types (virtual functions)
- Returns nullptr if cast fails
- Runtime overhead

**6. Implicit Conversion (Automatic):**

```cpp
int x = 10;
double y = x;  // Automatic widening conversion
```

- Compiler automatically converts compatible types
- **Widening** (int→double): Safe, no data loss
- **Narrowing** (double→int): Unsafe, truncates decimal part
- Can cause subtle bugs with mixed types

**Best Practices:**

- Prefer static_cast for explicit conversions
- Avoid C-style casts
- Use const_cast only when absolutely necessary
- Use reinterpret_cast only for low-level operations
- Let compiler do implicit conversions for simple widening
- Be explicit with narrowing conversions to show intent

---

## Phase 0.3: Control Flow

### 0.3.1 Conditional Statements (if/else)

**Basic if/else Structure:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int score;
    cout << "Enter your score (0-100): ";
    cin >> score;

    // Simple if-else
    if (score >= 90) {
        cout << "Grade: A" << endl;
    }
    else if (score >= 80) {
        cout << "Grade: B" << endl;
    }
    else if (score >= 70) {
        cout << "Grade: C" << endl;
    }
    else if (score >= 60) {
        cout << "Grade: D" << endl;
    }
    else {
        cout << "Grade: F" << endl;
    }

    // Nested if statements
    if (score >= 0 && score <= 100) {
        if (score >= 90) {
            cout << "Excellent performance!" << endl;
        }
        else if (score >= 70) {
            cout << "Good job!" << endl;
        }
        else {
            cout << "Need improvement." << endl;
        }
    }
    else {
        cout << "Invalid score entered!" << endl;
    }

    return 0;
}
```

**Sample Output:**

```
Enter your score (0-100): 85
Grade: B
Good job!
```

**Conditional Statement Concepts:**

**if Statement:**

- Executes block only if condition is true
- Condition must evaluate to boolean (true/false)
- Braces `{}` optional for single statement (but recommended)

**else if:**

- Checks additional conditions if previous conditions were false
- Evaluated in order from top to bottom
- Once a condition is true, remaining else-if blocks are skipped

**else:**

- Catches all cases where no condition was true
- Always comes last
- Optional - not every if needs an else

**Condition Evaluation:**

- Numeric values: 0 is false, non-zero is true
- Relational operators: `<, >, <=, >=, ==, !=`
- Logical operators: `&&` (AND), `||` (OR), `!` (NOT)
- Short-circuit evaluation: `&&` stops if first is false, `||` stops if first is true

````

**Ternary Operator:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;

    // Ternary operator: condition ? value_if_true : value_if_false
    int max = (a > b) ? a : b;
    cout << "Maximum of " << a << " and " << b << " is: " << max << endl;

    // Nested ternary (use with caution)
    int x = 15;
    string category = (x > 20) ? "High" : (x > 10) ? "Medium" : "Low";
    cout << "Category: " << category << endl;

    // Complex condition
    int age = 25;
    bool hasLicense = true;
    string canDrive = (age >= 18 && hasLicense) ? "Can drive" : "Cannot drive";
    cout << canDrive << endl;

    return 0;
}
````

**Output:**

```
Maximum of 10 and 20 is: 20
Category: Medium
Can drive
```

### 0.3.2 Switch Statement

**Basic Switch Structure:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int choice;
    cout << "Calculator Menu:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    double num1, num2, result;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    switch (choice) {
        case 1:
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;

        case 2:
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;

        case 3:
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;

        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << result << endl;
            } else {
                cout << "Error: Division by zero!" << endl;
            }
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    return 0;
}
```

**Sample Output:**

```
Calculator Menu:
1. Addition
2. Subtraction
3. Multiplication
4. Division
Enter your choice (1-4): 1
Enter two numbers: 15 7
Result: 22
```

**Switch Statement Explained:**

**How switch works:**

1. Evaluates the expression once
2. Compares result with each case constant
3. Executes matching case block
4. Continues until break or end of switch

**Key Points:**

- **Expression must be integral type**: int, char, enum (not float or string in C++)
- **Case labels must be constants**: Cannot use variables `case x:` ❌
- **break statement**: Exits the switch; without it, execution "falls through" to next case
- **default case**: Optional catch-all for unmatched values
- **Multiple statements**: No braces needed after case label

**Fall-through behavior:**

```cpp
case 1:
case 2:
case 3:
    cout << "Weekday";  // Executes for cases 1, 2, or 3
    break;
```

**When to use switch vs if-else:**

- **Use switch**: Multiple specific discrete values, cleaner code
- **Use if-else**: Ranges, complex conditions, floating-point comparisons

````

**Switch with Character and Fall-through:**

```cpp
#include <iostream>
using namespace std;

int main() {
    char grade;
    cout << "Enter your grade (A-F): ";
    cin >> grade;

    switch (grade) {
        case 'A':
        case 'a':
            cout << "Excellent! (90-100)" << endl;
            break;

        case 'B':
        case 'b':
            cout << "Good! (80-89)" << endl;
            break;

        case 'C':
        case 'c':
            cout << "Average (70-79)" << endl;
            break;

        case 'D':
        case 'd':
            cout << "Below Average (60-69)" << endl;
            break;

        case 'F':
        case 'f':
            cout << "Fail (Below 60)" << endl;
            break;

        default:
            cout << "Invalid grade!" << endl;
    }

    // Example of intentional fall-through
    int dayOfWeek;
    cout << "\nEnter day number (1-7): ";
    cin >> dayOfWeek;

    cout << "Day type: ";
    switch (dayOfWeek) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            cout << "Weekday" << endl;
            break;

        case 6:
        case 7:
            cout << "Weekend" << endl;
            break;

        default:
            cout << "Invalid day!" << endl;
    }

    return 0;
}
````

**Sample Output:**

```
Enter your grade (A-F): B
Good! (80-89)

Enter day number (1-7): 6
Day type: Weekend
```

**Fall-Through Explained:**

**Intentional Fall-Through:**

- When you want multiple case values to execute the same code
- Omit `break` statement for cases that should "fall through"
- Common pattern for handling uppercase and lowercase together

**Example:**

```cpp
case 'A':
case 'a':
    // Both 'A' and 'a' execute this code
    cout << "Excellent!";
    break;
```

**Warning about Fall-Through:**

- **Accidental fall-through** is a common source of bugs
- If you forget `break`, execution continues to next case
- Use C++17 `[[fallthrough]]` attribute to indicate intentional fall-through:

```cpp
case 1:
    doSomething();
    [[fallthrough]];  // Tells compiler this is intentional
case 2:
    doSomethingElse();
    break;
```

````

### 0.3.3 Loops

**For Loop:**

```cpp
#include <iostream>
using namespace std;

int main() {
    // Basic for loop
    cout << "Numbers 1-10:" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << i << " ";
    }
    cout << endl;

    // For loop with different increments
    cout << "Even numbers up to 20:" << endl;
    for (int i = 2; i <= 20; i += 2) {
        cout << i << " ";
    }
    cout << endl;

    // Countdown loop
    cout << "Countdown:" << endl;
    for (int i = 10; i >= 1; i--) {
        cout << i << " ";
    }
    cout << "Blast off!" << endl;

    // Nested for loops - multiplication table
    cout << "\nMultiplication Table (1-5):" << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cout << i * j << "\t";
        }
        cout << endl;
    }

    // Multiple variables in for loop
    cout << "\nMultiple variables:" << endl;
    for (int i = 0, j = 10; i < 5; i++, j--) {
        cout << "i = " << i << ", j = " << j << endl;
    }

    return 0;
}
````

**Output:**

```
Numbers 1-10:
1 2 3 4 5 6 7 8 9 10
Even numbers up to 20:
2 4 6 8 10 12 14 16 18 20
Countdown:
10 9 8 7 6 5 4 3 2 1 Blast off!

Multiplication Table (1-5):
1	2	3	4	5
2	4	6	8	10
3	6	9	12	15
4	8	12	16	20
5	10	15	20	25

Multiple variables:
i = 0, j = 10
i = 1, j = 9
i = 2, j = 8
i = 3, j = 7
i = 4, j = 6
```

**While Loop:**

```cpp
#include <iostream>
using namespace std;

int main() {
    // Basic while loop
    int count = 1;
    cout << "While loop counting:" << endl;
    while (count <= 5) {
        cout << "Count: " << count << endl;
        count++;
    }

    // Input validation with while loop
    int number;
    cout << "\nEnter a number between 1 and 10: ";
    cin >> number;

    while (number < 1 || number > 10) {
        cout << "Invalid input! Please enter a number between 1 and 10: ";
        cin >> number;
    }
    cout << "Thank you! You entered: " << number << endl;

    // Calculate sum of digits
    int num = 12345;
    int sum = 0;
    int temp = num;

    cout << "\nCalculating sum of digits of " << num << ":" << endl;
    while (temp > 0) {
        int digit = temp % 10;
        sum += digit;
        cout << "Digit: " << digit << ", Running sum: " << sum << endl;
        temp /= 10;
    }
    cout << "Total sum of digits: " << sum << endl;

    return 0;
}
```

**Do-While Loop:**

```cpp
#include <iostream>
using namespace std;

int main() {
    // Basic do-while loop
    int i = 1;
    cout << "Do-while loop:" << endl;
    do {
        cout << "Iteration: " << i << endl;
        i++;
    } while (i <= 3);

    // Menu system using do-while
    int choice;
    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Say Hello" << endl;
        cout << "2. Display Date" << endl;
        cout << "3. Calculate Square" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Hello, World!" << endl;
                break;
            case 2:
                cout << "Today's date: September 21, 2025" << endl;
                break;
            case 3: {
                int num;
                cout << "Enter a number: ";
                cin >> num;
                cout << "Square of " << num << " is " << (num * num) << endl;
                break;
            }
            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}
```

### 0.3.4 Break and Continue Statements

**Break Statement:**

```cpp
#include <iostream>
using namespace std;

int main() {
    // Break in for loop
    cout << "Finding first multiple of 7 greater than 50:" << endl;
    for (int i = 51; i <= 100; i++) {
        if (i % 7 == 0) {
            cout << "Found: " << i << endl;
            break;  // Exit the loop
        }
        cout << "Checking: " << i << endl;
    }

    // Break in while loop - number guessing game
    int secretNumber = 42;
    int guess;
    int attempts = 0;
    const int maxAttempts = 5;

    cout << "\nGuess the number (1-100). You have " << maxAttempts << " attempts." << endl;
    while (true) {
        attempts++;
        cout << "Attempt " << attempts << ": ";
        cin >> guess;

        if (guess == secretNumber) {
            cout << "Congratulations! You guessed it in " << attempts << " attempts!" << endl;
            break;
        }
        else if (attempts >= maxAttempts) {
            cout << "Game over! The number was " << secretNumber << endl;
            break;
        }
        else if (guess < secretNumber) {
            cout << "Too low!" << endl;
        }
        else {
            cout << "Too high!" << endl;
        }
    }

    // Break in nested loops
    cout << "\nBreak in nested loops:" << endl;
    for (int i = 1; i <= 3; i++) {
        cout << "Outer loop: " << i << endl;
        for (int j = 1; j <= 5; j++) {
            if (j == 3) {
                cout << "  Breaking inner loop at j = " << j << endl;
                break;  // Only breaks inner loop
            }
            cout << "  Inner loop: " << j << endl;
        }
    }

    return 0;
}
```

**Continue Statement:**

```cpp
#include <iostream>
using namespace std;

int main() {
    // Continue in for loop - print odd numbers
    cout << "Odd numbers from 1 to 10:" << endl;
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;  // Skip even numbers
        }
        cout << i << " ";
    }
    cout << endl;

    // Continue in while loop - skip negative numbers
    cout << "\nEnter numbers (0 to stop). Negative numbers will be skipped:" << endl;
    int num;
    while (true) {
        cout << "Enter number: ";
        cin >> num;

        if (num == 0) {
            break;
        }

        if (num < 0) {
            cout << "Negative number skipped!" << endl;
            continue;  // Skip processing negative numbers
        }

        cout << "Square of " << num << " is " << (num * num) << endl;
    }

    // Continue in nested loops
    cout << "\nPrint multiplication table skipping multiples of 3:" << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            int product = i * j;
            if (product % 3 == 0) {
                continue;  // Skip multiples of 3
            }
            cout << i << "*" << j << "=" << product << " ";
        }
        cout << endl;
    }

    return 0;
}
```

**Output Example:**

```
Odd numbers from 1 to 10:
1 3 5 7 9

Print multiplication table skipping multiples of 3:
1*1=1 1*2=2 1*4=4 1*5=5
2*1=2 2*2=4 2*4=8 2*5=10
4*1=4 4*2=8 4*4=16 4*5=20
5*1=5 5*2=10 5*4=20 5*5=25
```

### 0.3.5 Goto Statement (Generally Avoided)

**Goto Example (Educational Purpose):**

```cpp
#include <iostream>
using namespace std;

int main() {
    int choice;

    // Label definition
    menu:
    cout << "\n--- Simple Calculator ---" << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Exit" << endl;
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1) {
        double a, b;
        cout << "Enter two numbers: ";
        cin >> a >> b;
        cout << "Sum: " << (a + b) << endl;
        goto menu;  // Jump to menu label
    }
    else if (choice == 2) {
        double a, b;
        cout << "Enter two numbers: ";
        cin >> a >> b;
        cout << "Difference: " << (a - b) << endl;
        goto menu;  // Jump to menu label
    }
    else if (choice == 3) {
        cout << "Goodbye!" << endl;
        goto end;   // Jump to end label
    }
    else {
        cout << "Invalid choice!" << endl;
        goto menu;  // Jump to menu label
    }

    end:
    cout << "Program terminated." << endl;

    return 0;
}
```

**Why Goto is Discouraged:**

- Makes code hard to read and maintain
- Can create "spaghetti code"
- Modern C++ provides better alternatives (loops, functions)
- Can lead to logical errors and infinite loops

**Better Alternative using Functions:**

```cpp
#include <iostream>
using namespace std;

void displayMenu() {
    cout << "\n--- Simple Calculator ---" << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Exit" << endl;
    cout << "Choice: ";
}

void performAddition() {
    double a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Sum: " << (a + b) << endl;
}

void performSubtraction() {
    double a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Difference: " << (a - b) << endl;
}

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                performAddition();
                break;
            case 2:
                performSubtraction();
                break;
            case 3:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);

    return 0;
}
```

---

## Phase 0.4: Functions

### 0.4.1 Function Declaration and Definition

**Basic Function Structure:**

```cpp
#include <iostream>
using namespace std;

// Function declaration (prototype)
int add(int a, int b);
void greetUser(string name);
double calculateCircleArea(double radius);

int main() {
    // Function calls
    int sum = add(5, 3);
    cout << "Sum: " << sum << endl;

    greetUser("Alice");

    double area = calculateCircleArea(5.0);
    cout << "Circle area: " << area << endl;

    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

void greetUser(string name) {
    cout << "Hello, " << name << "!" << endl;
}

double calculateCircleArea(double radius) {
    const double PI = 3.14159;
    return PI * radius * radius;
}
```

**Output:**

```
Sum: 8
Hello, Alice!
Circle area: 78.5397
```

**Function Components:**

1. **Return Type**: Data type of the value returned (void for no return)
2. **Function Name**: Identifier to call the function
3. **Parameters**: Input values (formal parameters)
4. **Function Body**: Code to execute
5. **Return Statement**: Value to return (optional for void functions)

### 0.4.2 Default Arguments

**Default Parameters:**

```cpp
#include <iostream>
using namespace std;

// Function with default arguments
void displayInfo(string name, int age = 25, string city = "Unknown") {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "City: " << city << endl;
    cout << "---" << endl;
}

// Default arguments must be at the end
double calculatePower(double base, int exponent = 2) {
    double result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// Complex default argument example
void printPattern(char ch = '*', int rows = 5, int cols = 5) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

int main() {
    // Different ways to call function with default arguments
    displayInfo("John");                          // Uses default age and city
    displayInfo("Alice", 30);                     // Uses default city
    displayInfo("Bob", 28, "New York");          // No defaults used

    // Power function examples
    cout << "5^2 = " << calculatePower(5) << endl;         // Uses default exponent 2
    cout << "2^3 = " << calculatePower(2, 3) << endl;      // Custom exponent
    cout << "3^4 = " << calculatePower(3, 4) << endl;      // Custom exponent

    // Pattern examples
    cout << "\nDefault pattern:" << endl;
    printPattern();

    cout << "\nCustom pattern:" << endl;
    printPattern('#', 3, 8);

    return 0;
}
```

**Output:**

```
Name: John
Age: 25
City: Unknown
---
Name: Alice
Age: 30
City: Unknown
---
Name: Bob
Age: 28
City: New York
---
5^2 = 25
2^3 = 8
3^4 = 81

Default pattern:
* * * * *
* * * * *
* * * * *
* * * * *
* * * * *

Custom pattern:
# # # # # # # #
# # # # # # # #
# # # # # # # #
```

### 0.4.3 Inline Functions

**Inline Function Example:**

```cpp
#include <iostream>
using namespace std;

// Inline function definition
inline int max(int a, int b) {
    return (a > b) ? a : b;
}

inline double square(double x) {
    return x * x;
}

// Complex inline function (compiler may ignore inline request)
inline int factorial(int n) {
    if (n <= 1) return 1;
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Class with inline member function
class Rectangle {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Inline member function (implicitly inline when defined inside class)
    double getArea() {
        return length * width;
    }

    // Explicitly inline member function
    inline double getPerimeter();
};

inline double Rectangle::getPerimeter() {
    return 2 * (length + width);
}

int main() {
    // Using inline functions
    int a = 10, b = 20;
    cout << "Max of " << a << " and " << b << " is: " << max(a, b) << endl;

    double x = 5.5;
    cout << "Square of " << x << " is: " << square(x) << endl;

    int n = 5;
    cout << "Factorial of " << n << " is: " << factorial(n) << endl;

    // Using inline member functions
    Rectangle rect(10.5, 7.2);
    cout << "Rectangle area: " << rect.getArea() << endl;
    cout << "Rectangle perimeter: " << rect.getPerimeter() << endl;

    return 0;
}
```

**Benefits of Inline Functions:**

- Eliminates function call overhead
- Faster execution for small functions
- Maintains type safety (unlike macros)

**When to Use Inline:**

- Small, frequently called functions
- Simple operations (getters, setters)
- Functions with 1-3 lines of code

### 0.4.4 Function Overloading

**Function Overloading Example:**

```cpp
#include <iostream>
#include <string>
using namespace std;

// Function overloading - same name, different parameters
void print(int value) {
    cout << "Integer: " << value << endl;
}

void print(double value) {
    cout << "Double: " << value << endl;
}

void print(string value) {
    cout << "String: " << value << endl;
}

void print(char value) {
    cout << "Character: " << value << endl;
}

// Overloading with different number of parameters
int add(int a, int b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

double add(double a, double b) {
    return a + b;
}

// Overloading with different parameter order
void displayInfo(string name, int id) {
    cout << "Name: " << name << ", ID: " << id << endl;
}

void displayInfo(int id, string name) {
    cout << "ID: " << id << ", Name: " << name << endl;
}

// Volume calculation overloading
double volume(double radius) {  // Sphere
    const double PI = 3.14159;
    return (4.0/3.0) * PI * radius * radius * radius;
}

double volume(double length, double width, double height) {  // Box
    return length * width * height;
}

double volume(double radius, double height) {  // Cylinder
    const double PI = 3.14159;
    return PI * radius * radius * height;
}

int main() {
    // Using overloaded print functions
    print(42);
    print(3.14159);
    print("Hello World");
    print('A');

    // Using overloaded add functions
    cout << "\nAddition results:" << endl;
    cout << "2 + 3 = " << add(2, 3) << endl;
    cout << "1 + 2 + 3 = " << add(1, 2, 3) << endl;
    cout << "2.5 + 3.7 = " << add(2.5, 3.7) << endl;

    // Using overloaded displayInfo
    cout << "\nDisplay info:" << endl;
    displayInfo("Alice", 101);
    displayInfo(102, "Bob");

    // Using overloaded volume functions
    cout << "\nVolume calculations:" << endl;
    cout << "Sphere (r=3): " << volume(3.0) << endl;
    cout << "Box (5x4x3): " << volume(5.0, 4.0, 3.0) << endl;
    cout << "Cylinder (r=2, h=5): " << volume(2.0, 5.0) << endl;

    return 0;
}
```

**Output:**

```
Integer: 42
Double: 3.14159
String: Hello World
Character: A

Addition results:
2 + 3 = 5
1 + 2 + 3 = 6
2.5 + 3.7 = 6.2

Display info:
Name: Alice, ID: 101
ID: 102, Name: Bob

Volume calculations:
Sphere (r=3): 113.097
Box (5x4x3): 60
Cylinder (r=2, h=5): 62.8318
```

### 0.4.5 Parameter Passing Mechanisms

**Pass by Value:**

```cpp
#include <iostream>
using namespace std;

void passByValue(int x) {
    cout << "Inside function - before: " << x << endl;
    x = 100;  // Only changes local copy
    cout << "Inside function - after: " << x << endl;
}

int main() {
    int num = 50;
    cout << "Before function call: " << num << endl;
    passByValue(num);
    cout << "After function call: " << num << endl;  // Original value unchanged

    return 0;
}
```

**Pass by Reference:**

```cpp
#include <iostream>
using namespace std;

void passByReference(int &x) {
    cout << "Inside function - before: " << x << endl;
    x = 100;  // Changes original variable
    cout << "Inside function - after: " << x << endl;
}

void swapNumbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function returning reference
int& getElement(int arr[], int index) {
    return arr[index];
}

int main() {
    // Pass by reference example
    int num = 50;
    cout << "Before function call: " << num << endl;
    passByReference(num);
    cout << "After function call: " << num << endl;  // Original value changed

    // Swap example
    int x = 10, y = 20;
    cout << "\nBefore swap: x = " << x << ", y = " << y << endl;
    swapNumbers(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    // Reference return example
    int array[] = {1, 2, 3, 4, 5};
    cout << "\nArray before: ";
    for (int i = 0; i < 5; i++) cout << array[i] << " ";
    cout << endl;

    getElement(array, 2) = 99;  // Modifies array[2]
    cout << "Array after: ";
    for (int i = 0; i < 5; i++) cout << array[i] << " ";
    cout << endl;

    return 0;
}
```

**Pass by Pointer:**

```cpp
#include <iostream>
using namespace std;

void passByPointer(int *x) {
    cout << "Inside function - before: " << *x << endl;
    *x = 100;  // Changes value at address
    cout << "Inside function - after: " << *x << endl;
}

void swapWithPointers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void modifyArray(int arr[], int size) {  // Array name is a pointer
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

// Function returning pointer
int* findMax(int arr[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return &arr[maxIndex];
}

int main() {
    // Pass by pointer example
    int num = 50;
    cout << "Before function call: " << num << endl;
    passByPointer(&num);
    cout << "After function call: " << num << endl;

    // Swap with pointers
    int x = 10, y = 20;
    cout << "\nBefore swap: x = " << x << ", y = " << y << endl;
    swapWithPointers(&x, &y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    // Array modification
    int array[] = {1, 2, 3, 4, 5};
    cout << "\nArray before: ";
    for (int i = 0; i < 5; i++) cout << array[i] << " ";
    cout << endl;

    modifyArray(array, 5);
    cout << "Array after doubling: ";
    for (int i = 0; i < 5; i++) cout << array[i] << " ";
    cout << endl;

    // Find maximum
    int numbers[] = {45, 23, 78, 12, 67};
    int *maxPtr = findMax(numbers, 5);
    cout << "Maximum value: " << *maxPtr << endl;

    return 0;
}
```

**Output:**

```
Before function call: 50
Inside function - before: 50
Inside function - after: 100
After function call: 100

Before swap: x = 10, y = 20
After swap: x = 20, y = 10

Array before: 1 2 3 4 5
Array after doubling: 2 4 6 8 10
Maximum value: 78
```

**Comparison of Parameter Passing:**

```cpp
#include <iostream>
#include <chrono>
using namespace std;

struct LargeStruct {
    int data[1000];
    LargeStruct() {
        for (int i = 0; i < 1000; i++) {
            data[i] = i;
        }
    }
};

// Pass by value - expensive for large objects
void processByValue(LargeStruct obj) {
    // Process the copy
    obj.data[0] = 999;
}

// Pass by reference - efficient
void processByReference(LargeStruct &obj) {
    obj.data[0] = 999;
}

// Pass by const reference - efficient and safe
void processByConstReference(const LargeStruct &obj) {
    // Can read but not modify
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += obj.data[i];
    }
    cout << "Sum of first 10 elements: " << sum << endl;
}

int main() {
    LargeStruct myStruct;

    cout << "Original data[0]: " << myStruct.data[0] << endl;

    // Pass by value - original unchanged
    processByValue(myStruct);
    cout << "After pass by value: " << myStruct.data[0] << endl;

    // Pass by reference - original changed
    processByReference(myStruct);
    cout << "After pass by reference: " << myStruct.data[0] << endl;

    // Pass by const reference
    processByConstReference(myStruct);

    return 0;
}
```

### 0.4.6 Recursion

**Basic Recursion Examples:**

```cpp
#include <iostream>
using namespace std;

// Factorial calculation
int factorial(int n) {
    // Base case
    if (n <= 1) {
        return 1;
    }
    // Recursive case
    return n * factorial(n - 1);
}

// Fibonacci sequence
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Power calculation
double power(double base, int exponent) {
    if (exponent == 0) {
        return 1.0;
    }
    if (exponent < 0) {
        return 1.0 / power(base, -exponent);
    }
    return base * power(base, exponent - 1);
}

// Sum of digits
int sumOfDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + sumOfDigits(n / 10);
}

// Greatest Common Divisor (GCD)
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    // Factorial examples
    cout << "Factorial examples:" << endl;
    for (int i = 0; i <= 5; i++) {
        cout << i << "! = " << factorial(i) << endl;
    }

    // Fibonacci examples
    cout << "\nFibonacci sequence:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "F(" << i << ") = " << fibonacci(i) << endl;
    }

    // Power examples
    cout << "\nPower calculations:" << endl;
    cout << "2^5 = " << power(2, 5) << endl;
    cout << "3^4 = " << power(3, 4) << endl;
    cout << "2^(-3) = " << power(2, -3) << endl;

    // Sum of digits
    cout << "\nSum of digits:" << endl;
    int numbers[] = {123, 4567, 89};
    for (int num : numbers) {
        cout << "Sum of digits of " << num << " = " << sumOfDigits(num) << endl;
    }

    // GCD examples
    cout << "\nGCD calculations:" << endl;
    cout << "GCD(48, 18) = " << gcd(48, 18) << endl;
    cout << "GCD(100, 25) = " << gcd(100, 25) << endl;

    return 0;
}
```

**Output:**

```
Factorial examples:
0! = 1
1! = 1
2! = 2
3! = 6
4! = 24
5! = 120

Fibonacci sequence:
F(0) = 0
F(1) = 1
F(2) = 1
F(3) = 2
F(4) = 3
F(5) = 5
F(6) = 8
F(7) = 13
F(8) = 21
F(9) = 34

Power calculations:
2^5 = 32
3^4 = 81
2^(-3) = 0.125

Sum of digits:
Sum of digits of 123 = 6
Sum of digits of 4567 = 22
Sum of digits of 89 = 17

GCD calculations:
GCD(48, 18) = 6
GCD(100, 25) = 25
```

---

## Phase 0.5: Pointers & References

### 0.5.1 Pointer Basics

**Understanding Pointers:**

```cpp
#include <iostream>
using namespace std;

int main() {
    // Variable declaration
    int number = 42;
    cout << "Value of number: " << number << endl;
    cout << "Address of number: " << &number << endl;

    // Pointer declaration and initialization
    int* ptr = &number;  // ptr stores address of number

    cout << "\nPointer information:" << endl;
    cout << "Value of ptr (address it holds): " << ptr << endl;
    cout << "Value at address (dereferencing): " << *ptr << endl;
    cout << "Address of ptr itself: " << &ptr << endl;

    // Modifying value through pointer
    *ptr = 100;
    cout << "\nAfter modifying through pointer:" << endl;
    cout << "Value of number: " << number << endl;
    cout << "Value through pointer: " << *ptr << endl;

    // Pointer arithmetic
    int arr[] = {10, 20, 30, 40, 50};
    int* arrPtr = arr;  // Points to first element

    cout << "\nPointer arithmetic:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "arr[" << i << "] = " << *(arrPtr + i) << " at address " << (arrPtr + i) << endl;
    }

    return 0;
}
```

**Output:**

```
Value of number: 42
Address of number: 0x7ffe5c8f4b4c

Pointer information:
Value of ptr (address it holds): 0x7ffe5c8f4b4c
Value at address (dereferencing): 42
Address of ptr itself: 0x7ffe5c8f4b48

After modifying through pointer:
Value of number: 100
Value through pointer: 100

Pointer arithmetic:
arr[0] = 10 at address 0x7ffe5c8f4b30
arr[1] = 20 at address 0x7ffe5c8f4b34
arr[2] = 30 at address 0x7ffe5c8f4b38
arr[3] = 40 at address 0x7ffe5c8f4b3c
arr[4] = 50 at address 0x7ffe5c8f4b40
```

### 0.5.2 Types of Pointers

**Different Pointer Types:**

```cpp
#include <iostream>
using namespace std;

int main() {
    // Null pointer
    int* nullPtr = nullptr;  // Modern C++ way
    int* oldNullPtr = NULL;  // C-style (deprecated)

    cout << "Null pointer value: " << nullPtr << endl;

    // Wild pointer (dangerous - don't do this!)
    // int* wildPtr;  // Uninitialized pointer

    // Void pointer - can point to any data type
    int intVal = 42;
    char charVal = 'A';
    double doubleVal = 3.14;

    void* voidPtr;

    voidPtr = &intVal;
    cout << "Void pointer pointing to int: " << *(static_cast<int*>(voidPtr)) << endl;

    voidPtr = &charVal;
    cout << "Void pointer pointing to char: " << *(static_cast<char*>(voidPtr)) << endl;

    voidPtr = &doubleVal;
    cout << "Void pointer pointing to double: " << *(static_cast<double*>(voidPtr)) << endl;

    // Constant pointers
    int a = 10, b = 20;

    // Pointer to constant - can't change value through pointer
    const int* ptrToConst = &a;
    cout << "Value through pointer to constant: " << *ptrToConst << endl;
    // *ptrToConst = 30;  // Error! Can't modify
    ptrToConst = &b;  // OK - can change what it points to

    // Constant pointer - can't change what it points to
    int* const constPtr = &a;
    *constPtr = 30;  // OK - can modify value
    cout << "Value through constant pointer: " << *constPtr << endl;
    // constPtr = &b;  // Error! Can't change what it points to

    // Constant pointer to constant
    const int* const constPtrToConst = &a;
    cout << "Value through const pointer to const: " << *constPtrToConst << endl;
    // *constPtrToConst = 40;  // Error! Can't modify value
    // constPtrToConst = &b;   // Error! Can't change what it points to

    return 0;
}
```

### 0.5.3 Pointer to Pointer

**Multi-level Pointers:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int value = 100;
    int* ptr = &value;           // Pointer to int
    int** ptrToPtr = &ptr;       // Pointer to pointer
    int*** ptrToPtrToPtr = &ptrToPtr;  // Pointer to pointer to pointer

    cout << "Multi-level pointer example:" << endl;
    cout << "Value: " << value << endl;
    cout << "Through ptr: " << *ptr << endl;
    cout << "Through ptrToPtr: " << **ptrToPtr << endl;
    cout << "Through ptrToPtrToPtr: " << ***ptrToPtrToPtr << endl;

    cout << "\nAddresses:" << endl;
    cout << "Address of value: " << &value << endl;
    cout << "Value in ptr: " << ptr << endl;
    cout << "Address of ptr: " << &ptr << endl;
    cout << "Value in ptrToPtr: " << ptrToPtr << endl;
    cout << "Address of ptrToPtr: " << &ptrToPtr << endl;
    cout << "Value in ptrToPtrToPtr: " << ptrToPtrToPtr << endl;

    // Practical example - dynamic 2D array
    int rows = 3, cols = 4;
    int** matrix = new int*[rows];

    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j + 1;
        }
    }

    cout << "\nDynamic 2D array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Clean up memory
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
```

### 0.5.4 References

**Reference Basics:**

```cpp
#include <iostream>
using namespace std;

int main() {
    // Reference declaration and initialization
    int original = 42;
    int& ref = original;  // Reference must be initialized

    cout << "Original value: " << original << endl;
    cout << "Reference value: " << ref << endl;
    cout << "Same address? " << (&original == &ref ? "Yes" : "No") << endl;

    // Modifying through reference
    ref = 100;
    cout << "\nAfter modifying through reference:" << endl;
    cout << "Original value: " << original << endl;
    cout << "Reference value: " << ref << endl;

    // Reference vs Pointer comparison
    int a = 10, b = 20;

    // Using pointer
    int* ptr = &a;
    cout << "\nUsing pointer:" << endl;
    cout << "Value: " << *ptr << endl;
    ptr = &b;  // Can reassign pointer
    cout << "After reassignment: " << *ptr << endl;

    // Using reference
    int& refA = a;
    cout << "\nUsing reference:" << endl;
    cout << "Value: " << refA << endl;
    // refA = &b;  // Error! Can't reassign reference
    // int& refB;  // Error! Must initialize reference

    return 0;
}
```

**References in Functions:**

```cpp
#include <iostream>
using namespace std;

// Reference parameters
void swapByReference(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

// Reference return type
int& getMax(int& a, int& b) {
    return (a > b) ? a : b;
}

// Const reference parameter (efficient for large objects)
void displayString(const string& str) {
    cout << "String: " << str << endl;
    // str[0] = 'X';  // Error! Can't modify const reference
}

// Reference to array
void printArray(int (&arr)[5]) {  // Reference to array of 5 integers
    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Swap example
    int x = 10, y = 20;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapByReference(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    // Reference return example
    int a = 50, b = 75;
    cout << "\nBefore modification: a = " << a << ", b = " << b << endl;
    getMax(a, b) = 100;  // Modifies the larger value
    cout << "After modification: a = " << a << ", b = " << b << endl;

    // Const reference example
    string message = "Hello, World!";
    displayString(message);

    // Array reference example
    int numbers[5] = {1, 2, 3, 4, 5};
    printArray(numbers);

    return 0;
}
```

**Output:**

```
Before swap: x = 10, y = 20
After swap: x = 20, y = 10

Before modification: a = 50, b = 75
After modification: a = 50, b = 100

String: Hello, World!
Array elements: 1 2 3 4 5
```

### 0.5.5 Dynamic Memory Management

**Basic Dynamic Allocation:**

```cpp
#include <iostream>
using namespace std;

int main() {
    // Dynamic allocation for single variable
    int* dynamicInt = new int(42);  // Allocate and initialize
    cout << "Dynamic integer: " << *dynamicInt << endl;
    delete dynamicInt;  // Free memory
    dynamicInt = nullptr;  // Good practice

    // Dynamic allocation for arrays
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int* dynamicArray = new int[size];

    // Initialize array
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = (i + 1) * 10;
    }

    // Display array
    cout << "Dynamic array elements: ";
    for (int i = 0; i < size; i++) {
        cout << dynamicArray[i] << " ";
    }
    cout << endl;

    delete[] dynamicArray;  // Free array memory
    dynamicArray = nullptr;

    // Dynamic allocation with error handling
    try {
        int* hugeArray = new int[1000000000];  // May fail
        cout << "Huge array allocated successfully!" << endl;
        delete[] hugeArray;
    }
    catch (const bad_alloc& e) {
        cout << "Memory allocation failed: " << e.what() << endl;
    }

    // Using nothrow version
    int* safePtr = new(nothrow) int[1000000000];
    if (safePtr == nullptr) {
        cout << "Safe allocation failed - returned nullptr" << endl;
    }
    else {
        cout << "Safe allocation succeeded" << endl;
        delete[] safePtr;
    }

    return 0;
}
```

**Dynamic 2D Arrays:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter matrix dimensions (rows cols): ";
    cin >> rows >> cols;

    // Method 1: Array of pointers
    int** matrix1 = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix1[i] = new int[cols];
    }

    // Initialize matrix1
    cout << "\nMethod 1 - Array of pointers:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix1[i][j] = i * cols + j + 1;
            cout << matrix1[i][j] << "\t";
        }
        cout << endl;
    }

    // Clean up matrix1
    for (int i = 0; i < rows; i++) {
        delete[] matrix1[i];
    }
    delete[] matrix1;

    // Method 2: Single block allocation
    int* matrix2 = new int[rows * cols];

    // Initialize matrix2
    cout << "\nMethod 2 - Single block:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix2[i * cols + j] = (i + 1) * (j + 1);
            cout << matrix2[i * cols + j] << "\t";
        }
        cout << endl;
    }

    delete[] matrix2;

    return 0;
}
```

### 0.5.6 Memory Management Best Practices

**RAII and Smart Pointer Preview:**

```cpp
#include <iostream>
#include <memory>
using namespace std;

// Simple RAII wrapper class
class IntArray {
private:
    int* data;
    size_t size;

public:
    IntArray(size_t s) : size(s) {
        data = new int[size];
        cout << "Array of size " << size << " allocated" << endl;
    }

    ~IntArray() {
        delete[] data;
        cout << "Array of size " << size << " deallocated" << endl;
    }

    int& operator[](size_t index) {
        return data[index];
    }

    size_t getSize() const { return size; }
};

// Memory leak demonstration
void memoryLeakExample() {
    cout << "\n--- Memory Leak Example ---" << endl;

    // BAD: Memory leak
    int* leakyPtr = new int[100];
    // Forgot to delete[] leakyPtr; - MEMORY LEAK!

    // GOOD: Proper cleanup
    int* goodPtr = new int[100];
    delete[] goodPtr;
    goodPtr = nullptr;

    // BEST: Using RAII
    IntArray raii_array(100);
    // Automatically cleaned up when going out of scope
}

// Dangling pointer demonstration
void danglingPointerExample() {
    cout << "\n--- Dangling Pointer Example ---" << endl;

    int* ptr = new int(42);
    int* copy = ptr;  // Two pointers to same memory

    delete ptr;       // Free memory
    ptr = nullptr;    // Good practice

    // copy is now a dangling pointer!
    // cout << *copy;  // UNDEFINED BEHAVIOR - DON'T DO THIS!

    copy = nullptr;   // Fix the dangling pointer
}

int main() {
    // RAII example
    {
        IntArray myArray(10);
        for (size_t i = 0; i < myArray.getSize(); i++) {
            myArray[i] = i * i;
        }

        cout << "Array elements: ";
        for (size_t i = 0; i < myArray.getSize(); i++) {
            cout << myArray[i] << " ";
        }
        cout << endl;
    }  // myArray is automatically destroyed here

    memoryLeakExample();
    danglingPointerExample();

    // Modern C++ preview - Smart Pointers
    cout << "\n--- Smart Pointers Preview ---" << endl;

    // unique_ptr - exclusive ownership
    unique_ptr<int> smartInt = make_unique<int>(100);
    cout << "Smart pointer value: " << *smartInt << endl;
    // Automatically cleaned up

    // shared_ptr - shared ownership
    shared_ptr<int> shared1 = make_shared<int>(200);
    shared_ptr<int> shared2 = shared1;  // Share ownership
    cout << "Shared pointer value: " << *shared1 << endl;
    cout << "Reference count: " << shared1.use_count() << endl;

    return 0;
}
```

**Output:**

```
Array of size 10 allocated
Array elements: 0 1 4 9 16 25 36 49 64 81
Array of size 10 deallocated

--- Memory Leak Example ---
Array of size 100 allocated
Array of size 100 deallocated

--- Dangling Pointer Example ---

--- Smart Pointers Preview ---
Smart pointer value: 100
Shared pointer value: 200
Reference count: 2
```

---

## Phase 0.6: Arrays & Strings

### 0.6.1 One-Dimensional Arrays

**Array Basics:**

```cpp
#include <iostream>
using namespace std;

int main() {
    // Array declaration and initialization
    int numbers[5];  // Declaration only

    // Initialization during declaration
    int scores[5] = {85, 92, 78, 96, 88};

    // Partial initialization
    int grades[5] = {90, 85};  // Rest initialized to 0

    // Size determined by initializer
    int values[] = {10, 20, 30, 40, 50};  // Size is 5

    // Modern C++ uniform initialization
    int modern[5]{1, 2, 3, 4, 5};

    // Display arrays
    cout << "Scores: ";
    for (int i = 0; i < 5; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;

    cout << "Grades: ";
    for (int i = 0; i < 5; i++) {
        cout << grades[i] << " ";
    }
    cout << endl;

    // Array size
    cout << "Size of scores array: " << sizeof(scores) << " bytes" << endl;
    cout << "Number of elements: " << sizeof(scores) / sizeof(scores[0]) << endl;

    // Input array elements
    cout << "\nEnter 5 numbers for the array: ";
    for (int i = 0; i < 5; i++) {
        cin >> numbers[i];
    }

    // Find maximum and minimum
    int max = numbers[0], min = numbers[0];
    int maxIndex = 0, minIndex = 0;

    for (int i = 1; i < 5; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
            maxIndex = i;
        }
        if (numbers[i] < min) {
            min = numbers[i];
            minIndex = i;
        }
    }

    cout << "Maximum: " << max << " at index " << maxIndex << endl;
    cout << "Minimum: " << min << " at index " << minIndex << endl;

    // Calculate sum and average
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += numbers[i];
    }
    double average = static_cast<double>(sum) / 5;

    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;

    return 0;
}
```

**Array Operations:**

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int data[10] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50};
    int size = 10;

    cout << "Original array: ";
    printArray(data, size);

    // Reverse array
    int reversed[10];
    for (int i = 0; i < size; i++) {
        reversed[i] = data[size - 1 - i];
    }
    cout << "Reversed array: ";
    printArray(reversed, size);

    // Sort array (using STL algorithm)
    sort(data, data + size);
    cout << "Sorted array: ";
    printArray(data, size);

    // Search element
    int target = 25;
    bool found = false;
    int position = -1;

    for (int i = 0; i < size; i++) {
        if (data[i] == target) {
            found = true;
            position = i;
            break;
        }
    }

    if (found) {
        cout << "Element " << target << " found at position " << position << endl;
    } else {
        cout << "Element " << target << " not found" << endl;
    }

    // Binary search (array must be sorted)
    bool binaryFound = binary_search(data, data + size, target);
    cout << "Binary search result for " << target << ": " << (binaryFound ? "Found" : "Not found") << endl;

    return 0;
}
```

### 0.6.2 Multi-Dimensional Arrays

**2D Array Basics:**

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // 2D array declaration and initialization
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Alternative initialization
    int grid[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // Partial initialization
    int partial[3][3] = {{1, 2}, {3}, {4, 5, 6}};

    // Display 2D array
    cout << "Matrix (3x4):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }

    cout << "\nPartial initialization matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(4) << partial[i][j];
        }
        cout << endl;
    }

    // Input 2D array
    int userMatrix[2][3];
    cout << "\nEnter elements for 2x3 matrix:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> userMatrix[i][j];
        }
    }

    cout << "Your matrix:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(4) << userMatrix[i][j];
        }
        cout << endl;
    }

    // Matrix operations
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    int sum[2][2], product[2][2];

    // Matrix addition
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    // Matrix multiplication
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            product[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    cout << "\nMatrix A:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }

    cout << "Matrix B:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << setw(4) << b[i][j];
        }
        cout << endl;
    }

    cout << "A + B:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << setw(4) << sum[i][j];
        }
        cout << endl;
    }

    cout << "A * B:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << setw(4) << product[i][j];
        }
        cout << endl;
    }

    return 0;
}
```

### 0.6.3 Character Arrays and C-Strings

**Character Array Basics:**

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    // Character array initialization
    char name1[20] = "Hello";
    char name2[] = "World";  // Size determined automatically
    char name3[20];

    cout << "name1: " << name1 << endl;
    cout << "name2: " << name2 << endl;

    // Input character array
    cout << "Enter your name: ";
    cin >> name3;  // Reads until whitespace
    cout << "Hello, " << name3 << "!" << endl;

    // Input with spaces
    char fullName[50];
    cin.ignore();  // Clear input buffer
    cout << "Enter your full name: ";
    cin.getline(fullName, 50);
    cout << "Full name: " << fullName << endl;

    // C-string functions
    char str1[50] = "Hello";
    char str2[50] = "World";
    char str3[100];

    // String length
    cout << "\nString lengths:" << endl;
    cout << "Length of str1: " << strlen(str1) << endl;
    cout << "Length of str2: " << strlen(str2) << endl;

    // String copy
    strcpy(str3, str1);
    cout << "After copying str1 to str3: " << str3 << endl;

    // String concatenation
    strcat(str3, " ");
    strcat(str3, str2);
    cout << "After concatenating: " << str3 << endl;

    // String comparison
    if (strcmp(str1, str2) == 0) {
        cout << "str1 and str2 are equal" << endl;
    } else if (strcmp(str1, str2) < 0) {
        cout << "str1 comes before str2 alphabetically" << endl;
    } else {
        cout << "str1 comes after str2 alphabetically" << endl;
    }

    // Character manipulation
    char sentence[] = "Hello World";
    cout << "\nOriginal: " << sentence << endl;

    // Convert to uppercase
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] >= 'a' && sentence[i] <= 'z') {
            sentence[i] = sentence[i] - 'a' + 'A';
        }
    }
    cout << "Uppercase: " << sentence << endl;

    return 0;
}
```

### 0.6.4 C++ String Class

**std::string Basics:**

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    // String creation and initialization
    string str1;                    // Empty string
    string str2 = "Hello";          // Initialization
    string str3("World");           // Constructor
    string str4(5, 'A');            // 5 A's: "AAAAA"
    string str5(str2);              // Copy constructor

    cout << "str1: '" << str1 << "'" << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    cout << "str4: " << str4 << endl;
    cout << "str5: " << str5 << endl;

    // String input
    string name;
    cout << "\nEnter your name: ";
    cin >> name;  // Reads until whitespace
    cout << "Hello, " << name << "!" << endl;

    // Input with spaces
    string fullSentence;
    cin.ignore();  // Clear input buffer
    cout << "Enter a sentence: ";
    getline(cin, fullSentence);
    cout << "You said: " << fullSentence << endl;

    // String properties
    cout << "\nString properties:" << endl;
    cout << "Length of str2: " << str2.length() << endl;
    cout << "Size of str2: " << str2.size() << endl;
    cout << "Is str1 empty? " << (str1.empty() ? "Yes" : "No") << endl;
    cout << "Capacity of str2: " << str2.capacity() << endl;

    return 0;
}
```

**String Operations:**

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string text = "Hello World";
    string word = "World";

    // String concatenation
    string greeting = "Hello";
    string name = "Alice";
    string message = greeting + ", " + name + "!";
    cout << "Concatenated string: " << message << endl;

    // Append operations
    string builder = "C++";
    builder += " is";
    builder.append(" awesome");
    builder.append(3, '!');  // Append 3 exclamation marks
    cout << "Built string: " << builder << endl;

    // Substring
    string original = "Programming";
    string sub = original.substr(3, 4);  // Starting at index 3, length 4
    cout << "Substring: " << sub << endl;

    // Find operations
    string sentence = "The quick brown fox jumps over the lazy dog";
    size_t pos = sentence.find("fox");
    if (pos != string::npos) {
        cout << "'fox' found at position: " << pos << endl;
    }

    // Find last occurrence
    pos = sentence.rfind("the");
    if (pos != string::npos) {
        cout << "Last 'the' found at position: " << pos << endl;
    }

    // Replace
    string replaceable = "I love Java programming";
    replaceable.replace(7, 4, "C++");  // Replace 4 chars starting at pos 7
    cout << "After replace: " << replaceable << endl;

    // Insert and erase
    string modifiable = "Hello World";
    modifiable.insert(5, " Beautiful");
    cout << "After insert: " << modifiable << endl;

    modifiable.erase(5, 10);  // Erase 10 chars starting at pos 5
    cout << "After erase: " << modifiable << endl;

    // Character access
    string chars = "Hello";
    cout << "First character: " << chars[0] << endl;
    cout << "Last character: " << chars.at(chars.length() - 1) << endl;
    cout << "Front: " << chars.front() << endl;
    cout << "Back: " << chars.back() << endl;

    // Modify characters
    chars[0] = 'h';  // Change to lowercase
    cout << "Modified: " << chars << endl;

    return 0;
}
```

**String Algorithms and Manipulation:**

```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    // Case conversion
    string text = "Hello World 123!";
    string uppercase = text;
    string lowercase = text;

    transform(uppercase.begin(), uppercase.end(), uppercase.begin(), ::toupper);
    transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::tolower);

    cout << "Original: " << text << endl;
    cout << "Uppercase: " << uppercase << endl;
    cout << "Lowercase: " << lowercase << endl;

    // Reverse string
    string reversible = "Hello World";
    reverse(reversible.begin(), reversible.end());
    cout << "Reversed: " << reversible << endl;

    // Palindrome check
    string word = "racecar";
    string temp = word;
    reverse(temp.begin(), temp.end());
    bool isPalindrome = (word == temp);
    cout << "'" << word << "' is " << (isPalindrome ? "" : "not ") << "a palindrome" << endl;

    // Count characters
    string sample = "programming";
    char target = 'r';
    int count = 0;
    for (char c : sample) {
        if (c == target) count++;
    }
    cout << "Character '" << target << "' appears " << count << " times in '" << sample << "'" << endl;

    // Count vowels
    string phrase = "Hello World";
    string vowels = "aeiouAEIOU";
    int vowelCount = 0;
    for (char c : phrase) {
        if (vowels.find(c) != string::npos) {
            vowelCount++;
        }
    }
    cout << "Number of vowels in '" << phrase << "': " << vowelCount << endl;

    // Remove spaces
    string spaced = "H e l l o   W o r l d";
    spaced.erase(remove(spaced.begin(), spaced.end(), ' '), spaced.end());
    cout << "After removing spaces: " << spaced << endl;

    // String comparison
    string str1 = "Apple";
    string str2 = "Banana";
    if (str1 < str2) {
        cout << str1 << " comes before " << str2 << " alphabetically" << endl;
    }

    // Sorting words
    string words[] = {"zebra", "apple", "banana", "cherry"};
    int numWords = 4;

    sort(words, words + numWords);
    cout << "Sorted words: ";
    for (int i = 0; i < numWords; i++) {
        cout << words[i] << " ";
    }
    cout << endl;

    // String tokenization (simple version)
    string csv = "apple,banana,cherry,date";
    size_t start = 0, end = 0;
    cout << "Tokens: ";
    while ((end = csv.find(',', start)) != string::npos) {
        cout << csv.substr(start, end - start) << " ";
        start = end + 1;
    }
    cout << csv.substr(start) << endl;  // Last token

    return 0;
}
```

**Output Example:**

```
Original: Hello World 123!
Uppercase: HELLO WORLD 123!
Lowercase: hello world 123!
Reversed: dlroW olleH
'racecar' is a palindrome
Character 'r' appears 2 times in 'programming'
Number of vowels in 'Hello World': 3
After removing spaces: HelloWorld
Apple comes before Banana alphabetically
Sorted words: apple banana cherry zebra
Tokens: apple banana cherry date
```

---

## Phase 0.7: C++ Memory Model

### 0.7.1 Stack vs Heap

**Understanding Memory Regions:**

```cpp
#include <iostream>
using namespace std;

// Global variables stored in data segment
int globalVar = 100;
static int staticGlobal = 200;

void demonstrateStack() {
    // Local variables stored on stack
    int localVar = 42;
    char localArray[100];

    cout << "\n--- Stack Memory ---" << endl;
    cout << "Address of localVar: " << &localVar << endl;
    cout << "Address of localArray: " << &localArray << endl;
    cout << "Value of localVar: " << localVar << endl;

    // Stack variables are automatically destroyed when function ends
}

void demonstrateHeap() {
    // Dynamic allocation - heap memory
    int* heapInt = new int(50);
    int* heapArray = new int[10];

    cout << "\n--- Heap Memory ---" << endl;
    cout << "Address of heapInt: " << heapInt << endl;
    cout << "Value at heapInt: " << *heapInt << endl;
    cout << "Address of heapArray: " << heapArray << endl;

    // Initialize heap array
    for (int i = 0; i < 10; i++) {
        heapArray[i] = i * i;
    }

    cout << "Heap array values: ";
    for (int i = 0; i < 10; i++) {
        cout << heapArray[i] << " ";
    }
    cout << endl;

    // Must manually free heap memory
    delete heapInt;
    delete[] heapArray;

    // Good practice: set pointers to null after deletion
    heapInt = nullptr;
    heapArray = nullptr;
}

int main() {
    cout << "=== C++ Memory Model Demonstration ===" << endl;

    // Local variables on stack
    int mainVar = 10;

    cout << "\n--- Global/Static Memory ---" << endl;
    cout << "Address of globalVar: " << &globalVar << endl;
    cout << "Address of staticGlobal: " << &staticGlobal << endl;
    cout << "Value of globalVar: " << globalVar << endl;
    cout << "Value of staticGlobal: " << staticGlobal << endl;

    cout << "\n--- Main Function Stack ---" << endl;
    cout << "Address of mainVar: " << &mainVar << endl;
    cout << "Value of mainVar: " << mainVar << endl;

    demonstrateStack();
    demonstrateHeap();

    // Memory layout comparison
    cout << "\n--- Memory Layout Comparison ---" << endl;
    cout << "Global variable address: " << &globalVar << endl;
    cout << "Local variable address: " << &mainVar << endl;

    int* dynamicVar = new int(99);
    cout << "Heap variable address: " << dynamicVar << endl;

    delete dynamicVar;

    return 0;
}
```

**Stack Growth and Function Calls:**

```cpp
#include <iostream>
using namespace std;

void recursiveFunction(int level, int maxLevel) {
    int localVar = level * 10;

    cout << "Level " << level << " - Address of localVar: " << &localVar
         << " - Value: " << localVar << endl;

    if (level < maxLevel) {
        recursiveFunction(level + 1, maxLevel);
    }

    cout << "Returning from level " << level << endl;
}

void demonstrateStackFrames() {
    cout << "\n--- Stack Frame Demonstration ---" << endl;

    int mainLocal = 100;
    cout << "Main function - Address of mainLocal: " << &mainLocal << endl;

    recursiveFunction(1, 3);

    cout << "Back in main - mainLocal still exists: " << mainLocal << endl;
}

int main() {
    demonstrateStackFrames();
    return 0;
}
```

### 0.7.2 sizeof and alignof

**Memory Size and Alignment:**

```cpp
#include <iostream>
#include <cstddef>  // For size_t
using namespace std;

// Structure for alignment demonstration
struct SimpleStruct {
    char c;      // 1 byte
    int i;       // 4 bytes
    double d;    // 8 bytes
};

struct PackedStruct {
    char c1;     // 1 byte
    char c2;     // 1 byte
    short s;     // 2 bytes
    int i;       // 4 bytes
};

// Aligned structure
struct alignas(16) AlignedStruct {
    char c;
    int i;
};

int main() {
    cout << "=== sizeof Operator ===" << endl;

    // Basic data types
    cout << "Basic Data Types:" << endl;
    cout << "sizeof(char): " << sizeof(char) << " byte(s)" << endl;
    cout << "sizeof(short): " << sizeof(short) << " byte(s)" << endl;
    cout << "sizeof(int): " << sizeof(int) << " byte(s)" << endl;
    cout << "sizeof(long): " << sizeof(long) << " byte(s)" << endl;
    cout << "sizeof(long long): " << sizeof(long long) << " byte(s)" << endl;
    cout << "sizeof(float): " << sizeof(float) << " byte(s)" << endl;
    cout << "sizeof(double): " << sizeof(double) << " byte(s)" << endl;
    cout << "sizeof(long double): " << sizeof(long double) << " byte(s)" << endl;
    cout << "sizeof(bool): " << sizeof(bool) << " byte(s)" << endl;
    cout << "sizeof(void*): " << sizeof(void*) << " byte(s)" << endl;

    // Arrays
    cout << "\nArrays:" << endl;
    int arr[10];
    char str[50];
    cout << "sizeof(int[10]): " << sizeof(arr) << " byte(s)" << endl;
    cout << "sizeof(char[50]): " << sizeof(str) << " byte(s)" << endl;
    cout << "Elements in int array: " << sizeof(arr) / sizeof(arr[0]) << endl;

    // Structures
    cout << "\nStructures:" << endl;
    cout << "sizeof(SimpleStruct): " << sizeof(SimpleStruct) << " byte(s)" << endl;
    cout << "sizeof(PackedStruct): " << sizeof(PackedStruct) << " byte(s)" << endl;
    cout << "sizeof(AlignedStruct): " << sizeof(AlignedStruct) << " byte(s)" << endl;

    // Memory alignment
    cout << "\n=== alignof Operator ===" << endl;
    cout << "alignof(char): " << alignof(char) << " byte(s)" << endl;
    cout << "alignof(int): " << alignof(int) << " byte(s)" << endl;
    cout << "alignof(double): " << alignof(double) << " byte(s)" << endl;
    cout << "alignof(SimpleStruct): " << alignof(SimpleStruct) << " byte(s)" << endl;
    cout << "alignof(AlignedStruct): " << alignof(AlignedStruct) << " byte(s)" << endl;

    // Structure member offsets
    cout << "\n=== Structure Layout ===" << endl;
    cout << "SimpleStruct layout:" << endl;
    cout << "Offset of c: " << offsetof(SimpleStruct, c) << endl;
    cout << "Offset of i: " << offsetof(SimpleStruct, i) << endl;
    cout << "Offset of d: " << offsetof(SimpleStruct, d) << endl;

    // Demonstrate padding
    SimpleStruct s;
    cout << "\nActual addresses:" << endl;
    cout << "Address of s: " << &s << endl;
    cout << "Address of s.c: " << &s.c << endl;
    cout << "Address of s.i: " << &s.i << endl;
    cout << "Address of s.d: " << &s.d << endl;

    return 0;
}
```

**Typical Output:**

```
=== sizeof Operator ===
Basic Data Types:
sizeof(char): 1 byte(s)
sizeof(short): 2 byte(s)
sizeof(int): 4 byte(s)
sizeof(long): 4 byte(s)
sizeof(long long): 8 byte(s)
sizeof(float): 4 byte(s)
sizeof(double): 8 byte(s)
sizeof(long double): 8 byte(s)
sizeof(bool): 1 byte(s)
sizeof(void*): 8 byte(s)

Arrays:
sizeof(int[10]): 40 byte(s)
sizeof(char[50]): 50 byte(s)
Elements in int array: 10

Structures:
sizeof(SimpleStruct): 16 byte(s)
sizeof(PackedStruct): 8 byte(s)
sizeof(AlignedStruct): 16 byte(s)

=== alignof Operator ===
alignof(char): 1 byte(s)
alignof(int): 4 byte(s)
alignof(double): 8 byte(s)
alignof(SimpleStruct): 8 byte(s)
alignof(AlignedStruct): 16 byte(s)
```

### 0.7.3 malloc/free vs new/delete

**Memory Allocation Comparison:**

```cpp
#include <iostream>
#include <cstdlib>  // For malloc, free
#include <cstring>  // For memset
using namespace std;

class TestClass {
public:
    int value;

    TestClass() : value(42) {
        cout << "TestClass constructor called, value = " << value << endl;
    }

    TestClass(int v) : value(v) {
        cout << "TestClass constructor called with value = " << value << endl;
    }

    ~TestClass() {
        cout << "TestClass destructor called, value = " << value << endl;
    }
};

int main() {
    cout << "=== malloc/free vs new/delete ===" << endl;

    // C-style memory allocation
    cout << "\n--- Using malloc/free ---" << endl;

    // Allocate memory for integers
    int* mallocInt = (int*)malloc(sizeof(int));
    if (mallocInt != nullptr) {
        *mallocInt = 100;
        cout << "malloc'd integer: " << *mallocInt << endl;
        free(mallocInt);
        mallocInt = nullptr;
    }

    // Allocate array using malloc
    int* mallocArray = (int*)malloc(5 * sizeof(int));
    if (mallocArray != nullptr) {
        // Initialize array
        for (int i = 0; i < 5; i++) {
            mallocArray[i] = i * 10;
        }

        cout << "malloc'd array: ";
        for (int i = 0; i < 5; i++) {
            cout << mallocArray[i] << " ";
        }
        cout << endl;

        free(mallocArray);
        mallocArray = nullptr;
    }

    // C++ style memory allocation
    cout << "\n--- Using new/delete ---" << endl;

    // Allocate single integer
    int* newInt = new int(200);
    cout << "new'd integer: " << *newInt << endl;
    delete newInt;
    newInt = nullptr;

    // Allocate array using new
    int* newArray = new int[5]{10, 20, 30, 40, 50};
    cout << "new'd array: ";
    for (int i = 0; i < 5; i++) {
        cout << newArray[i] << " ";
    }
    cout << endl;
    delete[] newArray;
    newArray = nullptr;

    // Object allocation - shows constructor/destructor calls
    cout << "\n--- Object Allocation ---" << endl;

    // malloc doesn't call constructor
    cout << "Using malloc for object (BAD PRACTICE):" << endl;
    TestClass* mallocObj = (TestClass*)malloc(sizeof(TestClass));
    if (mallocObj != nullptr) {
        // Value is garbage because constructor wasn't called
        cout << "malloc'd object value (garbage): " << mallocObj->value << endl;
        free(mallocObj);  // Destructor not called
    }

    // new calls constructor, delete calls destructor
    cout << "\nUsing new for object (CORRECT):" << endl;
    TestClass* newObj = new TestClass(500);
    cout << "new'd object value: " << newObj->value << endl;
    delete newObj;  // Destructor called

    // Array of objects
    cout << "\nArray of objects:" << endl;
    TestClass* objArray = new TestClass[3];
    delete[] objArray;  // All destructors called

    return 0;
}
```

### 0.7.4 Memory Leaks and Dangling Pointers

**Common Memory Problems:**

```cpp
#include <iostream>
using namespace std;

// Memory leak examples
void memoryLeakExamples() {
    cout << "\n=== Memory Leak Examples ===" << endl;

    // Memory leak 1: Forgot to delete
    cout << "Creating memory leak..." << endl;
    int* leak1 = new int(100);
    // Forgot: delete leak1;  <-- MEMORY LEAK!

    // Memory leak 2: Exception safety
    cout << "Exception safety issue..." << endl;
    int* leak2 = new int[1000];
    // If exception occurs here, memory is leaked
    // throw runtime_error("Oops!");  // Uncomment to see leak
    delete[] leak2;  // This might not be reached

    // Memory leak 3: Overwriting pointer
    cout << "Overwriting pointer..." << endl;
    int* ptr = new int(50);
    ptr = new int(75);  // Lost reference to first allocation - LEAK!
    delete ptr;  // Only deletes second allocation

    // Memory leak 4: Lost pointer in function
    auto createArray = []() -> int* {
        return new int[100];  // Caller must remember to delete
    };

    int* arrayPtr = createArray();
    // If we forget to delete arrayPtr, it's a leak
    delete[] arrayPtr;
}

// Dangling pointer examples
void danglingPointerExamples() {
    cout << "\n=== Dangling Pointer Examples ===" << endl;

    // Dangling pointer 1: Double delete
    cout << "Double delete scenario..." << endl;
    int* ptr1 = new int(42);
    int* ptr2 = ptr1;  // Two pointers to same memory

    delete ptr1;
    ptr1 = nullptr;  // Good practice

    // ptr2 is now dangling!
    // cout << *ptr2;  // UNDEFINED BEHAVIOR!
    // delete ptr2;    // UNDEFINED BEHAVIOR - double delete!

    ptr2 = nullptr;  // Fix the dangling pointer

    // Dangling pointer 2: Returning local address
    auto getBadPointer = []() -> int* {
        int local = 100;
        return &local;  // BAD! Returns address of local variable
    };

    // int* dangling = getBadPointer();  // Dangling pointer
    // cout << *dangling;  // UNDEFINED BEHAVIOR!

    // Dangling pointer 3: Using freed memory
    cout << "Using freed memory..." << endl;
    char* buffer = new char[100];
    strcpy(buffer, "Hello");

    delete[] buffer;
    buffer = nullptr;  // Prevent accidental use

    // cout << buffer[0];  // Would be undefined behavior if we didn't null it
}

// Solutions and best practices
void bestPractices() {
    cout << "\n=== Best Practices ===" << endl;

    // RAII (Resource Acquisition Is Initialization)
    class SafeArray {
    private:
        int* data;
        size_t size;

    public:
        SafeArray(size_t s) : size(s) {
            data = new int[size];
            cout << "SafeArray allocated " << size << " integers" << endl;
        }

        ~SafeArray() {
            delete[] data;
            cout << "SafeArray deallocated" << endl;
        }

        int& operator[](size_t index) {
            return data[index];
        }

        size_t getSize() const { return size; }
    };

    {
        SafeArray arr(10);
        for (size_t i = 0; i < arr.getSize(); i++) {
            arr[i] = i * i;
        }
        // arr is automatically destroyed here - no memory leak!
    }

    // Smart pointers preview
    cout << "\nSmart pointer preview..." << endl;
    {
        unique_ptr<int> smartPtr = make_unique<int>(42);
        cout << "Smart pointer value: " << *smartPtr << endl;
        // Automatically cleaned up - no explicit delete needed!
    }

    // Always pair new with delete
    cout << "\nProper pairing..." << endl;
    int* properPtr = new int(100);
    cout << "Proper allocation: " << *properPtr << endl;
    delete properPtr;
    properPtr = nullptr;

    int* properArray = new int[5];
    delete[] properArray;  // Note: delete[] for arrays
    properArray = nullptr;
}

int main() {
    memoryLeakExamples();
    danglingPointerExamples();
    bestPractices();

    cout << "\n=== Memory Management Summary ===" << endl;
    cout << "1. Always pair new with delete, new[] with delete[]" << endl;
    cout << "2. Set pointers to nullptr after deletion" << endl;
    cout << "3. Use RAII and smart pointers when possible" << endl;
    cout << "4. Be careful with exception safety" << endl;
    cout << "5. Don't return addresses of local variables" << endl;

    return 0;
}
```

---

## Phase 0.8: Storage Classes

### 0.8.1 Auto Storage Class

**Auto Keyword:**

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    cout << "=== Auto Storage Class ===" << endl;

    // Traditional variable declarations
    int traditionalInt = 42;
    double traditionalDouble = 3.14;
    string traditionalString = "Hello";

    // Auto keyword - type deduction (C++11)
    auto autoInt = 42;              // Deduced as int
    auto autoDouble = 3.14;         // Deduced as double
    auto autoString = "Hello";      // Deduced as const char*
    auto autoStringClass = string("Hello");  // Deduced as string

    cout << "Auto type deduction:" << endl;
    cout << "autoInt: " << autoInt << " (size: " << sizeof(autoInt) << ")" << endl;
    cout << "autoDouble: " << autoDouble << " (size: " << sizeof(autoDouble) << ")" << endl;
    cout << "autoString: " << autoString << " (size: " << sizeof(autoString) << ")" << endl;

    // Auto with complex types
    vector<int> numbers = {1, 2, 3, 4, 5};
    auto autoVector = numbers;      // Deduced as vector<int>

    // Auto with iterators
    auto it = numbers.begin();      // Deduced as vector<int>::iterator
    cout << "First element via auto iterator: " << *it << endl;

    // Auto with function return types
    auto lambda = [](int x, int y) -> int { return x + y; };
    auto result = lambda(5, 3);     // Deduced as int
    cout << "Lambda result: " << result << endl;

    // Auto with references
    int value = 100;
    auto& autoRef = value;          // Reference to int
    autoRef = 200;
    cout << "Modified value through auto reference: " << value << endl;

    // Auto with const
    const auto constAuto = 42;      // const int
    // constAuto = 50;              // Error! Cannot modify const

    // Auto in range-based for loops
    cout << "Range-based for with auto: ";
    for (auto element : numbers) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
```

### 0.8.2 Static Storage Class

**Static Variables and Functions:**

```cpp
#include <iostream>
using namespace std;

// Static global variable - internal linkage
static int staticGlobal = 100;

// Function with static local variable
void countCalls() {
    static int callCount = 0;  // Initialized only once
    callCount++;
    cout << "Function called " << callCount << " times" << endl;
}

// Static function - internal linkage
static void staticFunction() {
    cout << "This is a static function" << endl;
}

class Counter {
private:
    static int objectCount;  // Declaration of static member
    int id;

public:
    Counter() {
        objectCount++;
        id = objectCount;
        cout << "Counter object " << id << " created. Total objects: " << objectCount << endl;
    }

    ~Counter() {
        cout << "Counter object " << id << " destroyed" << endl;
    }

    static int getObjectCount() {  // Static member function
        return objectCount;
    }

    void showInfo() {
        cout << "Object ID: " << id << ", Total objects: " << objectCount << endl;
    }
};

// Definition of static member variable
int Counter::objectCount = 0;

int main() {
    cout << "=== Static Storage Class ===" << endl;

    // Static local variable demonstration
    cout << "\n--- Static Local Variable ---" << endl;
    for (int i = 0; i < 5; i++) {
        countCalls();
    }

    // Static global variable
    cout << "\n--- Static Global Variable ---" << endl;
    cout << "Static global value: " << staticGlobal << endl;
    staticGlobal = 200;
    cout << "Modified static global: " << staticGlobal << endl;

    // Static function
    cout << "\n--- Static Function ---" << endl;
    staticFunction();

    // Static class members
    cout << "\n--- Static Class Members ---" << endl;
    cout << "Initial object count: " << Counter::getObjectCount() << endl;

    {
        Counter obj1;
        Counter obj2;
        obj1.showInfo();
        obj2.showInfo();
        cout << "Object count from static function: " << Counter::getObjectCount() << endl;
    }  // Objects destroyed here

    cout << "Object count after destruction: " << Counter::getObjectCount() << endl;

    return 0;
}
```

### 0.8.3 Extern Storage Class

**File1.cpp (External definitions):**

```cpp
// This would be in a separate file (File1.cpp)
// For demonstration, we'll show the concept in comments

/*
#include <iostream>
using namespace std;

// Global variables defined here
int globalVar = 42;
double globalDouble = 3.14;

// Function defined here
void externalFunction() {
    cout << "This function is defined in another file" << endl;
}
*/
```

**Main file demonstrating extern:**

```cpp
#include <iostream>
using namespace std;

// External declarations - these are defined elsewhere
// extern int globalVar;        // Would be defined in File1.cpp
// extern double globalDouble;  // Would be defined in File1.cpp
// extern void externalFunction(); // Would be defined in File1.cpp

// For this example, we'll define them here
int globalVar = 42;
double globalDouble = 3.14;

void externalFunction() {
    cout << "This function demonstrates external linkage" << endl;
}

// Extern with C linkage
extern "C" {
    void cStyleFunction() {
        cout << "C-style function with C linkage" << endl;
    }
}

void demonstrateExtern() {
    cout << "\n=== Extern Storage Class ===" << endl;

    cout << "External global variable: " << globalVar << endl;
    cout << "External global double: " << globalDouble << endl;

    externalFunction();
    cStyleFunction();

    // Extern in block scope
    {
        extern int globalVar;  // Refers to the global variable
        cout << "Accessing global var from block scope: " << globalVar << endl;
        globalVar = 100;  // Modifies the global variable
    }

    cout << "Global var after modification: " << globalVar << endl;
}

int main() {
    demonstrateExtern();
    return 0;
}
```

### 0.8.4 Register Storage Class (Deprecated)

**Register Keyword (Mostly Historical):**

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "=== Register Storage Class (Deprecated) ===" << endl;

    // Register keyword - hint to compiler to store in CPU register
    // Modern compilers ignore this hint and optimize automatically
    register int fastVar = 42;

    cout << "Register variable: " << fastVar << endl;

    // Note: Cannot take address of register variable
    // cout << "Address: " << &fastVar;  // Error in older C++

    // Modern approach: let compiler optimize
    int optimizedVar = 100;
    cout << "Compiler-optimized variable: " << optimizedVar << endl;

    cout << "\nNote: 'register' keyword is deprecated in modern C++" << endl;
    cout << "Compilers are better at optimization than manual hints" << endl;

    return 0;
}
```

### 0.8.5 Mutable Storage Class

**Mutable Keyword:**

```cpp
#include <iostream>
#include <string>
using namespace std;

class CacheableData {
private:
    string data;
    mutable bool cached;        // Can be modified in const functions
    mutable string cachedResult; // Can be modified in const functions

public:
    CacheableData(const string& d) : data(d), cached(false) {}

    // Const function that can modify mutable members
    string getProcessedData() const {
        if (!cached) {
            // Expensive operation simulation
            cachedResult = "Processed: " + data;
            cached = true;
            cout << "Data processed and cached" << endl;
        } else {
            cout << "Returning cached data" << endl;
        }
        return cachedResult;
    }

    void setData(const string& newData) {
        data = newData;
        cached = false;  // Invalidate cache
    }

    // Const function accessing mutable member
    bool isCached() const {
        return cached;
    }
};

// Another example with mutable
class Counter {
private:
    int value;
    mutable int accessCount;  // Tracks how many times value is accessed

public:
    Counter(int v) : value(v), accessCount(0) {}

    int getValue() const {
        accessCount++;  // Allowed because accessCount is mutable
        return value;
    }

    int getAccessCount() const {
        return accessCount;
    }

    void setValue(int v) {
        value = v;
    }
};

int main() {
    cout << "=== Mutable Storage Class ===" << endl;

    // Cacheable data example
    cout << "\n--- Cacheable Data Example ---" << endl;
    const CacheableData data("Hello World");

    cout << "First access: " << data.getProcessedData() << endl;
    cout << "Second access: " << data.getProcessedData() << endl;
    cout << "Is cached: " << (data.isCached() ? "Yes" : "No") << endl;

    // Counter example
    cout << "\n--- Counter Example ---" << endl;
    const Counter counter(42);  // const object

    cout << "Value: " << counter.getValue() << endl;
    cout << "Value: " << counter.getValue() << endl;
    cout << "Value: " << counter.getValue() << endl;

    cout << "Access count: " << counter.getAccessCount() << endl;

    // Lambda with mutable
    cout << "\n--- Mutable in Lambda ---" << endl;
    int x = 10;
    auto lambda = [x]() mutable -> int {
        x++;  // Allowed because of mutable
        return x;
    };

    cout << "Original x: " << x << endl;
    cout << "Lambda call 1: " << lambda() << endl;
    cout << "Lambda call 2: " << lambda() << endl;
    cout << "Original x after lambda calls: " << x << endl;

    return 0;
}
```

### 0.8.6 Scope and Lifetime

**Variable Scope and Lifetime Demonstration:**

```cpp
#include <iostream>
using namespace std;

// Global scope - program lifetime
int globalVariable = 100;
static int staticGlobal = 200;

void demonstrateScope() {
    cout << "\n=== Scope and Lifetime ===" << endl;

    // Local scope - function lifetime
    int localVar = 10;
    static int staticLocal = 0;  // Program lifetime, function scope

    staticLocal++;

    cout << "Local variable: " << localVar << endl;
    cout << "Static local (call #): " << staticLocal << endl;

    // Block scope
    {
        int blockVar = 20;       // Block lifetime
        int localVar = 30;       // Shadows function's localVar

        cout << "Block variable: " << blockVar << endl;
        cout << "Shadowed local variable: " << localVar << endl;
        cout << "Global variable: " << globalVariable << endl;

        // Inner block
        {
            int innerVar = 40;
            cout << "Inner block variable: " << innerVar << endl;
        }
        // innerVar is destroyed here

    }
    // blockVar is destroyed here

    cout << "Function's local variable: " << localVar << endl;

    // Loop scope
    for (int i = 0; i < 3; i++) {
        int loopVar = i * 10;
        cout << "Loop iteration " << i << ", loopVar: " << loopVar << endl;
    }
    // i and loopVar are destroyed after loop
}

class ScopeDemo {
private:
    int memberVar;
    static int staticMember;

public:
    ScopeDemo(int value) : memberVar(value) {
        staticMember++;
        cout << "Object created with memberVar = " << memberVar
             << ", total objects = " << staticMember << endl;
    }

    ~ScopeDemo() {
        cout << "Object with memberVar = " << memberVar << " destroyed" << endl;
        staticMember--;
    }

    void showScopes() {
        cout << "Member variable: " << memberVar << endl;
        cout << "Static member: " << staticMember << endl;
        cout << "Global variable: " << globalVariable << endl;

        // Local variable shadows member variable
        int memberVar = 999;
        cout << "Local memberVar (shadows member): " << memberVar << endl;
        cout << "Actual member variable: " << this->memberVar << endl;
    }

    static void staticFunction() {
        cout << "Static function - can access static member: " << staticMember << endl;
        // cout << memberVar;  // Error! Cannot access non-static member
    }
};

int ScopeDemo::staticMember = 0;

int main() {
    cout << "=== Storage Classes and Scope Demonstration ===" << endl;

    cout << "Global variable at start: " << globalVariable << endl;

    // Function calls to show static local behavior
    demonstrateScope();
    demonstrateScope();
    demonstrateScope();

    // Object lifetime and scope
    cout << "\n--- Object Lifetime ---" << endl;
    {
        ScopeDemo obj1(10);
        ScopeDemo obj2(20);

        obj1.showScopes();
        ScopeDemo::staticFunction();
    }
    // Objects destroyed here

    ScopeDemo::staticFunction();

    // Variable shadowing example
    cout << "\n--- Variable Shadowing ---" << endl;
    int x = 1;
    cout << "Outer x: " << x << endl;

    {
        int x = 2;  // Shadows outer x
        cout << "Inner x: " << x << endl;

        {
            int x = 3;  // Shadows both outer x's
            cout << "Innermost x: " << x << endl;
        }

        cout << "Back to inner x: " << x << endl;
    }

    cout << "Back to outer x: " << x << endl;

    return 0;
}
```

**Output Example:**

```
=== Storage Classes and Scope Demonstration ===
Global variable at start: 100

=== Scope and Lifetime ===
Local variable: 10
Static local (call #): 1
Block variable: 20
Shadowed local variable: 30
Global variable: 100
Inner block variable: 40
Function's local variable: 10
Loop iteration 0, loopVar: 0
Loop iteration 1, loopVar: 10
Loop iteration 2, loopVar: 20

=== Scope and Lifetime ===
Local variable: 10
Static local (call #): 2
...

--- Object Lifetime ---
Object created with memberVar = 10, total objects = 1
Object created with memberVar = 20, total objects = 2
Member variable: 10
Static member: 2
Global variable: 100
Local memberVar (shadows member): 999
Actual member variable: 10
Static function - can access static member: 2
Object with memberVar = 10 destroyed
Object with memberVar = 20 destroyed
Static function - can access static member: 0
```

---

# 🎉 Phase 0 Complete!

Congratulations! You have successfully completed **Phase 0: Core C++ Foundations**. You now have a solid understanding of:

✅ **C++ Program Structure** - Headers, namespaces, main function  
✅ **Data Types & Variables** - Fundamental types, constants, type casting  
✅ **Operators** - Arithmetic, logical, bitwise, assignment operators  
✅ **Control Flow** - Conditionals, loops, break/continue, goto  
✅ **Functions** - Declaration, definition, overloading, parameter passing, recursion  
✅ **Pointers & References** - Memory addresses, dynamic allocation, smart pointers  
✅ **Arrays & Strings** - 1D/2D arrays, C-strings, std::string manipulation  
✅ **Memory Model** - Stack vs heap, sizeof/alignof, memory management  
✅ **Storage Classes** - auto, static, extern, mutable, scope, and lifetime

## What's Next?

You're now ready to move on to **Phase 1: Object-Oriented Programming Core** where you'll learn:

- Classes and Objects
- Constructors and Destructors
- Inheritance and Polymorphism
- Encapsulation and Abstraction
- Operator Overloading
- Virtual Functions

## Practice Recommendations

1. **Implement the examples** - Type out and run every code example
2. **Modify and experiment** - Change values, add features, break things (safely!)
3. **Create small projects** - Calculator, text processor, simple games
4. **Solve problems** - Practice with arrays, strings, and memory management
5. **Read error messages** - Understanding compiler errors is crucial

Keep practicing and experimenting with these concepts before moving to OOP. Strong foundations in Phase 0 will make Phase 1 much easier to understand and master!

---
