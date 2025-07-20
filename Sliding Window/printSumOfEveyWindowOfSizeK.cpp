#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 5, 9, 5, 2, 6};
    int size = arr.size();
    int sum = 0;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    cout << sum << endl;
    for (int i = k; i < size + 1; i++)
    {
        sum -= arr[i - k];
        sum += arr[i];
        cout << sum << endl;
    }
    return 0;
}