// #include <iostream>

// using namespace std;

// int timesMult(int value, int n, int actual)
// {
//     int finalval = value;
//     for (int i = 0; i < n; i++)
//     {
//         finalval *= finalval;
//     }
//     if (finalval != actual)
//     {
//         return false;
//     }
//     else
//     {
//         return true;
//     }
// };
// int possibleSquare(int num, int start, int mid, int end, int n, int actual)
// {
//     while (start <= end)
//     {
//         if (timesMult(mid, n, actual) > actual)
//         {
//             end = mid - 1;
//             mid = (start + end) / 2;
//             possibleSquare(num, start, mid, end, n, num);
//         }
//         else if (timesMult(mid, n, actual) < actual)
//         {
//             start = mid + 1;
//             mid = (start + end) / 2;
//             possibleSquare(num, start, mid, end, n, num);
//         }
//         else if (timesMult(mid, n, actual) == actual)
//         {
//             return mid;
//         }
//         else
//         {
//             return 1;
//         }
//     }
//     return mid;
// }

// int main()
// {
//     int num = 9;
//     int n = 2;
//     int start = 1;
//     int end = num / 2;
//     int mid = (start + end) / 2;
//     int initialTarget = mid;
//     int root = possibleSquare(num, start, mid, end, n, num);
//     cout << root;
//     return 0;
// }

#include <iostream>
using namespace std;

int timesMult(int value, int n)
{
    int finalval = value;
    for (int i = 1; i < n; i++)
    {
        finalval *= value;
    }
    return finalval;
}

int possibleSquare(int num, int start, int end, int n)
{
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        int power = timesMult(mid, n);

        if (power == num)
        {
            return mid;
        }
        else if (power < num)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int num = 9;
    int n = 2;
    int start = 1;
    int end = num;
    int root = possibleSquare(num, start, end, n);
    cout << root << endl;
    return 0;
}
