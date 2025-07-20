#include <iostream>
#include <string>
using namespace std;

void kthCharacter(string s)
{
    char ch = s[0];
    cout << ch + 1;
}

int main()
{
    string s = "a";
    kthCharacter(s);
    return 0;
}