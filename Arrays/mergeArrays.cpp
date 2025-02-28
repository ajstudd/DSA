#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {1, 5, 9, 11, 77};
    int arr2[5] = {2, 6, 11, 14, 78};
    int final[10];
    int pt1 = 0;
    int pt2 = 0;
    int ptf = 0;
    int n1 = sizeof(arr) / sizeof(arr[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    while (pt1 < n1 && pt2 < n2)
    {
        if (arr[pt1] < arr2[pt2])
        {
            final[ptf] = arr[pt1];
            pt1++;
            ptf++;
        }
        else
        {
            final[ptf] = arr2[pt2];
            pt2++;
            ptf++;
        }
    }
    if (pt1 < n1)
    {
        for (int i = pt1; i < n1; i++)
        {
            final[ptf] = arr[i];
            ptf++;
        }
    }
    if (pt2 < n2)
    {
        for (int i = pt2; i < n2; i++)
        {
            final[ptf] = arr2[i];
            ptf++;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout << final[i] << endl;
    }
    return 0;
}
