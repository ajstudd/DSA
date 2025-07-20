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
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int numberOfCustomers;
    cin >> numberOfCustomers;

    map<int, int> customerChanges;

    for (int i = 0; i < numberOfCustomers; i++)
    {
        int arrivalTime, departureTime;
        cin >> arrivalTime >> departureTime;

        customerChanges[arrivalTime] += 1;
        customerChanges[departureTime + 1] -= 1;
    }

    int maxCustomersInside = 0;
    int currentCustomersInside = 0;

    for (auto &[time, changeInCustomers] : customerChanges)
    {
        currentCustomersInside += changeInCustomers;
        maxCustomersInside = max(maxCustomersInside, currentCustomersInside);
    }

    cout << maxCustomersInside;

    return 0;
}
