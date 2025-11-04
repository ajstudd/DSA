#include <iostream>
#include <string>
using namespace std;
const int YEAR = 2025;
void greetUser(const string &name);
void calculateage(int birthyear);
// INFO: There was this issue that after printing some values, when I was closing the program, it was still giving me output as per last option.
int main()
{
    int input;
    do
    {
        cin >> input;
        switch (input)
        {
        case 1:
        {
            string name;
            cin >> name;
            greetUser(name);
            break;
        }
        case 2:
        {
            int birthyear;
            cin >> birthyear;
            calculateage(birthyear);
            break;
        }
        case 3:
            break;
        default:
            break;
        }
    } while (input != 3);
    return 0;
}

void greetUser(const string &name)
{
    cout << "Hello " << name << endl;
}

void calculateage(int b)
{
    int age = YEAR - b;
    cout << "Your age is " << age << endl;
}