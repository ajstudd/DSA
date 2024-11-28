#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> dual;
    dual.push_back({1, 2});
    cout << dual[0][1];
    return 0;
}