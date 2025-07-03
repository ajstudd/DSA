#include <iostream>
using namespace std;

class Car
{
public:
    string st;

    Car(string a)
    {
        st = a;
        cout << "Constructor Called for : " << st << endl;
    }
    ~Car() { cout << "Destructor Called for : " << st << endl; }
};

int main()
{
    Car car1("1");
    Car car2("2");
    Car car3("3");
}
