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

    // Remove elements
    q.pop(); // Removes the front element
    cout << "After dequeuing, front element: " << q.front() << endl;

    return 0;
}
