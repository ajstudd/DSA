#include <iostream>
using namespace std;

class Abc
{
public:
    string ab;
    int numb;
    Abc(string st, int n)
    {
        this->ab = st;
        this->numb = n;
    }
    void print()
    {
        cout << "AB is: " << this->ab << endl;
        cout << "Numb is: " << this->numb << endl;
    }
};
int main()
{
    // stack allocation
    Abc anObject("hello", 123);
    anObject.print();
    // pointer method or we can say heap allocation
    Abc *ptr = new Abc("Junaid", 786);
    cout << ptr->ab << endl;
    cout << ptr->numb << endl;
    ptr->print();
    return 0;
}