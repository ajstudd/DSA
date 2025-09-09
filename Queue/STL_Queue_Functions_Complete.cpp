#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <list>
#include <functional>

using namespace std;

/*
=============================================================================
                    COMPLETE STL QUEUE FUNCTIONS REFERENCE
=============================================================================

This file demonstrates ALL STL queue functions with detailed explanations,
examples, and use cases. The queue in C++ STL is a container adapter that
follows FIFO (First In, First Out) principle.

Header: #include <queue>
Default underlying container: deque
Other allowed containers: list, deque (must support front(), back(), push_back(), pop_front())

=============================================================================
*/

void demonstrateBasicQueueOperations()
{
    cout << "\n=== BASIC QUEUE OPERATIONS ===" << endl;

    // 1. CONSTRUCTOR - Creating queues
    cout << "\n1. CONSTRUCTORS:" << endl;

    // Default constructor - creates empty queue
    queue<int> q1;
    cout << "   queue<int> q1; - Creates empty queue" << endl;

    // Constructor with underlying container
    deque<int> dq = {1, 2, 3, 4, 5};
    queue<int> q2(dq);
    cout << "   queue<int> q2(deque); - Creates queue from deque" << endl;

    // Copy constructor
    queue<int> q3(q2);
    cout << "   queue<int> q3(q2); - Copy constructor" << endl;

    // With different underlying containers
    queue<int, list<int>> q_list;
    queue<int, deque<int>> q_deque;
    cout << "   Can use list or deque as underlying container" << endl;
}

void demonstrateCapacityFunctions()
{
    cout << "\n=== CAPACITY FUNCTIONS ===" << endl;

    queue<int> q;

    // 2. EMPTY() - Check if queue is empty
    cout << "\n2. empty() - Returns true if queue is empty" << endl;
    cout << "   q.empty(): " << q.empty() << " (1 = true, 0 = false)" << endl;

    q.push(10);
    q.push(20);
    cout << "   After adding elements, q.empty(): " << q.empty() << endl;

    // 3. SIZE() - Get number of elements
    cout << "\n3. size() - Returns number of elements in queue" << endl;
    cout << "   q.size(): " << q.size() << endl;

    q.push(30);
    q.push(40);
    cout << "   After adding more elements, q.size(): " << q.size() << endl;
}

void demonstrateElementAccess()
{
    cout << "\n=== ELEMENT ACCESS FUNCTIONS ===" << endl;

    queue<int> q;
    for (int i = 1; i <= 5; i++)
    {
        q.push(i * 10);
    }

    // 4. FRONT() - Access first element (oldest)
    cout << "\n4. front() - Returns reference to first element (next to be removed)" << endl;
    cout << "   Queue contains: 10, 20, 30, 40, 50 (front to back)" << endl;
    cout << "   q.front(): " << q.front() << endl;
    cout << "   Can modify: q.front() = 15" << endl;
    q.front() = 15;
    cout << "   After modification, q.front(): " << q.front() << endl;

    // 5. BACK() - Access last element (newest)
    cout << "\n5. back() - Returns reference to last element (most recently added)" << endl;
    cout << "   q.back(): " << q.back() << endl;
    cout << "   Can modify: q.back() = 55" << endl;
    q.back() = 55;
    cout << "   After modification, q.back(): " << q.back() << endl;
}

void demonstrateModifiers()
{
    cout << "\n=== MODIFIER FUNCTIONS ===" << endl;

    queue<int> q;

    // 6. PUSH() - Add element to back
    cout << "\n6. push(value) - Adds element to the back of queue" << endl;
    cout << "   Adding elements 1, 2, 3, 4, 5:" << endl;
    for (int i = 1; i <= 5; i++)
    {
        q.push(i);
        cout << "   Pushed " << i << ", queue size now: " << q.size() << endl;
    }

    // 7. POP() - Remove element from front
    cout << "\n7. pop() - Removes element from front (FIFO)" << endl;
    cout << "   Note: pop() doesn't return the removed element!" << endl;
    cout << "   Before pop - front: " << q.front() << ", size: " << q.size() << endl;
    q.pop();
    cout << "   After pop - front: " << q.front() << ", size: " << q.size() << endl;

    // 8. EMPLACE() - Construct element in-place (C++11)
    cout << "\n8. emplace(args...) - Constructs element in-place at back" << endl;
    cout << "   More efficient than push for complex objects" << endl;
    q.emplace(100);
    cout << "   Emplaced 100, back: " << q.back() << ", size: " << q.size() << endl;

    // 9. SWAP() - Swap contents with another queue
    cout << "\n9. swap(other_queue) - Swaps contents with another queue" << endl;
    queue<int> q2;
    q2.push(99);
    q2.push(88);
    cout << "   Before swap - q.size(): " << q.size() << ", q2.size(): " << q2.size() << endl;
    q.swap(q2);
    cout << "   After swap - q.size(): " << q.size() << ", q2.size(): " << q2.size() << endl;
}

void demonstrateAdvancedOperations()
{
    cout << "\n=== ADVANCED OPERATIONS ===" << endl;

    // 10. Assignment operator
    cout << "\n10. Assignment operator (=)" << endl;
    queue<int> q1, q2;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q2 = q1; // Deep copy
    cout << "   q2 = q1; - Deep copy, q2.size(): " << q2.size() << endl;

    // 11. Comparison operators
    cout << "\n11. Comparison operators (==, !=, <, <=, >, >=)" << endl;
    queue<int> qa, qb;
    qa.push(1);
    qa.push(2);
    qb.push(1);
    qb.push(2);
    cout << "   qa == qb: " << (qa == qb) << endl;
    qa.push(3);
    cout << "   After adding 3 to qa, qa == qb: " << (qa == qb) << endl;
    cout << "   qa != qb: " << (qa != qb) << endl;
}

void demonstrateEmplaceVsPush()
{
    cout << "\n=== EMPLACE() vs PUSH() - DETAILED COMPARISON ===" << endl;

    // Define a complex class to show the difference
    class Person
    {
    public:
        string name;
        int age;
        string city;

        // Constructor
        Person(const string &n, int a, const string &c) : name(n), age(a), city(c)
        {
            cout << "   Constructor called for: " << name << endl;
        }

        // Copy constructor
        Person(const Person &other) : name(other.name), age(other.age), city(other.city)
        {
            cout << "   Copy constructor called for: " << name << endl;
        }

        // Move constructor
        Person(Person &&other) noexcept : name(move(other.name)), age(other.age), city(move(other.city))
        {
            cout << "   Move constructor called for: " << name << endl;
        }

        void display() const
        {
            cout << "   " << name << " (" << age << ") from " << city;
        }
    };

    cout << "\n1. USING PUSH() - Creates temporary object then copies/moves:" << endl;
    queue<Person> q1;
    cout << "   q1.push(Person(\"Alice\", 25, \"NYC\"));" << endl;
    q1.push(Person("Alice", 25, "NYC")); // Creates temp object, then copies/moves

    cout << "\n2. USING EMPLACE() - Constructs object directly in queue:" << endl;
    queue<Person> q2;
    cout << "   q2.emplace(\"Bob\", 30, \"LA\");" << endl;
    q2.emplace("Bob", 30, "LA"); // Constructs directly, no temporary object

    cout << "\n3. PERFORMANCE COMPARISON:" << endl;
    cout << "   push(): Constructor + Copy/Move constructor (2 operations)" << endl;
    cout << "   emplace(): Only Constructor (1 operation) - MORE EFFICIENT!" << endl;

    cout << "\n4. WITH SIMPLE TYPES (int, double, etc.) - No significant difference:" << endl;
    queue<int> q_int;
    q_int.push(42);    // Same efficiency
    q_int.emplace(43); // Same efficiency
    cout << "   For simple types, both push(42) and emplace(43) are equally efficient" << endl;

    cout << "\n5. WHEN TO USE EACH:" << endl;
    cout << "   - Use emplace() for complex objects (classes/structs)" << endl;
    cout << "   - Use emplace() when you have constructor arguments" << endl;
    cout << "   - Use push() when you already have an object instance" << endl;
    cout << "   - Use push() for simple types (both are fine)" << endl;

    cout << "\n6. EXAMPLES WITH DIFFERENT SCENARIOS:" << endl;

    // Scenario 1: Already have an object
    Person existing("Charlie", 35, "Chicago");
    queue<Person> q3;
    cout << "\n   When you already have an object:" << endl;
    cout << "   q3.push(existing); // Better choice" << endl;
    q3.push(existing);

    // Scenario 2: Need to construct object
    queue<Person> q4;
    cout << "\n   When you need to construct an object:" << endl;
    cout << "   q4.emplace(\"Diana\", 28, \"Miami\"); // Better choice" << endl;
    q4.emplace("Diana", 28, "Miami");

    cout << "\n7. EMPLACE WITH CONTAINERS (Advanced):" << endl;
    queue<vector<int>> q_vectors;
    cout << "   q_vectors.emplace(5, 100); // Creates vector with 5 elements of value 100" << endl;
    q_vectors.emplace(5, 100); // Calls vector constructor vector(5, 100)
    cout << "   Vector size: " << q_vectors.front().size() << ", first element: " << q_vectors.front()[0] << endl;

    cout << "\n8. SUMMARY:" << endl;
    cout << "   emplace() = Construct in-place (more efficient for complex objects)" << endl;
    cout << "   push() = Copy/move existing object (use when object already exists)" << endl;
}

void demonstrateCompleteQueueUsage()
{
    cout << "\n=== COMPLETE QUEUE USAGE EXAMPLE ===" << endl;

    queue<string> taskQueue;

    cout << "\nSimulating a task processing system:" << endl;

    // Adding tasks
    vector<string> tasks = {"Task1", "Task2", "Task3", "Task4", "Task5"};
    cout << "\nAdding tasks to queue:" << endl;
    for (const string &task : tasks)
    {
        taskQueue.push(task);
        cout << "   Added: " << task << " (Queue size: " << taskQueue.size() << ")" << endl;
    }

    // Processing tasks
    cout << "\nProcessing tasks (FIFO order):" << endl;
    while (!taskQueue.empty())
    {
        cout << "   Processing: " << taskQueue.front()
             << " (Remaining: " << (taskQueue.size() - 1) << ")" << endl;
        taskQueue.pop();
    }

    cout << "\nAll tasks completed! Queue is empty: " << taskQueue.empty() << endl;
}

void demonstrateQueueWithCustomObjects()
{
    cout << "\n=== QUEUE WITH CUSTOM OBJECTS ===" << endl;

    struct Task
    {
        int id;
        string description;

        Task(int i, string desc) : id(i), description(desc) {}

        // For demonstration
        void display() const
        {
            cout << "Task " << id << ": " << description;
        }
    };

    queue<Task> taskQueue;

    // Using push
    taskQueue.push(Task(1, "Initialize system"));

    // Using emplace (more efficient - constructs in place)
    taskQueue.emplace(2, "Load configuration");
    taskQueue.emplace(3, "Start services");

    cout << "\nProcessing custom objects:" << endl;
    while (!taskQueue.empty())
    {
        cout << "   ";
        taskQueue.front().display();
        cout << endl;
        taskQueue.pop();
    }
}

void demonstrateQueueWithDifferentContainers()
{
    cout << "\n=== QUEUE WITH DIFFERENT UNDERLYING CONTAINERS ===" << endl;

    // Default (deque)
    queue<int> q_default;

    // Explicit deque
    queue<int, deque<int>> q_deque;

    // With list
    queue<int, list<int>> q_list;

    // Add some elements to each
    for (int i = 1; i <= 3; i++)
    {
        q_default.push(i);
        q_deque.push(i * 10);
        q_list.push(i * 100);
    }

    cout << "\nAll queue types work the same way:" << endl;
    cout << "   Default queue front: " << q_default.front() << endl;
    cout << "   Deque queue front: " << q_deque.front() << endl;
    cout << "   List queue front: " << q_list.front() << endl;
}

void demonstrateCommonPitfalls()
{
    cout << "\n=== COMMON PITFALLS AND BEST PRACTICES ===" << endl;

    queue<int> q;

    cout << "\n1. ALWAYS check if queue is empty before accessing front/back:" << endl;
    // WRONG: q.front(); // Undefined behavior if empty
    // CORRECT:
    if (!q.empty())
    {
        cout << "   Front: " << q.front() << endl;
    }
    else
    {
        cout << "   Queue is empty - cannot access front!" << endl;
    }

    cout << "\n2. pop() doesn't return the removed element:" << endl;
    q.push(42);
    cout << "   Before pop, front is: " << q.front() << endl;
    q.pop(); // Doesn't return 42!
    cout << "   After pop, queue is empty: " << q.empty() << endl;

    cout << "\n3. To get and remove element, use front() then pop():" << endl;
    q.push(100);
    int value = q.front(); // Get the value
    q.pop();               // Remove it
    cout << "   Retrieved and removed: " << value << endl;

    cout << "\n4. Queue elements are accessed in FIFO order:" << endl;
    for (int i = 1; i <= 3; i++)
        q.push(i);
    cout << "   Added: 1, 2, 3" << endl;
    cout << "   Will be removed in order: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    cout << "=============================================================================";
    cout << "\n              COMPLETE STL QUEUE FUNCTIONS DEMONSTRATION";
    cout << "\n=============================================================================";

    demonstrateBasicQueueOperations();
    demonstrateCapacityFunctions();
    demonstrateElementAccess();
    demonstrateModifiers();
    demonstrateAdvancedOperations();
    demonstrateEmplaceVsPush();
    demonstrateCompleteQueueUsage();
    demonstrateQueueWithCustomObjects();
    demonstrateQueueWithDifferentContainers();
    demonstrateCommonPitfalls();

    cout << "\n=============================================================================";
    cout << "\n                           SUMMARY OF ALL FUNCTIONS";
    cout << "\n=============================================================================";
    cout << "\nCONSTRUCTORS:";
    cout << "\n   queue<T>()              - Default constructor";
    cout << "\n   queue<T>(container)     - Constructor with underlying container";
    cout << "\n   queue<T>(other)         - Copy constructor";

    cout << "\nCAPACITY:";
    cout << "\n   empty()                 - Check if queue is empty";
    cout << "\n   size()                  - Get number of elements";

    cout << "\nELEMENT ACCESS:";
    cout << "\n   front()                 - Access first element (next to be removed)";
    cout << "\n   back()                  - Access last element (most recently added)";

    cout << "\nMODIFIERS:";
    cout << "\n   push(value)             - Add element to back";
    cout << "\n   pop()                   - Remove element from front";
    cout << "\n   emplace(args...)        - Construct element in-place at back";
    cout << "\n   swap(other)             - Swap contents with another queue";

    cout << "\nOPERATORS:";
    cout << "\n   =                       - Assignment operator";
    cout << "\n   ==, !=, <, <=, >, >=    - Comparison operators";

    cout << "\n\nREMEMBER:";
    cout << "\n   - Queue follows FIFO (First In, First Out) principle";
    cout << "\n   - Always check empty() before accessing front()/back()";
    cout << "\n   - pop() doesn't return the removed element";
    cout << "\n   - Use front() then pop() to get and remove element";
    cout << "\n   - Default underlying container is deque";
    cout << "\n=============================================================================\n";

    return 0;
}

/*
=============================================================================
                             ADDITIONAL NOTES
=============================================================================

TIME COMPLEXITIES:
- push():    O(1)
- pop():     O(1)
- front():   O(1)
- back():    O(1)
- empty():   O(1)
- size():    O(1)
- swap():    O(1)

SPACE COMPLEXITY: O(n) where n is number of elements

WHEN TO USE QUEUE:
- BFS (Breadth-First Search) in graphs/trees
- Level order traversal of trees
- Task scheduling systems
- Print queue management
- Buffer for data streams
- Process scheduling in operating systems

ALTERNATIVES:
- priority_queue: When you need priority-based ordering
- deque: When you need double-ended operations
- vector: When you need random access
- stack: When you need LIFO behavior

UNDERLYING CONTAINERS:
- deque (default): Good performance for both ends
- list: Good for frequent insertions/deletions
- vector: Not recommended (inefficient pop_front)

=============================================================================
*/
