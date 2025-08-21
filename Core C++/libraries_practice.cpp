#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string st = "Junaid";
    cout << "String before edits: " << st << endl;
    st.append(" Ahmad");
    cout << "String after append: " << st << endl;
    cout << "Subtring from 0 to 4: " << st.substr(0, 4) << endl;
    cout << "Subtring from 4 to last: " << st.substr(4) << endl;
    st.replace(0, 6, "Jazzy");
    cout << "Replaced String from 0 to 6: " << st << endl;

    cout << "Vector/Array Practice: " << st << endl;
    int *arr = new int[5];
    int arr2[] = {1, 2, 3, 4, 5};
    // cannot write arr = {1,2,3,4,5}
    // This is not allowed in C++ because:
    // {1, 2, 3, 4, 5} is an initializer list.
    // You can't assign an initializer list directly to a raw pointer like arr.
    // This assignment tries to assign a braced initializer list to a pointer, which is not a valid operation.
    vector<int> test;
    test = {1, 2, 3, 4, 5, 6};
    // sort in ascending
    sort(test.begin(), test.end());
    // reverse vector
    reverse(test.begin(), test.end());
    // sort in descending
    sort(test.begin(), test.end(), greater<int>());

    return 0;
}
