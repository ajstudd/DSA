#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> items(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        cin >> items[i];
    }
    for (int i = 0; i < n; i++)
    {
        ans[items[i] - 1] = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}