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
    int size = 5;                                   // Original array size
    int *dynamicArr = new int[size]{1, 2, 3, 4, 5}; // Allocate memory on heap and initialize
                                                    // 'new int[size]' allocates 5*sizeof(int) bytes
                                                    // Returns pointer to first element
                                                    // Memory layout: [1][2][3][4][5] at some heap address

    cout << "Original array address: " << dynamicArr << endl;
    cout << "Original array contents: ";
    for (int i = 0; i < size; i++)
        cout << dynamicArr[i] << " ";
    cout << endl;

    // Resize by creating new array (C++ arrays can't be resized directly)
    int newSize = 7;                 // Target size is larger than original
    int *resized = new int[newSize]; // Allocate NEW memory block on heap (7*sizeof(int) bytes)
                                     // This is a DIFFERENT memory location from dynamicArr
                                     // Memory layout: [garbage][garbage][garbage][garbage][garbage][garbage][garbage]

    cout << "New array address: " << resized << endl;
    cout << "Addresses are different: " << (dynamicArr != resized ? "Yes" : "No") << endl;

    // Copy existing data from old array to new array
    copy(dynamicArr, dynamicArr + size, resized); // STL algorithm copies elements [0] to [4]
                                                  // Source: dynamicArr[0] to dynamicArr[4]
                                                  // Destination: resized[0] to resized[4]
                                                  // After copy: resized = [1][2][3][4][5][garbage][garbage]

    cout << "After copying old data: ";
    for (int i = 0; i < newSize; i++)
        cout << resized[i] << " ";
    cout << endl;

    // Initialize the new elements that weren't in original array
    resized[5] = 6; // Set 6th element (index 5)
    resized[6] = 7; // Set 7th element (index 6)
                    // Now: resized = [1][2][3][4][5][6][7]

    cout << "After adding new elements: ";
    for (int i = 0; i < newSize; i++)
        cout << resized[i] << " ";
    cout << endl;

    // Memory management: Clean up old array
    delete[] dynamicArr; // FREE the original memory block
                         // The memory that dynamicArr pointed to is now deallocated
                         // dynamicArr still holds the old address but it's invalid now
                         // Accessing *dynamicArr after this point = undefined behavior

    cout << "Old array memory freed. Old pointer still points to: " << dynamicArr << " (now invalid)" << endl;

    // Update pointer to point to new array
    dynamicArr = resized; // dynamicArr now points to the new memory location
                          // Both dynamicArr and resized point to same memory
                          // We now have TWO pointers to the SAME memory block

    cout << "dynamicArr now points to: " << dynamicArr << endl;
    cout << "resized points to: " << resized << endl;
    cout << "Same address: " << (dynamicArr == resized ? "Yes" : "No") << endl;

    // Display the resized array using the updated pointer
    cout << "Final resized array: ";
    for (int i = 0; i < newSize; i++)
    {
        cout << dynamicArr[i] << " "; // Access through dynamicArr (now points to new array)
    }
    cout << endl;

    // Final cleanup: Free the new array memory
    delete[] dynamicArr; // Free the memory that dynamicArr points to
                         // Since dynamicArr and resized point to same memory,
                         // this frees the memory allocated for 'resized'
                         // After this: both dynamicArr and resized are dangling pointers

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

/*
Worst Case Time Complexity: O(n log n)
Most operations in this code are O(n) where n is the array size: loops, copying, memory allocation.
The sorting operations (sort()) dominate with O(n log n) complexity using comparison-based algorithms.
Individual operations like push_back, pop_back, and element access are O(1) amortized time.
*/