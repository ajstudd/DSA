#include <iostream>
#include <stack>
#include <algorithm> // For reverse
#include <vector>    // For extra storage

using namespace std;

// Function to print the stack elements
void printStack(stack<int> s)
{
    if (s.empty())
    {
        cout << "Stack is empty.\n";
        return;
    }

    stack<int> tempStack; // Temporary stack to print in LIFO order
    while (!s.empty())
    {
        cout << s.top() << " ";  // Print the top element
        tempStack.push(s.top()); // Push it to a temp stack
        s.pop();
    }
    cout << "\n";

    // Restore the original stack
    while (!tempStack.empty())
    {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

// Function to reverse a stack
void reverseStack(stack<int> &s)
{
    vector<int> temp; // Temporary storage
    while (!s.empty())
    {
        temp.push_back(s.top());
        s.pop();
    }
    for (int i : temp)
    {
        s.push(i);
    }
}

// Function to sort a stack
void sortStack(stack<int> &s)
{
    vector<int> temp; // Temporary storage
    while (!s.empty())
    {
        temp.push_back(s.top());
        s.pop();
    }
    sort(temp.begin(), temp.end()); // Sort using STL
    for (int i : temp)
    {
        s.push(i); // Push back in sorted order
    }
}

int main()
{
    stack<int> s; // Create a stack

    // Push elements into the stack
    s.push(30);
    s.push(10);
    s.push(20);

    cout << "Initial Stack: ";
    printStack(s);

    cout << "Top element: " << s.top() << "\n";

    s.pop(); // Remove the top element
    cout << "Stack after pop: ";
    printStack(s);

    s.push(40);
    s.push(5);

    cout << "Stack before sorting: ";
    printStack(s);

    sortStack(s);
    cout << "Stack after sorting: ";
    printStack(s);

    reverseStack(s);
    cout << "Stack after reversing: ";
    printStack(s);

    return 0;
}

/*
Worst Case Time Complexity: O(n log n)
Basic stack operations (push, pop, top) are O(1) each.
PrintStack function: O(n) to traverse and O(n) to restore = O(n) total.
SortStack function: O(n) to transfer + O(n log n) to sort + O(n) to push back = O(n log n).
ReverseStack function: O(n) to empty + O(n) to refill = O(n) total.
Overall complexity is dominated by the sorting operation.
*/
