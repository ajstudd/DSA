# Comprehensive Stack Data Structure Tutorial

## From Basics to Advanced Applications

---

## Table of Contents

1. [Introduction to Stack](#introduction-to-stack)
2. [Core Stack Structure (Custom Implementation)](#core-stack-structure)
3. [STL Stack Implementation](#stl-stack-implementation)
4. [Basic Stack Operations](#basic-stack-operations)
5. [Uses of Stack Data Structure](#uses-of-stack)
6. [Stack Applications](#stack-applications)
7. [Monotonic Stack](#monotonic-stack)
8. [Expression Evaluation](#expression-evaluation)
9. [Recursion and Stack](#recursion-and-stack)
10. [Advanced Stack Problems](#advanced-stack-problems)
11. [More Practice Problems](#more-practice-problems)
12. [Real-World Applications](#real-world-applications)
13. [Time and Space Complexity Analysis](#complexity-analysis)

---

## Introduction to Stack

A **Stack** is a linear data structure that follows the **Last In First Out (LIFO)** principle. Think of it like a stack of plates - you can only add or remove plates from the top.

### Key Characteristics:

- **LIFO Ordering**: Last element added is the first one to be removed
- **Restricted Access**: Elements can only be accessed from one end (top)
- **Dynamic Size**: Can grow and shrink during runtime
- **Homogeneous**: Stores elements of the same data type

### Stack Visualization

```mermaid
graph TD
    A[Stack Visualization] --> B[Top of Stack]
    B --> C[Element 3 - Last Added]
    C --> D[Element 2]
    D --> E[Element 1]
    E --> F[Bottom of Stack - First Added]

    G[Operations] --> H[PUSH - Add to Top]
    G --> I[POP - Remove from Top]
    G --> J[TOP/PEEK - View Top Element]
    G --> K[EMPTY - Check if Stack is Empty]
```

---

## Core Stack Structure (Custom Implementation)

Before using STL, let's understand how a stack works internally by implementing our own stack class.

### Array-Based Stack Implementation

```cpp
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;           // Dynamic array to store stack elements
    int topIndex;     // Index of the top element
    int capacity;     // Maximum capacity of the stack

    // Helper function to resize the stack when full
    void resize() {
        int newCapacity = capacity * 2;
        T* newArr = new T[newCapacity];

        // Copy existing elements to new array
        for (int i = 0; i <= topIndex; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    // Constructor: Initialize empty stack with given capacity
    Stack(int initialCapacity = 10) {
        capacity = initialCapacity;
        arr = new T[capacity];
        topIndex = -1;  // -1 indicates empty stack
    }

    // Destructor: Clean up dynamic memory
    ~Stack() {
        delete[] arr;
    }

    // Push operation: Add element to top of stack
    void push(const T& element) {
        // Resize if stack is full
        if (topIndex == capacity - 1) {
            resize();
        }
        arr[++topIndex] = element;
    }

    // Pop operation: Remove and return top element
    T pop() {
        if (isEmpty()) {
            throw runtime_error("Stack Underflow: Cannot pop from empty stack");
        }
        return arr[topIndex--];
    }

    // Top/Peek operation: Return top element without removing
    T top() const {
        if (isEmpty()) {
            throw runtime_error("Stack is empty: No top element");
        }
        return arr[topIndex];
    }

    // Check if stack is empty
    bool isEmpty() const {
        return topIndex == -1;
    }

    // Get current size of stack
    int size() const {
        return topIndex + 1;
    }

    // Display stack contents (for debugging)
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack contents (top to bottom): ";
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Example usage of custom stack
void demonstrateCustomStack() {
    Stack<int> myStack;

    // Push elements
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "After pushing 10, 20, 30:" << endl;
    myStack.display();

    // Access top element
    cout << "Top element: " << myStack.top() << endl;

    // Pop elements
    cout << "Popped: " << myStack.pop() << endl;
    cout << "Popped: " << myStack.pop() << endl;

    cout << "After popping twice:" << endl;
    myStack.display();
}
```

### Linked List-Based Stack Implementation

```cpp
#include <iostream>
using namespace std;

template <typename T>
class LinkedStack {
private:
    // Node structure for linked list implementation
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* topNode;    // Pointer to top node
    int stackSize;    // Current size of stack

public:
    // Constructor: Initialize empty stack
    LinkedStack() : topNode(nullptr), stackSize(0) {}

    // Destructor: Clean up all nodes
    ~LinkedStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Push operation: Add new node at the beginning
    void push(const T& element) {
        Node* newNode = new Node(element);
        newNode->next = topNode;
        topNode = newNode;
        stackSize++;
    }

    // Pop operation: Remove and return top element
    T pop() {
        if (isEmpty()) {
            throw runtime_error("Stack Underflow: Cannot pop from empty stack");
        }

        Node* nodeToDelete = topNode;
        T data = topNode->data;
        topNode = topNode->next;
        delete nodeToDelete;
        stackSize--;

        return data;
    }

    // Top operation: Return top element without removing
    T top() const {
        if (isEmpty()) {
            throw runtime_error("Stack is empty: No top element");
        }
        return topNode->data;
    }

    // Check if stack is empty
    bool isEmpty() const {
        return topNode == nullptr;
    }

    // Get current size
    int size() const {
        return stackSize;
    }

    // Display stack contents
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack contents (top to bottom): ";
        Node* current = topNode;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
```

---

## STL Stack Implementation

C++ Standard Template Library provides a ready-to-use stack container that we'll use for solving DSA problems.

```cpp
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void demonstrateSTLStack() {
    // Creating stacks of different types
    stack<int> intStack;
    stack<string> stringStack;
    stack<char> charStack;

    // Basic operations with STL stack
    cout << "=== STL Stack Demonstration ===" << endl;

    // Push operations
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    cout << "Stack size: " << intStack.size() << endl;
    cout << "Top element: " << intStack.top() << endl;

    // Pop operations
    while (!intStack.empty()) {
        cout << "Popping: " << intStack.top() << endl;
        intStack.pop();
    }

    cout << "Stack is now empty: " << (intStack.empty() ? "Yes" : "No") << endl;
}

// STL Stack with custom objects
struct Person {
    string name;
    int age;

    Person(string n, int a) : name(n), age(a) {}
};

void stackWithCustomObjects() {
    stack<Person> peopleStack;

    peopleStack.push(Person("Alice", 25));
    peopleStack.push(Person("Bob", 30));
    peopleStack.push(Person("Charlie", 35));

    cout << "=== Stack with Custom Objects ===" << endl;
    while (!peopleStack.empty()) {
        Person p = peopleStack.top();
        cout << "Name: " << p.name << ", Age: " << p.age << endl;
        peopleStack.pop();
    }
}
```

---

## Basic Stack Operations

### Operation Flow Diagram

```mermaid
flowchart TD
    A[Start] --> B{Stack Operation?}
    B -->|PUSH| C[Check if stack is full]
    B -->|POP| G[Check if stack is empty]
    B -->|TOP/PEEK| K[Check if stack is empty]
    B -->|EMPTY| N[Return topIndex == -1]

    C -->|Full| D[Resize/Throw Error]
    C -->|Not Full| E[Add element at ++topIndex]
    D --> E
    E --> F[Operation Complete]

    G -->|Empty| H[Throw Underflow Error]
    G -->|Not Empty| I[Return arr topIndex]
    I --> J[Decrement topIndex]
    J --> F

    K -->|Empty| L[Throw Error]
    K -->|Not Empty| M[Return arr topIndex]
    M --> F

    N --> F
    F --> O[End]
```

### Time Complexity Analysis

| Operation | Array Implementation | Linked List Implementation |
| --------- | -------------------- | -------------------------- |
| Push      | O(1) amortized\*     | O(1)                       |
| Pop       | O(1)                 | O(1)                       |
| Top/Peek  | O(1)                 | O(1)                       |
| Empty     | O(1)                 | O(1)                       |
| Size      | O(1)                 | O(1)                       |

\*Amortized because of occasional resizing

---

## Uses of Stack Data Structure

Stack is one of the most fundamental data structures with wide-ranging applications across computer science. Understanding when and why to use stacks is crucial for solving complex problems efficiently.

```mermaid
graph TD
    A[Stack Applications] --> B[System Level]
    A --> C[Algorithm Design]
    A --> D[Software Engineering]
    A --> E[Mathematical Computing]

    B --> B1[Function Call Management]
    B --> B2[Memory Management]
    B --> B3[Operating System Tasks]
    B --> B4[Compiler Design]

    C --> C1[Expression Evaluation]
    C --> C2[Tree Traversal]
    C --> C3[Graph Algorithms DFS]
    C --> C4[Backtracking Problems]

    D --> D1[Undo/Redo Operations]
    D --> D2[Browser History]
    D --> D3[Syntax Checking]
    D --> D4[Code Parsing]

    E --> E1[Arithmetic Operations]
    E --> E2[Function Composition]
    E --> E3[Recursion Simulation]
    E --> E4[Mathematical Notation]

    style A fill:#f9f,stroke:#333,stroke-width:4px
    style B fill:#bbf,stroke:#333,stroke-width:2px
    style C fill:#bfb,stroke:#333,stroke-width:2px
    style D fill:#ffb,stroke:#333,stroke-width:2px
    style E fill:#fbb,stroke:#333,stroke-width:2px
```

### 1. System Level Applications

#### Function Call Management

Every programming language uses a call stack to manage function calls, local variables, and return addresses.

```cpp
// Example: How function calls use stack internally
void functionC() {
    int localVar = 30;
    cout << "In Function C" << endl;
    // Stack: [main, functionA, functionB, functionC]
}

void functionB() {
    int localVar = 20;
    cout << "In Function B" << endl;
    functionC();  // Push functionC onto call stack
    // functionC completes, stack becomes: [main, functionA, functionB]
}

void functionA() {
    int localVar = 10;
    cout << "In Function A" << endl;
    functionB();  // Push functionB onto call stack
    // functionB completes, stack becomes: [main, functionA]
}

int main() {
    cout << "In Main" << endl;
    functionA();  // Push functionA onto call stack
    // functionA completes, stack becomes: [main]
    return 0;
}
```

#### Memory Management

Stack is used for automatic memory management of local variables.

```mermaid
graph TD
    A[Function Call Stack] --> B[Stack Frame for main]
    B --> C[Stack Frame for functionA]
    C --> D[Stack Frame for functionB]
    D --> E[Stack Frame for functionC]

    B --> B1[Local variables of main]
    B --> B2[Return address]
    B --> B3[Function parameters]

    C --> C1[Local variables of functionA]
    C --> C2[Return address to main]
    C --> C3[Function parameters]

    style A fill:#e3f2fd
    style E fill:#ffcdd2
```

### 2. Algorithm Design Applications

#### Expression Evaluation and Parsing

Stacks are essential for converting between different mathematical notations and evaluating expressions.

**Why Stack is Perfect for This**:

- **LIFO matches operator precedence**: Higher precedence operators are processed first
- **Natural bracket handling**: Opening brackets push context, closing brackets pop context
- **Efficient evaluation**: Operators and operands are processed in correct order

#### Tree and Graph Traversal

Depth-First Search (DFS) naturally uses stack for traversal.

```cpp
class GraphDFS {
public:
    void dfsIterative(vector<vector<int>>& graph, int start) {
        int n = graph.size();
        vector<bool> visited(n, false);
        stack<int> dfsStack;

        dfsStack.push(start);

        while (!dfsStack.empty()) {
            int current = dfsStack.top();
            dfsStack.pop();

            if (!visited[current]) {
                visited[current] = true;
                cout << current << " ";

                // Add neighbors to stack (in reverse order for left-to-right traversal)
                for (int i = graph[current].size() - 1; i >= 0; i--) {
                    if (!visited[graph[current][i]]) {
                        dfsStack.push(graph[current][i]);
                    }
                }
            }
        }
    }
};
```

### 3. Software Engineering Applications

#### Undo/Redo Mechanisms

Software applications use stacks to implement undo/redo functionality.

**Why Stack is Ideal**:

- **Natural order**: Most recent action should be undone first
- **State preservation**: Each stack entry represents a complete state
- **Efficient operations**: O(1) push/pop for undo/redo

#### Syntax Checking and Code Parsing

Compilers and IDEs use stacks to check syntax correctness.

```cpp
class SyntaxChecker {
public:
    bool checkCodeSyntax(string code) {
        stack<char> bracketStack;
        stack<string> blockStack;  // For tracking code blocks

        for (int i = 0; i < code.length(); i++) {
            char c = code[i];

            // Handle brackets
            if (c == '{' || c == '[' || c == '(') {
                bracketStack.push(c);
                if (c == '{') blockStack.push("block");
            }
            else if (c == '}' || c == ']' || c == ')') {
                if (bracketStack.empty()) return false;

                char expected = getMatchingBracket(c);
                if (bracketStack.top() != expected) return false;

                bracketStack.pop();
                if (c == '}' && !blockStack.empty()) blockStack.pop();
            }
        }

        return bracketStack.empty() && blockStack.empty();
    }

private:
    char getMatchingBracket(char closing) {
        switch(closing) {
            case ')': return '(';
            case ']': return '[';
            case '}': return '{';
            default: return '\0';
        }
    }
};
```

### 4. Mathematical Computing Applications

#### Arithmetic Expression Processing

Mathematical calculators and computer algebra systems use stacks extensively.

**Benefits of Stack-based Computation**:

- **Operator precedence handling**: Natural precedence management
- **Function composition**: Nested function calls are handled elegantly
- **Memory efficiency**: Only necessary intermediate results are stored

### 5. When NOT to Use Stack

```mermaid
graph TD
    A[Avoid Stack When] --> B[Need Random Access]
    A --> C[Require FIFO Behavior]
    A --> D[Need Bidirectional Access]
    A --> E[Want Indexed Operations]

    B --> B1[Use Array/Vector Instead]
    C --> C1[Use Queue Instead]
    D --> D1[Use Deque Instead]
    E --> E1[Use Array/List Instead]

    style A fill:#ffcdd2
    style B1 fill:#c8e6c9
    style C1 fill:#c8e6c9
    style D1 fill:#c8e6c9
    style E1 fill:#c8e6c9
```

---

## Monotonic Stack

A **Monotonic Stack** is a specialized stack that maintains elements in either strictly increasing or decreasing order. It's a powerful technique for solving problems that require finding the next/previous greater or smaller element.

```mermaid
graph TD
    A[Monotonic Stack Types] --> B[Increasing Stack]
    A --> C[Decreasing Stack]

    B --> B1[Elements increase from bottom to top]
    B --> B2[Used for: Next/Previous Smaller Element]
    B --> B3[Pop when current >= top]

    C --> C1[Elements decrease from bottom to top]
    C --> C2[Used for: Next/Previous Greater Element]
    C --> C3[Pop when current <= top]

    D[Key Properties] --> E[Maintains Order Invariant]
    D --> F[Each Element Processed Once]
    D --> G[Amortized O1 Operations]
    D --> H[Natural for Range Queries]

    style A fill:#f9f,stroke:#333,stroke-width:4px
    style B fill:#bbf,stroke:#333,stroke-width:2px
    style C fill:#bfb,stroke:#333,stroke-width:2px
    style D fill:#ffb,stroke:#333,stroke-width:2px
```

### Understanding Monotonic Stack Behavior

**Key Insight**: When we pop elements from a monotonic stack, we're finding relationships between elements that wouldn't be easily discoverable with other data structures.

### Monotonic Stack Templates

```cpp
class MonotonicStackTemplates {
public:
    // Template for Next Greater Element (Decreasing Stack)
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> decreasingStack;  // Stores indices in decreasing order of values

        for (int i = 0; i < n; i++) {
            // Pop all elements smaller than current
            while (!decreasingStack.empty() &&
                   nums[i] > nums[decreasingStack.top()]) {
                int index = decreasingStack.top();
                decreasingStack.pop();
                result[index] = nums[i];  // Found next greater element
            }
            decreasingStack.push(i);
        }

        return result;
    }

    // Template for Next Smaller Element (Increasing Stack)
    vector<int> nextSmallerElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> increasingStack;  // Stores indices in increasing order of values

        for (int i = 0; i < n; i++) {
            // Pop all elements greater than current
            while (!increasingStack.empty() &&
                   nums[i] < nums[increasingStack.top()]) {
                int index = increasingStack.top();
                increasingStack.pop();
                result[index] = nums[i];  // Found next smaller element
            }
            increasingStack.push(i);
        }

        return result;
    }

    // Template for Previous Greater Element
    vector<int> previousGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> decreasingStack;

        for (int i = 0; i < n; i++) {
            // Pop elements smaller than or equal to current
            while (!decreasingStack.empty() &&
                   nums[decreasingStack.top()] <= nums[i]) {
                decreasingStack.pop();
            }

            // If stack not empty, top is previous greater element
            if (!decreasingStack.empty()) {
                result[i] = nums[decreasingStack.top()];
            }

            decreasingStack.push(i);
        }

        return result;
    }

    void demonstrateMonotonicStack() {
        vector<int> nums = {2, 1, 2, 4, 3, 1};

        cout << "=== Monotonic Stack Demonstration ===" << endl;
        cout << "Input: ";
        for (int x : nums) cout << x << " ";
        cout << endl;

        vector<int> nextGreater = nextGreaterElements(nums);
        cout << "Next Greater: ";
        for (int x : nextGreater) cout << x << " ";
        cout << endl;

        vector<int> nextSmaller = nextSmallerElements(nums);
        cout << "Next Smaller: ";
        for (int x : nextSmaller) cout << x << " ";
        cout << endl;

        vector<int> prevGreater = previousGreaterElements(nums);
        cout << "Previous Greater: ";
        for (int x : prevGreater) cout << x << " ";
        cout << endl;
    }
};
```

### Advanced Monotonic Stack Problems

#### Problem 1: Largest Rectangle in Histogram (Enhanced)

**Problem Statement**: Given heights of bars in a histogram, find the area of the largest rectangle.

**Approach**: Use monotonic increasing stack to find the previous and next smaller elements for each bar efficiently.

**Why Monotonic Stack Works**:

1. **Increasing stack** helps us find boundaries where rectangle can extend
2. **When we pop**, we know we've found the right boundary for that height
3. **Stack top** gives us the left boundary after popping
4. **Current index** gives us the right boundary

```cpp
class LargestRectangleAdvanced {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> increasingStack;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!increasingStack.empty() &&
                   heights[increasingStack.top()] > currentHeight) {

                int height = heights[increasingStack.top()];
                increasingStack.pop();

                // Width calculation:
                // If stack empty: rectangle extends from 0 to i-1
                // Otherwise: rectangle extends from (stack.top() + 1) to (i - 1)
                int width = increasingStack.empty() ? i : (i - increasingStack.top() - 1);

                maxArea = max(maxArea, height * width);

                cout << "Height: " << height << ", Width: " << width
                     << ", Area: " << height * width << endl;
            }

            increasingStack.push(i);
        }

        return maxArea;
    }

    // Visualization helper
    void visualizeProcess(vector<int>& heights) {
        cout << "=== Largest Rectangle Visualization ===" << endl;
        cout << "Heights: ";
        for (int h : heights) cout << h << " ";
        cout << endl;

        int maxArea = largestRectangleArea(heights);
        cout << "Maximum Area: " << maxArea << endl;
    }
};
```

#### Problem 2: Trapping Rain Water (Monotonic Stack Approach)

**Problem Statement**: Given heights of bars, calculate how much rainwater can be trapped.

**Approach**: Use monotonic decreasing stack to find water pockets.

**Why This Works**:

1. **Decreasing stack** maintains potential water containers
2. **When height increases**, we can calculate trapped water
3. **Stack represents** left boundaries of water pockets

```cpp
class TrappingRainWater {
public:
    int trap(vector<int>& height) {
        stack<int> decreasingStack;
        int waterTrapped = 0;

        for (int i = 0; i < height.size(); i++) {
            while (!decreasingStack.empty() &&
                   height[i] > height[decreasingStack.top()]) {

                int bottomIndex = decreasingStack.top();
                decreasingStack.pop();

                if (decreasingStack.empty()) break;

                int leftBoundary = decreasingStack.top();
                int rightBoundary = i;

                int width = rightBoundary - leftBoundary - 1;
                int waterHeight = min(height[leftBoundary], height[rightBoundary]) - height[bottomIndex];

                int currentWater = width * waterHeight;
                waterTrapped += currentWater;

                cout << "Water trapped between indices " << leftBoundary
                     << " and " << rightBoundary << ": " << currentWater << endl;
            }

            decreasingStack.push(i);
        }

        return waterTrapped;
    }

    void demonstrateTrapping() {
        vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

        cout << "=== Rain Water Trapping ===" << endl;
        cout << "Heights: ";
        for (int h : heights) cout << h << " ";
        cout << endl;

        int totalWater = trap(heights);
        cout << "Total water trapped: " << totalWater << endl;
    }
};
```

#### Problem 3: Maximum Width Ramp

**Problem Statement**: Given an array, find the maximum width ramp where i < j and A[i] <= A[j].

**Approach**: Use monotonic decreasing stack to store potential left boundaries, then traverse from right to find maximum width.

```cpp
class MaximumWidthRamp {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> decreasingStack;

        // Build decreasing stack (potential left boundaries)
        for (int i = 0; i < n; i++) {
            if (decreasingStack.empty() || nums[i] < nums[decreasingStack.top()]) {
                decreasingStack.push(i);
            }
        }

        int maxWidth = 0;

        // Traverse from right to find maximum width
        for (int j = n - 1; j >= 0; j--) {
            while (!decreasingStack.empty() &&
                   nums[j] >= nums[decreasingStack.top()]) {
                int i = decreasingStack.top();
                decreasingStack.pop();
                maxWidth = max(maxWidth, j - i);
            }
        }

        return maxWidth;
    }

    void demonstrateMaxWidth() {
        vector<int> nums = {6, 0, 8, 2, 1, 5};

        cout << "=== Maximum Width Ramp ===" << endl;
        cout << "Array: ";
        for (int x : nums) cout << x << " ";
        cout << endl;
        cout << "Maximum width ramp: " << maxWidthRamp(nums) << endl;
    }
};
```

### When to Use Monotonic Stack

```mermaid
graph TD
    A[Use Monotonic Stack When] --> B[Finding Next/Previous Relations]
    A --> C[Range Query Problems]
    A --> D[Optimal Substructure with Order]

    B --> B1[Next Greater/Smaller Element]
    B --> B2[Stock Span Problems]
    B --> B3[Daily Temperature Problems]

    C --> C1[Largest Rectangle Problems]
    C --> C2[Trapping Water Problems]
    C --> C3[Maximum Width Problems]

    D --> D1[Sliding Window Maximum]
    D --> D2[Beautiful Arrangements]
    D --> D3[Competitive Programming Optimizations]

    style A fill:#e3f2fd
    style B fill:#ffecb3
    style C fill:#c8e6c9
    style D fill:#f3e5f5
```

---

### 1. Balanced Parentheses Problem

**Problem Statement**: Given a string containing parentheses, brackets, and braces, determine if they are balanced.

**Example**:

- Input: `"()[]{}"` → Output: `true` (balanced)
- Input: `"([)]"` → Output: `false` (not balanced)

**Approach Explanation**:

1. **Use stack to track opening brackets**: Push every opening bracket onto the stack
2. **Match closing brackets**: For each closing bracket, check if it matches the most recent opening bracket (stack top)
3. **LIFO property ensures correct nesting**: Stack naturally handles nested structures
4. **Final check**: Stack should be empty if all brackets are properly matched

**Why this approach works**:

- Stack's LIFO property perfectly matches the nested nature of balanced parentheses
- Opening brackets create context that must be closed in reverse order
- Each closing bracket must match the most recently opened bracket

**Time Complexity**: O(n) - single pass through string
**Space Complexity**: O(n) - worst case all opening brackets

```mermaid
graph TD
    A[Process Each Character] --> B{Opening Bracket?}
    B -->|Yes| C[Push to Stack]
    B -->|No| D{Closing Bracket?}
    D -->|Yes| E{Stack Empty?}
    D -->|No| F[Continue to Next Character]
    E -->|Yes| G[Return False - Unmatched]
    E -->|No| H[Check if Top Matches]
    H -->|Match| I[Pop Stack]
    H -->|No Match| J[Return False - Mismatch]
    C --> F
    I --> F
    F --> K{More Characters?}
    K -->|Yes| A
    K -->|No| L{Stack Empty?}
    L -->|Yes| M[Return True - Balanced]
    L -->|No| N[Return False - Unmatched Opening]

    style A fill:#e3f2fd
    style M fill:#c8e6c9
    style G fill:#ffcdd2
    style J fill:#ffcdd2
    style N fill:#ffcdd2
```

```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class BalancedParentheses {
public:
    bool isBalanced(string s) {
        stack<char> bracketStack;

        for (char c : s) {
            // Push opening brackets onto stack
            if (c == '(' || c == '[' || c == '{') {
                bracketStack.push(c);
            }
            // Check closing brackets
            else if (c == ')' || c == ']' || c == '}') {
                // No matching opening bracket
                if (bracketStack.empty()) {
                    return false;
                }

                char top = bracketStack.top();
                bracketStack.pop();

                // Check if brackets match
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }
            }
        }

        // All brackets should be matched
        return bracketStack.empty();
    }

    void testBalancedParentheses() {
        vector<string> testCases = {
            "()",           // Balanced
            "()[]{}",       // Balanced
            "([{}])",       // Balanced
            "([)]",         // Not balanced
            "(((",          // Not balanced
            ")))",          // Not balanced
            "{[()]}",       // Balanced
            ""              // Balanced (empty)
        };

        cout << "=== Balanced Parentheses Test ===" << endl;
        for (const string& test : testCases) {
            cout << "\"" << test << "\" is "
                 << (isBalanced(test) ? "balanced" : "not balanced") << endl;
        }
    }
};
```

### 2. Next Greater Element

**Problem Statement**: For each element in an array, find the next greater element to its right. If no such element exists, return -1.

**Example**:

- Input: `[2, 1, 2, 4, 3, 1]`
- Output: `[4, 2, 4, -1, -1, -1]`

**Approach Explanation**:

1. **Use stack to store indices**: Keep track of elements waiting for their next greater element
2. **Process left to right**: For each element, it might be the answer for previous elements
3. **Maintain decreasing order**: Pop elements from stack while current element is greater
4. **Store indices, not values**: This allows us to update results efficiently

**Why this approach works**:

- Stack maintains elements in decreasing order of their values
- When we find a greater element, it's the answer for all smaller elements in stack
- Each element is pushed and popped at most once, ensuring O(n) complexity

**Detailed Algorithm**:

1. Initialize result array with -1 (default for no greater element)
2. For each element at index i:
   - While stack not empty AND current element > element at stack top index:
     - Pop index from stack and set result[index] = current element
   - Push current index to stack
3. Remaining elements in stack have no next greater element

**Time Complexity**: O(n) - each element pushed and popped at most once
**Space Complexity**: O(n) - for stack and result array

```mermaid
graph LR
    A[Input Array: 2,1,2,4,3,1] --> B[Process Index 0: value=2]
    B --> C[Stack: empty → push 0]
    C --> D[Process Index 1: value=1]
    D --> E[1 < 2, no pop → push 1]
    E --> F[Stack: 0,1]
    F --> G[Process Index 2: value=2]
    G --> H[2 > 1, pop 1, result[1]=2]
    H --> I[2 = 2, no more pops]
    I --> J[push 2, Stack: 0,2]
    J --> K[Process Index 3: value=4]
    K --> L[4 > 2, pop and update results]
    L --> M[Final: Stack maintains decreasing order]

    style A fill:#e3f2fd
    style M fill:#c8e6c9
```

```cpp
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class NextGreaterElement {
public:
    vector<int> findNextGreater(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);  // Initialize with -1 (no greater element)
        stack<int> indexStack;      // Store indices instead of values

        for (int i = 0; i < n; i++) {
            // While stack is not empty and current element is greater
            // than element at index stored in stack top
            while (!indexStack.empty() && nums[i] > nums[indexStack.top()]) {
                int index = indexStack.top();
                indexStack.pop();
                result[index] = nums[i];  // Found next greater element
            }

            indexStack.push(i);  // Push current index
        }

        return result;
    }

    // Optimized version for circular array
    vector<int> findNextGreaterCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> indexStack;

        // Process array twice to handle circular nature
        for (int i = 0; i < 2 * n; i++) {
            int currentIndex = i % n;

            while (!indexStack.empty() &&
                   nums[currentIndex] > nums[indexStack.top()]) {
                int index = indexStack.top();
                indexStack.pop();
                result[index] = nums[currentIndex];
            }

            // Only push indices in first iteration
            if (i < n) {
                indexStack.push(currentIndex);
            }
        }

        return result;
    }

    void demonstrateNextGreater() {
        vector<int> nums = {2, 1, 2, 4, 3, 1};

        cout << "=== Next Greater Element Demo ===" << endl;
        cout << "Input array: ";
        for (int num : nums) cout << num << " ";
        cout << endl;

        vector<int> result = findNextGreater(nums);
        cout << "Next greater: ";
        for (int res : result) cout << res << " ";
        cout << endl;

        vector<int> circularResult = findNextGreaterCircular(nums);
        cout << "Next greater (circular): ";
        for (int res : circularResult) cout << res << " ";
        cout << endl;
    }
};
```

### 3. Stock Span Problem

**Problem Statement**: Calculate the span of stock prices, where span is the number of consecutive days before the current day (including current day) where the price was less than or equal to current day's price.

**Example**:

- Input prices: `[100, 80, 60, 70, 60, 75, 85]`
- Output spans: `[1, 1, 1, 2, 1, 4, 6]`

**Detailed Explanation**:

- Day 0: Price=100, no previous days → span=1
- Day 1: Price=80 < 100, only current day → span=1
- Day 2: Price=60 < 80, only current day → span=1
- Day 3: Price=70 > 60, includes day 2 and 3 → span=2
- Day 4: Price=60 < 70, only current day → span=1
- Day 5: Price=75 > 60,70,60, includes days 2,3,4,5 → span=4
- Day 6: Price=85 > all previous, includes all days → span=6

**Approach Explanation**:

1. **Use stack to store indices**: Keep indices of days whose span calculation is pending
2. **Maintain decreasing prices**: Pop days with prices ≤ current day's price
3. **Calculate span efficiently**: Span = current_index - previous_higher_price_index
4. **Handle empty stack**: If stack empty, current price is highest so far

**Why this approach works**:

- Stack maintains days in decreasing order of prices
- When we pop elements, we're finding all days with lower prices
- The remaining top of stack (if any) gives us the boundary for span calculation
- Each day is processed exactly once

**Time Complexity**: O(n) - each element pushed and popped at most once
**Space Complexity**: O(n) - for stack storage

```mermaid
graph TD
    A[Stock Span Calculation Process] --> B[Day i: Price P]
    B --> C{Stack Empty?}
    C -->|Yes| D[Span = i + 1]
    C -->|No| E{P >= Price at Stack Top?}
    E -->|Yes| F[Pop Stack - Found smaller price]
    E -->|No| G[Span = i - Stack Top Index]
    F --> C
    D --> H[Push Current Index]
    G --> H
    H --> I[Move to Next Day]

    J[Example Visualization] --> K[Prices: 100,80,60,70,60,75,85]
    K --> L[Day 3: Price=70]
    L --> M[Stack has indices of prices ≥ 70]
    M --> N[Pop index 2 price=60]
    M --> O[Keep index 1 price=80]
    O --> P[Span = 3 - 1 = 2]

    style A fill:#e3f2fd
    style J fill:#fff3e0
    style P fill:#c8e6c9
```

```cpp
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class StockSpan {
public:
    vector<int> calculateSpan(vector<int>& prices) {
        int n = prices.size();
        vector<int> span(n);
        stack<int> indexStack;  // Stack to store indices

        for (int i = 0; i < n; i++) {
            // Pop elements while stack is not empty and current price
            // is greater than or equal to price at stack top
            while (!indexStack.empty() && prices[i] >= prices[indexStack.top()]) {
                indexStack.pop();
            }

            // If stack is empty, current element is greater than all previous
            // Otherwise, span is distance from current index to index at stack top
            span[i] = indexStack.empty() ? (i + 1) : (i - indexStack.top());

            indexStack.push(i);  // Push current index
        }

        return span;
    }

    void demonstrateStockSpan() {
        vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

        cout << "=== Stock Span Problem Demo ===" << endl;
        cout << "Stock prices: ";
        for (int price : prices) cout << price << " ";
        cout << endl;

        vector<int> spans = calculateSpan(prices);
        cout << "Stock spans:  ";
        for (int span : spans) cout << span << " ";
        cout << endl;

        // Explanation
        cout << "\nExplanation:" << endl;
        for (int i = 0; i < prices.size(); i++) {
            cout << "Day " << i + 1 << ": Price=" << prices[i]
                 << ", Span=" << spans[i] << endl;
        }
    }
};
```

---

## Expression Evaluation

### Infix to Postfix Conversion

**Problem Statement**: Convert infix expressions (normal mathematical notation) to postfix notation (Reverse Polish Notation).

**Example**:

- Infix: `"a+b*c"` → Postfix: `"abc*+"`
- Infix: `"(a+b)*c"` → Postfix: `"ab+c*"`

**Approach Explanation**:

1. **Operator precedence handling**: Higher precedence operators are processed first
2. **Left-to-right associativity**: For same precedence, left operator comes first
3. **Parentheses override precedence**: Expressions in parentheses are evaluated first
4. **Stack maintains operator context**: Operators wait in stack until their operands are ready

**Algorithm Steps**:

1. **Operands**: Direct output to result
2. **Opening parenthesis**: Push to stack (creates new precedence level)
3. **Operators**: Pop operators with higher/equal precedence, then push current operator
4. **Closing parenthesis**: Pop until opening parenthesis found
5. **End**: Pop all remaining operators

**Why this works**: Stack naturally handles operator precedence and associativity by delaying lower precedence operators until higher precedence ones are processed.

```mermaid
graph TD
    A[Infix to Postfix Conversion] --> B[Scan Left to Right]
    B --> C{Token Type?}

    C -->|Operand| D[Add to Output]
    C -->|Operator| E[Check Precedence]
    C -->|Open Paren| F[Push to Stack]
    C -->|Close Paren| G[Pop until Open Paren]

    E --> H{Higher/Equal Precedence on Stack?}
    H -->|Yes| I[Pop and Add to Output]
    H -->|No| J[Push to Stack]
    I --> H

    D --> K{More Tokens?}
    F --> K
    G --> K
    J --> K
    K -->|Yes| B
    K -->|No| L[Pop All Remaining]
    L --> M[Postfix Expression Ready]

    style A fill:#e3f2fd
    style M fill:#c8e6c9
```

```cpp
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

class ExpressionConverter {
private:
    // Get precedence of operators
    int getPrecedence(char op) {
        switch (op) {
            case '+':
            case '-': return 1;
            case '*':
            case '/': return 2;
            case '^': return 3;
            default: return -1;
        }
    }

    // Check if operator is right associative
    bool isRightAssociative(char op) {
        return op == '^';
    }

    // Check if character is an operator
    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
    }

public:
    string infixToPostfix(string infix) {
        stack<char> operatorStack;
        string postfix = "";

        for (char c : infix) {
            // If operand, add to output
            if (isalnum(c)) {
                postfix += c;
            }
            // If opening parenthesis, push to stack
            else if (c == '(') {
                operatorStack.push(c);
            }
            // If closing parenthesis, pop until opening parenthesis
            else if (c == ')') {
                while (!operatorStack.empty() && operatorStack.top() != '(') {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.pop();  // Remove opening parenthesis
            }
            // If operator
            else if (isOperator(c)) {
                // Pop operators with higher or equal precedence
                while (!operatorStack.empty() &&
                       operatorStack.top() != '(' &&
                       (getPrecedence(operatorStack.top()) > getPrecedence(c) ||
                        (getPrecedence(operatorStack.top()) == getPrecedence(c) &&
                         !isRightAssociative(c)))) {
                    postfix += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(c);
            }
        }

        // Pop remaining operators
        while (!operatorStack.empty()) {
            postfix += operatorStack.top();
            operatorStack.pop();
        }

        return postfix;
    }

    string infixToPrefix(string infix) {
        // Reverse the infix expression
        reverse(infix.begin(), infix.end());

        // Replace ( with ) and vice versa
        for (int i = 0; i < infix.length(); i++) {
            if (infix[i] == '(') {
                infix[i] = ')';
            } else if (infix[i] == ')') {
                infix[i] = '(';
            }
        }

        // Get postfix of modified expression
        string postfix = infixToPostfix(infix);

        // Reverse the postfix to get prefix
        reverse(postfix.begin(), postfix.end());

        return postfix;
    }

    void demonstrateConversion() {
        vector<string> expressions = {
            "a+b*c",
            "(a+b)*c",
            "a+b*c-d",
            "a^b^c",
            "((a+b)*c-d)*e"
        };

        cout << "=== Expression Conversion Demo ===" << endl;
        for (const string& expr : expressions) {
            cout << "Infix:   " << expr << endl;
            cout << "Postfix: " << infixToPostfix(expr) << endl;
            cout << "Prefix:  " << infixToPrefix(expr) << endl;
            cout << "---" << endl;
        }
    }
};
```

### Postfix Expression Evaluation

**Problem Statement**: Evaluate arithmetic expressions written in postfix notation (Reverse Polish Notation).

**Example**:

- Postfix: `"23+"` → Result: `5` (2+3)
- Postfix: `"23*54*+"` → Result: `26` (2*3 + 5*4 = 6+20)

**Approach Explanation**:

1. **Process left to right**: Scan postfix expression from left to right
2. **Operands go to stack**: Numbers are pushed onto stack for later use
3. **Operators consume operands**: Pop required operands, apply operator, push result
4. **LIFO ensures correct order**: Most recent operands are used first

**Why postfix is stack-perfect**:

- No parentheses needed (precedence already handled)
- No ambiguity in evaluation order
- Each operator immediately follows its operands
- Stack naturally provides operands in correct order

**Algorithm**:

1. For each token in postfix expression:
   - If operand: push to stack
   - If operator: pop required operands, apply operation, push result
2. Final stack top is the result

```mermaid
graph LR
    A[Postfix: 2 3 * 5 4 * +] --> B[Process 2]
    B --> C[Stack: 2]
    C --> D[Process 3]
    D --> E[Stack: 2,3]
    E --> F[Process *]
    F --> G[Pop 3,2 → 2*3=6]
    G --> H[Stack: 6]
    H --> I[Process 5]
    I --> J[Stack: 6,5]
    J --> K[Process 4]
    K --> L[Stack: 6,5,4]
    L --> M[Process *]
    M --> N[Pop 4,5 → 5*4=20]
    N --> O[Stack: 6,20]
    O --> P[Process +]
    P --> Q[Pop 20,6 → 6+20=26]
    Q --> R[Stack: 26 - Final Result]

    style A fill:#e3f2fd
    style R fill:#c8e6c9
```

```cpp
class PostfixEvaluator {
public:
    int evaluatePostfix(string postfix) {
        stack<int> operandStack;

        for (char c : postfix) {
            // If operand, push to stack
            if (isdigit(c)) {
                operandStack.push(c - '0');  // Convert char to int
            }
            // If operator, pop two operands and perform operation
            else {
                int operand2 = operandStack.top(); operandStack.pop();
                int operand1 = operandStack.top(); operandStack.pop();

                switch (c) {
                    case '+': operandStack.push(operand1 + operand2); break;
                    case '-': operandStack.push(operand1 - operand2); break;
                    case '*': operandStack.push(operand1 * operand2); break;
                    case '/': operandStack.push(operand1 / operand2); break;
                    case '^': operandStack.push(pow(operand1, operand2)); break;
                }
            }
        }

        return operandStack.top();
    }

    void demonstrateEvaluation() {
        vector<string> postfixExpressions = {
            "23+",      // 2 + 3 = 5
            "23*54*+",  // 2*3 + 5*4 = 6 + 20 = 26
            "15+2*",    // (1 + 5) * 2 = 12
            "42/3-"     // 4/2 - 3 = 2 - 3 = -1
        };

        cout << "=== Postfix Evaluation Demo ===" << endl;
        for (const string& expr : postfixExpressions) {
            cout << "Expression: " << expr
                 << " = " << evaluatePostfix(expr) << endl;
        }
    }
};
```

---

## Recursion and Stack

### Understanding Recursion Call Stack

**Concept**: Every recursive function call uses the system's call stack to store function state, parameters, and return addresses.

**Why recursion uses stack**:

1. **LIFO order**: Last called function returns first
2. **State preservation**: Each call maintains its own local variables
3. **Return address tracking**: System knows where to continue after function returns
4. **Memory management**: Automatic cleanup when function completes

```mermaid
graph TD
    A[Recursion Call Stack Visualization] --> B[factorial 4]
    B --> C[factorial 3]
    C --> D[factorial 2]
    D --> E[factorial 1]
    E --> F[factorial 0 - Base Case]

    F --> G[Return 1]
    G --> H[1 * 1 = 1]
    H --> I[2 * 1 = 2]
    I --> J[3 * 2 = 6]
    J --> K[4 * 6 = 24]

    L[Stack Frame Contents] --> M[Local Variables]
    L --> N[Function Parameters]
    L --> O[Return Address]
    L --> P[Return Value Space]

    Q[Memory Layout] --> R[Stack grows downward]
    R --> S[Each call adds frame]
    S --> T[Returns remove frames]
    T --> U[LIFO order maintained]

    style A fill:#e3f2fd
    style F fill:#ffcdd2
    style K fill:#c8e6c9
    style U fill:#fff3e0
```

**Stack Overflow**: Occurs when recursive calls exceed available stack space, typically due to:

- Missing or incorrect base case
- Too deep recursion for available memory
- Infinite recursion loops

```mermaid
graph TD
    A[Factorial Function Call Stack] --> B[factorial(4)]
    B --> C[factorial(3)]
    C --> D[factorial(2)]
    D --> E[factorial(1)]
    E --> F[factorial(0) - Base Case]

    F --> G[Return 1]
    G --> H[Return 1 * 1 = 1]
    H --> I[Return 2 * 1 = 2]
    I --> J[Return 3 * 2 = 6]
    J --> K[Return 4 * 6 = 24]
```

```cpp
#include <iostream>
#include <stack>
using namespace std;

class RecursionStack {
public:
    // Recursive factorial
    long long factorialRecursive(int n) {
        cout << "Entering factorial(" << n << ")" << endl;

        if (n <= 1) {
            cout << "Base case reached: factorial(" << n << ") = 1" << endl;
            return 1;
        }

        long long result = n * factorialRecursive(n - 1);
        cout << "Returning from factorial(" << n << ") = " << result << endl;

        return result;
    }

    // Iterative factorial using explicit stack
    long long factorialIterative(int n) {
        if (n <= 1) return 1;

        stack<int> callStack;

        // Simulate function calls by pushing onto stack
        for (int i = n; i > 1; i--) {
            callStack.push(i);
        }

        long long result = 1;

        // Simulate returns by popping from stack
        while (!callStack.empty()) {
            result *= callStack.top();
            cout << "Processing: " << callStack.top()
                 << ", Current result: " << result << endl;
            callStack.pop();
        }

        return result;
    }

    // Tower of Hanoi - Classic recursion problem
    void towerOfHanoi(int n, char source, char destination, char auxiliary) {
        if (n == 1) {
            cout << "Move disk 1 from " << source << " to " << destination << endl;
            return;
        }

        // Move n-1 disks from source to auxiliary
        towerOfHanoi(n - 1, source, auxiliary, destination);

        // Move largest disk from source to destination
        cout << "Move disk " << n << " from " << source << " to " << destination << endl;

        // Move n-1 disks from auxiliary to destination
        towerOfHanoi(n - 1, auxiliary, destination, source);
    }

    void demonstrateRecursionStack() {
        cout << "=== Recursive vs Iterative Factorial ===" << endl;
        cout << "Recursive approach:" << endl;
        long long recursiveResult = factorialRecursive(4);
        cout << "Final result: " << recursiveResult << endl << endl;

        cout << "Iterative approach with explicit stack:" << endl;
        long long iterativeResult = factorialIterative(4);
        cout << "Final result: " << iterativeResult << endl << endl;

        cout << "=== Tower of Hanoi (3 disks) ===" << endl;
        towerOfHanoi(3, 'A', 'C', 'B');
    }
};
```

---

## Advanced Stack Problems

### 1. Largest Rectangle in Histogram

**Problem Statement**: Find the area of the largest rectangle that can be formed in a histogram where each bar has width 1.

**Example**:

- Input: `heights = [2,1,5,6,2,3]`
- Output: `10` (rectangle with height 5 and width 2)

**Approach Explanation**:

1. **Use monotonic increasing stack**: Stack stores indices of bars in increasing order of heights
2. **When height decreases**: Pop bars taller than current and calculate rectangles
3. **Width calculation**: Distance between current index and index after stack top
4. **Each bar as height**: Every bar gets a chance to be the smallest in some rectangle

**Detailed Algorithm**:

1. For each bar (including a sentinel 0 at the end):
   - While stack not empty and current height < height at stack top:
     - Pop index and use its height for rectangle calculation
     - Width = current_index - new_stack_top - 1 (if stack not empty) or current_index (if empty)
     - Update maximum area
   - Push current index

**Why this works**:

- **Monotonic stack property**: When we pop, we know all bars to the right are taller
- **Efficient boundary finding**: Stack gives us left boundary, current position gives right boundary
- **Complete coverage**: Every possible rectangle with each bar as minimum height is considered

**Time Complexity**: O(n) - each bar pushed and popped at most once
**Space Complexity**: O(n) - for stack storage

```mermaid
graph TD
    A[Largest Rectangle Algorithm] --> B[Process Each Bar]
    B --> C{Current Height < Stack Top Height?}
    C -->|Yes| D[Pop Stack Top]
    C -->|No| G[Push Current Index]
    D --> E[Calculate Rectangle Area]
    E --> F[Height = Popped Bar Height]
    F --> H[Width = Current Index - New Stack Top - 1]
    H --> I[Update Max Area]
    I --> C
    G --> J{More Bars?}
    J -->|Yes| B
    J -->|No| K[Return Max Area]

    L[Example Visualization] --> M[Heights: 2,1,5,6,2,3]
    M --> N[At Index 4 Height=2]
    N --> O[Pop Index 3 Height=6, Width=1, Area=6]
    O --> P[Pop Index 2 Height=5, Width=2, Area=10]
    P --> Q[Stack becomes: 0,1]

    style A fill:#e3f2fd
    style K fill:#c8e6c9
    style Q fill:#fff3e0
```

```cpp
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class LargestRectangle {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> indexStack;  // Stack to store indices
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            // Use 0 as sentinel value for last iteration
            int currentHeight = (i == n) ? 0 : heights[i];

            // Process all bars higher than current bar
            while (!indexStack.empty() &&
                   heights[indexStack.top()] > currentHeight) {

                int height = heights[indexStack.top()];
                indexStack.pop();

                // Calculate width: if stack is empty, width is i
                // Otherwise, width is distance between current index and stack top
                int width = indexStack.empty() ? i : (i - indexStack.top() - 1);

                maxArea = max(maxArea, height * width);
            }

            indexStack.push(i);
        }

        return maxArea;
    }

    void demonstrateLargestRectangle() {
        vector<vector<int>> testCases = {
            {2, 1, 5, 6, 2, 3},
            {2, 4},
            {1, 2, 3, 4, 5},
            {5, 4, 3, 2, 1}
        };

        cout << "=== Largest Rectangle in Histogram ===" << endl;
        for (auto& heights : testCases) {
            cout << "Heights: ";
            for (int h : heights) cout << h << " ";
            cout << "=> Max Area: " << largestRectangleArea(heights) << endl;
        }
    }
};
```

### 2. Maximum Rectangle in Binary Matrix

**Problem**: Find the area of the largest rectangle containing only 1s in a binary matrix.

**Approach**: Convert each row to histogram and apply largest rectangle algorithm.

```cpp
class MaxRectangleMatrix {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            // Update heights for current row
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            // Find largest rectangle in current histogram
            LargestRectangle lr;
            maxArea = max(maxArea, lr.largestRectangleArea(heights));
        }

        return maxArea;
    }

    void demonstrateMaxRectangle() {
        vector<vector<char>> matrix = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
        };

        cout << "=== Maximum Rectangle in Binary Matrix ===" << endl;
        cout << "Matrix:" << endl;
        for (auto& row : matrix) {
            for (char c : row) cout << c << " ";
            cout << endl;
        }

        cout << "Maximum Rectangle Area: " << maximalRectangle(matrix) << endl;
    }
};
```

### 3. Min Stack with O(1) Space

**Problem Statement**: Design a stack that supports push, pop, top, and getMin operations all in O(1) time.

**Example**:

```
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
```

**Approach Explanation**:

1. **Store differences instead of actual values**: Stack stores (value - currentMin)
2. **Negative differences indicate new minimum**: When difference < 0, current value is new minimum
3. **Restore previous minimum on pop**: When popping negative difference, restore previous minimum
4. **Space optimization**: No extra space needed beyond the main stack

**Key Insights**:

- **Encoding information**: Differences encode both value and minimum information
- **Sign significance**: Negative differences mark minimum changes
- **Restoration formula**: previous_min = current_min - difference

**Algorithm Details**:

- **Push**: Store (value - min), update min if value < min
- **Pop**: If top < 0, restore previous min = current_min - top
- **Top**: If top < 0, return current_min; else return min + top
- **GetMin**: Return current minimum

**Why this works**:

- Differences preserve relative ordering
- Negative values serve as markers for minimum changes
- Mathematical properties ensure correct restoration

```mermaid
graph TD
    A[Min Stack Operations] --> B[Push Operation]
    A --> C[Pop Operation]
    A --> D[Top Operation]
    A --> E[GetMin Operation]

    B --> B1{Value < Current Min?}
    B1 -->|Yes| B2[Store: value - currentMin < 0]
    B1 -->|No| B3[Store: value - currentMin >= 0]
    B2 --> B4[Update: currentMin = value]
    B3 --> B5[Keep: currentMin unchanged]

    C --> C1{Top < 0?}
    C1 -->|Yes| C2[Popped value was minimum]
    C1 -->|No| C3[Normal pop operation]
    C2 --> C4[Restore: previousMin = currentMin - top]
    C3 --> C5[currentMin unchanged]

    D --> D1{Top < 0?}
    D1 -->|Yes| D2[Return currentMin]
    D1 -->|No| D3[Return currentMin + top]

    E --> E1[Return currentMin]

    style A fill:#e3f2fd
    style B4 fill:#ffecb3
    style C4 fill:#ffecb3
    style E1 fill:#c8e6c9
```

```cpp
class MinStack {
private:
    stack<long long> st;
    long long minElement;

public:
    MinStack() {
        minElement = LLONG_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            st.push(0);
            minElement = val;
        } else {
            // Store difference between current value and minimum
            st.push((long long)val - minElement);

            // Update minimum if current value is smaller
            if (val < minElement) {
                minElement = val;
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long top = st.top();
        st.pop();

        // If top is negative, it means the popped element was minimum
        if (top < 0) {
            minElement = minElement - top;  // Restore previous minimum
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long top = st.top();

        // If top is negative, actual value is current minimum
        if (top < 0) {
            return minElement;
        } else {
            return minElement + top;
        }
    }

    int getMin() {
        return minElement;
    }

    void demonstrateMinStack() {
        cout << "=== Min Stack Demonstration ===" << endl;

        push(5);
        cout << "Pushed 5, Min: " << getMin() << ", Top: " << top() << endl;

        push(3);
        cout << "Pushed 3, Min: " << getMin() << ", Top: " << top() << endl;

        push(7);
        cout << "Pushed 7, Min: " << getMin() << ", Top: " << top() << endl;

        push(1);
        cout << "Pushed 1, Min: " << getMin() << ", Top: " << top() << endl;

        pop();
        cout << "Popped, Min: " << getMin() << ", Top: " << top() << endl;

        pop();
        cout << "Popped, Min: " << getMin() << ", Top: " << top() << endl;
    }
};
```

### 4. Sliding Window Maximum

**Problem**: Find the maximum element in every sliding window of size k.

**Approach**: Use deque (double-ended queue) to maintain elements in decreasing order.

```cpp
#include <deque>

class SlidingWindowMaximum {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;  // Store indices in decreasing order of values
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // Remove indices outside current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove indices whose corresponding values are smaller
            // than current element (they can never be maximum)
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Add maximum of current window to result
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }

    void demonstrateSlidingWindow() {
        vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
        int k = 3;

        cout << "=== Sliding Window Maximum ===" << endl;
        cout << "Array: ";
        for (int num : nums) cout << num << " ";
        cout << endl << "Window size: " << k << endl;

        vector<int> result = maxSlidingWindow(nums, k);
        cout << "Maximum in each window: ";
        for (int max : result) cout << max << " ";
        cout << endl;
    }
};
```

---

## More Practice Problems

### Problem 1: Valid Parentheses with Minimum Removals

**Problem Statement**: Given a string with parentheses, find the minimum number of parentheses to remove to make the string valid.

**Example**:

- Input: `"()())()"` → Output: `1` (remove one ')')
- Input: `"((("` → Output: `3` (remove all '(')

**Approach Explanation**:

1. **Track unmatched parentheses**: Use stack for unmatched opening brackets
2. **Count excess closing brackets**: Count closing brackets without matching opening
3. **Final calculation**: unmatched_opening + excess_closing

```cpp
class MinimumParenthesesRemoval {
public:
    int minRemoveToMakeValid(string s) {
        int unmatched_open = 0;  // Count of unmatched '('
        int excess_close = 0;    // Count of excess ')'

        for (char c : s) {
            if (c == '(') {
                unmatched_open++;
            } else if (c == ')') {
                if (unmatched_open > 0) {
                    unmatched_open--;  // Match found
                } else {
                    excess_close++;    // Excess closing bracket
                }
            }
        }

        return unmatched_open + excess_close;
    }

    // Alternative: Return the valid string after removing invalid parentheses
    string removeInvalidParentheses(string s) {
        stack<int> indexStack;
        set<int> toRemove;

        // First pass: identify indices to remove
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                indexStack.push(i);
            } else if (s[i] == ')') {
                if (!indexStack.empty()) {
                    indexStack.pop();  // Matched pair
                } else {
                    toRemove.insert(i);  // Unmatched closing
                }
            }
        }

        // Add remaining unmatched opening brackets
        while (!indexStack.empty()) {
            toRemove.insert(indexStack.top());
            indexStack.pop();
        }

        // Build result string
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            if (toRemove.find(i) == toRemove.end()) {
                result += s[i];
            }
        }

        return result;
    }

    void demonstrateMinRemoval() {
        vector<string> testCases = {
            "()())",
            "(((",
            "()()())",
            ")(",
            "((a))",
            "a)b(c"
        };

        cout << "=== Minimum Parentheses Removal ===" << endl;
        for (const string& test : testCases) {
            cout << "Input: '" << test << "'" << endl;
            cout << "Min removals: " << minRemoveToMakeValid(test) << endl;
            cout << "Valid string: '" << removeInvalidParentheses(test) << "'" << endl;
            cout << "---" << endl;
        }
    }
};
```

### Problem 2: Maximum Rectangle in Binary Matrix

**Problem Statement**: Given a binary matrix filled with 0s and 1s, find the largest rectangle containing only 1s and return its area.

**Example**:

```
Matrix:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Output: 6 (rectangle from row 1-2, col 2-4)
```

**Approach Explanation**:

1. **Convert to histogram problem**: For each row, calculate heights of consecutive 1s ending at that row
2. **Apply largest rectangle algorithm**: Use the histogram algorithm for each row
3. **Dynamic height calculation**: Update heights as we process each row

**Why this works**: Each row can be viewed as the base of a histogram where heights represent consecutive 1s ending at that row.

```cpp
class MaxRectangleInMatrix {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            // Update heights for current row
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;  // Extend height
                } else {
                    heights[j] = 0;  // Reset height
                }
            }

            // Find largest rectangle in current histogram
            int currentArea = largestRectangleInHistogram(heights);
            maxArea = max(maxArea, currentArea);

            cout << "Row " << i << " heights: ";
            for (int h : heights) cout << h << " ";
            cout << "→ Max area so far: " << maxArea << endl;
        }

        return maxArea;
    }

private:
    int largestRectangleInHistogram(vector<int>& heights) {
        stack<int> indexStack;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!indexStack.empty() &&
                   heights[indexStack.top()] > currentHeight) {

                int height = heights[indexStack.top()];
                indexStack.pop();

                int width = indexStack.empty() ? i : (i - indexStack.top() - 1);
                maxArea = max(maxArea, height * width);
            }

            indexStack.push(i);
        }

        return maxArea;
    }

public:
    void demonstrateMaxRectangle() {
        vector<vector<char>> matrix = {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
        };

        cout << "=== Maximum Rectangle in Binary Matrix ===" << endl;
        cout << "Matrix:" << endl;
        for (const auto& row : matrix) {
            for (char c : row) cout << c << " ";
            cout << endl;
        }
        cout << endl;

        int result = maximalRectangle(matrix);
        cout << "Maximum Rectangle Area: " << result << endl;
    }
};
```

### Problem 3: Evaluate Reverse Polish Notation

**Problem Statement**: Evaluate the value of an arithmetic expression in Reverse Polish Notation (RPN).

**Example**:

- Input: `["2","1","+","3","*"]` → Output: `9` ((2+1)\*3)
- Input: `["4","13","5","/","+"]` → Output: `6` (4+(13/5))

**Approach Explanation**:

1. **Process tokens left to right**: Numbers are operands, symbols are operators
2. **Stack for operands**: Push numbers onto stack
3. **Apply operators**: Pop two operands, apply operator, push result back
4. **Final result**: Last remaining element in stack

**Why RPN is stack-friendly**: RPN eliminates need for parentheses and precedence rules by using postfix notation where operators come after their operands.

```cpp
class EvaluateRPN {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operandStack;

        for (const string& token : tokens) {
            if (isOperator(token)) {
                // Pop two operands (order matters for - and /)
                int operand2 = operandStack.top(); operandStack.pop();
                int operand1 = operandStack.top(); operandStack.pop();

                int result = applyOperator(operand1, operand2, token);
                operandStack.push(result);

                cout << operand1 << " " << token << " " << operand2
                     << " = " << result << endl;
            } else {
                // It's a number
                operandStack.push(stoi(token));
                cout << "Push: " << token << endl;
            }
        }

        return operandStack.top();
    }

private:
    bool isOperator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int applyOperator(int operand1, int operand2, const string& op) {
        if (op == "+") return operand1 + operand2;
        if (op == "-") return operand1 - operand2;
        if (op == "*") return operand1 * operand2;
        if (op == "/") return operand1 / operand2;
        return 0;
    }

public:
    void demonstrateRPN() {
        vector<vector<string>> testCases = {
            {"2", "1", "+", "3", "*"},
            {"4", "13", "5", "/", "+"},
            {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}
        };

        cout << "=== Reverse Polish Notation Evaluation ===" << endl;
        for (const auto& tokens : testCases) {
            cout << "Expression: ";
            for (const string& token : tokens) cout << token << " ";
            cout << endl;

            vector<string> tokensCopy = tokens;  // Copy for demonstration
            int result = evalRPN(tokensCopy);
            cout << "Result: " << result << endl;
            cout << "---" << endl;
        }
    }
};
```

### Problem 4: Basic Calculator

**Problem Statement**: Implement a basic calculator to evaluate a simple expression string containing '+', '-', '(', ')' and non-negative integers.

**Example**:

- Input: `"1 + 1"` → Output: `2`
- Input: `"2-1 + 2"` → Output: `3`
- Input: `"(1+(4+5+2)-3)+(6+8)"` → Output: `23`

**Approach Explanation**:

1. **Stack for nested calculations**: Handle parentheses by pushing intermediate results
2. **Current number and operator tracking**: Process digit by digit
3. **Parentheses handling**: Push current state when '(', restore when ')'

```cpp
class BasicCalculator {
public:
    int calculate(string s) {
        stack<int> resultStack;
        int result = 0;
        int number = 0;
        int sign = 1;  // 1 for positive, -1 for negative

        for (char c : s) {
            if (isdigit(c)) {
                number = number * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * number;
                number = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * number;
                number = 0;
                sign = -1;
            } else if (c == '(') {
                // Push current result and sign to stack
                resultStack.push(result);
                resultStack.push(sign);

                // Reset for new sub-expression
                result = 0;
                sign = 1;
            } else if (c == ')') {
                // Complete current sub-expression
                result += sign * number;
                number = 0;

                // Pop sign and previous result
                result *= resultStack.top(); resultStack.pop();  // sign
                result += resultStack.top(); resultStack.pop();  // previous result
            }
        }

        return result + (sign * number);
    }

    void demonstrateCalculator() {
        vector<string> expressions = {
            "1 + 1",
            "2-1 + 2",
            "(1+(4+5+2)-3)+(6+8)",
            "2147483647",
            "1-(     -2)"
        };

        cout << "=== Basic Calculator ===" << endl;
        for (const string& expr : expressions) {
            cout << "Expression: '" << expr << "'" << endl;
            cout << "Result: " << calculate(expr) << endl;
            cout << "---" << endl;
        }
    }
};
```

### Problem 5: Remove K Digits

**Problem Statement**: Given a non-negative integer num represented as a string and an integer k, remove k digits from the number so that the new number is the smallest possible.

**Example**:

- Input: `num = "1432219", k = 3` → Output: `"1219"`
- Input: `num = "10200", k = 1` → Output: `"200"`

**Approach Explanation**:

1. **Use monotonic increasing stack**: Maintain digits in increasing order
2. **Remove larger digits**: When we see a smaller digit, remove larger digits from stack
3. **Handle remaining removals**: If we haven't removed k digits, remove from end
4. **Handle leading zeros**: Remove leading zeros from final result

**Why this works**: To get the smallest number, we want smaller digits to appear before larger digits. Monotonic stack ensures this property.

```cpp
class RemoveKDigits {
public:
    string removeKdigits(string num, int k) {
        stack<char> monotonicStack;
        int toRemove = k;

        for (char digit : num) {
            // Remove larger digits to maintain increasing order
            while (!monotonicStack.empty() &&
                   monotonicStack.top() > digit &&
                   toRemove > 0) {
                monotonicStack.pop();
                toRemove--;
            }
            monotonicStack.push(digit);
        }

        // Remove remaining digits from end if needed
        while (toRemove > 0 && !monotonicStack.empty()) {
            monotonicStack.pop();
            toRemove--;
        }

        // Build result string
        string result = "";
        while (!monotonicStack.empty()) {
            result = monotonicStack.top() + result;
            monotonicStack.pop();
        }

        // Remove leading zeros
        int startIndex = 0;
        while (startIndex < result.length() && result[startIndex] == '0') {
            startIndex++;
        }

        result = result.substr(startIndex);
        return result.empty() ? "0" : result;
    }

    void demonstrateRemoveKDigits() {
        vector<pair<string, int>> testCases = {
            {"1432219", 3},
            {"10200", 1},
            {"10", 2},
            {"9", 1},
            {"54321", 2}
        };

        cout << "=== Remove K Digits ===" << endl;
        for (const auto& test : testCases) {
            cout << "Number: " << test.first << ", Remove: " << test.second << endl;
            cout << "Result: " << removeKdigits(test.first, test.second) << endl;
            cout << "---" << endl;
        }
    }
};
```

### Problem 6: Online Stock Span

**Problem Statement**: Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

**Approach**: Implement a class that processes stock prices one by one and maintains a stack of indices with decreasing prices.

```cpp
class StockSpanner {
private:
    stack<pair<int, int>> priceIndexStack;  // {price, index}
    int dayIndex;

public:
    StockSpanner() : dayIndex(0) {}

    int next(int price) {
        int span = 1;

        // Pop all days with price <= current price
        while (!priceIndexStack.empty() &&
               priceIndexStack.top().first <= price) {
            priceIndexStack.pop();
        }

        // Calculate span
        if (priceIndexStack.empty()) {
            span = dayIndex + 1;  // All previous days have lower price
        } else {
            span = dayIndex - priceIndexStack.top().second;
        }

        priceIndexStack.push({price, dayIndex});
        dayIndex++;

        return span;
    }

    void demonstrateStockSpanner() {
        cout << "=== Online Stock Span ===" << endl;
        vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

        StockSpanner spanner;
        for (int i = 0; i < prices.size(); i++) {
            int span = spanner.next(prices[i]);
            cout << "Day " << i + 1 << ": Price=" << prices[i]
                 << ", Span=" << span << endl;
        }
    }
};
```

---

## Real-World Applications

Stack data structure is ubiquitous in software systems, from low-level system operations to high-level application features. Understanding these applications helps appreciate the practical importance of stacks.

```mermaid
graph TD
    A[Real-World Stack Applications] --> B[System Software]
    A --> C[Application Software]
    A --> D[Web Technologies]
    A --> E[Compilers & Interpreters]

    B --> B1[Operating System Call Stack]
    B --> B2[Memory Management]
    B --> B3[Interrupt Handling]
    B --> B4[Process Context Switching]

    C --> C1[Undo/Redo in Editors]
    C --> C2[Browser History]
    C --> C3[Game State Management]
    C --> C4[Expression Calculators]

    D --> D1[JavaScript Call Stack]
    D --> D2[HTTP Request/Response]
    D --> D3[Navigation Stack]
    D --> D4[Session Management]

    E --> E1[Syntax Parsing]
    E --> E2[Symbol Table Management]
    E --> E3[Code Generation]
    E --> E4[Runtime Environment]

    style A fill:#f9f,stroke:#333,stroke-width:4px
    style B fill:#bbf,stroke:#333,stroke-width:2px
    style C fill:#bfb,stroke:#333,stroke-width:2px
    style D fill:#ffb,stroke:#333,stroke-width:2px
    style E fill:#fbb,stroke:#333,stroke-width:2px
```

### 1. Browser History Management

**Real-World Context**: Every web browser implements back/forward navigation using stack-like structures to manage user browsing history.

**Why Stack is Perfect**:

- **Back navigation**: LIFO order naturally shows recently visited pages first
- **Forward stack**: Maintains pages user can navigate forward to
- **New page visits**: Clear forward history (user chose new path)
- **Memory efficiency**: Only store necessary navigation context

**Browser Implementation Insights**:

- Back button → Pop from back stack, push to forward stack
- Forward button → Pop from forward stack, push to back stack
- New URL → Clear forward stack, push current page to back stack
- Memory limits → Implement maximum history size

```mermaid
graph LR
    A[User Visits google.com] --> B[Back Stack: empty]
    B --> C[User Visits facebook.com]
    C --> D[Back Stack: google.com]
    D --> E[User Visits youtube.com]
    E --> F[Back Stack: google.com, facebook.com]
    F --> G[User Clicks Back]
    G --> H[Back Stack: google.com]
    H --> I[Forward Stack: youtube.com]
    I --> J[User Visits linkedin.com]
    J --> K[Forward Stack: cleared]
    K --> L[Back Stack: google.com, facebook.com]

    style A fill:#e3f2fd
    style F fill:#ffecb3
    style L fill:#c8e6c9
```

```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class BrowserHistory {
private:
    stack<string> backStack;    // Pages we can go back to
    stack<string> forwardStack; // Pages we can go forward to
    string currentPage;

public:
    BrowserHistory(string homepage) {
        currentPage = homepage;
    }

    void visit(string url) {
        backStack.push(currentPage);
        currentPage = url;

        // Clear forward history when visiting new page
        while (!forwardStack.empty()) {
            forwardStack.pop();
        }

        cout << "Visited: " << url << endl;
    }

    string back(int steps) {
        while (steps > 0 && !backStack.empty()) {
            forwardStack.push(currentPage);
            currentPage = backStack.top();
            backStack.pop();
            steps--;
        }

        cout << "Went back to: " << currentPage << endl;
        return currentPage;
    }

    string forward(int steps) {
        while (steps > 0 && !forwardStack.empty()) {
            backStack.push(currentPage);
            currentPage = forwardStack.top();
            forwardStack.pop();
            steps--;
        }

        cout << "Went forward to: " << currentPage << endl;
        return currentPage;
    }

    void demonstrateBrowserHistory() {
        cout << "=== Browser History Demo ===" << endl;

        visit("google.com");
        visit("facebook.com");
        visit("youtube.com");

        back(1);        // youtube.com -> facebook.com
        back(1);        // facebook.com -> google.com
        forward(1);     // google.com -> facebook.com
        visit("linkedin.com");  // Clear forward history
        forward(1);     // Can't go forward
    }
};
```

### 2. Undo/Redo Functionality

**Real-World Context**: Text editors, image editors, IDEs, and most interactive software implement undo/redo using dual stack architecture.

**Why Dual Stack Design**:

- **Undo stack**: Stores previous states in reverse chronological order
- **Redo stack**: Stores undone operations that can be reapplied
- **State preservation**: Each entry represents complete state or command
- **Efficiency**: O(1) operations for both undo and redo

**Advanced Considerations**:

- **Memory management**: Limit undo history to prevent memory exhaustion
- **State compression**: Store deltas instead of full states when possible
- **Command pattern**: Store operations instead of states for better efficiency
- **Persistent storage**: Some applications save undo history to disk

```mermaid
graph TD
    A[Text Editor State Management] --> B[User Types Hello]
    B --> C[Undo Stack: empty → push empty state]
    C --> D[User Types World]
    D --> E[Undo Stack: empty, Hello]
    E --> F[User Presses Undo]
    F --> G[Undo Stack: empty]
    G --> H[Redo Stack: Hello World]
    H --> I[User Types New Text]
    I --> J[Redo Stack: cleared]
    J --> K[Undo Stack: empty, Hello]

    L[Memory Optimization] --> M[Delta Storage]
    L --> N[Command Pattern]
    L --> O[Circular Buffer]
    L --> P[Compression]

    style A fill:#e3f2fd
    style K fill:#c8e6c9
    style L fill:#fff3e0
```

```cpp
class TextEditor {
private:
    string text;
    stack<string> undoStack;
    stack<string> redoStack;

public:
    TextEditor() : text("") {}

    void type(string characters) {
        undoStack.push(text);  // Save current state
        text += characters;

        // Clear redo stack
        while (!redoStack.empty()) {
            redoStack.pop();
        }

        cout << "Typed: '" << characters << "' | Text: '" << text << "'" << endl;
    }

    void undo() {
        if (!undoStack.empty()) {
            redoStack.push(text);
            text = undoStack.top();
            undoStack.pop();
            cout << "Undo | Text: '" << text << "'" << endl;
        } else {
            cout << "Nothing to undo" << endl;
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            undoStack.push(text);
            text = redoStack.top();
            redoStack.pop();
            cout << "Redo | Text: '" << text << "'" << endl;
        } else {
            cout << "Nothing to redo" << endl;
        }
    }

    void demonstrateTextEditor() {
        cout << "=== Text Editor Demo ===" << endl;

        type("Hello");
        type(" World");
        type("!");

        undo();  // Remove "!"
        undo();  // Remove " World"

        redo();  // Add back " World"

        type(" from C++");  // This clears redo stack
        redo();  // Nothing to redo
    }
};
```

### 4. JavaScript Call Stack and Event Loop

**Real-World Context**: JavaScript engines use a call stack to manage function execution, which is crucial for understanding asynchronous programming and debugging.

**Call Stack Behavior**:

- **Synchronous execution**: Functions execute in LIFO order
- **Stack frames**: Each function call creates a stack frame
- **Error propagation**: Stack traces show call chain
- **Stack overflow**: Recursive calls can exceed stack limit

**Web Development Applications**:

1. **Event handling**: User interactions create function calls
2. **AJAX callbacks**: Asynchronous operations use callback stack
3. **Promise chains**: Then/catch handlers managed by stack
4. **Debugging**: Browser dev tools show call stack

```cpp
// Simulating JavaScript call stack behavior
class JavaScriptCallStack {
private:
    struct StackFrame {
        string functionName;
        int lineNumber;
        map<string, string> localVariables;

        StackFrame(string name, int line) : functionName(name), lineNumber(line) {}
    };

    stack<StackFrame> callStack;

public:
    void enterFunction(string functionName, int lineNumber) {
        callStack.push(StackFrame(functionName, lineNumber));
        cout << "Entering: " << functionName << " at line " << lineNumber << endl;
        printCallStack();
    }

    void exitFunction() {
        if (!callStack.empty()) {
            string functionName = callStack.top().functionName;
            callStack.pop();
            cout << "Exiting: " << functionName << endl;
            printCallStack();
        }
    }

    void setVariable(string name, string value) {
        if (!callStack.empty()) {
            callStack.top().localVariables[name] = value;
        }
    }

    void printCallStack() {
        cout << "Call Stack:" << endl;
        stack<StackFrame> temp = callStack;
        vector<StackFrame> frames;

        while (!temp.empty()) {
            frames.push_back(temp.top());
            temp.pop();
        }

        for (const auto& frame : frames) {
            cout << "  " << frame.functionName << ":" << frame.lineNumber << endl;
        }
        cout << "---" << endl;
    }

    void simulateJavaScript() {
        cout << "=== JavaScript Call Stack Simulation ===" << endl;

        enterFunction("main", 1);
        setVariable("x", "10");

        enterFunction("calculateSum", 5);
        setVariable("a", "5");
        setVariable("b", "3");

        enterFunction("add", 10);
        setVariable("result", "8");
        exitFunction();

        exitFunction();
        exitFunction();
    }
};
```

### 5. Compiler and Parser Applications

**Real-World Context**: Compilers, interpreters, and code analysis tools extensively use stacks for parsing and code generation.

**Parsing Applications**:

1. **Syntax analysis**: Recursive descent parsers use implicit call stack
2. **Expression parsing**: Operator precedence handled by stack
3. **Symbol table management**: Nested scopes managed with stack
4. **Error recovery**: Stack helps backtrack during syntax errors

**Code Generation**:

1. **Intermediate code**: Stack machines for virtual execution
2. **Register allocation**: Stack for managing temporary values
3. **Optimization**: Stack for tracking optimization contexts

```mermaid
graph TD
    A[Compiler Stack Applications] --> B[Lexical Analysis]
    A --> C[Syntax Analysis]
    A --> D[Semantic Analysis]
    A --> E[Code Generation]

    B --> B1[Token Stack for Lookahead]
    C --> C1[Parse Stack for Grammar Rules]
    C --> C2[Operator Stack for Expressions]
    D --> D1[Symbol Table Stack for Scopes]
    D --> D2[Type Stack for Checking]
    E --> E1[Code Stack for Optimization]
    E --> E2[Register Stack for Allocation]

    F[Real Example] --> G[Expression: a + b * c]
    G --> H[Operator Stack: +, *]
    H --> I[Output: a b c * +]

    style A fill:#e3f2fd
    style F fill:#fff3e0
    style I fill:#c8e6c9
```

### 6. Game Development Applications

**Real-World Context**: Game engines and interactive applications use stacks for state management, AI, and user interface systems.

**Game State Management**:

1. **Game state stack**: Menu → Game → Pause → Settings
2. **AI decision trees**: Depth-first search with backtracking
3. **Pathfinding**: DFS algorithms for navigation
4. **Animation sequencing**: Stack of animation states

```cpp
class GameStateManager {
private:
    enum GameState { MENU, PLAYING, PAUSED, SETTINGS, INVENTORY };
    stack<GameState> stateStack;

public:
    void pushState(GameState newState) {
        stateStack.push(newState);
        cout << "Entered state: " << stateToString(newState) << endl;
    }

    void popState() {
        if (!stateStack.empty()) {
            GameState poppedState = stateStack.top();
            stateStack.pop();
            cout << "Exited state: " << stateToString(poppedState) << endl;
        }
    }

    GameState getCurrentState() {
        return stateStack.empty() ? MENU : stateStack.top();
    }

    string stateToString(GameState state) {
        switch(state) {
            case MENU: return "Menu";
            case PLAYING: return "Playing";
            case PAUSED: return "Paused";
            case SETTINGS: return "Settings";
            case INVENTORY: return "Inventory";
            default: return "Unknown";
        }
    }

    void simulateGameplay() {
        cout << "=== Game State Management ===" << endl;

        pushState(MENU);        // Start at menu
        pushState(PLAYING);     // Start game
        pushState(PAUSED);      // Player pauses
        pushState(SETTINGS);    // Open settings

        popState();             // Close settings
        popState();             // Resume game
        pushState(INVENTORY);   // Open inventory
        popState();             // Close inventory
        popState();             // End game, back to menu
    }
};
```

---

```cpp
class CallStackSimulator {
private:
    struct FunctionCall {
        string functionName;
        vector<string> parameters;
        string returnValue;

        FunctionCall(string name, vector<string> params)
            : functionName(name), parameters(params), returnValue("") {}
    };

    stack<FunctionCall> callStack;

public:
    void enterFunction(string functionName, vector<string> parameters) {
        callStack.push(FunctionCall(functionName, parameters));

        cout << "Entering " << functionName << "(";
        for (int i = 0; i < parameters.size(); i++) {
            cout << parameters[i];
            if (i < parameters.size() - 1) cout << ", ";
        }
        cout << ")" << endl;

        printCallStack();
    }

    void exitFunction(string returnValue) {
        if (!callStack.empty()) {
            FunctionCall& topCall = callStack.top();
            topCall.returnValue = returnValue;

            cout << "Exiting " << topCall.functionName
                 << " with return value: " << returnValue << endl;

            callStack.pop();
            printCallStack();
        }
    }

    void printCallStack() {
        cout << "Call Stack (top to bottom):" << endl;

        stack<FunctionCall> tempStack = callStack;
        vector<FunctionCall> stackContents;

        while (!tempStack.empty()) {
            stackContents.push_back(tempStack.top());
            tempStack.pop();
        }

        for (const auto& call : stackContents) {
            cout << "  " << call.functionName << "(";
            for (int i = 0; i < call.parameters.size(); i++) {
                cout << call.parameters[i];
                if (i < call.parameters.size() - 1) cout << ", ";
            }
            cout << ")" << endl;
        }
        cout << "---" << endl;
    }

    void demonstrateCallStack() {
        cout << "=== Call Stack Simulation ===" << endl;

        enterFunction("main", {});
        enterFunction("calculateSum", {"a", "b"});
        enterFunction("add", {"5", "3"});
        exitFunction("8");
        exitFunction("8");
        enterFunction("printResult", {"8"});
        exitFunction("void");
        exitFunction("0");
    }
};
```

---

## Complexity Analysis

### Time Complexity Summary

| Operation/Algorithm        | Best Case | Average Case | Worst Case | Space Complexity |
| -------------------------- | --------- | ------------ | ---------- | ---------------- |
| **Basic Stack Operations** |
| Push                       | O(1)      | O(1)         | O(1)\*     | O(1)             |
| Pop                        | O(1)      | O(1)         | O(1)       | O(1)             |
| Top/Peek                   | O(1)      | O(1)         | O(1)       | O(1)             |
| **Stack Applications**     |
| Balanced Parentheses       | O(n)      | O(n)         | O(n)       | O(n)             |
| Next Greater Element       | O(n)      | O(n)         | O(n)       | O(n)             |
| Stock Span                 | O(n)      | O(n)         | O(n)       | O(n)             |
| Infix to Postfix           | O(n)      | O(n)         | O(n)       | O(n)             |
| Postfix Evaluation         | O(n)      | O(n)         | O(n)       | O(n)             |
| **Advanced Problems**      |
| Largest Rectangle          | O(n)      | O(n)         | O(n)       | O(n)             |
| Min Stack                  | O(1)      | O(1)         | O(1)       | O(1)             |
| Sliding Window Max         | O(n)      | O(n)         | O(n)       | O(k)             |

\*Amortized O(1) for dynamic array implementation due to occasional resizing

### Space Complexity Analysis

```mermaid
graph TD
    A[Stack Space Complexity] --> B[Array Implementation]
    A --> C[Linked List Implementation]

    B --> D[Fixed Size: O(n)]
    B --> E[Dynamic Size: O(n) + resize overhead]

    C --> F[Node Overhead: O(n) + pointer space]
    C --> G[No resize needed]

    H[Stack Applications] --> I[Auxiliary Space]
    I --> J[Balanced Parentheses: O(n) worst case]
    I --> K[Expression Evaluation: O(n) for operators]
    I --> L[Next Greater Element: O(n) for indices]
```

---

## Advanced Topics and Optimizations

### 1. Stack with Multiple Data Types

```cpp
#include <variant>
#include <iostream>
using namespace std;

class MultiTypeStack {
private:
    stack<variant<int, string, double>> multiStack;

public:
    template<typename T>
    void push(const T& value) {
        multiStack.push(value);
    }

    template<typename T>
    T pop() {
        if (multiStack.empty()) {
            throw runtime_error("Stack is empty");
        }

        auto value = multiStack.top();
        multiStack.pop();

        if (holds_alternative<T>(value)) {
            return get<T>(value);
        } else {
            throw runtime_error("Type mismatch");
        }
    }

    void printTop() {
        if (multiStack.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        auto value = multiStack.top();

        visit([](const auto& v) {
            cout << "Top element: " << v << " (type: " << typeid(v).name() << ")" << endl;
        }, value);
    }

    void demonstrateMultiTypeStack() {
        cout << "=== Multi-Type Stack Demo ===" << endl;

        push<int>(42);
        push<string>("Hello");
        push<double>(3.14);

        printTop();  // 3.14

        double d = pop<double>();
        cout << "Popped double: " << d << endl;

        printTop();  // "Hello"

        string s = pop<string>();
        cout << "Popped string: " << s << endl;

        printTop();  // 42
    }
};
```

### 2. Thread-Safe Stack

```cpp
#include <mutex>
#include <condition_variable>

template<typename T>
class ThreadSafeStack {
private:
    mutable mutex mtx;
    stack<T> data;
    condition_variable cv;

public:
    void push(T item) {
        lock_guard<mutex> lock(mtx);
        data.push(move(item));
        cv.notify_one();
    }

    bool tryPop(T& item) {
        lock_guard<mutex> lock(mtx);
        if (data.empty()) {
            return false;
        }
        item = move(data.top());
        data.pop();
        return true;
    }

    shared_ptr<T> tryPop() {
        lock_guard<mutex> lock(mtx);
        if (data.empty()) {
            return shared_ptr<T>();
        }
        shared_ptr<T> result = make_shared<T>(move(data.top()));
        data.pop();
        return result;
    }

    void waitAndPop(T& item) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] { return !data.empty(); });
        item = move(data.top());
        data.pop();
    }

    shared_ptr<T> waitAndPop() {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] { return !data.empty(); });
        shared_ptr<T> result = make_shared<T>(move(data.top()));
        data.pop();
        return result;
    }

    bool empty() const {
        lock_guard<mutex> lock(mtx);
        return data.empty();
    }

    size_t size() const {
        lock_guard<mutex> lock(mtx);
        return data.size();
    }
};
```

---

## Practice Problems and Solutions

### Problem Set 1: Basic Stack Operations

```cpp
class BasicStackProblems {
public:
    // Problem: Remove All Adjacent Duplicates
    string removeDuplicates(string s) {
        stack<char> st;

        for (char c : s) {
            if (!st.empty() && st.top() == c) {
                st.pop();  // Remove duplicate
            } else {
                st.push(c);
            }
        }

        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }

    // Problem: Valid Parentheses with Multiple Types
    bool isValidParentheses(string s) {
        stack<char> st;
        unordered_map<char, char> mapping = {
            {')', '('}, {']', '['}, {'}', '{'}
        };

        for (char c : s) {
            if (mapping.find(c) != mapping.end()) {
                if (st.empty() || st.top() != mapping[c]) {
                    return false;
                }
                st.pop();
            } else {
                st.push(c);
            }
        }

        return st.empty();
    }

    // Problem: Simplify Unix Path
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string directory;

        while (getline(ss, directory, '/')) {
            if (directory == "" || directory == ".") {
                continue;  // Skip empty and current directory
            } else if (directory == "..") {
                if (!st.empty()) {
                    st.pop();  // Go to parent directory
                }
            } else {
                st.push(directory);
            }
        }

        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result.empty() ? "/" : result;
    }

    void demonstrateBasicProblems() {
        cout << "=== Basic Stack Problems Demo ===" << endl;

        cout << "Remove Duplicates 'abbaca': " << removeDuplicates("abbaca") << endl;
        cout << "Valid Parentheses '()[]{}': " << isValidParentheses("()[]{}") << endl;
        cout << "Simplify Path '/a//b////c/d//././/..': "
             << simplifyPath("/a//b////c/d//././/..") << endl;
    }
};
```

### Problem Set 2: Advanced Applications

```cpp
class AdvancedStackProblems {
public:
    // Problem: Asteroid Collision
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int asteroid : asteroids) {
            bool destroyed = false;

            while (!st.empty() && asteroid < 0 && st.top() > 0) {
                if (st.top() < -asteroid) {
                    st.pop();  // Top asteroid destroyed
                    continue;
                } else if (st.top() == -asteroid) {
                    st.pop();  // Both destroyed
                }
                destroyed = true;  // Current asteroid destroyed
                break;
            }

            if (!destroyed) {
                st.push(asteroid);
            }
        }

        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }

    // Problem: Daily Temperatures
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> indexStack;

        for (int i = 0; i < n; i++) {
            while (!indexStack.empty() &&
                   temperatures[i] > temperatures[indexStack.top()]) {
                int index = indexStack.top();
                indexStack.pop();
                result[index] = i - index;
            }
            indexStack.push(i);
        }

        return result;
    }

    // Problem: Decode String
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int currentCount = 0;

        for (char c : s) {
            if (isdigit(c)) {
                currentCount = currentCount * 10 + (c - '0');
            } else if (c == '[') {
                countStack.push(currentCount);
                stringStack.push(currentString);
                currentCount = 0;
                currentString = "";
            } else if (c == ']') {
                int count = countStack.top();
                countStack.pop();
                string prevString = stringStack.top();
                stringStack.pop();

                string temp = "";
                for (int i = 0; i < count; i++) {
                    temp += currentString;
                }
                currentString = prevString + temp;
            } else {
                currentString += c;
            }
        }

        return currentString;
    }

    void demonstrateAdvancedProblems() {
        cout << "=== Advanced Stack Problems Demo ===" << endl;

        vector<int> asteroids = {5, 10, -5};
        vector<int> result = asteroidCollision(asteroids);
        cout << "Asteroid Collision [5,10,-5]: ";
        for (int r : result) cout << r << " ";
        cout << endl;

        vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
        vector<int> days = dailyTemperatures(temps);
        cout << "Daily Temperatures: ";
        for (int d : days) cout << d << " ";
        cout << endl;

        cout << "Decode String '3[a2[c]]': " << decodeString("3[a2[c]]") << endl;
    }
};
```

---

## Conclusion and Best Practices

### Stack Problem Recognition Patterns

Understanding when to use a stack is crucial for efficient problem-solving. Here are the key patterns that indicate stack usage:

```mermaid
graph TD
    A[Stack Usage Patterns] --> B[Structure Recognition]
    A --> C[Order Requirements]
    A --> D[Matching Problems]
    A --> E[State Management]

    B --> B1[Nested Structures]
    B --> B2[Hierarchical Data]
    B --> B3[Tree-like Relations]

    C --> C1[LIFO Processing]
    C --> C2[Recent First Access]
    C --> C3[Reverse Order Needs]

    D --> D1[Bracket Matching]
    D --> D2[Tag Validation]
    D --> D3[Expression Parsing]

    E --> E1[Undo/Redo Systems]
    E --> E2[Navigation History]
    E --> E3[Function Call Management]

    F[Performance Indicators] --> G[O1 Push/Pop Needed]
    F --> H[Memory Efficiency Important]
    F --> I[Simple Access Pattern]

    style A fill:#f9f,stroke:#333,stroke-width:4px
    style F fill:#e3f2fd
```

### When to Use Stack vs Other Data Structures

| **Use Stack When**           | **Use Alternative When**   | **Alternative** |
| ---------------------------- | -------------------------- | --------------- |
| Need LIFO behavior           | Need FIFO behavior         | Queue           |
| Bracket/parentheses matching | Need random access         | Array/Vector    |
| Expression evaluation        | Need bidirectional access  | Deque           |
| Undo/Redo functionality      | Need indexed operations    | List/Array      |
| DFS traversal                | Need BFS traversal         | Queue           |
| Function call simulation     | Need priority-based access | Priority Queue  |
| Backtracking algorithms      | Need sorted data           | Balanced BST    |

### Performance Optimization Guidelines

#### 1. Memory Management

```cpp
// Good: Pre-allocate when size is known
class OptimizedStack {
private:
    vector<int> data;
    int topIndex;

public:
    OptimizedStack(int expectedSize) {
        data.reserve(expectedSize);  // Pre-allocate memory
        topIndex = -1;
    }

    void push(int value) {
        if (topIndex + 1 < data.capacity()) {
            data[++topIndex] = value;
        } else {
            data.push_back(value);
            topIndex = data.size() - 1;
        }
    }
};
```

#### 2. Avoid Common Pitfalls

```cpp
class SafeStack {
public:
    int pop() {
        if (empty()) {
            throw underflow_error("Cannot pop from empty stack");
        }
        // ... rest of implementation
    }

    int top() const {  // Make const when not modifying
        if (empty()) {
            throw runtime_error("Stack is empty");
        }
        // ... rest of implementation
    }

    // Always provide size and empty methods
    bool empty() const noexcept { return topIndex < 0; }
    size_t size() const noexcept { return topIndex + 1; }
};
```

### Algorithm Complexity Reference

#### Basic Operations

- **Push**: O(1) average, O(n) worst case (resizing)
- **Pop**: O(1) always
- **Top/Peek**: O(1) always
- **Empty**: O(1) always
- **Size**: O(1) if maintained, O(n) if calculated

#### Application Complexities

- **Balanced Parentheses**: O(n) time, O(n) space
- **Expression Evaluation**: O(n) time, O(n) space
- **Next Greater Element**: O(n) time, O(n) space (amortized)
- **Largest Rectangle**: O(n) time, O(n) space
- **Stock Span**: O(n) time, O(n) space (amortized)

### Design Patterns with Stacks

#### 1. Command Pattern for Undo/Redo

```cpp
class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() = default;
};

class CommandManager {
private:
    stack<unique_ptr<Command>> undoStack;
    stack<unique_ptr<Command>> redoStack;

public:
    void executeCommand(unique_ptr<Command> command) {
        command->execute();
        undoStack.push(move(command));

        // Clear redo stack when new command is executed
        while (!redoStack.empty()) {
            redoStack.pop();
        }
    }

    void undo() {
        if (!undoStack.empty()) {
            auto command = move(undoStack.top());
            undoStack.pop();
            command->undo();
            redoStack.push(move(command));
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            auto command = move(redoStack.top());
            redoStack.pop();
            command->execute();
            undoStack.push(move(command));
        }
    }
};
```

#### 2. State Machine with Stack

```cpp
template<typename StateType>
class StateMachine {
private:
    stack<StateType> stateStack;

public:
    void pushState(StateType newState) {
        stateStack.push(newState);
    }

    void popState() {
        if (!stateStack.empty()) {
            stateStack.pop();
        }
    }

    StateType getCurrentState() {
        return stateStack.empty() ? StateType{} : stateStack.top();
    }

    bool hasStates() const {
        return !stateStack.empty();
    }
};
```

### Testing and Debugging Stack Code

#### Essential Test Cases

1. **Empty stack operations**: Test pop(), top() on empty stack
2. **Single element**: Test all operations with one element
3. **Capacity limits**: Test resizing behavior
4. **Large datasets**: Test performance with many elements
5. **Exception safety**: Ensure proper cleanup on exceptions

#### Debugging Techniques

```cpp
class DebuggableStack {
private:
    stack<int> data;
    bool debugMode;

public:
    void enableDebug(bool enable) { debugMode = enable; }

    void push(int value) {
        if (debugMode) {
            cout << "Pushing " << value << ", size will be " << data.size() + 1 << endl;
        }
        data.push(value);
    }

    int pop() {
        if (debugMode) {
            cout << "Popping " << data.top() << ", size will be " << data.size() - 1 << endl;
        }
        int value = data.top();
        data.pop();
        return value;
    }

    void printState() const {
        cout << "Stack size: " << data.size() << endl;
        if (!data.empty()) {
            cout << "Top element: " << data.top() << endl;
        }
    }
};
```

### Final Recommendations

#### For Beginners

1. **Master basic operations** before attempting complex problems
2. **Practice with simple examples** like balanced parentheses
3. **Understand LIFO principle** through visualization
4. **Start with STL stack** before implementing custom versions

#### For Intermediate Developers

1. **Learn monotonic stack patterns** for optimization problems
2. **Practice expression evaluation** and parsing problems
3. **Understand recursion-stack relationship** deeply
4. **Implement thread-safe versions** for concurrent applications

#### For Advanced Developers

1. **Optimize for specific use cases** (memory, speed, functionality)
2. **Design stack-based DSLs** and interpreters
3. **Implement custom memory management** for performance-critical applications
4. **Contribute to stack-based algorithms** in competitive programming

### Common Interview Questions Summary

#### Easy Level

- Implement stack using arrays/linked lists
- Valid parentheses checking
- Remove duplicates using stack
- Implement queue using two stacks

#### Medium Level

- Next greater element variants
- Largest rectangle in histogram
- Basic calculator implementation
- Stock span problem variations

#### Hard Level

- Expression evaluation with complex operators
- Minimum number of insertions for valid parentheses
- Maximum rectangle in binary matrix
- Design browser with back/forward functionality

### Resources for Further Learning

1. **Algorithm Textbooks**: CLRS, Sedgewick's Algorithms
2. **Online Platforms**: LeetCode, HackerRank, Codeforces
3. **System Design**: Understanding call stacks in operating systems
4. **Compiler Design**: Stack usage in parsing and code generation
5. **Game Development**: State management and AI applications

Remember: **Stack is not just a data structure—it's a fundamental concept that appears everywhere in computer science. Mastering stacks opens doors to understanding recursion, parsing, system design, and many advanced algorithms.**
