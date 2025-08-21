#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        string st;
        cin >> st;
        string firstNum, secondNum;
        int index = 0;
        firstNum = st[index];
        index += 1;
        while (index < st.length())
        {
            if (st[index] == '0')
            {
                firstNum += st[index];
                index++;
            }
            else
            {
                break;
            }
        }
        while (index < st.length())
        {
            secondNum += st[index];
            index++;
        }

        if (secondNum.empty())
        {
            cout << -1 << endl;
        }
        else
        {
            int fnum = stoi(firstNum), snum = stoi(secondNum);
            if (snum > fnum)
                cout << stoi(firstNum) << " " << stoi(secondNum) << endl;
            else
            {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}