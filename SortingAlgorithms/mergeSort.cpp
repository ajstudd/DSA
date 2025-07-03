#include <iostream>
#include <vector>
using namespace std;
// we do not actually break array, we just conceptually make it seem

void merge(vector<int> &a, int left, int right, int mid)
{
    int n1 = mid - left + 1;
    int n2 = right - (mid + 1) + 1;
    // basically we assume we have two sorted arrays, we need to merge them using two pointers
    vector<int> l(n1), r(n2);
    int pt1 = 0, pt2 = 0, pt3 = left;
    for (int i = 0; i < n1; i++)
    {
        l[i] = a[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        r[i] = a[i + mid + 1];
    }
    while (pt1 < n1 && pt2 < n2)
    {
        if (l[pt1] <= r[pt2])
        {
            a[pt3] = l[pt1];
            pt1++;
        }
        else
        {
            a[pt3] = r[pt2];
            pt2++;
        }
        pt3++;
    }
    while (pt1 < n1)
    {
        a[pt3] = l[pt1];
        pt3++;
        pt1++;
    }
    while (pt2 < n2)
    {
        a[pt3] = r[pt2];
        pt2++;
        pt3++;
    }
}
void mergesort(vector<int> &a, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    mergesort(a, left, mid);
    mergesort(a, mid + 1, right);
    merge(a, left, right, mid);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        // because i is the actual element, not index
        cin >> i;
    mergesort(a, 0, n - 1);
    for (auto &i : a)
        cout << i << endl;
    return 0;
}