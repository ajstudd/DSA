#include <iostream>
#include <cctype>
using namespace std;
bool checkValid(char ch)
{
    int ascii = ch;
    return (ascii >= 48 && ascii <= 57) || (ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122);
}
void main()
{
    string st = "A man, a plana, a canal: Panama";
    int start = 0, end = st.size() - 1;
    while (start < end)
    {
        if (!checkValid(st[start]))
        {
            start++;
        }
        else if (!checkValid(st[end]))
        {
            end--;
        }
        else if (tolower(st[start]) == tolower(st[end]))
        {
            start++;
            end--;
        }
        else
        {
            cout << "False";
            return;
        }
    }
    cout << "Palindrome";
}