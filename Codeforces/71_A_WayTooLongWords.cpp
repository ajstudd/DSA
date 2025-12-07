#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string st;
        cin >> st;
        int length = st.length();
        if (length > 10)
        {
            int remaining = length - 2;
            cout << st[0] << remaining << st[length - 1];
        }
        else
        {
            cout << st;
        }
        cout << endl;
    }
    return 0;
}