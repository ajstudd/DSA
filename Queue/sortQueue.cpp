#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void sortQueue(queue<int> &q)
{
    vector<int> vec;

    // Transfer queue elements to a vector
    while (!q.empty())
    {
        vec.push_back(q.front());
        q.pop();
    }

    // Sort the vector
    sort(vec.begin(), vec.end());

    // Transfer back to the queue
    for (int item : vec)
    {
        q.push(item);
    }
}

int main()
{
    queue<int> q;
    q.push(30);
    q.push(10);
    q.push(50);
    q.push(20);

    cout << "Queue before sorting: ";
    queue<int> temp = q;
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }

    sortQueue(q);

    cout << "\nQueue after sorting: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
