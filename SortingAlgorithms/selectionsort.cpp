#include <iostream>
using namespace std;

void mySwap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// LABEL: SELECTION SORT

int main()
{
    int array[] = {5, 14, 18, 19, 2, 36, 14, 202, 65, 98, 14, 1, 0, 155};
    int size = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[min] > array[j])
            {
                min = j;
            }
        }
        if (min != array[i])
        {
            mySwap(array[min], array[i]);
        }
    }
    cout << "printing the sorted array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}

/*
Worst Case Time Complexity: O(n²)
The outer loop runs n times, and for each iteration, the inner loop runs (n-i-1) times.
Total comparisons = (n-1) + (n-2) + ... + 1 = n(n-1)/2, which simplifies to O(n²).
Selection sort always performs the same number of comparisons regardless of input order.
*/