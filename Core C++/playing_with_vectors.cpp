#include <iostream>
#include <vector>
#include <iterator>
// #include <algorithm>
using namespace std;

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    // to empty v1 and move to v2
    vector<int> v2;
    v2 = move(v1);

    // print whole vector without for loop
    copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
    vector<int> v3(v2);
    copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, " "));
    return 0;
}