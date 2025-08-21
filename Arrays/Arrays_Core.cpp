#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // this is for accumulate function
using namespace std;

int main()
{
    // array with fixed size;
    int arr[5] = {1, 2, 3, 4, 5};
    // array with automatically size set
    int arr2[] = {1, 2, 3, 4, 5, 6};

    // Array pointers
    int *ptr = arr;      // pointer to first element
    int *ptr2 = &arr[0]; // same as above

    // Sort fixed size array
    sort(arr, arr + 5);

    // Reverse fixed size array
    reverse(arr, arr + 5);

    // Sort in descending order
    sort(arr, arr + 5, greater<int>());

    // Sort auto-sized array
    sort(arr2, arr2 + 6);

    // Reverse auto-sized array
    reverse(arr2, arr2 + 6);

    // Sort in descending order
    sort(arr2, arr2 + 6, greater<int>());

    // Loop and update array using pointer
    for (int i = 0; i < 5; i++)
    {
        *(ptr + i) = *(ptr + i) * 2; // multiply each element by 2
    }

    // Alternative: using pointer arithmetic
    int *p = arr;
    for (int i = 0; i < 5; i++)
    {
        *p = *p * 3; // multiply by 3
        p++;         // move to next element
    }

    // Display updated array
    cout << "Updated array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Using pointers to access elements
    cout << "First element: " << *ptr << endl;
    cout << "Second element: " << *(ptr + 1) << endl;

    // Dynamic array allocation (resizable)
    int size = 5;
    int *dynamicArr = new int[size]{1, 2, 3, 4, 5};

    // Resize by creating new array
    int newSize = 7;
    int *resized = new int[newSize];
    copy(dynamicArr, dynamicArr + size, resized); // copy old data
    resized[5] = 6;                               // add new elements
    resized[6] = 7;

    delete[] dynamicArr;  // free old memory
    dynamicArr = resized; // update pointer

    for (int i = 0; i < newSize; i++)
    {
        cout << dynamicArr[i] << " ";
    }
    cout << endl;

    delete[] dynamicArr; // cleanup

    // LABEL: Dynamic Arrays
    vector<int> v; // dynamic array

    v.push_back(10); // Insert
    v.push_back(20);
    v.pop_back(); // Remove last

    // Sort
    sort(v.begin(), v.end());

    // Reverse
    reverse(v.begin(), v.end());

    // Find
    if (find(v.begin(), v.end(), 3) != v.end())
        cout << "Found 3";

    // Accumulate (sum)
    int sum = accumulate(v.begin(), v.end(), 0);

    // converting traditional arrays to vector
    int t_array[] = {1, 2, 3, 4, 5};
    vector<int> vect(t_array, t_array + sizeof(t_array) / sizeof(t_array[0]));

    // but it will not work with dynamically allocated arrays
    // because sizeof() does not work correctly on pointers.
    // If you're working with a pointer (int* arr = new int[5];), you'll need to pass the size manually:
    int *pointerArr = new int[5]{1, 2, 3, 4, 5};
    vector<int> vect2(pointerArr, pointerArr + 5); // Manual size
    return 0;
}