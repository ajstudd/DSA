#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;

    // Add elements
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl;
    cout << "Rear element: " << q.back() << endl;

    // creating a tuple queue, basically storing more data in each queue element
    queue<tuple<int, int>> tupq;
    //  taking out the data from que front
    auto [item1, item2] = tupq.front();

    // Remove elements
    q.pop(); // Removes the front element
    cout << "After dequeuing, front element: " << q.front() << endl;

    return 0;
}

/*
Worst Case Time Complexity: O(1)
All basic queue operations (push, pop, front, back) have constant time complexity.
The STL queue is typically implemented using deque, providing O(1) operations at both ends.
Creating tuple queue and structured binding operations are also O(1).
Overall program complexity is O(1) as it performs a fixed number of constant-time operations.
*/
