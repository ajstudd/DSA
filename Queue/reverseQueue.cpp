#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> s;

    // Transfer queue elements to a stack
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    // Transfer back to the queue
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Queue before reversing: ";
    queue<int> temp = q;
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }

    reverseQueue(q);

    cout << "\nQueue after reversing: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
