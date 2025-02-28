#include <iostream>
using namespace std;
// this question is solved similarly to tower of hanoi

int alienMover(int n, int count = 0)
{
    if (n <= 0)
    {
        return count;
    };
    count = alienMover(n - 1, count++);
    count++;
    count = alienMover(n - 1, count++);
    count++;
    count = alienMover(n - 1, count++);
}
int main()
{
    int n, m;
    cin >> n >> m;
    cout << alienMover(n);
}