#include <iostream>
using namespace std;

class Queue
{
private:
    int front, rear, size, capacity;
    int *array;

public:
    // Constructor: Initialize the queue
    Queue(int capacity)
    {
        this->capacity = capacity;
        front = 0;
        size = 0;
        rear = capacity - 1; // Rear starts at the end
        array = new int[capacity];
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Check if the queue is full
    bool isFull()
    {
        return size == capacity;
    }

    // Add an element to the queue (Enqueue)
    void enqueue(int item)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue " << item << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Move rear circularly
        array[rear] = item;
        size++;
        cout << item << " enqueued to queue.\n";
    }

    // Remove an element from the queue (Dequeue)
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue.\n";
            return INT_MIN;
        }
        int item = array[front];
        front = (front + 1) % capacity; // Move front circularly
        size--;
        return item;
    }

    // Get the front element of the queue
    int frontElement()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return INT_MIN;
        }
        return array[front];
    }

    // Get the rear element of the queue
    int rearElement()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return INT_MIN;
        }
        return array[rear];
    }

    // Destructor: Free memory
    ~Queue()
    {
        delete[] array;
    }
};

// Main function
int main()
{
    Queue q(5); // Create a queue with capacity 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Front element is " << q.frontElement() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Front element is now " << q.frontElement() << endl;

    q.enqueue(50);
    q.enqueue(60); // This will show "Queue is full" since capacity is 5

    return 0;
}
