#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int maxCustomers = 0;
    vector<pair<int, int>> arriveAndDepart;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arriveAndDepart.push_back({a, b});
    }
    sort(arriveAndDepart.begin(), arriveAndDepart.end());
    for (int i = 0; i < arriveAndDepart.size() - 1; i++)
    {
        int range = arriveAndDepart[i].second;
        int customers = 1;
        int index = i + 1;
        while (range >= arriveAndDepart[index].first)
        {
            customers++;
            index++;
        }
        maxCustomers = max(customers, maxCustomers);
    }
    cout << maxCustomers;
    return 0;
}