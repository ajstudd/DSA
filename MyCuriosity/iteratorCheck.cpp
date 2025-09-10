#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>

using namespace std;

int main()
{
    vector<int> arr(5);
    iota(arr.begin(), arr.end(), 1);
    auto itr = arr.begin();
    itr++;
    cout << itr[0];
    return 0;
}