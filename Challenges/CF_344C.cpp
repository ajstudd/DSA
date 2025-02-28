// #include <iostream>
// using namespace std;

// long long answer = 0;

// void recFun(long a, long b)
// {
//     if (a == 0 || b == 0)
//     {
//         return;
//     }
//     if (a >= b)
//     {
//         answer++;
//         recFun(a - b, b);
//     }
//     else
//     {
//         answer++;
//         recFun(a, b - a);
//     }
// }
// int main()
// {
//     long a, b;
//     cin >> a >> b;
//     recFun(a, b);
//     cout << answer;
//     return 0;
// }

// LABEL: updated code to handle overflow

#include <iostream>
using namespace std;

long long answer = 0;

void recFun(long long a, long long b)
{
    if (a == 0 || b == 0)
    {
        return;
    }
    if (a >= b)
    {
        answer += a / b;
        recFun(a % b, b);
    }
    else
    {
        answer += b / a;
        recFun(a, b % a);
    }
}
int main()
{
    long long a, b;
    cin >> a >> b;
    recFun(a, b);
    cout << answer;
    return 0;
}

// LABEL: More Optimised

#include <iostream>
using namespace std;

long long answer = 0;

void recFun(long long a, long long b)
{
    if (b == 0)
    {
        return;
    }
    answer += a / b;
    recFun(b, a % b);
}
int main()
{
    long long a, b;
    cin >> a >> b;
    recFun(a, b);
    cout << answer;
    return 0;
}