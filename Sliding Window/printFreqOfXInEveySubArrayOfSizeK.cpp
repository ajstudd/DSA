#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 2, 2, 2, 9, 5, 2, 6};
    int size = arr.size();
    int freq = 0;
    int k, x;
    cin >> k;
    cin >> x;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] == x)
            freq += 1;
    }
    cout << freq << endl;
    for (int i = k; i < size + 1; i++)
    {

        if (arr[i] == x)
        {
            freq += 1;
        }
        if (arr[i - k] == x)
        {
            freq -= 1;
        }
        cout << freq << endl;
    }
    return 0;
}