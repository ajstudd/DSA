// #include <iostream>
// using namespace std;

// void backAndForth(int direction, int current, int n)
// {
//     if ((direction == 1 && current < 0) || (direction == 0 && current >= n))
//     {
//         return;
//     }
//     backAndForth(0, current + 1, n);
//     cout << n << endl;
//     backAndForth(1, n - 1, n);

//     // if (iterator >= n)
//     // {
//     //     backAndForth(n - 1, n - 1);
//     // }
//     // if (iterator < 0)
//     // {
//     //     return;
//     // }
//     // cout << iterator << endl;
//     // backAndForth(iterator + 1, n);
// }
// int main()
// {
//     int n;
//     cin >> n;
//     backAndForth(0, 1, n);
//     return 0;
// }

#include <iostream>
using namespace std;

void backAndForth(int current, int n)
{
    if (current == 0)
        return;

    cout << current << " ";

    backAndForth(current - 1, n);

    if (current != n)
        cout << current << " ";
}

int main()
{
    int n;
    cin >> n;
    backAndForth(n, n);
    return 0;
}
