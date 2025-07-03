#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// trucks can be ordered in ascending order using main streed and side street? no truck can reverse and re-enter side street
// side street is stack
int main()
{
    int n;
    cin >> n;
    vector<int> items(n);
    for (int i = 0; i < n; i++)
    {
        cin >> items[i];
    }
    stack<int> st;
    int zero;
    cin >> zero;
    int expected = 1;
    int index = 0;
    while (index < n || (!st.empty() && st.top() == expected))
    {
        if (index < n && items[index] == expected)
        {
            expected++;
            index++;
        }
        else if (!st.empty() && st.top() == expected)
        {
            st.pop();
            expected++;
        }
        else if (index < n)
        {
            st.push(items[index]);
            index++;
        }
        else
        {
            break;
        }
    }
    if (expected == n + 1)
        cout << "yes";
    else
        cout << "no";
    return 0;
}