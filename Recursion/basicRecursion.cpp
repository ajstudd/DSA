#include <iostream>
using namespace std;

int sum(int prevnum)
{
    if (prevnum < 0)
    {
        return 0;
    }
    return prevnum + sum(prevnum - 1);
}

int main()
{
    int sumofN = 0;
    sumofN = sum(10);
    int input;
    cout << "Enter a number";
    cin >> input;
    cout << input << endl;
    cout << sumofN;
    return 0;
}
