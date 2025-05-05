#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// convert into Hexatrigesimal
//  base 36
//  0 to 9 and A to Z
int main()
{
    int n = 20;
    string st = "";
    while (n > 0)
    {
        int rem = n % 36;
        if (rem >= 10)
        {
            st += (char)(65 + (rem - 10));
        }
        else
        {
            st += to_string(rem);
        }
        n = n / 36;
    };
    reverse(st.begin(), st.end());
    cout << st;
    return 0;
};