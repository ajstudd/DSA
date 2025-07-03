// You are given the arrival and leaving times of n customers in a restaurant.
// What was the maximum number of customers in the restaurant at any time?

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// int main()
// {
//     int size;
//     map<int, int> checkInOut;
//     for (int i = 0; i < size; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         for (int j = a; j <= b; j++)
//         {
//             checkInOut[j] += 1;
//         }
//     }
//     int maxCustomersAtAtime = 0;
//     for (auto &[key, value] : checkInOut)
//     {
//         if (value > maxCustomersAtAtime)
//         {
//             maxCustomersAtAtime = value;
//         }
//     }
//     cout << maxCustomersAtAtime;
//     return 0;
// }

// optimised version
int main()
{
    int size;
    cin >> size;
    map<int, int> events;
    for (int i = 0; i < size; i++)
    {
        int a, b;
        cin >> a >> b;
        events[a] += 1;
        events[b + 1] -= 1;
    }
    int maxCustomers = 0, current = 0;
    for (auto &[time, delta] : events)
    {
        current += delta;
        maxCustomers = max(maxCustomers, current);
    }
    cout << maxCustomers;

    return 0;
}
