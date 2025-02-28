#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b)
{
    return a > b;
}
int main()
{
    vector<int> v = {1, 3, 5, 7, 9};

    vector<vector<int>> dual;
    dual.push_back({1, 2});

    // max element of vector
    cout << *max_element(dual[0].begin(), dual[0].end());

    // Find the min element
    int min = *min_element(v.begin(), v.end());

    // Reverse the vector
    reverse(v.begin(), v.end());

    // Finding the index of 5
    auto it = find(v.begin(), v.end(), 5);

    // Sort vector in descending order
    sort(v.begin(), v.end(), comp);

    for (auto i : v)
        cout << i << " ";
    return 0;
}