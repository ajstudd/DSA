#include <iostream>
using namespace std;

// Define a Stack class
class Stack
{
private:
    int *arr;     // Pointer to the stack array
    int top;      // Index of the top element
    int capacity; // Maximum capacity of the stack

public:
    // Constructor to initialize the stack
    Stack(int size)
    {
        capacity = size;
        arr = new int[capacity]; // Dynamically allocate array
        top = -1;                // Initialize top as -1 (stack is empty)
    }

    // Destructor to free memory
    ~Stack()
    {
        delete[] arr;
    }

    // Push operation: Add an element to the stack
    void push(int value)
    {
        if (top == capacity - 1)
        { // Check for overflow
            cout << "Stack Overflow! Cannot add more elements.\n";
            return;
        }
        arr[++top] = value; // Increment top and add element
    }

    // Pop operation: Remove the top element
    int pop()
    {
        if (top == -1)
        { // Check for underflow
            cout << "Stack Underflow! Cannot remove element.\n";
            return -1; // Return an invalid value
        }
        return arr[top--]; // Return top element and decrement top
    }

    // Peek/Top operation: Retrieve the top element without removing it
    int peek()
    {
        if (top == -1)
        { // Check if the stack is empty
            cout << "Stack is empty.\n";
            return -1;
        }
        return arr[top]; // Return the top element
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // Get the size of the stack
    int size()
    {
        return top + 1;
    }

    // Reverse the stack
    void reverse()
    {
        int start = 0, end = top;
        while (start < end)
        {
            swap(arr[start], arr[end]); // Swap elements
            start++;
            end--;
        }
    }

    // Print all elements in the stack
    void print()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return;
        }
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

// Main function to demonstrate stack operations
int main()
{
    Stack s(5); // Create a stack with capacity 5

    s.push(10); // Add elements
    s.push(20);
    s.push(30);

    cout << "Stack after pushing elements: ";
    s.print();

    cout << "Top element: " << s.peek() << "\n";

    s.pop(); // Remove the top element
    cout << "Stack after popping an element: ";
    s.print();

    s.reverse(); // Reverse the stack
    cout << "Stack after reversing: ";
    s.print();

    return 0;
}
