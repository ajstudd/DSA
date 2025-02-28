#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<vector<int>> dual;
    dual.push_back({1, 2});

    // max element of vector
    cout << *max_element(dual[0].begin(), dual[0].end());
    cout << dual[0][1];
    return 0;
}