#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int tcases;
    cin >> tcases;
    for (int i = 0; i < tcases; i++)
    {
        int n, k;
        cin >> n >> k;
        // we chose pair because we wanted to preserve the index of elements after sorting
        vector<pair<int, int>> A(n); //{value, index}
        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            A[i] = {val, i};
        }
        sort(A.begin(), A.end());
        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        vector<int> answer(n);
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++)
        {
            answer[A[i].second] = b[i];
        }
        for (int i = 0; i < n; i++)
        {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    return 0;
}