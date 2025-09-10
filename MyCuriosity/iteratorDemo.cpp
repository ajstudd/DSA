#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    vector<int> arr(5);
    iota(arr.begin(), arr.end(), 1);

    cout << "Vector contents: ";
    for (int x : arr)
        cout << x << " ";
    cout << "\n\n";

    auto itr = arr.begin();
    cout << "Initially, itr points to: " << *itr << "\n";
    cout << "itr[0] = " << itr[0] << " (same as *itr)\n";
    cout << "itr[1] = " << itr[1] << " (next element)\n";
    cout << "itr[2] = " << itr[2] << " (two elements ahead)\n\n";

    itr++; // Move to second element
    cout << "After itr++, itr points to: " << *itr << "\n";
    cout << "itr[0] = " << itr[0] << " (current position)\n";
    cout << "itr[1] = " << itr[1] << " (next element)\n";
    cout << "itr[-1] = " << itr[-1] << " (previous element)\n";

    return 0;
}
